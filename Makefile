# This makefile is for NMAKE (Visual Studio) and Windows.
# If you're saner than me and use GNU Make and *nix, feel free to provide and
# maintain a GNUMakefile.

CC = cl65
CFLAGS = -O

LD = cl65
LDFLAGS = 

CAT = type
RM = del

AR = c1541

# the only supported target so far
TARGET = c64

DISK = breakout.d64

PROGRAMS = breakout.prg

breakout_HEADERS = \
 common.h \
 sprite.h \
 paddle.h

breakout_SOURCES = \
 breakout.c \
 common.c \
 sprite.c \
 paddle.c

breakout_OBJS = $(breakout_SOURCES:.c=.o)
breakout_DEPS = $(breakout_SOURCES:.c=.dep)

all: $(PROGRAMS)
dist: $(DISK)

.c.o:
	$(CC) -t $(TARGET) -c $(CFLAGS) --create-dep $(<:.c=.dep) -o $@ $<

breakout.prg: $(breakout_OBJS)
	$(LD) -t $(TARGET) $(LDFLAGS) -o $@ -m breakout.map $**

$(DISK)::
	$(AR) -format "breakout,00" d64 $@

$(DISK):: breakout.prg
	$(AR) -attach $@ -write breakout.prg breakout,p

# updates deps.mak from .dep files generated during build
deps: $(breakout_DEPS)
	$(CAT) $** > deps.mak

clean:
	$(RM) $(breakout_OBJS) $(breakout_DEPS) $(PROGRAMS) $(DISK) breakout.map

!include deps.mak

.SUFFIXES:
.SUFFIXES: .o .c
.PHONY: all clean dist deps
