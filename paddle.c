#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"
#include "paddle.h"
#include "sprite.h"
#include "resources.h"

#define PADDLE_WIDTH 24
#define PADDLE_CENTER_OFF PADDLE_WIDTH / 24
#define PADDLE_HEIGHT 5

#define PADDLE_Y 230

unsigned paddle_left(void)
{
  return sprite_posx(SPR_PADDLE);
}

unsigned paddle_right(void)
{
  return paddle_left() + PADDLE_WIDTH;
}

unsigned paddle_pos(void)
{
  return paddle_left() + PADDLE_CENTER_OFF;
}

void paddle_move(unsigned pos)
{
  sprite_movex(SPR_PADDLE, pos - PADDLE_CENTER_OFF);
}

void paddle_show(void)
{
  sprite_set(SPR_PADDLE, spr_paddle);
  sprite_color(SPR_PADDLE, COLOR_WHITE);
  sprite_movey(SPR_PADDLE, PADDLE_Y);
  sprite_enable(SPR_PADDLE);
}

void paddle_hide(void)
{
  sprite_disable(SPR_PADDLE);
}
