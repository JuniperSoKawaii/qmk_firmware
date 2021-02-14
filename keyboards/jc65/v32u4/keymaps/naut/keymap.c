#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layer
    [0] = LAYOUT(
         KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSLS, KC_GRV, KC_INS,
         KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,        KC_BSPC, KC_DEL,
        KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,                 KC_ENT,KC_PGUP,
        KC_LSFT,  KC_NO,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,  KC_UP,KC_PGDN,
          MO(1),KC_LALT,KC_LGUI,         KC_SPC, KC_SPC, KC_SPC,                        KC_RGUI,  KC_NO,KC_RALT,KC_LEFT,KC_DOWN,KC_RGHT
    ),
    // Fn Layer
    [1] = LAYOUT(
        KC_TRNS,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,KC_TRNS,KC_TRNS,  TG(2),
        KC_CAPS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,        KC_TRNS,KC_VOLU,KC_MPLY,
        KC_TRNS,KC_TRNS,KC_TRNS,        TG(3),  TG(3),  TG(3),                          KC_TRNS,KC_TRNS,KC_TRNS,KC_MRWD,KC_VOLD,KC_MFFD
    ),
    // RGB and BL Layer
    [2] = LAYOUT(
          TO(0),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  TO(0),
          KC_NO,RGB_HUD,RGB_HUI,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,BL_TOGG,
          KC_NO,RGB_SAD,RGB_SAI,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                  KC_NO,RGB_TOG,
          KC_NO,  KC_NO,RGB_VAD,RGB_VAI, BL_DEC, BL_INC,  KC_NO,  KC_NO,  KC_NO,  KC_NO,RGB_MOD,RGB_RMOD,         KC_NO,RGB_M_P,RGB_M_R,
          KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,RGB_M_G,RGB_M_SW
    ),
    // Button Mash Layer
    [3] = LAYOUT(
          TO(0),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,
          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                  KC_NO,  KC_NO,
          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO,
          RESET,  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
    ),
};
