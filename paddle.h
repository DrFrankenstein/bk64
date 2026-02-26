#ifndef PADDLE_H_INCLUDED

#include <c64.h>

#define SPR_ID_PADDLE 0

int paddle_left(void);
int paddle_right(void);

int paddle_pos(void);
void paddle_moveto(int pos);
void paddle_moveby(int dx);

void paddle_show(void);
void paddle_hide(void);


#define PADDLE_H_INCLUDED
#endif
