/*
Copyright 2018 Jeff Shufelt <jshuf@puppyfish.com> @jshuf

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KBD19X_H
#define KBD19X_H

#include "quantum.h"
#include "led.h"

inline void kbd19x_caps_led_on(void)    { DDRB |=  (1<<0); PORTB &= ~(1<<0); }
inline void kbd19x_caps_led_off(void)   { DDRB &= ~(1<<0); PORTB &= ~(1<<0); }

inline void kbd19x_sclk_led_on(void)    { DDRB |=  (1<<1); PORTB &= ~(1<<1); }
inline void kbd19x_sclk_led_off(void)   { DDRB &= ~(1<<1); PORTB &= ~(1<<1); }

inline void kbd19x_nmlk_led_on(void)    { DDRB |=  (1<<2); PORTB &= ~(1<<2); }
inline void kbd19x_nmlk_led_off(void)   { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }

// readability
#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT( \
  k00,  k01, k02, k03, k04,  k05, k06, k07, k08,  k09, k0a, k0b, k0c,   k0e,  k0f, k0g, k0h, k0i, \
  k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e,  k1f, k1g, k1h, k1i, \
  k20,  k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c,     k2e,  k2f, k2g, k2h, k2i, \
  k30,    k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c,        k3e,  k3f, k3g, k3h, k3i, \
  k40,  k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c,    k4e,   k4f, k4g, k4h, k4i, \
  k50,  k51, k52,                k56,            k59, k5a, k5b,   k5d, k5e, k5f,   k5g, k5h, k5i  \
)\
{\
  {k00, k01, k02, k03, k04, k09, k0a, k0b, k0c, k0f, k0g, k0h, k0i},\
  {k10, k11, k12, k13, k14, k19, k1a, k1b, k1c, k1f, k1g, k1h, k1i},\
  {k20, k21, k22, k23, k24, k29, k2a, k2b, k2c, k2f, k2g, k2h, k2i},\
  {k30, k32, k33, k34, k35, k3a, k3b, k3c, k3e, k3f, k3g, k3h, k3i},\
  {k40, k41, k42, k43, k44, k49, k4a, k4b, k4c, k4f, k4g, k4h, k4i},\
  {k50, k51, k52, k5e, k5f, k59, k5a, k5b, k5d, k56, k5g, k5h, k5i},\
  {k05, k06, k07, k08, k15, k16, k17, k18, k25, k26, k27, k28, k36},\
  {k1d, k1e, k0e, k2e, k4e, k37, k38, k39, k45, k46, k47, k48, XXX},\
}
#endif
