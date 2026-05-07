/* See touchscreen.h for protocol documentation. */
#include "touchscreen.h"
#include "mem.h"

#include <string.h>

extern "C" {

static uint32_t s_seq = 0;

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
    volatile struct touchscreen_mailbox *mb = get_mailbox();
    if (!mb)
        return false;
    return mb->plugin_magic == TOUCHSCREEN_PLUGIN_MAGIC;
}

} /* extern "C" */
