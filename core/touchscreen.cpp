/* See touchscreen.h for protocol documentation. */
#include "touchscreen.h"
#include "mem.h"
#include "emu.h"

#include <stdio.h>
#include <string.h>
#include <stddef.h>

extern "C" {

static uint32_t s_seq = 0;
static bool     s_diagnosed = false;
/* Physical address where the plugin's mailbox actually lives. The plugin
 * places its mailbox in its own data segment so the OS's MMU determines
 * the physical page; we discover it by scanning SDRAM for PLUGIN_MAGIC.
 * 0 == not discovered yet. */
static uint32_t s_mailbox_phys = 0;

/* Scan the entire emulated SDRAM looking for the plugin magic 'TPRD'
 * IMMEDIATELY followed by sentinel 'NSPR' (the os_id field). Requiring
 * both rejects coincidental PLUGIN_MAGIC matches from literal pool words
 * inside the plugin's compiled .text or stale bytes from previous runs.
 * Returns the physical address of the plugin_magic field, or -1. */
static int32_t scan_for_plugin_magic(void)
{
    /* mem_areas[1] is SDRAM in firebird's memory layout. */
    const struct mem_area_desc *sd = &mem_areas[1];
    if (!sd->ptr || sd->size == 0)
        return -1;
    const uint32_t magic    = TOUCHSCREEN_PLUGIN_MAGIC;
    const uint32_t sentinel = TOUCHSCREEN_PLUGIN_SENTINEL;
    /* Aligned 4-byte scan. We need 8 bytes (magic + sentinel). */
    for (uint32_t off = 0; off + 8 <= sd->size; off += 4) {
        uint32_t v0, v1;
        memcpy(&v0, sd->ptr + off,     4);
        memcpy(&v1, sd->ptr + off + 4, 4);
        if (v0 == magic && v1 == sentinel)
            return (int32_t)(sd->base + off);
    }
    return -1;
}

static void diagnose_once(void)
{
    /* Wait until SDRAM is actually allocated AND a valid plugin mailbox
     * has been located. Otherwise the diagnostic line is useless and
     * just confuses the user (we used to fire it on emu start, before
     * the user even loaded the plugin). */
    if (s_diagnosed) return;
    const struct mem_area_desc *sd = &mem_areas[1];
    if (!sd->ptr || sd->size == 0)
        return;
    int32_t found = scan_for_plugin_magic();
    if (found < 0)
        return;  /* don't burn the one-shot until we have something useful */
    s_diagnosed = true;

    void *p = phys_mem_ptr(TOUCHSCREEN_MAILBOX_PHYS_ADDR,
                           sizeof(struct touchscreen_mailbox));
    emuprintf("[touchscreen] SDRAM base=0x%08x size=%u MiB ptr=%p\n",
              sd->base, sd->size / (1024*1024), (void*)sd->ptr);
    emuprintf("[touchscreen] mailbox expected @0x%08x phys_mem_ptr=%p\n",
              TOUCHSCREEN_MAILBOX_PHYS_ADDR, p);
    emuprintf("[touchscreen] plugin TPRD+NSPR magic FOUND @phys 0x%08x\n",
              (uint32_t)found);
}

/* Locate the plugin's mailbox. Caches the discovered phys addr in
 * s_mailbox_phys. The mailbox structure starts 0x10 bytes BEFORE the
 * plugin_magic field (see struct layout in touchscreen.h). */
static volatile struct touchscreen_mailbox *get_mailbox(void)
{
    if (s_mailbox_phys == 0) {
        int32_t magic_phys = scan_for_plugin_magic();
        if (magic_phys < 0)
            return NULL;
        /* plugin_magic field sits at offset 0x10 within the mailbox. */
        const uint32_t MAGIC_OFFSET =
            (uint32_t)offsetof(struct touchscreen_mailbox, plugin_magic);
        if ((uint32_t)magic_phys < MAGIC_OFFSET)
            return NULL;
        uint32_t base = (uint32_t)magic_phys - MAGIC_OFFSET;
        /* Suppress duplicate logs when an unchanged plugin is re-scanned. */
        static uint32_t last_logged_base = 0;
        if (base != last_logged_base) {
            emuprintf("[touchscreen] mailbox located @phys 0x%08x\n", base);
            last_logged_base = base;
        }
        s_mailbox_phys = base;
    }
    void *p = phys_mem_ptr(s_mailbox_phys,
                           sizeof(struct touchscreen_mailbox));
    return (volatile struct touchscreen_mailbox *)p;
}

bool touchscreen_send_tap(uint16_t screen_x, uint16_t screen_y, uint8_t action)
{
    volatile struct touchscreen_mailbox *mb = get_mailbox();
    if (!mb)
        return false;

    /* Plugin reads in this order: magic, seq (last), x, y, action.
     * To keep the protocol race-free without locks we write payload first,
     * then a memory barrier, then bump seq last. The plugin polls seq;
     * when it changes it reads the rest. */
    mb->x = screen_x;
    mb->y = screen_y;
    mb->action = action;
    mb->reserved0 = 0;
    mb->reserved1 = 0;
    mb->magic = TOUCHSCREEN_HOST_MAGIC;
    /* On x86 host, regular stores are sufficiently ordered for this
     * single-writer / single-reader producer. The emulated CPU sees
     * memory in firebird's program order. */
    s_seq++;
    mb->seq = s_seq;
    return true;
}

bool touchscreen_plugin_ready(void)
{
    diagnose_once();
    volatile struct touchscreen_mailbox *mb = get_mailbox();
    if (!mb) {
        /* Plugin not loaded (yet) — drop any stale cached address so a
         * future load at a different phys page is picked up cleanly. */
        s_mailbox_phys = 0;
        return false;
    }
    if (mb->plugin_magic != TOUCHSCREEN_PLUGIN_MAGIC ||
        mb->os_id        != TOUCHSCREEN_PLUGIN_SENTINEL) {
        /* Magic mismatch. With the v2 (resident hook) plugin this
         * really shouldn't happen once we've located it, but keep the
         * cache-invalidation as a defensive fallback — covers the
         * theoretical case of the user wiping the plugin and rebooting
         * the emulated calc, where the mailbox would no longer exist
         * in SDRAM. */
        s_mailbox_phys = 0;
        s_diagnosed    = false;  /* let diagnostic re-fire on reload */
        return false;
    }
    return true;
}

} /* extern "C" */
