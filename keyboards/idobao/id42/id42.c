/* Copyright 2021 TW59420 <https://github.com/TW59420>
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

#include "id42.h"

#define __ NO_LED

#ifdef RGB_MATRIX_ENABLE

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │41 │40 │39 │38 │37 │36 │35 │34 │33 │32 │31 │30 │
 * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
 * │ 29 │28 │27 │26 │25 │24 │23 │22 │21 │20 │  19  │
 * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──┬┴──┬───┤
 * │ 18  │17 │16 │15 │14 │13 │12 │11 │ 10  │ 9 │ 8 │
 * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴───┼─┬───┼───┼───┤
 * │ 7  │ 6 │ 5  │    4    │    3    │ │ 2 │ 1 │ 0 │
 * └────┴───┴────┴─────────┴─────────┘ └───┴───┴───┘
 */
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    // WS2812 LED strings are addressed from 0 (1st) to DRIVER_LED_TOTAL-1 (last)
    { 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30 },
    { 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, __, 19 },
    { 18, 17, 16, 15, 14, 13, 12, 11, 10, __, 9,  8  },
    { 7,  6,  5,  4,  __, __, 3,  __, __, 2,  1,  0  }
}, {
    // LED Index to Physical Position
    // **NB**: Reversed order
    // Generated from: https://xelus.netlify.app/guides/KLE_to_RGB_parser
    {224,64 }, {204,64 }, {183,64 },                       {135,64 },                       { 84,64 }, { 48,64 }, { 25,64 }, {  3,64 },
    {224,43 }, {204,43 },            {181,43 }, {158,43 }, {137,43 }, {117,43 }, { 97,43 }, { 76,43 }, { 56,43 }, { 36,43 }, {  8,43 },
    {216,21 },            {188,21 }, {168,21 }, {148,21 }, {127,21 }, {107,21 }, { 87,21 }, { 66,21 }, { 46,21 }, { 25,21 }, {  3,21 },
    {224,0  }, {204,0  }, {183,0  }, {163,0  }, {143,0  }, {122,0  }, {102,0  }, { 81,0  }, { 61,0  }, { 41,0  }, { 20,0  }, {  0,0  }
}, {
    // LED Index to Flag
    // **NB**: Reversed order
    4, 4, 4,       1,       4, 4, 4, 4,
    4, 4,    4, 1, 1, 1, 1, 1, 1, 1, 4,
    4,    1, 1, 1, 1, 1, 1, 1, 1, 1, 4,
    4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4
} };

#endif
