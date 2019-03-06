/*
  gpio.c - additional gpio controls
  Part of Grbl

  Copyright (c) 2019 Chris Coley

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "grbl.h"

void gpio_init()
{
  GPIO_OUTPUT(LUBRICATION);
  GPIO_OUTPUT(SPINDLE_BREAK);
}

void lube_control(uint8_t reason, uint8_t enable)
{
    static uint8_t state = 0;

    if (reason == 0) break_control(enable);

    if (enable) {
        state |= (1 << reason);
    } else {
        state &= ~(1 << reason);
    }

    if (state) {
        GPIO_SET(LUBRICATION);
    } else {
        GPIO_CLR(LUBRICATION);
    }
}

void break_control(uint8_t enable)
{
    if (enable) {
        GPIO_SET(SPINDLE_BREAK);
    } else {
        GPIO_CLR(SPINDLE_BREAK);
    }
}
