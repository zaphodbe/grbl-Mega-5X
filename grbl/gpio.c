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
  GPIO_OUTPUT(RELAY_RSVD3);
  GPIO_OUTPUT(COMPRESSOR);
  GPIO_OUTPUT(VACUUM);
  GPIO_OUTPUT(SPINDLE_READY);
  GPIO_OUTPUT(SPINDLE_BREAK);

  GPIO_SET(COMPRESSOR);
  GPIO_SET(VACUUM);
}

void lube_control(uint8_t reason, uint8_t enable)
{
    static uint8_t state = 0;

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
    #ifdef INVERT_SPINDLE_BREAK_PIN
      enable = !enable;
    #endif
    if (enable) {
        GPIO_SET(SPINDLE_BREAK);
    } else {
        GPIO_CLR(SPINDLE_BREAK);
    }
}

void gpio_set(uint8_t gpio,uint8_t value)
{
    switch (gpio) {
    case 17:
        if (value) {
            GPIO_SET(ARDUINO_MEGA_D17);
        } else {
            GPIO_CLR(ARDUINO_MEGA_D17);
        }
        break;
    case 18:
        if (value) {
            GPIO_SET(ARDUINO_MEGA_D18);
        } else {
            GPIO_CLR(ARDUINO_MEGA_D18);
        }
        break;
    case 19:
        if (value) {
            GPIO_SET(ARDUINO_MEGA_D19);
        } else {
            GPIO_CLR(ARDUINO_MEGA_D19);
        }
        break;
    }
}

uint8_t gpio_get(uint8_t gpio)
{
    uint8_t value = 0;
    switch (gpio) {
    case 17:
        value = GPIO_GET(ARDUINO_MEGA_D17);
        break;
    case 18:
        value = GPIO_GET(ARDUINO_MEGA_D18);
        break;
    case 19:
        value = GPIO_GET(ARDUINO_MEGA_D19);
        break;
    }
    return value;
}

void gpio_sleep()
{
    GPIO_CLR(COMPRESSOR);
    GPIO_CLR(VACUUM);
}
