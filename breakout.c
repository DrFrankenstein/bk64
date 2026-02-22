#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <peekpoke.h>
#include <string.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"

#include "paddle.h"

void main(void)
{
  clrscr();
  printf("\nHello World!\n");
  paddle_move(160);
  paddle_show();
  getchar();
}
