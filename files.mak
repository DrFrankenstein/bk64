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
