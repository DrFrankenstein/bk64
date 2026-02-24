#ifndef UTIL_H_INCLUDED

#define BIT_GET(src, bit) ((src) >> (bit) & 1)
#define BIT_SET(dest, bit) ((dest) |= 1 << (bit))
#define BIT_CLEAR(dest, bit) ((dest) &= ~(1 << (bit)))
#define MKINT(high, low) ((unsigned)(high) << 8 | (low))

int clamp(int n, int min, int max);

#define UTIL_H_INCLUDED
#endif
