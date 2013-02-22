CSRCS=delay.c convert.c lcdUtilDragon12.c stdio.c

OC = m68hc12-objcopy
CC = m68hc11-gcc
RM = rm
CP = cp
CLS = clear

CFLAGS  = -m68hc12 -O2 -fno-ident -fno-common -fomit-frame-pointer -mshort
LDFLAGS = -Wl,-u,-mm68hc12elfb
OCFLAGS = -O srec
INCDIR = ../include

OBJS=$(CSRCS:.c=.o)

all:	$(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $<

clean:
	$(RM) -f *~
	$(RM) -f *.o
	$(CLS)