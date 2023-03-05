/*
Copyright 2021 @kuriatsu

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

#pragma once
#define MASTER_RIGHT

#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }

#define RGB_DI_PIN D2
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 12
#    define RGBLIGHT_SPLIT
#    define RGBLED_SPLIT {6, 6}
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 1
#    define RGBLIGHT_VAL_STEP 1
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif

#define ENCODERS_PAD_A { }
#define ENCODERS_PAD_B { }
#define ENCODER_RESOLUTIONS { }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTIONS_RIGHT { 4 }

#define SPLIT_WPM_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
