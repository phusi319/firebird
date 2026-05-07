/* Touchscreen mailbox: shared protocol between firebird (host)
 * and the in-OS Ndless plugin "fb_touchscreen.tns".
 *
 * Mechanism:
 *   On a tap from the host UI, firebird writes a request into a fixed
 *   region of emulated SDRAM. A small Ndless plugin running inside the
 *   Nspire OS polls the same region and, when it sees a new sequence
 *   number, calls the OS's send_click_event(x, y) — the same function
 *   TI's PC Teacher Software invokes via JNI. The OS then handles the
 *   click natively: cursor jumps to (x, y) and the click is dispatched
 *   to whichever widget is at that location.
 *
 * Mailbox layout (32 bytes, little-endian):
 *   +0x00 u32  magic        host writes 'TPCL' (0x4C435054). Plugin checks.
 *   +0x04 u32  seq          host increments per request; plugin remembers last.
 *   +0x08 u16  x            screen pixel X (0..319 for CX II)
 *   +0x0A u16  y            screen pixel Y (0..239)
 *   +0x0C u8   action       1=press, 2=release, 3=click (press+release)
 *   +0x0D u8   reserved
 *   +0x0E u16  reserved
 *   +0x10 u32  plugin_magic plugin writes 'TPRD' (0x44525054) to acknowledge readiness
 *   +0x14 u32  os_id        plugin writes Ndless OSID (helps host verify match)
 *   +0x18 u32  send_click_event_addr  plugin writes resolved syscall addr (debug)
 *   +0x1C u32  reserved
 *
 * Address: the plugin places the mailbox in its own data segment; firebird
 * locates the actual physical page by scanning SDRAM for PLUGIN_MAGIC on
 * first use and caches the result. Earlier versions tried a fixed phys
 * address (0x13FFFFE0) but the Ndless plugin process MMU re-mapped that
 * virtual address to a different physical page, breaking the protocol.
 */
#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TOUCHSCREEN_MAILBOX_PHYS_ADDR 0x13FFFFE0u
#define TOUCHSCREEN_HOST_MAGIC        0x4C435054u  /* 'TPCL' */
#define TOUCHSCREEN_PLUGIN_MAGIC      0x44525054u  /* 'TPRD' */

#define TOUCHSCREEN_ACTION_PRESS      1
#define TOUCHSCREEN_ACTION_RELEASE    2
#define TOUCHSCREEN_ACTION_CLICK      3

struct touchscreen_mailbox {
    uint32_t magic;
    uint32_t seq;
    uint16_t x;
    uint16_t y;
    uint8_t  action;
    uint8_t  reserved0;
    uint16_t reserved1;
    uint32_t plugin_magic;
    uint32_t os_id;
    uint32_t send_click_event_addr;
    uint32_t reserved2;
};

/* Returns true if the request was queued. False if SDRAM not mapped yet. */
bool touchscreen_send_tap(uint16_t screen_x, uint16_t screen_y, uint8_t action);

/* True if the in-OS plugin has confirmed it's ready (polled lazily). */
bool touchscreen_plugin_ready(void);

#ifdef __cplusplus
}
#endif

#endif
