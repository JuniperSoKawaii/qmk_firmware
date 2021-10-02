/* Copyright 2021 @ Grayson Carr
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

// clang-format off

enum led_indexes {
    LED_ESC,            LED_F1,   LED_F2,   LED_F3,   LED_F4,   LED_F5,   LED_F6,   LED_F7,   LED_F8,   LED_F9,   LED_F10,  LED_F11,  LED_F12,  LED_DEL,  LED_INS,
    LED_GRV,  LED_1,    LED_2,    LED_3,    LED_4,    LED_5,    LED_6,    LED_7,    LED_8,    LED_9,    LED_0,    LED_MINS, LED_EQL,  LED_BSPC,           LED_PGUP,
    LED_TAB,  LED_Q,    LED_W,    LED_E,    LED_R,    LED_T,    LED_Y,    LED_U,    LED_I,    LED_O,    LED_P,    LED_LBRC, LED_RBRC, LED_BSLS,           LED_PGDN,
    LED_CAPS, LED_A,    LED_S,    LED_D,    LED_F,    LED_G,    LED_H,    LED_J,    LED_K,    LED_L,    LED_SCLN, LED_QUOT,           LED_ENT,            LED_HOME,
    LED_LSFT,           LED_Z,    LED_X,    LED_C,    LED_V,    LED_B,    LED_N,    LED_M,    LED_COMM, LED_DOT,  LED_SLSH,           LED_RSFT, LED_UP,
    LED_LCTL, LED_LGUI, LED_LALT,                               LED_SPC,                                LED_RALT, LED_FN,   LED_RCTL, LED_LEFT, LED_DOWN, LED_RGHT
};

// clang-format on

void rgb_matrix_set_color_macos_fn(uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_set_color_alphas(uint8_t red, uint8_t green, uint8_t blue);
void rgb_matrix_set_color_leds(const uint8_t led_index[], uint8_t led_count, uint8_t red, uint8_t green, uint8_t blue);
