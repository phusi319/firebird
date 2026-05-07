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
/* Hooked by main.c to get periodic execution from the OS redraw loop. */
#define OS_CASCX2_6_2_0_333_GUI_GC_GETGC     0x10021964u

/* Currently we hardcode this single OS. Extend later. */
#define SEND_CLICK_EVENT_ADDR  OS_CASCX2_6_2_0_333_SEND_CLICK_EVENT
#define SEND_PAD_EVENT_ADDR    OS_CASCX2_6_2_0_333_SEND_PAD_EVENT
#define GUI_GC_GETGC_ADDR      OS_CASCX2_6_2_0_333_GUI_GC_GETGC

#endif
