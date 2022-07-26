/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  _GAME,
  _DVORAK_NEXT,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  DVORAK_NEXT = SAFE_RANGE,
  GAME,
  G_EXIT,
  PLOVER,
  LOWER,
  RAISE,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LAYOUT_planck_grid_MOD_TAP( \
    k00, k01, k02, k03, k04, k05, k40, k41, k42, k43, k44, k45, \
    k10, k11, k12, k13, k14, k15, k50, k51, k52, k53, k54, k55, \
    k20, k21, k22, k23, k24, k25, k60, k61, k62, k63, k64, k65, \
    k30, k31, k32, k73, k74, k75, k70, k71, k72, k33, k34, k35 \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, LGUI_T(k11), LALT_T(k12), LSFT_T(k13), LCTL_T(k14), k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { k40, k41, k42, k43, k44, k45 }, \
    { k50, RCTL_T(k51), RSFT_T(k52), LALT_T(k53), RGUI_T(k54), k55 }, \
    { k60, k61, k62, k63, k64, k65 }, \
    { k70, k71, k72, k73, k74, k75 } \
}
  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak Next
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | XXXX |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | XXXX |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | Esc  |Lower | Back | Space|Raise | Enter| XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK_NEXT] = LAYOUT_planck_grid_MOD_TAP(
  XXXXXXX, KC_QUOT, KC_COMM, KC_DOT, KC_P,  KC_Y,    KC_F,   KC_G,  KC_C,   KC_R,    KC_L,    XXXXXXX,
  XXXXXXX, KC_A,    KC_O,    KC_E,   KC_U,  KC_I,    KC_D,   KC_H,  KC_T,   KC_N,    KC_S,    XXXXXXX,
  XXXXXXX, KC_SCLN, KC_Q,    KC_J,   KC_K,  KC_X,    KC_B,   KC_M,  KC_W,   KC_V,    KC_Z,    XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC, LOWER, KC_BSPC, KC_SPC, RAISE, KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * |   1  |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |  Up  |   O  |  P   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   2  |  Esc |   A  |   S  |   D  |   F  |   G  |   H  | Left | Down | Right|  ;   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   3  | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   4  | Ctrl |      | Alt  |Lower |    Space    |Raise |      |      |      | Exit |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
 KC_1,  KC_TAB, KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,  KC_U,    KC_UP,   KC_O,     KC_P,
 KC_2,  KC_ESC, KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_SCLN,
 KC_3, KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,  KC_M,    KC_COMM, KC_DOT,   KC_ENT,
 KC_4, KC_LCTL, _______, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, _______, _______, _______,  G_EXIT  
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   _  |  /   | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX |   `  |   ~  |   =  |  (   |   [  |  ]   |   )  |   +  |   -  |  \   | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX |  <   |   {  |  }   |   >  | XXXX | XXXX |  |   | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX |  Del |      |      |      | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
 XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,     KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR, KC_UNDS,  KC_SLSH, XXXXXXX,
 XXXXXXX, KC_GRV,  KC_TILD, KC_EQL,  KC_LPRN,    KC_LBRC, KC_RBRC, KC_RPRN,   KC_PLUS, KC_MINUS, KC_BSLS, XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_COMM), KC_LCBR, KC_RCBR, S(KC_DOT), XXXXXXX, XXXXXXX,  KC_PIPE, XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  _______,    _______, _______, XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX 
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | XXXX |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | XXXX |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | XXXX |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Left | Down |  Up  |Right | XXXX |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | XXXX |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX |    Tab      |      | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
 XXXXXXX, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,   KC_6,   KC_7,       KC_8,    KC_9,    KC_0,     XXXXXXX,
 XXXXXXX, KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,  KC_F6,  KC_LEFT,    KC_DOWN, KC_UP  , KC_RIGHT, XXXXXXX,
 XXXXXXX, KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_F12, S(KC_SLSH), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
 XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL, XXXXXXX, KC_TAB, KC_TAB, _______,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX 
),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = LAYOUT_planck_grid(
 KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,
 XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
 XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
 EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX 
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |  M^  |      |      |      |  M1  |  M2  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  M<  |  Mv  |  M>  |AGnorm|AGswap|      | Game |Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
 _______, RESET,   _______,    KC_MS_UP,   _______,     _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,
 _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, AG_NORM, AG_SWAP, _______, GAME,    DVORAK_NEXT,  PLOVER,  _______,
 _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, _______, _______, _______,
 _______, _______, _______,    _______,    _______,     _______, _______, _______, _______, _______, _______, _______ 
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
    case G_EXIT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK_NEXT);
      }
      return false;
      break;
    case DVORAK_NEXT:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK_NEXT);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
