#include QMK_KEYBOARD_H
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |   ~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -| =|Del|Bksp|
   * |-----------------------------------------------------------|
   * |  Tab|  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| |  \|
   * |-----------------------------------------------------------|
   * |  Ctrl|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|
   * |-----------------------------------------------------------|
   * |  Shift|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|    /|   Up| Fn|
   * |-----------------------------------------------------------|
   * |Ctrl| Alt| Super|  Shift| Space |Esc|Shift|Ctrl| LT| DN| RT|
   * `-----------------------------------------------------------'
   */
  // 0: Base Layer
  LAYOUT_all_rev3(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_DEL,   KC_BSPC,  \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,  \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_TRNS,           KC_ENT,   \
      KC_LSFT, KC_TRNS, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    MO(1),    \
      KC_LCTL, KC_LALT, KC_LGUI,          KC_LSFT,                KC_SPC,         KC_ESC,  KC_RSFT, KC_RCTL,  KC_LEFT, KC_DOWN,  KC_RIGHT),
  // 1: Function Layer
  LAYOUT_all_rev3(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_TRNS,   KC_TRNS, \
      KC_TRNS, BL_TOGG, BL_INC,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, KC_MUTE,  KC_VOLU,  KC_VOLD,  KC_TRNS, KC_TRNS,            KC_TRNS,  \
      KC_TRNS, BL_STEP, BL_DEC,  KC_TRNS, KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,            KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_PSCR, KC_PGUP,   KC_TRNS, \
      KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS, KC_HOME, KC_PGDOWN, KC_END),
};

// Macros
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {

  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) { register_code(KC_RSFT); }
      else { unregister_code(KC_RSFT); }
      break;
  }

  return MACRO_NONE;
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
