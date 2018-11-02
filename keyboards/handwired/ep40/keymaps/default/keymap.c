/* Copyright 2018 Elliot Powell
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

static bool bsdel_mods = false;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  M_BSDEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC_GESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, M_BSDEL,\
    KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,       KC_ENT, \
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_RSFT,\
    LCTL_T(KC_LBRC), KC_LGUI, KC_LALT,  KC_SPC,  LT(1, KC_SPC), KC_RALT, MO(2), RCTL_T(KC_RBRC),  KC_F5 \
  ),

  [1] = LAYOUT( /* Base */
    KC_TRNS,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0,     KC_TRNS,\
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,         KC_TRNS,\
    KC_TRNS,           KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, KC_TRNS,\
    KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS \
  ),

  [2] = LAYOUT( /* Base */
    KC_F1  ,  KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,\
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SCLN, KC_QUOT, KC_NUHS,          KC_TRNS,\
    KC_TRNS,           KC_NUBS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS, KC_TRNS,\
    KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, RESET \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case M_BSDEL: {
        uint8_t kc = KC_BSPC;

        if (record->event.pressed) {
            if (keyboard_report->mods) {
                kc = KC_DEL;
            }
            register_code (kc);
            bsdel_mods = keyboard_report->mods;
        }
        else {
            if (bsdel_mods) {
                kc = KC_DEL;
            }
            unregister_code (kc);
        }

        return false;
        break;
    }
  }
  return true;
}
