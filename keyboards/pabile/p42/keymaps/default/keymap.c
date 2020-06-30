#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_default(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,         KC_U,   KC_I,    KC_O,   KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,          KC_H,         KC_J,   KC_K,    KC_L,   LT(3,KC_MINS),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,         KC_M,   KC_COMM, KC_DOT, KC_SLSH,       KC_BTN1,
    KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, LT(2,KC_BSPC), LT(1,KC_SPC), KC_ENT, KC_APP,  KC_DEL, LT(4,KC_ESC),  KC_ESC)
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_WH_D); /*mouse wheel down */
    } else {
      tap_code(KC_WH_U); /*mouse wheel up*/
    }
  } 
}
