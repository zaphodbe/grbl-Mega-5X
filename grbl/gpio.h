/*
  gpio.h - additional gpio controls
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

#ifndef gpio_h
#define gpio_h

// Macros to simplify port definitions in cpu_map.h etc...
#define _GPIO_CONCAT(a,b) a##b
#define GPIO_CONCAT(a,b)  _GPIO_CONCAT(a,b)
#define GPIO_BIT(gpio)    gpio##_BIT
#define GPIO_MASK(gpio)   (1 << gpio##_BIT)
#define GPIO_PORT(gpio)   GPIO_CONCAT(PORT,gpio##_PORT)
#define GPIO_DDR(gpio)    GPIO_CONCAT(DDR,gpio##_PORT)
#define GPIO_SET(gpio)    GPIO_PORT(gpio) |= GPIO_MASK(gpio)
#define GPIO_CLR(gpio)    GPIO_PORT(gpio) &= ~GPIO_MASK(gpio)
#define GPIO_TOGGLE(gpio) GPIO_PORT(gpio) ^= GPIO_MASK(gpio)
#define GPIO_OUTPUT(gpio) GPIO_DDR(gpio) |= GPIO_MASK(gpio)
#define GPIO_INPUT(gpio)  GPIO_DDR(gpio) &= ~GPIO_MASK(gpio)

// Macros to make old GRBL pin definitions work with GPIO macros and functions
#define DDRPORTA    DDRA
#define DDRPORTB    DDRB
#define DDRPORTC    DDRC
#define DDRPORTD    DDRD
#define DDRPORTE    DDRE
#define DDRPORTF    DDRF
#define DDRPORTG    DDRG
#define DDRPORTH    DDRH
#define DDRPORTI    DDRI
#define DDRPORTJ    DDRJ
#define DDRPORTK    DDRK
#define DDRPORTL    DDRL
#define PORTPORTA   PORTA
#define PORTPORTB   PORTB
#define PORTPORTC   PORTC
#define PORTPORTD   PORTD
#define PORTPORTE   PORTE
#define PORTPORTF   PORTF
#define PORTPORTG   PORTG
#define PORTPORTH   PORTH
#define PORTPORTI   PORTI
#define PORTPORTJ   PORTJ
#define PORTPORTK   PORTK
#define PORTPORTL   PORTL

// Arduino MEGA Pin definitions
#define A0_BIT  (0)
#define A0_PORT F
#define A1_BIT  (1)
#define A1_PORT F
#define A2_BIT  (2)
#define A2_PORT F
#define A3_BIT  (3)
#define A3_PORT F
#define A4_BIT  (4)
#define A4_PORT F
#define A5_BIT  (5)
#define A5_PORT F
#define A6_BIT  (6)
#define A6_PORT F
#define A7_BIT  (7)
#define A7_PORT F
#define A8_BIT  (0)
#define A8_PORT K
#define A9_BIT  (1)
#define A9_PORT K
#define A10_BIT  (2)
#define A10_PORT K
#define A11_BIT  (3)
#define A11_PORT K
#define A12_BIT  (4)
#define A12_PORT K
#define A13_BIT  (5)
#define A13_PORT K
#define A14_BIT  (6)
#define A14_PORT K
#define A15_BIT  (7)
#define A15_PORT K

// Initializes gpio pins.
void gpio_init();

#endif
