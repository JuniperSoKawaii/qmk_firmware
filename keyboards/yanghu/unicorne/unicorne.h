/* Copyright 2020 Yang Hu
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

#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// clang-format off
#define LAYOUT_unicorne( \
    K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,      K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,      K26, K27, K28, K29, K2A, K2B, \
                K30, K31, K32, K33,  K34, K35, K36, K37 \
) \
{ \
    { K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K0A, K0B }, \
    { K10, K11, K12, K13, K14, K15,      K16, K17, K18, K19, K1A, K1B }, \
    { K20, K21, K22, K23, K24, K25,      K26, K27, K28, K29, K2A, K2B }, \
    { KC_NO, KC_NO, K30, K31, K32, K33,  K34, K35, K36, K37, KC_NO, KC_NO} \
}

#define LAYOUT_kc( \
    K00, K01, K02, K03, K04, K05,      K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15,      K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25,      K26, K27, K28, K29, K2A, K2B, \
                K30, K31, K32, K33,  K34, K35, K36, K37 \
) \
LAYOUT_unicorne( \
    KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05,      KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, \
    KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15,      KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, \
    KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25,      KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, \
           KC_##K30, KC_##K31, KC_##K32, KC_##K33,  KC_##K34, KC_##K35, KC_##K36, KC_##K37 \
)
// clang-format on

#define LAYOUT LAYOUT_unicorne
