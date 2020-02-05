#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

    [1] = LAYOUT(
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_DEL,  KC_PSCR,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END)
};

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K20, K21, K22, K23, K24, K25, \
    K40, K41, K42, K43, K44, K45, K60, K61, K62, K63, K64, K65, \
    K10, K11, K12, K13, K14, K15, K30, K31, K32, K33, K34, K35, \
    K50, K51, K52, K53, K54, K55, K70, K71, K72, K73, K74, K75 \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05 }, \
    { K10,   K11,   K12,   K13,   K14,   K15 }, \
    { K20,   K21,   K22,   K23,   K24,   K25 }, \
    { K30,   K31,   K32,   K33,   K34,   K35 }, \
    { K40,   K41,   K42,   K43,   K44,   K45 }, \
    { K50,   K51,   K52,   K53,   K54,   K55 }, \
    { K60,   K61,   K62,   K63,   K64,   K65 }, \
    { K70,   K71,   K72,   K73,   K74,   K75 }  \
}

~

