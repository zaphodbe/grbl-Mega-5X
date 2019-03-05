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
//  GPIO_DDR(COOLANT_FLOOD) |= (1 << GPIO_BIT(COOLANT_FLOOD)); // Configure as output pin.
//  GPIO_DDR(COOLANT_MIST) |= (1 << GPIO_BIT(COOLANT_MIST)); // Configure as output pin.
//  GPIO_DDR(COOLANT_FLOOD) |= GPIO_MASK(COOLANT_FLOOD); // Configure as output pin.
//  GPIO_DDR(COOLANT_MIST) |= GPIO_MASK(COOLANT_MIST); // Configure as output pin.
//  GPIO_DDR(MEGA2560_A0) |= GPIO_MASK(MEGA2560_A0);
//  GPIO_DDR(MEGA2560_A1) |= GPIO_MASK(MEGA2560_A1);
//  GPIO_OUTPUT(SPINDLE_ENABLE);
//  GPIO_INPUT(SPINDLE_DIRECTION);
//  GPIO_PULLUP(SPINDLE_DIRECTION);
//  GPIO_PULLDOWN(SPINDLE_DIRECTION);
//  GPIO_SET(COOLANT_FLOOD);
//  GPIO_CLR(COOLANT_MIST);
//  GPIO_TOGGLE(SPINDLE_DIRECTION);
//  coolant_stop();
  GPIO_OUTPUT(COOLANT_FLOOD);
  GPIO_OUTPUT(ARDUINO_MEGA_D10);
  int a = GPIO_PIN(CONTROL_RESET);
  a = GPIO_PORT(CONTROL_FEED_HOLD);
  GPIO_TOGGLE(GPIO_IDX(STEP,AXIS_1));
  GPIO_TOGGLE(GPIO_IDX(STEP,AXIS_2));
  GPIO_TOGGLE(GPIO_IDX(STEP,AXIS_3));
  GPIO_TOGGLE(GPIO_IDX(STEP,AXIS_4));
//  GPIO_PULLUP(MEGA2560_D40);
}


