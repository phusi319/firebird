/* fb_touchscreen — Ndless plugin paired with firebird's mailbox.
 *
 * See README.md for the architecture diagram.
 *
 * Layout of the mailbox MUST match firebird/core/touchscreen.h.
 */
#include <os.h>
#include <libndls.h>
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

/* The mailbox lives in the plugin's own data segment. We DON'T pin it to
 * a fixed virtual/physical address: the Ndless plugin process has its own
 * MMU mapping, and a hard-coded virtual address (we tried 0x13FFFFE0) was
 * being silently re-mapped by the MMU to whatever physical page the OS
 * had handed the plugin anyway -> host couldn't find it.
 *
 * Strategy: let the plugin's loader place the struct wherever it wants,
 * the host then scans SDRAM for PLUGIN_MAGIC to discover the actual
 * physical address. Once found the host caches it. */
static struct mailbox g_mailbox;

static struct mailbox *get_mailbox(void)
{
    return &g_mailbox;
}

static void announce(struct mailbox *mb)
{
    /* Two adjacent magics so the host can tell our mailbox apart from
     * coincidental occurrences of PLUGIN_MAGIC inside the plugin's own
     * code (literal pool entries) or stale bytes from a previous run. */
    mb->plugin_magic          = PLUGIN_MAGIC;
    mb->os_id                 = PLUGIN_SENTINEL;
    mb->send_click_event_addr = SEND_CLICK_EVENT_ADDR;
}

static void dispatch(struct mailbox *mb)
{
    /* Snapshot fields before the host can race us. */
    uint16_t x = mb->x;
    uint16_t y = mb->y;
    uint8_t  a = mb->action;

    if (x >= 320) x = 319;
    if (y >= 240) y = 239;

    send_click_event_t click = (send_click_event_t)SEND_CLICK_EVENT_ADDR;

    switch (a) {
    case ACTION_PRESS:
    case ACTION_CLICK:
        click(x, y);
        break;
    case ACTION_RELEASE:
        /* The OS auto-releases after a click; nothing to do here for v1. */
        break;
    default:
        break;
    }
}

int main(void)
{
    /* NOTE: this binary is built against the addresses for CX II CAS
     * 6.2.0.333. Running on a different OS version will likely jump to
     * garbage when a tap is dispatched. Multi-OS dispatch is a TODO. */

    struct mailbox *mb = get_mailbox();
    announce(mb);

    uint32_t last_seq = mb->seq;

    /* Polling loop. We yield to the OS each iteration with idle() so we
     * don't peg the CPU. The OS still preempts us on its own schedule. */
    while (1) {
        uint32_t cur = mb->seq;
        if (cur != last_seq) {
            last_seq = cur;
            if (mb->magic == HOST_MAGIC)
                dispatch(mb);
        }

        /* Quit if the user presses ESC for ~half a second so the plugin
         * isn't impossible to unload. */
        if (isKeyPressed(KEY_NSPIRE_ESC)) {
            /* Clear BOTH magics so firebird falls back to relative mode
             * and won't keep finding our stale mailbox on the next scan. */
            mb->plugin_magic = 0;
            mb->os_id        = 0;
            break;
        }

        idle();
    }

    return 0;
}
