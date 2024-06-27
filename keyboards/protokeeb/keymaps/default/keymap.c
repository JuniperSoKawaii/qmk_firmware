/* Protokeeb Copyright 2024 A-Tech Officials (@atechofficials)
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. 
 * If not, see <https://www.gnu.org/licenses/gpl-3.0.html>.
 */

/* Protokeeb v1.0
 * Keymap: Default
 */

#include QMK_KEYBOARD_H

enum protokeeb_keymap_layers {
    LAYER_BASE,
    LAYER_LOWER,
};

#define LOWER LT(LAYER_LOWER, KC_KP_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[LAYER_BASE] = LAYOUT( /* Base */
	KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_SLASH, KC_MUTE,
	KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK,
	KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS,
	LOWER, KC_KP_DOT, KC_KP_ENTER, KC_KP_PLUS
	),

	[LAYER_LOWER] = LAYOUT( /* RGB Control */
	RGB_MODE_PLAIN, RGB_MODE_FORWARD, RGB_MODE_REVERSE, RGB_TOG, KC_MUTE,
	RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,
	RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD,
	KC_TRNS, RGB_MODE_SWIRL, QK_DEBUG_TOGGLE, QK_BOOT
	),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_LOWER] = { ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP) },
};
#endif