/* Copyright 2018 wanleg
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
#include QMK_KEYBOARD_H
#include "wanleg.h"


#define LAYOUT_kbd6x_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
	 KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, FUNCTION, \
     KC_TAB, 			K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, _______, _______, _______, \
     TD(TD_SFT_CAPS), 	K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, KC_QUOT, KC_ENT, \
     KC_LSFT, 			K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, KC_LSFT, _______, \
     KC_LCTL, KC_LGUI, KC_LALT,				KC_SPC,			KC_RALT, KC_RGUI, KC_RCTL \
  )
#define LAYOUT_kbd6x_base_wrapper(...)       LAYOUT_kbd6x_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[gGK] = LAYOUT_kbd6x_base_wrapper(
  _______________Gherkin_Row_0_______________,
  _______________Gherkin_Row_1_______________,
  _______________Gherkin_Row_2_______________
),

[gNUM] = LAYOUT_kbd6x_base_wrapper(
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_NUM_1_______________,
  _______________Gherkin_NUM_2_______________
),

[gDIR] = LAYOUT_kbd6x_base_wrapper(
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________
),

[gETC] = LAYOUT_kbd6x_base_wrapper(
  _______________Gherkin_ETC_0_______________,
  _______________Gherkin_ETC_1_______________,
  _______________Gherkin_ETC_2_______________
),

[_FN] = LAYOUT_kbd6x_base_wrapper(
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______, _______
      ),
	  
};