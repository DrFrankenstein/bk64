breakout.o:	breakout.c common.h util.h paddle.h ball.h

breakout.c common.h util.h paddle.h ball.h:

common.o:	common.c common.h

common.c common.h:

util.o:	util.c util.h

util.c util.h:

sprite.o:	sprite.c common.h util.h sprite.h

sprite.c common.h util.h sprite.h:

paddle.o:	paddle.c util.h paddle.h sprite.h common.h resources.h

paddle.c util.h paddle.h sprite.h common.h resources.h:

ball.o:	ball.c ball.h sprite.h common.h

ball.c ball.h sprite.h common.h:

resources.o:	resources.s

resources.s:

