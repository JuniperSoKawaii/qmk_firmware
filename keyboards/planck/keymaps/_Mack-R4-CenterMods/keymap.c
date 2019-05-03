/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | Tab  | Bksp |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | Esc  |  "   |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | Shift|Enter |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Menu |  Gui |  Alt |Lower |    Space    |Raise | Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_TAB,              KC_BSPC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P},
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_ESC,              KC_QUOT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN},
  {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_LSFT, MT(MOD_RSFT, KC_ENT),    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH},
  {KC_LCTL, KC_APP, KC_LGUI, KC_LALT, LOWER,   KC_SPC,               KC_SPC,   RAISE, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |   ~  |  Del |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | DTL  | DTR  |      |      | PgUp |      |   |  | Home |   _  |   +  |   {  |   }  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | PgDn |      |      |  End |      |   ,  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {             KC_EXLM,              KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_TILD,  KC_DEL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), _______, _______, KC_PGUP, _______, KC_PIPE, KC_HOME, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR},
  {             _______,            _______, _______, _______, KC_PGDN, _______, _______,  KC_END, _______, KC_COMM,  KC_DOT, _______},
  {             _______,            _______, _______, _______,          _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   '  | Bksp |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |   \  |  F6  |   -  |   =  |   [  |   ]  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |      |      |  F12 |      |   ,  |   .  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Left | Down |  Up  | Rght |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  KC_GRV, KC_BSPC,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0},
  {   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  ______, KC_BSLS,  KC_F6, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC},
  {   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  ______, _______, KC_F12, _______, KC_COMM,  KC_DOT, _______},
  { _______, _______, _______, _______, _______, _______,         _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset|      |      |      |      |      |  Del |      |      |      |      | PScr |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | MUTE | VDWN | VUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | PREV | PLAY | NEXT |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {  RESET, _______, _______, _______, _______, _______,  KC_DEL, _______, _______,  _______, _______, KC_PSCR},
  {_______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,  KC_MUTE, KC_VOLD, KC_VOLU, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,  KC_MPRV, KC_MPLY, KC_MNXT, _______}
}


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


