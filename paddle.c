#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"
#include "paddle.h"

unsigned paddle_left(void)
{
  byte low = VIC.spr_pos[SPR_PADDLE].x;
  byte high = VIC.spr_hi_x >> SPR_PADDLE & 1;
  
  return (unsigned)(high << 8) & low;
}

unsigned paddle_right(void)
{
  return paddle_left() + 24;
}

unsigned paddle_pos(void)
{
  return paddle_left() + 12;
}

void paddle_move(unsigned pos)
{
  byte high;
  
  pos -= 12;

  VIC.spr_pos[SPR_PADDLE].x = (byte) pos;
  high = pos >> 8;
  
  if (high)
    VIC.spr_hi_x |= 1 << SPR_PADDLE;
  else
    VIC.spr_hi_x &= ~(1 << SPR_PADDLE);
}

void paddle_show(void)
{
  VIC.spr_color[SPR_PADDLE] = 1;
  VIC.spr_pos[SPR_PADDLE].y = 200;
  VIC.spr_ena |= 1 << SPR_PADDLE;
}

void paddle_hide(void)
{
  VIC.spr_ena &= ~(1 << SPR_PADDLE);
}
