#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_APP,  KC_RCTL
    ),
    [1] = LAYOUT_60_ansi_split_bs_rshift(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, MO(2),   _______
    ),
    [2] = LAYOUT_60_ansi_split_bs_rshift(
        RGB_TOG, RGB_RMOD,RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI, _______, _______, RGB_VAD, RGB_VAI, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______
    )
};
