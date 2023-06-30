 /* Copyright 2023 deddia permana (@depermana12)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────────┐                   ┌─────────┐
     * │  mute   │                   │  MO(1)  │
     * ├─────────┼─────────┬─────────┼─────────┤
     * │    1    │    2    │    3    │    4    │
     * ├─────────┼─────────┼─────────┼─────────┤
     * │    5    │    6    │    7    │    8    │
     * └─────────┴─────────┴─────────┴─────────┘
     */
    [0] = LAYOUT(
        KC_MUTE,          MO(1),
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8
        ),
    [1] = LAYOUT(
        QK_BOOT,                MO(1),
        KC_1,   KC_2,  KC_3,     KC_4,
        TO(0), TO(2), TO(3), RGB_TOG
        ),
    [2] = LAYOUT(
        _______,                   _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
        ),
    [3] = LAYOUT(
        _______,                   _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______
        )
        };

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [1] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP),   ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [2] = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),   ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [3] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)},
};
bool oled_task_user(void) {
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("0"), false);
            break;
        case 1:
            oled_write_P(PSTR("1"), false);
            break;
        case 2:
            oled_write_P(PSTR("2"), false);
            break;
        case 3:
            oled_write_P(PSTR("3"), false);
            break;
    }

    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(0, 1);
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_set_cursor(0, 2);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_set_cursor(0, 3);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
