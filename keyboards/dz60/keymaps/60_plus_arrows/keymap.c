#include QMK_KEYBOARD_H

#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | ` ~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |   Bkspc   |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * | Caps    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh |  U  | FN  |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Alt  |  Cmd  |              Space                | Cmd | RAlt |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT,         KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(1),
      KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
      ),

/* FN Layer
 * ,-----------------------------------------------------------------------------------------.
 * | Esc | BL- | BL+ | BL  |     |     |     |RESET|     |     |     |     |     |           |
 * |-----------------------------------------------------------------------------------------+
 * |        |RBGM |     |     |     |     |     |     |     |     |     | Val+ | Val- |RBGTOG|
 * |-----------------------------------------------------------------------------------------+
 * |         | Hue+| Hue-| Sat+| Sat-|     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |     | Ctrl|     |
 * |-----------------------------------------------------------------------------------------+
 * |      |       |       |                                   |     |      |     |     |     |
 * `-----------------------------------------------------------------------------------------'
 */

  LAYOUT_directional(
      KC_ESC, BL_TOGG, BL_STEP, BL_DEC, BL_INC, ______, ______, RESET, ______, ______, ______, ______, ______, ______, ______,
      ______, RGB_MOD, ______, ______, ______, ______, ______, ______, ______, ______, ______, RGB_VAI, RGB_VAD, RGB_TOG,
      ______, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, ______, ______, ______, ______, ______, ______, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_RCTL, ______,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______
      ),
};
