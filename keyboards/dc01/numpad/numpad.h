/* Copyright 2018 Yiancar
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef NUMPAD_H
#define NUMPAD_H

#include "quantum.h"

#define XXX KC_NO

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT_NUMPAD( \
    K00, K01, K02, K03, \
    K10, K11, K12, K13, \
    K20, K21, K22,      \
    K30, K31, K32,      \
    K40,      K42, K43  \
) \
{ \
    { K00, K01, K02, K03 }, \
    { K10, K11, K12, K13 }, \
    { K20, K21, K22, XXX }, \
    { K30, K31, K32, XXX }, \
    { K40, XXX, K42, K43 }  \
}

#endif
