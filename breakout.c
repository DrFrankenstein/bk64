#include <stdlib.h>
#include <c64.h>
#include <cbm_petscii_charmap.h>
#include <joystick.h>

#include "common.h"

#include "paddle.h"

int main(void)
{
  /* go back to PETSCII graphics characters;
     crt0 sets us to lowercase but we don't want that */
  BIT_CLEAR(VIC.addr, 1);

  joy_install(joy_static_stddrv);
  paddle_moveto(160);
  paddle_show();

  while (true)
  {
    byte joystatus = joy_read(0);
    if (JOY_LEFT(joystatus))
      paddle_moveby(-1);
    else if (JOY_RIGHT(joystatus))
      paddle_moveby(1);
    else if (JOY_BTN_1(joystatus))
      break;  /* for now */

    waitvsync();
  }

  return EXIT_SUCCESS;
}
