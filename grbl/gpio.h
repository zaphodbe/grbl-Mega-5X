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
#define _GPIO_CONCAT(a,b)   a##b
#define GPIO_CONCAT(a,b)    _GPIO_CONCAT(a,b)
#define _GPIO_IDX(gpio,idx) gpio##_##idx
#define GPIO_IDX(gpio,idx)  _GPIO_IDX(gpio,idx)
#define _GPIO_BIT(gpio)     (gpio##_BIT)
#define GPIO_BIT(gpio)      _GPIO_BIT(gpio)
#define GPIO_MASK(gpio)     (1 << GPIO_BIT(gpio))
#define _GPIO_PIN(gpio)     GPIO_CONCAT(PIN ,gpio##_PORT)
#define GPIO_PIN(gpio)      _GPIO_PIN(gpio)
#define _GPIO_PORT(gpio)    GPIO_CONCAT(PORT ,gpio##_PORT)
#define GPIO_PORT(gpio)     _GPIO_PORT(gpio)
#define _GPIO_DDR(gpio)     GPIO_CONCAT(DDR ,gpio##_PORT)
#define GPIO_DDR(gpio)      _GPIO_DDR(gpio)
#define GPIO_WR(gpio,val)   GPIO_PORT(gpio) = (GPIO_PORT(gpio) & ~GPIO_MASK(gpio)) | val
#define GPIO_SET(gpio)      GPIO_PORT(gpio) |= GPIO_MASK(gpio)
#define GPIO_CLR(gpio)      GPIO_PORT(gpio) &= ~GPIO_MASK(gpio)
#define GPIO_GET(gpio)      (GPIO_PIN(gpio) & GPIO_MASK(gpio))
#define GPIO_TOGGLE(gpio)   GPIO_PIN(gpio) = GPIO_MASK(gpio)
#define GPIO_OUTPUT(gpio)   GPIO_DDR(gpio) |= GPIO_MASK(gpio)
#define GPIO_INPUT(gpio)    GPIO_DDR(gpio) &= ~GPIO_MASK(gpio)
#define GPIO_PULLUP(gpio)   GPIO_SET(gpio)
#define GPIO_NOPULL(gpio)   GPIO_CLR(gpio)

// AVR port mapping
#define AVR_PA0_PORT    A
#define AVR_PA1_PORT    A
#define AVR_PA2_PORT    A
#define AVR_PA3_PORT    A
#define AVR_PA4_PORT    A
#define AVR_PA5_PORT    A
#define AVR_PA6_PORT    A
#define AVR_PA7_PORT    A

#define AVR_PB0_PORT    B
#define AVR_PB1_PORT    B
#define AVR_PB2_PORT    B
#define AVR_PB3_PORT    B
#define AVR_PB4_PORT    B
#define AVR_PB5_PORT    B
#define AVR_PB6_PORT    B
#define AVR_PB7_PORT    B

#define AVR_PC0_PORT    C
#define AVR_PC1_PORT    C
#define AVR_PC2_PORT    C
#define AVR_PC3_PORT    C
#define AVR_PC4_PORT    C
#define AVR_PC5_PORT    C
#define AVR_PC6_PORT    C
#define AVR_PC7_PORT    C

#define AVR_PD0_PORT    D
#define AVR_PD1_PORT    D
#define AVR_PD2_PORT    D
#define AVR_PD3_PORT    D
#define AVR_PD4_PORT    D
#define AVR_PD5_PORT    D
#define AVR_PD6_PORT    D
#define AVR_PD7_PORT    D

#define AVR_PE0_PORT    E
#define AVR_PE1_PORT    E
#define AVR_PE2_PORT    E
#define AVR_PE3_PORT    E
#define AVR_PE4_PORT    E
#define AVR_PE5_PORT    E
#define AVR_PE6_PORT    E
#define AVR_PE7_PORT    E

#define AVR_PF0_PORT    F
#define AVR_PF1_PORT    F
#define AVR_PF2_PORT    F
#define AVR_PF3_PORT    F
#define AVR_PF4_PORT    F
#define AVR_PF5_PORT    F
#define AVR_PF6_PORT    F
#define AVR_PF7_PORT    F

#define AVR_PG0_PORT    G
#define AVR_PG1_PORT    G
#define AVR_PG2_PORT    G
#define AVR_PG3_PORT    G
#define AVR_PG4_PORT    G
#define AVR_PG5_PORT    G
#define AVR_PG6_PORT    G
#define AVR_PG7_PORT    G

#define AVR_PH0_PORT    H
#define AVR_PH1_PORT    H
#define AVR_PH2_PORT    H
#define AVR_PH3_PORT    H
#define AVR_PH4_PORT    H
#define AVR_PH5_PORT    H
#define AVR_PH6_PORT    H
#define AVR_PH7_PORT    H

