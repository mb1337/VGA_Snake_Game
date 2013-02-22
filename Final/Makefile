CFILES=main.c vga.c input.c random.c interrupts.c speaker.c startup.c
SFILES=vga_timing.asm delay.asm

OC = m68hc12-objcopy
CC = m68hc11-gcc
RM = rm
AS = m68hc12-as

CFLAGS  = -m68hc12 -mshort -mlong-calls -g -Os -Wall -Wmissing-prototypes -Wno-char-subscripts -fomit-frame-pointer -msoft-reg-count=0 -mauto-incdec #-Os -fomit-frame-pointer
ASFLAGS = -m68hc12
LDFLAGS = -m68hc12 -mshort -mlong-calls -Wl,-T,ld.x
OCFLAGS = --srec-len=0x20 --change-addresses 0xffff0000
INCDIR = ../include
LIBDIR = ../lib

SOBJS   =	$(SFILES:.asm=.o)
COBJS   =	$(CFILES:.c=.o)
OBJS    =	$(SOBJS) $(COBJS)

all:	000.elf 000.s19

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $<


%.o: %.asm
	$(AS) $(ASFLAGS) $< -o $@

000.elf:	$(OBJS)
	$(CC) $(LDFLAGS) -o 000.elf $(OBJS) ../lib/lcdUtilDragon12.o ../lib/convert.o #../lib/stdio.o 

000.s19:	000.elf
	$(OC) --output-target=srec $(OCFLAGS) 000.elf 000.s19 

clean:
	$(RM) -f 000.elf
	$(RM) -f 000.s19
	$(RM) -f 000.dmp
	$(RM) -f *~
	$(RM) -f *.o
	clear
