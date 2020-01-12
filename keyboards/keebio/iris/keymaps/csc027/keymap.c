#include QMK_KEYBOARD_H
#include "csc027.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT_wrapper(
        _____________________QWERTY_L1_____________________,                            _____________________QWERTY_R1_____________________,
        _____________________QWERTY_L2_____________________,                            _____________________QWERTY_R2_____________________,
        _____________________QWERTY_L3_____________________,                            _____________________QWERTY_R3_____________________,
        _____________________QWERTY_L4_____________________, KC_SPC,           KC_SPC,  _____________________QWERTY_R4_____________________,
                                   KC_LGUI,  KC_LALT,  KC_SPC,                    KC_SPC,   KC_RALT,  KC_RGUI
    ),

    [_RS] = LAYOUT_wrapper(
        ______________________RAISE_L1_____________________,                            ______________________RAISE_R1_____________________,
        ______________________RAISE_L2_____________________,                            ______________________RAISE_R2_____________________,
        ______________________RAISE_L3_____________________,                            ______________________RAISE_R3_____________________,
        ______________________RAISE_L4_____________________, _______,          _______, ______________________RAISE_R4_____________________,
                                   _______,  _______,  _______,                   _______,  _______,  _______
    ),

    [_LW] = LAYOUT_wrapper(
        ______________________LOWER_L1_____________________,                            ______________________LOWER_R1_____________________,
        ______________________LOWER_L2_____________________,                            ______________________LOWER_R2_____________________,
        ______________________LOWER_L3_____________________,                            ______________________LOWER_R3_____________________,
        ______________________LOWER_L4_____________________, _______,          _______, ______________________LOWER_R4_____________________,
                                   _______,  _______,  _______,                   _______,  _______,  _______
    ),

    [_MS] = LAYOUT_wrapper(
        ______________________MOUSE_L1_____________________,                            ______________________MOUSE_R1_____________________,
        ______________________MOUSE_L2_____________________,                            ______________________MOUSE_R2_____________________,
        ______________________MOUSE_L3_____________________,                            ______________________MOUSE_R3_____________________,
        ______________________MOUSE_L4_____________________, _______,          _______, ______________________MOUSE_R4_____________________,
                                   _______,  _______,  _______,                   _______,  _______,  _______
    ),

    [_GT] = LAYOUT_wrapper(
        _______________________GIT_L1______________________,                            _______________________GIT_R1______________________,
        _______________________GIT_L2______________________,                            _______________________GIT_R2______________________,
        _______________________GIT_L3______________________,                            _______________________GIT_R3______________________,
        _______________________GIT_L4______________________, _______,          _______, _______________________GIT_R4______________________,
                                   _______,  _______,  _______,                   _______,  _______,  _______
    ),

    [_CN] = LAYOUT_wrapper(
        ___________________CONVENIENCE_L1__________________,                            ___________________CONVENIENCE_L1__________________,
        ___________________CONVENIENCE_L2__________________,                            ___________________CONVENIENCE_L2__________________,
        ___________________CONVENIENCE_L3__________________,                            ___________________CONVENIENCE_L3__________________,
        ___________________CONVENIENCE_L4__________________, _______,          _______, ___________________CONVENIENCE_L4__________________,
                                   _______,  _______,  _______,                   _______,  _______,  _______
    ),

    [_GW] = LAYOUT(
        KC_Y,    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_B,    KC_TAB,  KC_T,    KC_W,    KC_4,    KC_R,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_M,    MC_LSEC, KC_A,    KC_S,    KC_D,    KC_F,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_I,    KC_LCTL, KC_Z,    KC_LALT, KC_V,    KC_SPC,  KC_SPC,          _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  TO(_CS), TO(_QW),
                                   KC_X,     KC_C,     KC_SPC,                    _______,  KC_M,     KC_B
    ),

    [_CS] = LAYOUT(
        XXXXXXX, KC_5,    KC_1,    KC_2,    KC_3,    KC_4,                               KC_6,    KC_P7,   KC_P8,   KC_P9,   KC_0,    KC_BSPC,
        XXXXXXX, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                               KC_Y,    KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_NLCK,
        KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                               KC_H,    KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_ESC,
        XXXXXXX, KC_LCTL, XXXXXXX, KC_X,    XXXXXXX, XXXXXXX, KC_SPC,           _______, KC_N,    KC_P0,   KC_P0,   KC_PDOT, TO(_QW), TO(_QW),
                                   KC_B,     KC_SPC,   KC_SPC,                    _______,  KC_N,     KC_P0
    )
};