#define AVR_PJ0_PORT    J
#define AVR_PJ1_PORT    J
#define AVR_PJ2_PORT    J
#define AVR_PJ3_PORT    J
#define AVR_PJ4_PORT    J
#define AVR_PJ5_PORT    J
#define AVR_PJ6_PORT    J
#define AVR_PJ7_PORT    J

#define AVR_PK0_PORT    K
#define AVR_PK1_PORT    K
#define AVR_PK2_PORT    K
#define AVR_PK3_PORT    K
#define AVR_PK4_PORT    K
#define AVR_PK5_PORT    K
#define AVR_PK6_PORT    K
#define AVR_PK7_PORT    K

#define AVR_PL0_PORT    L
#define AVR_PL1_PORT    L
#define AVR_PL2_PORT    L
#define AVR_PL3_PORT    L
#define AVR_PL4_PORT    L
#define AVR_PL5_PORT    L
#define AVR_PL6_PORT    L
#define AVR_PL7_PORT    L

// AVR bit mappintg
#define AVR_PA0_BIT     0
#define AVR_PA1_BIT     1
#define AVR_PA2_BIT     2
#define AVR_PA3_BIT     3
#define AVR_PA4_BIT     4
#define AVR_PA5_BIT     5
#define AVR_PA6_BIT     6
#define AVR_PA7_BIT     7
                    
#define AVR_PB0_BIT     0
#define AVR_PB1_BIT     1
#define AVR_PB2_BIT     2
#define AVR_PB3_BIT     3
#define AVR_PB4_BIT     4
#define AVR_PB5_BIT     5
#define AVR_PB6_BIT     6
#define AVR_PB7_BIT     7
                    
#define AVR_PC0_BIT     0
#define AVR_PC1_BIT     1
#define AVR_PC2_BIT     2
#define AVR_PC3_BIT     3
#define AVR_PC4_BIT     4
#define AVR_PC5_BIT     5
#define AVR_PC6_BIT     6
#define AVR_PC7_BIT     7
                    
#define AVR_PD0_BIT     0
#define AVR_PD1_BIT     1
#define AVR_PD2_BIT     2
#define AVR_PD3_BIT     3
#define AVR_PD4_BIT     4
#define AVR_PD5_BIT     5
#define AVR_PD6_BIT     6
#define AVR_PD7_BIT     7
                    
#define AVR_PE0_BIT     0
#define AVR_PE1_BIT     1
#define AVR_PE2_BIT     2
#define AVR_PE3_BIT     3
#define AVR_PE4_BIT     4
#define AVR_PE5_BIT     5
#define AVR_PE6_BIT     6
#define AVR_PE7_BIT     7
                    
#define AVR_PF0_BIT     0
#define AVR_PF1_BIT     1
#define AVR_PF2_BIT     2
#define AVR_PF3_BIT     3
#define AVR_PF4_BIT     4
#define AVR_PF5_BIT     5
#define AVR_PF6_BIT     6
#define AVR_PF7_BIT     7
                    
#define AVR_PG0_BIT     0
#define AVR_PG1_BIT     1
#define AVR_PG2_BIT     2
#define AVR_PG3_BIT     3
#define AVR_PG4_BIT     4
#define AVR_PG5_BIT     5
#define AVR_PG6_BIT     6
#define AVR_PG7_BIT     7
                    
#define AVR_PH0_BIT     0
#define AVR_PH1_BIT     1
#define AVR_PH2_BIT     2
#define AVR_PH3_BIT     3
#define AVR_PH4_BIT     4
#define AVR_PH5_BIT     5
#define AVR_PH6_BIT     6
#define AVR_PH7_BIT     7
                    
#define AVR_PJ0_BIT     0
#define AVR_PJ1_BIT     1
#define AVR_PJ2_BIT     2
#define AVR_PJ3_BIT     3
#define AVR_PJ4_BIT     4
#define AVR_PJ5_BIT     5
#define AVR_PJ6_BIT     6
#define AVR_PJ7_BIT     7
                    
#define AVR_PK0_BIT     0
#define AVR_PK1_BIT     1
#define AVR_PK2_BIT     2
#define AVR_PK3_BIT     3
#define AVR_PK4_BIT     4
#define AVR_PK5_BIT     5
#define AVR_PK6_BIT     6
#define AVR_PK7_BIT     7
                    
#define AVR_PL0_BIT     0
#define AVR_PL1_BIT     1
#define AVR_PL2_BIT     2
#define AVR_PL3_BIT     3
#define AVR_PL4_BIT     4
#define AVR_PL5_BIT     5
#define AVR_PL6_BIT     6
#define AVR_PL7_BIT     7

