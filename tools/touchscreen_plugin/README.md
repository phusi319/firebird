# fb_touchscreen — Ndless plugin for firebird touchscreen input

This plugin lets firebird's Android UI deliver **absolute taps** to the
TI-Nspire OS (cursor jumps to the tapped pixel and clicks there), instead
of the relative-touchpad behaviour the OS implements natively.

## How it works

```
 ┌──────────────┐        write           ┌────────────────────────────┐
 │ firebird (Qt)│ ──────────────────────▶ │ mailbox in plugin's static │
 │ Android UI   │  x, y, action, seq++    │ data (located by SDRAM     │
 └──────────────┘                          │ scan for TPRD+NSPR magic) │
                                            └─────────────┬──────────────┘
                                                          ▲
                                                          │ read on every
                                                          │ OS redraw
                                            ┌─────────────┴──────────────┐
                                            │ fb_touchscreen.tns  (this  │
                                            │ plugin, resident inside    │
                                            │ Nspire OS, hooks           │
                                            │ gui_gc_getGC @ ~30 Hz)     │
                                            └─────────────┬──────────────┘
                                                          │ on new seq:
                                                          ▼
                                            send_click_event(x, y)
                                            (native OS function — same
                                             one TI's PC Teacher Software
                                             invokes via JNI)
```

`main()` of the plugin installs a single hook on a frequently-called OS
UI function (`gui_gc_getGC`, called by every screen redraw), tells Ndless
to keep the plugin resident, and then `_exit`s. The OS UI keeps drawing;
each redraw briefly enters our hook which checks the mailbox and, if
firebird has bumped `seq`, forwards the coordinates as an absolute click.

The mailbox lives in the plugin's static data segment. Firebird locates
it once by scanning emulated SDRAM for the dual-magic sentinel
`TPRD` + `NSPR` (relying on a fixed phys address didn't work because
the Ndless plugin process had its own MMU mapping).

## Supported OS

Currently hardcoded for **TI-Nspire CX II CAS OS 6.2.0.333**. Hardcoded
addresses (taken from Ndless's `OS_ncascx2-6.2.0.333.idc`):

| Symbol             | Address      |
|--------------------|--------------|
| `send_click_event` | `0x1000F14C` |
| `gui_gc_getGC`     | `0x10021964` |

To support other OS versions, edit `os_addrs.h` + the `HOOK_TARGET_ADDR`
in `main.c` and rebuild.

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
   auto-runs on boot.
3. Reboot. The plugin installs its hook silently and goes resident.
   Firebird's QML detects the mailbox magics in SDRAM and switches its
   tap path to absolute mode.

## Caveats

- The plugin stays resident until the calculator is rebooted. There is
  no clean unload path in v1; if you remove `fb_touchscreen.tns` from
  startup and reboot, it's gone.
- `gui_gc_getGC` is called from the same task that processes user input.
  We use a re-entrance guard so a click triggered from inside the hook
  doesn't recurse, but if the OS adds a synchronous redraw inside its
  click handler this could still hiccup. Open an issue with a Data Abort
  trace if you hit it.
- HOOK_INSTALL writes to OS code in SDRAM. On the few Nspire builds that
  apply MMU read-only protection to the OS .text region, this will
  fault. CX II CAS 6.2.0.333 doesn't, but newer/locked-down OSes might.
