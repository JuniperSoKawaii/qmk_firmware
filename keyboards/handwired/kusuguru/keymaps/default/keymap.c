#include QMK_KEYBOARD_H

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == DRAG_SCROLL && record->event.pressed) {
        set_scrolling = !set_scrolling;
    }
    return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,  KC_NO,  RESET,  KC_NO,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12,   KC_PAUSE, KC_PSCR,
        KC_GRAVE, KC_1, KC_2, KC_3,  KC_4,  KC_5,  KC_6,   KC_INS, KC_HOME, KC_PGUP,    KC_7,  KC_8,  KC_9,  KC_0,   KC_MINS, KC_EQUAL, KC_BSLS,  KC_BSPACE,
        KC_TAB,   KC_Q, KC_W, KC_E,  KC_R,  KC_T,          KC_DEL, KC_END, KC_PGDN,     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENTER,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G,                                          KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_BSLS,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                                          DRAG_SCROLL, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT, KC_RSHIFT,
        KC_LCTL, KC_LALT,    KC_NO, KC_SPACE,                                       KC_BSPACE, KC_NO,       KC_RALT, KC_RGUI, KC_RCTL
        )
};
