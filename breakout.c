#include <stdlib.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>

#include "common.h"

#include "paddle.h"

void main(void)
{
  paddle_move(160);
  paddle_show();
}
