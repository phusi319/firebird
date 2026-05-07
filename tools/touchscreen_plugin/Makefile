# Build with the Ndless SDK toolchain in PATH.
# Produces fb_touchscreen.tns.

GCC      = nspire-gcc
LD       = nspire-ld
GENZEHN  = genzehn
GCCFLAGS = -Wall -W -marm -Os -ffunction-sections -fdata-sections
# Newer newlib (Ubuntu 24.04 ships 4.4) pulls _malloc_r from libc which
# conflicts with libsyscalls' override; --allow-multiple-definition lets
# libsyscalls win. _sbrk/_fini are provided locally by stubs.c.
LDFLAGS  = -Wl,--gc-sections -Wl,--allow-multiple-definition
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
