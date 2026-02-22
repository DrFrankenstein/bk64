#ifndef RESOURCES_H_INCLUDED

#include "common.h"

#define SPRITE_SIZE (3 * 21)	/* 21 lines of 24 pixels (3 bytes) each */
typedef byte Sprite[SPRITE_SIZE];

extern Sprite spr_paddle;

#define RESOURCES_H_INCLUDED
#endif
