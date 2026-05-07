# Build with the Ndless SDK toolchain in PATH.
# Produces fb_touchscreen.tns.

GCC      = nspire-gcc
LD       = nspire-ld
GENZEHN  = genzehn
GCCFLAGS = -Wall -W -marm -Os -ffunction-sections -fdata-sections
LDFLAGS  = -Wl,--gc-sections
ZEHNFLAGS = --name "fb_touchscreen"

OBJS = main.o

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
