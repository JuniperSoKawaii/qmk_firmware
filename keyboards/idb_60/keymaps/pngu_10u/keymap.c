#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT(
    KC_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_NO,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Z,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    LT(2, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT, KC_NUBS, KC_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
    KC_LCTL, KC_NO, KC_NO,                                     KC_SPC,                             KC_NO, KC_NO, KC_RALT
  ),
   [1] = LAYOUT(
	RESET,   _______, RALT(KC_Q), _______, LSFT(KC_GRV), _______, _______, RALT(KC_NUBS), _______, _______, _______, _______, RALT(KC_RBRC),  KC_DEL,  _______,
	_______, _______, _______, RALT(KC_E), _______, _______, _______, _______, _______, _______, KC_PSCR, RALT(KC_8), RALT(KC_9), RALT(KC_0),
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RALT(KC_7),          KC_INS,
	_______, RALT(KC_MINS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	KC_RALT, _______, _______,                                     _______,                            _______, _______, _______
  ),
  [2] = LAYOUT(
	_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, 
	_______, _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______,
	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	_______, _______, _______,                                     _______,                            _______, _______, _______
  )

};

void matrix_scan_user(void) {

	//Layer LED indicators

    if (layer_state_is(1) || layer_state_is(2)) {
        _idb_60_esc_led_on();
    } else {
        _idb_60_esc_led_off();
    }

};