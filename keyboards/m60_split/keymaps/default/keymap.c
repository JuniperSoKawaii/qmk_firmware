/*
Copyright 2021 Alin M Elena <alinm.elena@gmail.com>

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



#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap

enum layer_names { _QW = 0, _LWR, _RSE, _ADJ };

#define LOWER  TT(_LWR)
#define RAISE  TT(_RSE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LGUI, KC_LALT, KC_APP,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LWR] = LAYOUT_ortho_5x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RSE] = LAYOUT_ortho_5x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJ] =  LAYOUT_ortho_5x12(
    _______, RESET,   _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD,RGB_M_G, RESET,   _______,
    _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
// clang-format on

// let us assume we start with both layers off
bool toggle_lwr = false;
bool toggle_rse = false;

static inline void led_lwr(const bool on) {
#ifdef LED_NUM_LOCK_PIN
    writePin(LED_NUM_LOCK_PIN, on);
#endif
}

static inline void led_rse(const bool on) {
#ifdef LED_SCROLL_LOCK_PIN
    writePin(LED_SCROLL_LOCK_PIN, on);
#endif
}

static inline void led_caps(const bool on) {
#ifdef LED_CAPS_LOCK_PIN
    writePin(LED_CAPS_LOCK_PIN, !on);
#endif
}

bool led_update_user(led_t led_state) {
    // Disable the default LED update code, so that lock LEDs could be reused to show layer status.
    return false;
}

void matrix_scan_user(void) {
    led_lwr(toggle_lwr);
    led_rse(toggle_rse);
    led_t led_state = host_keyboard_led_state();
    led_caps(led_state.caps_lock);
    if (layer_state_is(_ADJ)) {
        led_lwr(true);
        led_rse(true);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case (TT(_LWR)):
            if (!record->event.pressed && record->tap.count == TAPPING_TOGGLE) {
                // This runs before the TT() handler toggles the layer state, so the current layer state is the opposite of the final one after toggle.
                toggle_lwr = !layer_state_is(_LWR);
            }
            return true;
            break;
        case (TT(_RSE)):
            if (record->event.pressed && record->tap.count == TAPPING_TOGGLE) {
                toggle_rse = !layer_state_is(_RSE);
            }
            return true;
            break;
        default:
            return true;
    }
}

#ifdef ENCODER_ENABLE

#define MEDIA_KEY_DELAY 10

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint16_t held_keycode_timer = timer_read();

    if (index == 0) { /* First encoder */
        if (clockwise) {
            register_code(KC_VOLD);
            while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
                // no-op
            }
            unregister_code(KC_VOLD);
        } else {
            register_code(KC_VOLU);
            while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) {
                // no-op
            }
            unregister_code(KC_VOLU);
        }
    }
    return true;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LWR, _RSE, _ADJ); }


