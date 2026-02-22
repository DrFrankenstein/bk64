#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"
#include "paddle.h"
#include "sprite.h"

unsigned paddle_left(void)
{
  return sprite_posx(SPR_PADDLE);
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
  sprite_movex(SPR_PADDLE, pos - 12);
}

void paddle_show(void)
{
  sprite_color(SPR_PADDLE, COLOR_WHITE);
  sprite_movey(SPR_PADDLE, 230);
  sprite_enable(SPR_PADDLE);
}

void paddle_hide(void)
{
  sprite_disable(SPR_PADDLE);
}
