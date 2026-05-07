# fb_touchscreen — Ndless plugin for firebird touchscreen input

This plugin lets firebird's Android UI deliver **absolute taps** to the
TI-Nspire OS (cursor jumps to the tapped pixel and clicks there), instead
of the relative-touchpad behaviour the OS implements natively.

## How it works

```
 ┌──────────────┐        write           ┌──────────────────────────┐
 │ firebird (Qt)│ ──────────────────────▶ │ mailbox @ phys 0x13FFFFE0│
 │ Android UI   │  x, y, action, seq++    │ (in emulated SDRAM)      │
 └──────────────┘                          └──────────────────────────┘
                                                       ▲ poll
                                                       │
                                            ┌──────────┴──────────┐
                                            │ fb_touchscreen.tns  │
                                            │ (this plugin, runs  │
                                            │  inside Nspire OS)  │
                                            └──────────┬──────────┘
                                                       │ on new seq:
                                                       ▼
                                            send_click_event(x, y)
                                            (native OS syscall)
```

The plugin polls a 32-byte mailbox at the very top of the 64 MB SDRAM region.
Firebird writes a tap; the plugin sees `seq` change and forwards the
coordinates to the OS's own click dispatcher — exactly the same syscall TI's
PC Teacher Software invokes via JNI.

## Supported OS

Currently hardcoded for **TI-Nspire CX II CAS OS 6.2.0.333**. The address of
`send_click_event` (0x1000F14C) is taken from Ndless's
`OS_cascx2-6.2.0.333.idc`. To support other OS versions, edit
`os_addrs.h` and rebuild.

## Build

Requires the [Ndless SDK](https://ndless.me) toolchain in `PATH`
(`arm-none-eabi-gcc`, `genzehn`, `make-prg`).

```sh
make
# produces fb_touchscreen.tns
```

## Install

1. Make sure Ndless 5.x is installed on your calculator (or in firebird's
   emulated NAND).
2. Copy `fb_touchscreen.tns` to `/documents/ndless/startup/` so it
   auto-runs on boot. (Or run it manually once per session.)
3. Reboot. The plugin announces readiness by writing the magic `'TPRD'` to
   the mailbox; firebird's QML then switches its tap path to absolute mode.

## Caveats

- v1 assumes the plugin's process address space identity-maps physical
  SDRAM (it does on every Ndless build we've tested on CX II). If you see
  a Data Abort when the plugin starts, the OS has tightened its page
  tables — open an issue.
- The plugin's polling loop runs on the foreground task. If you launch
  another app, the plugin may stop polling until you exit. A
  timer-interrupt version is planned.
