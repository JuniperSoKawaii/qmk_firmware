#include QMK_KEYBOARD_H

enum custom_keycodes {
    NEW_L = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    //replicate vim 'o' action with end keypress followed by enter keypress
    case NEW_L:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_alice_split_bs(
    DYN_MACRO_PLAY1, KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  _______, KC_BSPC, KC_BSPC,
    DYN_MACRO_PLAY2, KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       KC_LBRC, KC_RBRC, KC_BSLS,
    DYN_REC_STOP,    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_QUOT, KC_ENT,
                     KC_LSPO,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSPC, KC_DEL, 
                     KC_CAPS,        MO(2),                     KC_BSPC, KC_LGUI,                            KC_SPC,                    MO(1), KC_RALT),
	[1] = LAYOUT_alice_split_bs(
            KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, 
            DYN_REC_START1, KC_TRNS, KC_TRNS, LCTL(KC_RGHT), KC_TRNS, KC_TRNS, KC_TRNS,    KC_COPY, KC_PAGE_UP, KC_TRNS, NEW_L, KC_PSTE, KC_TRNS, KC_TRNS, KC_TRNS,
            DYN_REC_START2, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAGE_DOWN, KC_TRNS, KC_TRNS,           KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT),                      KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_FIND, KC_TRNS, KC_TRNS,
            KC_TRNS, MO(3), KC_TRNS, KC_TRNS,                                            KC_TRNS, KC_TRNS, KC_TRNS),
	[2] = LAYOUT_alice_split_bs(
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, 
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD,      KC_TRNS, KC_, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS, KC_TRNS, RGB_SAI, RGB_SAD, RGB_HUI, RGB_HUD,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
            KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, MO(3),                                     KC_TRNS)
