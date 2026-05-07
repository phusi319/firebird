/* OS-version-specific addresses.
 *
 * Source of truth: Ndless's per-OS .idc files, e.g.
 *   https://github.com/ndless-nspire/Ndless/blob/master/ndless-sdk/include/os/OS_cascx2-6.2.0.333.idc
 *
 * To support a new OS version: add a block below, run nl_osid() at
 * runtime, and dispatch to the right table.
 */
#ifndef OS_ADDRS_H
#define OS_ADDRS_H

/* TI-Nspire CX II CAS OS 6.2.0.333 */
#define OS_CASCX2_6_2_0_333_SEND_CLICK_EVENT 0x1000F14Cu
#define OS_CASCX2_6_2_0_333_SEND_PAD_EVENT   0x1000F20Cu
/* Hooked by main.c to get periodic execution from the OS redraw loop.
 *
 * The 6.2.0.333 IDC actually lists TWO symbols both named 'gui_gc_getGC':
 *   0x10021964 - a 92-byte wrapper / thunk near doc_opened. Its first
 *                8 bytes contain PC-relative instructions that cannot
 *                be relocated by HOOK_RESTORE_RETURN; hooking it sends
 *                the OS off into freed memory (PC ends up around
 *                0x13a1xxxx executing garbage / 0x0000 BKPT and the
 *                calculator wedges in firebird's debugger).
 *   0x10128fb8 - the real GUI rendering entry point inside the gui
 *                module, with a regular push-prologue that is safe to
 *                relocate. THIS is the one we want.
 */
#define OS_CASCX2_6_2_0_333_GUI_GC_GETGC     0x10128fb8u

/* Currently we hardcode this single OS. Extend later. */
#define SEND_CLICK_EVENT_ADDR  OS_CASCX2_6_2_0_333_SEND_CLICK_EVENT
#define SEND_PAD_EVENT_ADDR    OS_CASCX2_6_2_0_333_SEND_PAD_EVENT
#define GUI_GC_GETGC_ADDR      OS_CASCX2_6_2_0_333_GUI_GC_GETGC

#endif
