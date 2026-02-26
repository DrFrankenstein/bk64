#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "util.h"
#include "paddle.h"
#include "sprite.h"
#include "resources.h"

#define PADDLE_WIDTH 24
#define PADDLE_CENTER_OFF (PADDLE_WIDTH / 2)
#define PADDLE_HEIGHT 5

#define PADDLE_Y 230

int paddle_left(void)
{
  return paddle_right() - PADDLE_WIDTH;
}

int paddle_right(void)
{
  return sprite_posx(SPR_ID_PADDLE);
}

int paddle_pos(void)
{
  return paddle_right() - PADDLE_CENTER_OFF;
}

static void paddle_moveabs(int pos)
{
  sprite_movex(SPR_ID_PADDLE, pos);
}

void paddle_moveto(int pos)
{
  paddle_moveabs(pos + PADDLE_CENTER_OFF);
}

void paddle_moveby(int dx)
{
  int pos = paddle_right();
  int newpos = clamp(pos + dx, 0 + PADDLE_WIDTH, 320);

  paddle_moveabs(newpos);
}

void paddle_show(void)
{
  sprite_set(SPR_ID_PADDLE, spr_paddle);
  sprite_color(SPR_ID_PADDLE, COLOR_WHITE);
  sprite_movey(SPR_ID_PADDLE, PADDLE_Y);
  sprite_enable(SPR_ID_PADDLE);
}

void paddle_hide(void)
{
  sprite_disable(SPR_ID_PADDLE);
}
