#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_100_ansi(
                                                                                                                                                                                              KC_MUTE,
        KC_ESC,    KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,   KC_F12,   MO(1), MO(2),              KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, 
        KC_GRV,    KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,                   KC_P7,  KC_P8,   KC_P9,   KC_PPLS,
        KC_TAB,    KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,          KC_P4,  KC_P5,   KC_P6,
        KC_CAPS,   KC_A,    KC_S,     KC_D,     KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,           KC_P1,  KC_P2,   KC_P3,   KC_PENT,
        KC_LSFT,   KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,                 KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,          KC_P0,   KC_PDOT, 
        KC_LCTL,   KC_LGUI,                     KC_LALT, KC_SPC,               KC_SPC,  KC_RALT, KC_RGUI,  KC_RCTL,                                KC_LEFT, KC_DOWN,  KC_RIGHT  
    ),

    [1] = LAYOUT_100_ansi(
                                                                                                                                                                                                                             KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS, 
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,                        KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,             KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,             KC_TRNS,             KC_TRNS,  KC_TRNS, 
        KC_TRNS,   KC_TRNS,                           KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                                    KC_TRNS, KC_TRNS,  KC_TRNS 
    ),

    [2] = LAYOUT_100_ansi(
                                                                                                                                                                                                                             KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS, 
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,                        KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,             KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,             KC_TRNS,             KC_TRNS,  KC_TRNS, 
        KC_TRNS,   KC_TRNS,                           KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                                    KC_TRNS, KC_TRNS,  KC_TRNS 
    ),

    [3] = LAYOUT_100_ansi(
                                                                                                                                                                                                                             KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS, 
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,       KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,                        KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,             KC_TRNS,              KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,
        KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,             KC_TRNS,             KC_TRNS,  KC_TRNS, 
        KC_TRNS,   KC_TRNS,                           KC_TRNS,   KC_TRNS,                  KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,                                    KC_TRNS, KC_TRNS,  KC_TRNS 
    )
};
