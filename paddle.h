#ifndef PADDLE_H_INCLUDED

#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"

#define SPR_PADDLE 0

unsigned paddle_left(void);
unsigned paddle_right(void);

unsigned paddle_pos(void);
void paddle_moveto(unsigned pos);
void paddle_moveby(int dx);

void paddle_show(void);
void paddle_hide(void);


#define PADDLE_H_INCLUDED
#endif
