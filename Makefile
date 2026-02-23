# This makefile is for NMAKE (Visual Studio) and Windows.
# If you're saner than me and use GNU Make and *nix, feel free to provide and
# maintain a GNUMakefile.

AS = cl65
ASFLAGS = -g

CC = cl65
CFLAGS = -O -g

LD = cl65
LDFLAGS = 

CAT = type
RM = del

PKG = c1541

# the only supported target so far
TARGET = c64

!include files.mak

all: $(PROGRAMS)
dist: $(DISK)

.c.o:
	$(CC) -t $(TARGET) -c $(CFLAGS) -l $(<:.c=.lst) --add-source --create-dep $(<:.c=.dep) -o $@ $<

.s.o:
	$(AS) -t $(TARGET) -c $(ASFLAGS) --create-dep $(<:.s=.dep) -o $@ $<

!include deps.mak

breakout.prg: $(breakout_OBJS)
	$(LD) -t $(TARGET) $(LDFLAGS) -o $@ -m breakout.map $**

$(DISK)::
	$(PKG) -format "breakout,00" d64 $@

$(DISK):: breakout.prg
	$(PKG) -attach $@ -write breakout.prg breakout,p

# updates deps.mak from .dep files generated during build
deps: $(breakout_DEPS)
	$(CAT) $** > deps.mak

clean:
	$(RM) $(ARTIFACTS)

rebuild: clean all

.SUFFIXES:
.SUFFIXES: .o .c .s
.PHONY: all clean rebuild dist deps
