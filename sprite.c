#include <c64.h>

#include "common.h"
#include "sprite.h"

void sprite_enable(byte spriteid)
{
	BIT_SET(VIC.spr_ena, spriteid);
}

void sprite_disable(byte spriteid)
{
	BIT_CLEAR(VIC.spr_ena, spriteid);
}

unsigned sprite_posx(byte spriteid)
{
	byte low = VIC.spr_pos[spriteid].x;
	byte high = BIT_GET(VIC.spr_hi_x, spriteid);

	return MKINT(high, low);
}

byte sprite_posy(byte spriteid)
{
	return VIC.spr_pos[spriteid].y;
}

void sprite_movex(byte spriteid, unsigned x)
{
	const byte low = (byte) x;
	const byte high = x >> 8;

	VIC.spr_pos[spriteid].x = low;

	if (high)
		BIT_SET(VIC.spr_hi_x, spriteid);
	else
		BIT_CLEAR(VIC.spr_hi_x, spriteid);
}

void sprite_movey(byte spriteid, byte y)
{
	VIC.spr_pos[spriteid].y = y;
}

void sprite_movexy(byte spriteid, unsigned x, byte y)
{
	sprite_movex(spriteid, x);
	sprite_movey(spriteid, y);
}

void sprite_color(byte spriteid, byte color)
{
	VIC.spr_color[spriteid] = color;
}
