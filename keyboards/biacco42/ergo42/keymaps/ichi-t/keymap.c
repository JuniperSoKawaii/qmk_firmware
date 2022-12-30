#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _CMOVE 3
#define _WIN 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  | PGUP |   | PGDN |   Y  |   U  |   I  |   O  |   P  | BSPC |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |  <-  |   |  ->  |   H  |   J  |   K  |   L  |   ;  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  | HOME |   | END  |   N  |   M  |   ,  |   .  |   /  |ET/SFT|
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | ESC  | WIN  | ALT  | ALT  | GUI  |LOWER |Space |   |Space |RAISE | GUI  | HOME | LEFT | RGHT | CMOVE|
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,       KC_PGUP, KC_PGDN, KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL,  KC_A,    KC_S,   KC_D,    KC_F,    KC_G,       KC_LEFT, KC_RGHT, KC_H,       KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,       KC_HOME, KC_END,  KC_N,       KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
  KC_ESC, TT(_WIN), KC_LALT, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_SPC,  MO(_RAISE), KC_RGUI, KC_RCTL, KC_RSFT, KC_RALT, MO(_CMOVE)
),

/* RAISE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | GRV  |  1   |  2   |  3   |  4   |  5   | HOME |   | END  |  6   |  7   |  8   |  9   |  0   | DEL  |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  <-  |   |  ->  |  F6  | MINS | EQL  | LBRC | RBRC | BSLS |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  | PGUP |   | PGDN | F12  |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Space |   |Space |      |      |      |      |      | Alt+~|
 * `------------------------------------------------'   `------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RALT(KC_GRV)
),


/* LOWER
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |   ~  |   !  |  @   |   #  |  $   |   %  |      |   |      |   ^  |   &  |   *  |   (  |   )  | DEL  |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   |  UP  |  F6  |  _   |  +   |  {   |   }  |  |   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  | F11  |      |   | DOWN | F12  |      | PGUP | HOME |  UP  | END  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      | PGDN | LEFT | DOWN | RGHT |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,    KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
  _______, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   _______, KC_UP,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______,  KC_F7,  KC_F8,    KC_F9,   KC_F10,  KC_F11,  _______, KC_DOWN, KC_F12,  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END, \
  _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* CMOVE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      | PGUP | HOME |  UP  | END  |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      | PGDN | LEFT | DOWN | RIGHT|      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_CMOVE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* WIN
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      | LGUI |  ALT |      |      |   |      |      |      | ALT  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[_WIN] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_LGUI, ALT_T(KC_INT5), _______, _______, _______, _______, ALT_T(KC_INT4), _______, _______, _______, _______ \
),

};
