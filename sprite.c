#include <c64.h>
#include <string.h>

#include "common.h"
#include "sprite.h"

/* 192nd sprite address from bank 0 = $0300 */
/* it'll probably clobber BASIC state but we'll see */
#define SPRITE_DATA_IDX_BASE 192

static byte* get_sprite_table(void)
{
	return get_screen_memory() + 0x03F8;
}

void sprite_enable(byte spriteid)
{
	BIT_SET(VIC.spr_ena, spriteid);
}

void sprite_disable(byte spriteid)
{
	BIT_CLEAR(VIC.spr_ena, spriteid);
}

void sprite_set(byte spriteid, Sprite data)
{
	byte data_idx = SPRITE_DATA_IDX_BASE + spriteid;

	/* we don't currently preload sprite shapes, but I don't think we'll have
	   more than 8 for a while... */
	/* we copy 1 extra byte but it's harmless; the VIC doesn't use it */
	byte* dest = get_vic_bank_start() + data_idx * SPRITE_SIZE;
	memcpy(dest, data, SPRITE_SIZE);
	
	get_sprite_table()[spriteid] = data_idx;
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
