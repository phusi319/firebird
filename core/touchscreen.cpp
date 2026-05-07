/* See touchscreen.h for protocol documentation. */
#include "touchscreen.h"
#include "mem.h"
#include "emu.h"

#include <stdio.h>
#include <string.h>

extern "C" {

static uint32_t s_seq = 0;
static bool     s_diagnosed = false;

/* Scan the entire emulated SDRAM looking for the plugin magic 'TPRD'.
 * Useful when we suspect the plugin wrote it at a different physical
 * address than expected (e.g. SDRAM size mismatch, virt!=phys mapping
 * inside plugin process). Returns -1 if not found. */
static int32_t scan_for_plugin_magic(void)
{
    /* mem_areas[1] is SDRAM in firebird's memory layout. */
    const struct mem_area_desc *sd = &mem_areas[1];
    if (!sd->ptr || sd->size == 0)
        return -1;
    const uint32_t magic = TOUCHSCREEN_PLUGIN_MAGIC;
    /* Aligned 4-byte scan. */
    for (uint32_t off = 0; off + 4 <= sd->size; off += 4) {
        uint32_t v;
        memcpy(&v, sd->ptr + off, 4);
        if (v == magic)
            return (int32_t)(sd->base + off);
    }
    return -1;
}

static void diagnose_once(void)
{
    if (s_diagnosed) return;
    s_diagnosed = true;

    const struct mem_area_desc *sd = &mem_areas[1];
    void *p = phys_mem_ptr(TOUCHSCREEN_MAILBOX_PHYS_ADDR,
                           sizeof(struct touchscreen_mailbox));
    int32_t found = scan_for_plugin_magic();

    emuprintf("[touchscreen] SDRAM base=0x%08x size=%u MiB ptr=%p\n",
              sd->base, sd->size / (1024*1024), (void*)sd->ptr);
    emuprintf("[touchscreen] mailbox expected @0x%08x phys_mem_ptr=%p\n",
              TOUCHSCREEN_MAILBOX_PHYS_ADDR, p);
    if (found >= 0)
        emuprintf("[touchscreen] plugin TPRD magic FOUND @phys 0x%08x\n",
                  (uint32_t)found);
    else
        emuprintf("[touchscreen] plugin TPRD magic NOT FOUND in SDRAM\n");
}

static volatile struct touchscreen_mailbox *get_mailbox(void)
{
    /* phys_mem_ptr returns NULL if the address isn't mapped (e.g. before
     * SDRAM is configured by boot1/boot2). Caller must check. */
    void *p = phys_mem_ptr(TOUCHSCREEN_MAILBOX_PHYS_ADDR,
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
    if (!mb)
        return false;
    return mb->plugin_magic == TOUCHSCREEN_PLUGIN_MAGIC;
}

} /* extern "C" */
