/* Copyright 2021 SamuraiKek
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


enum custom_layers {
    _QWERTY,
    _LOWER,
    _UPPER,
    _MOUSE,
    _MEDIA,  
};
#define MD_SPC MT(MOD_LSFT, KC_SPC)
#define MD_ENT MT(MOD_RALT, KC_ENT)
#define LT_SPC LT(_LOWER, KC_SPC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  UPPER,
  MOUSE,
  MEDIA,
  KC_CTB,
  KC_CSTB,
  KC_QUIT,
  KC_CTLW,
  KC_CTLT,
  KC_CST
};
/*
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05,
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15,
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25,
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35,
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46,

    [_UNIVERSAL] = LAYOUT(
    //   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    //   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______
    //   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
      )

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      UPPER,   KC_HOME, MOUSE,   KC_RALT, KC_LCTL, MD_SPC,  KC_LALT,       KC_ENT,  KC_BSPC, LOWER,   KC_DEL,  KC_INS,  KC_END,  MEDIA
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, _______, KC_UP,   KC_LBRC, KC_RBRC, KC_F12,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_PGUP, _______, _______, _______, _______, _______,       _______, _______, _______, _______,  _______, KC_PGDN, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_UPPER] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         KC_NUM,  KC_P7,   KC_P8,   KC_P9,   _______, KC_F12,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______,  _______, _______,                        KC_PPLS, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______,  _______, _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_WH_U, KC_MS_U, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, KC_BTN3,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_WH_D, KC_BTN2, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, KC_BTN1, _______, _______, _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  ),

  [_MEDIA] = LAYOUT(
//   ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_VOLU,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, KC_MPLY, KC_VOLD,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                         _______, KC_MUTE, KC_MPRV, KC_MNXT, _______, _______,
//   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______
//   └────────┴────────┴────────┴────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┴────────┴────────┴────────┘
  )
};

// Automatically sets the numlock on at startup
void led_set_keymap(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    tap_code(KC_NUM_LOCK);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
    case UPPER:
      if(record->event.pressed) {
        layer_on(_UPPER);
      } else {
        layer_off(_UPPER);
      }
      return false;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
    case MEDIA:
      if(record->event.pressed) {
        layer_on(_MEDIA);
      } else {
        layer_off(_MEDIA);
      }
      return false;
    case KC_CTB:
      if(record->event.pressed) {
        tap_code16(C(KC_TAB));
      }
      return false;
    case KC_CSTB:
      if(record->event.pressed) {
        tap_code16(C(S(KC_TAB)));
      }
      return false;
    case KC_QUIT:
      if(record->event.pressed) {
        tap_code16(A(KC_F4));
      }
      return false;
    case KC_CTLW:
        if(record->event.pressed) {
            tap_code16(C(KC_W));
        }
        return false;
    case KC_CTLT:
        if(record->event.pressed) {
            tap_code16(C(KC_T));
        }
        return false;
    case KC_CST:
        if(record->event.pressed) {
            tap_code16(C(S(KC_T)));
        }
        return false;
    case  KC_ENT:
        if(record->event.pressed) {
          if(get_mods() & MOD_BIT(KC_LSFT)){
            tap_code(KC_SPC);
          }
          else {
             tap_code(KC_ENT);
          }
        }
        return false;
  }
  return true;
}
