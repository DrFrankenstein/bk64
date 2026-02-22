#ifndef SPRITE_H_INCLUDED

void sprite_enable(byte spriteid);
void sprite_disable(byte spriteid);

unsigned sprite_posx(byte spriteid);
byte sprite_posy(byte spriteid);
void sprite_movex(byte spriteid, unsigned x);
void sprite_movey(byte spriteid, byte y);
void sprite_movexy(byte spriteid, unsigned x, byte y);

void sprite_color(byte spriteid, byte color);

#define SPRITE_H_INCLUDED
#endif
