#ifndef SPRITE_H_INCLUDED

#define SPRITE_SIZE (64)	/* 21 lines of 24 pixels (3 bytes) each = 63 bytes, + 1 padding byte */
typedef byte Sprite[SPRITE_SIZE];

void sprite_enable(byte spriteid);
void sprite_disable(byte spriteid);

void sprite_set(byte spriteid, Sprite data);

unsigned sprite_posx(byte spriteid);
byte sprite_posy(byte spriteid);
void sprite_movex(byte spriteid, unsigned x);
void sprite_movey(byte spriteid, byte y);
void sprite_movexy(byte spriteid, unsigned x, byte y);

void sprite_color(byte spriteid, byte color);

#define SPRITE_H_INCLUDED
#endif
