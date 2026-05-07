/* fb_touchscreen — Ndless plugin paired with firebird's mailbox.
 *
 * v2 architecture (HOOK-based, resident):
 *
 *   main()  installs a hook on a frequently-called OS UI function
 *           (gui_gc_getGC -> called by every screen redraw, ~30 Hz),
 *           tells Ndless to keep the plugin resident, and _exits.
 *
 *   The hook function runs in the OS's normal control flow, so the
 *   home-screen UI keeps drawing. Each invocation peeks at the shared
 *   mailbox in our static data; when firebird bumps `seq`, we call the
 *   OS-internal send_click_event(x, y) to dispatch an absolute click.
 *
 *   v1 (polling while(1) { idle(); }) is gone -- it starved the OS UI
 *   thread and produced a black screen until the user ESC'd out, which
 *   in turn made the plugin disappear (mailbox vanished -> firebird
 *   fell back to relative touchpad mode).
 *
 *   Once installed, the plugin sticks around until the calculator is
 *   rebooted. There is no clean unload path in v1 of this design.
 *
 * Mailbox layout MUST match firebird/core/touchscreen.h.
 */
#include <os.h>
#include <libndls.h>
#include <hook.h>
#include <nucleus.h>
#include <unistd.h>
#include <stdint.h>

#include "os_addrs.h"

#define HOST_MAGIC        0x4C435054u  /* 'TPCL' */
#define PLUGIN_MAGIC      0x44525054u  /* 'TPRD' */
#define PLUGIN_SENTINEL   0x5253504Eu  /* 'NSPR' (LE) -- second magic to
                                          disambiguate scan hits from
                                          coincidental literal pool words */

#define ACTION_PRESS   1
#define ACTION_RELEASE 2
#define ACTION_CLICK   3

struct mailbox {
    volatile uint32_t magic;
    volatile uint32_t seq;
    volatile uint16_t x;
    volatile uint16_t y;
    volatile uint8_t  action;
    volatile uint8_t  reserved0;
    volatile uint16_t reserved1;
    volatile uint32_t plugin_magic;
    volatile uint32_t os_id;
    volatile uint32_t send_click_event_addr;
    volatile uint32_t reserved2;
};

typedef void (*send_click_event_t)(int x, int y);

/* Resident state. Lives in the plugin's data segment, kept alive by
 * nl_set_resident() so the hook can keep reading it. */
static struct mailbox g_mailbox;
static uint32_t       g_last_seq;
static volatile int   g_in_hook;  /* re-entrance guard */

/* Hook target on TI-Nspire CX II CAS OS 6.2.0.333.
 *   gui_gc_getGC @ 0x10021964
 * Source: ndless-nspire/Ndless tools/MakeSyscalls/idc/OS_ncascx2-6.2.0.333.idc
 *
 * This function is invoked on every screen redraw, giving us roughly
 * 30 Hz sampling without the plugin owning the CPU.
 *
 * NOTE: hooks overwrite 8 bytes (2 instructions) at the entry point.
 * Those 2 instructions must NOT contain PC-relative branches. Function
 * prologues like 'push {regs}; mov rN, r0' relocate fine. */
#define HOOK_TARGET_ADDR GUI_GC_GETGC_ADDR

HOOK_DEFINE(touch_tick) {
    /* The OS function we're hooking is part of the redraw path. If the
     * code we trigger (send_click_event) ends up causing another
     * redraw on the same call stack we'd recurse into ourselves; hooks
     * are not re-entrant. Skip when already inside. */
    if (!g_in_hook) {
        g_in_hook = 1;
        struct mailbox *mb = &g_mailbox;
        uint32_t cur = mb->seq;
        if (cur != g_last_seq) {
            g_last_seq = cur;
            if (mb->magic == HOST_MAGIC && mb->action != ACTION_RELEASE) {
                uint16_t x = mb->x;
                uint16_t y = mb->y;
                if (x >= 320) x = 319;
                if (y >= 240) y = 239;
                send_click_event_t click =
                    (send_click_event_t)SEND_CLICK_EVENT_ADDR;
                click(x, y);
            }
        }
        g_in_hook = 0;
    }
    HOOK_RESTORE_RETURN(touch_tick);
}

int main(void)
{
    /* Publish the mailbox magics so firebird (host) can find this
     * struct via SDRAM scan for [TPRD][NSPR]. */
    g_mailbox.plugin_magic          = PLUGIN_MAGIC;
    g_mailbox.os_id                 = PLUGIN_SENTINEL;
    g_mailbox.send_click_event_addr = SEND_CLICK_EVENT_ADDR;
    g_last_seq                      = g_mailbox.seq;
    g_in_hook                       = 0;

    /* Install the periodic hook into the OS redraw path. Macro takes
     * care of clear_cache() so the rewritten instructions are picked
     * up by the next instruction fetch. */
    HOOK_INSTALL(HOOK_TARGET_ADDR, touch_tick);

    /* Stay resident: don't free our pages on exit, otherwise the hook
     * code we just installed would dangle and crash the OS the next
     * time it redraws. _exit(0) is mandatory; using `return 0` or
     * exit(0) would run libc cleanup (atexit handlers, fclose all,
     * etc.) which corrupts the resident state. */
    nl_set_resident();
    _exit(0);
}
