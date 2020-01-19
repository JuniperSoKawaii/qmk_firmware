/* Copyright 2019 yohei
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

// Defines the keycodes used by our macros in process_record_user

enum layer_number {
  _BASE = 0,
  _SUSFT,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  KANJI,
  SUSFT,
  LOWER,
  RAISE,
  ADJUST,
};

enum user_macro {
  UM_EMHL,
  UM_KHKR
};
#define M_EMHL MACROTAP(UM_EMHL)      // 「Lower」キー用のキーコード
#define M_KHKR MACROTAP(UM_KHKR)      // 「Raise」キー用のキーコード

// Layer Mode aliases
#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADUJST ADJUST
#define KC_DLBS BASE //DF(_BASE)

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI
#define KC_RST   RESET
#define KC_SUSFT SUSFT
#define KC_ZSFT  LSFT_T(KC_Z)
#define KC_MNSF  LSFT_T(KC_MINS)
#define KC_ESCT  LCTL_T(KC_ESC)
#define KC_TBAL  LALT_T(KC_TAB)
#define KC_ALAL  LALT_T(KC_A)
#define KC_11SF  LSFT_T(KC_F11)
#define KC_ALAP  LALT_T(KC_APP)
#define KC_JEQL  LSFT(KC_MINS)
#define KC_WLCK  LALT(KC_L)
#define KC_SFEQ  LSFT(KC_MINS)
#define KC_SFPL  LSFT(KC_SCLN)
#define KC_SFAS  LSFT(KC_QUOT)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //|----------------------------------.                ,----------------------------------.
      KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                    KC_Y, KC_U, KC_I, KC_O, KC_P, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_A,  KC_S, KC_D,  KC_F, KC_G,                KC_H,  KC_J,  KC_K, KC_L,  KC_BSLS, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_ZSFT, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_MNSF, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_ESCT,KC_TBAL, KC_PSCR, LT(_LOWER, KC_SPC), KC_SPC, KC_SPC, LT(_RAISE, KC_SPC), KC_SLSH, KC_BSLS, KC_RBRC, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      MO(_LOWER), KC_LGUI,               KC_BSPC, KC_ENT,         LALT(KC_GRV), MO(_RAISE) \
  //|------+------+------+------+------|                |------+------+------+------+------|
  ),

  [_LOWER] = LAYOUT(
  //|---------------------------------------------------------------------------------------------------.
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,\
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,  KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10, \
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F11,  KC_F12, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, KC_SCLN, KC_UP,    KC_EQL, \
  //|---------+---------+---------+---------+---------+--------+---------+---------+---------+---------'
      KC_ESCT,KC_TBAL,KC_LGUI, KC_ENT, KC_BSPC, KC_SPC, LG(_SUSFT), KC_LEFT, KC_DOWN, KC_RGHT, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      MO(_LOWER), KC_LGUI,                 KC_SPC, KC_ENT,                KC_KANJI, TG(_SUSFT) \
  //|------+------+------+------+------|                |------+------+------+------+------|
  ),

  [_RAISE] = LAYOUT(
  //|---------------------------------------------------------------------------------------------------.
        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, \
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,  KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10, \
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       XXXXXXX,  XXXXXXX, XXXXXXX,  KANJI,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UP,    KC_RO, \
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
      KC_ESCT,KC_TBAL,KC_LGUI, TG(_SUSFT),KC_BSPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_RGHT, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      TG(_SUSFT), KC_TBAL,                 KC_SPC, KC_ENT,                KC_KANJI, MO(_RAISE) \
  //|------+------+------+------+------|                |------+------+------+------+------|
  ),
  
  [_SUSFT] = LAYOUT(
  //|---------------------------------------------------------------------------------------------------.
      KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                    KC_Y, KC_U, KC_I, KC_O, KC_P, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_A,  KC_S, KC_D,  KC_F, KC_G,                KC_H,  KC_J,  KC_K, KC_L,  KC_BSLS, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_ZSFT, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMM, KC_DOT, KC_MNSF, \
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'
      KC_ESCT,KC_TBAL,KC_LGUI, MO(_LOWER),KC_BSPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_RGHT, \
  //|------+------+------+------+------|                |------+------+------+------+------|
      KC_TRNS, KC_TBAL,                 KC_SPC, KC_ENT,                KC_KANJI, MO(_RAISE) \
  //|------+------+------+------+------|                |------+------+------+------+------|
  ),
};

//bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    switch (keycode) {
//        case QMKBEST:
//            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
//                SEND_STRING("QMK is the best thing ever!");
//            } else {
//                // when keycode QMKBEST is released
//            }
//            break;
//        case QMKURL:
//            if (record->event.pressed) {
                // when keycode QMKURL is pressed
//                SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
//            } else {
                // when keycode QMKURL is released
//            }
//            break;
//   }
//    return true;
//}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case UM_EMHL: // タップで「英数」と「無変換」、ホールドで「Lower」
        return MACRO_TAP_HOLD_LAYER( record, MACRO(T(MHEN), T(LANG2), END), _LOWER );
        case UM_KHKR: // タップで「かな」と「変換」、ホールドで「Raise」
        return MACRO_TAP_HOLD_LAYER( record, MACRO(T(HENK), T(LANG1), END), _RAISE );
        };
        return MACRO_NONE;
}


void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
