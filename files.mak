DISK = breakout.d64

PROGRAMS = breakout.prg

breakout_HEADERS = \
 common.h \
 sprite.h \
 paddle.h \
 resources.h

breakout_SOURCES = \
 breakout.c \
 common.c \
 sprite.c \
 paddle.c

breakout_ASM = \
 resources.s

breakout_LSTS = $(breakout_SOURCES:.c=.lst)
breakout_OBJS = $(breakout_SOURCES:.c=.o) $(breakout_ASM:.s=.o)
breakout_DEPS = $(breakout_SOURCES:.c=.dep) $(breakout_ASM:.s=.dep)

ARTIFACTS = \
 $(breakout_OBJS) \
 $(breakout_DEPS) \
 $(breakout_LSTS) \
 $(PROGRAMS) \
 $(DISK) \
 breakout.map
