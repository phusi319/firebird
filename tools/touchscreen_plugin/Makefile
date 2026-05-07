# Build with the Ndless SDK toolchain in PATH.
# Produces fb_touchscreen.tns.

GCC      = nspire-gcc
LD       = nspire-ld
GENZEHN  = genzehn
# IMPORTANT: do NOT use -ffunction-sections / -fdata-sections here.
# HOOK_DEFINE() emits inline asm labels (e.g. __touch_tick_saved_sp:)
# inside naked functions; with function-sections the function lives in
# .text.<name> but the inline-asm-defined symbol falls into plain .text,
# producing 'symbol .text.touch_tick is in a different section' from
# the assembler. Linker --gc-sections is also unsafe because the hook's
# _end_instrs[] trampoline is only referenced from inline asm and would
# get garbage-collected.
GCCFLAGS = -Wall -W -marm -Os
# Newer newlib (Ubuntu 24.04 ships 4.4) pulls _malloc_r from libc which
# conflicts with libsyscalls' override; --allow-multiple-definition lets
# libsyscalls win. _sbrk/_fini are provided locally by stubs.c.
LDFLAGS  = -Wl,--allow-multiple-definition
ZEHNFLAGS = --name "fb_touchscreen"

OBJS = main.o stubs.o

all: fb_touchscreen.tns

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

fb_touchscreen.elf: $(OBJS)
	$(LD) $^ -o $@ $(LDFLAGS)

fb_touchscreen.tns: fb_touchscreen.elf
	$(GENZEHN) --input $< --output fb_touchscreen.zehn $(ZEHNFLAGS)
	make-prg fb_touchscreen.zehn $@
	rm -f fb_touchscreen.zehn

clean:
	rm -f *.o *.elf *.zehn fb_touchscreen.tns

.PHONY: all clean