// Arduino MEGA pin definitions
#define ARDUINO_MEGA_A0     AVR_PF0
#define ARDUINO_MEGA_A1     AVR_PF1
#define ARDUINO_MEGA_A2     AVR_PF2
#define ARDUINO_MEGA_A3     AVR_PF3
#define ARDUINO_MEGA_A4     AVR_PF4
#define ARDUINO_MEGA_A5     AVR_PF5
#define ARDUINO_MEGA_A6     AVR_PF6
#define ARDUINO_MEGA_A7     AVR_PF7

#define ARDUINO_MEGA_A8     AVR_PK0
#define ARDUINO_MEGA_A9     AVR_PK1
#define ARDUINO_MEGA_A10    AVR_PK2
#define ARDUINO_MEGA_A11    AVR_PK3
#define ARDUINO_MEGA_A12    AVR_PK4
#define ARDUINO_MEGA_A13    AVR_PK5
#define ARDUINO_MEGA_A14    AVR_PK6
#define ARDUINO_MEGA_A15    AVR_PK7

#define ARDUINO_MEGA_D0     AVR_PE0
#define ARDUINO_MEGA_D1     AVR_PE1
#define ARDUINO_MEGA_D2     AVR_PE4
#define ARDUINO_MEGA_D3     AVR_PE5
#define ARDUINO_MEGA_D4     AVR_PG5
#define ARDUINO_MEGA_D5     AVR_PE3
#define ARDUINO_MEGA_D6     AVR_PH3
#define ARDUINO_MEGA_D7     AVR_PH4

#define ARDUINO_MEGA_D8     AVR_PH5
#define ARDUINO_MEGA_D9     AVR_PH6
#define ARDUINO_MEGA_D10    AVR_PB4
#define ARDUINO_MEGA_D11    AVR_PB5
#define ARDUINO_MEGA_D12    AVR_PB6
#define ARDUINO_MEGA_D13    AVR_PB7
#define ARDUINO_MEGA_D14    AVR_PJ1
#define ARDUINO_MEGA_D15    AVR_PJ0

#define ARDUINO_MEGA_D16    AVR_PH1
#define ARDUINO_MEGA_D17    AVR_PH0
#define ARDUINO_MEGA_D18    AVR_PD3
#define ARDUINO_MEGA_D19    AVR_PD2
#define ARDUINO_MEGA_D20    AVR_PD1
#define ARDUINO_MEGA_D21    AVR_PD0
#define ARDUINO_MEGA_D22    AVR_PA0
#define ARDUINO_MEGA_D23    AVR_PA1

#define ARDUINO_MEGA_D24    AVR_PA2
#define ARDUINO_MEGA_D25    AVR_PA3
#define ARDUINO_MEGA_D26    AVR_PA4
#define ARDUINO_MEGA_D27    AVR_PA5
#define ARDUINO_MEGA_D28    AVR_PA6
#define ARDUINO_MEGA_D29    AVR_PA7
#define ARDUINO_MEGA_D30    AVR_PC7
#define ARDUINO_MEGA_D31    AVR_PC6

#define ARDUINO_MEGA_D32    AVR_PC5
#define ARDUINO_MEGA_D33    AVR_PC4
#define ARDUINO_MEGA_D34    AVR_PC3
#define ARDUINO_MEGA_D35    AVR_PC2
#define ARDUINO_MEGA_D36    AVR_PC1
#define ARDUINO_MEGA_D37    AVR_PC0
#define ARDUINO_MEGA_D38    AVR_PD7
#define ARDUINO_MEGA_D39    AVR_PG2

#define ARDUINO_MEGA_D40    AVR_PG1
#define ARDUINO_MEGA_D41    AVR_PG0
#define ARDUINO_MEGA_D42    AVR_PL7
#define ARDUINO_MEGA_D43    AVR_PL6
#define ARDUINO_MEGA_D44    AVR_PL5
#define ARDUINO_MEGA_D45    AVR_PL4
#define ARDUINO_MEGA_D46    AVR_PL3
#define ARDUINO_MEGA_D47    AVR_PL2

#define ARDUINO_MEGA_D48    AVR_PL1
#define ARDUINO_MEGA_D49    AVR_PL0
#define ARDUINO_MEGA_D50    AVR_PB3
#define ARDUINO_MEGA_D51    AVR_PB2
#define ARDUINO_MEGA_D52    AVR_PB1
#define ARDUINO_MEGA_D53    AVR_PB0

// Initializes gpio pins.
void gpio_init();

void lube_control(uint8_t reason, uint8_t enable);
void break_control(uint8_t enable);
void gpio_set(uint8_t gpio, uint8_t value);
uint8_t gpio_get(uint8_t gpio);
void gpio_sleep();

#endif
