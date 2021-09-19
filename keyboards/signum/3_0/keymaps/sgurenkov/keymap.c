#include "signum.h"

#define M0(kc) MT(MOD_HYPR, kc)
#define M1(kc) MT(MOD_LGUI, kc)
#define M2(kc) MT(MOD_LCTL, kc)
#define M3(kc) MT(MOD_LALT, kc)
#define M4(kc) MT(MOD_LSFT, kc)
#define LTH1 LT(L_LEFT, KC_SPC)
#define LTH2 LT(L_NUM, KC_BSPC)
#define RTH1 LT(L_RIGHT, KC_SPC)
#define RTH2 LT(L_NUM, KC_ENT)
#define COPY  LCMD(KC_C)
#define PASTE LCMD(KC_V)
// Layers
#define L_BASE 0
#define L_LEFT 1
#define L_RIGHT 2
#define L_NUM 3


bool is_cmd_tab_active = false;

enum custom_keycodes {
  CMD_TAB = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// L_BASE
	LAYOUT(
    KC_ESC,         KC_Q,      KC_W,       KC_E,      KC_R,      KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,         KC_DEL,
    KC_TAB,         M4(KC_A),  M3(KC_S),   M2(KC_D),  M1(KC_F),  M0(KC_G),   M0(KC_H), M1(KC_J), M2(KC_K), M3(KC_L), M4(KC_COLN),  KC_QUOT,
    KC_GRV,         KC_Z,      KC_X,       KC_C,      KC_V,      KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,      KC_BSLS,
    OSM(MOD_LSFT),  KC_LEFT,   KC_RIGHT,   LTH1,      XXXXXXX,   LTH2,       RTH2,     XXXXXXX,  RTH1,     KC_DOWN,  KC_UP,        KC_ENT),

// L_LEFT
    LAYOUT(
    _______, XXXXXXX,   XXXXXXX, KC_EQL,  KC_PERC, KC_AT,        COPY,     KC_UNDS, KC_HASH, RALT(KC_SPC), KC_PLUS,  _______,
    _______, KC_LSHIFT, KC_LALT, KC_LCTL, KC_LGUI, KC_HYPR,      KC_LEFT,  KC_DOWN, KC_UP,   KC_RIGHT,     KC_LBRC,  KC_RBRC,
    _______, XXXXXXX,   KC_EXLM, KC_CIRC, XXXXXXX, KC_HOME,      KC_END,   KC_MINS, KC_LPRN, KC_RPRN,      PASTE,    XXXXXXX,
    _______, KC_BRID,   KC_BRIU, _______, _______,  _______,     _______, _______, _______, KC_VOLD,      KC_VOLU,  _______),

// L_RIGHT
    LAYOUT(
    _______, XXXXXXX, XXXXXXX, KC_EQL,  KC_PERC,      KC_AT,        COPY,    KC_UNDS, KC_HASH,  RALT(KC_SPC), KC_PLUS,  _______,
    _______, KC_AMPR, KC_ASTR, KC_DLR,  LGUI(KC_GRV), XXXXXXX,      KC_LEFT, KC_DOWN, KC_UP,    KC_RIGHT,     KC_RSFT,  KC_RBRC,
    _______, XXXXXXX, KC_EXLM, KC_CIRC, XXXXXXX,      KC_HOME,      KC_END,  KC_MINS, KC_LPRN,  KC_RPRN,      PASTE,    XXXXXXX,
    _______, KC_BRID, KC_BRIU, _______, _______,      _______,      _______, _______, _______,  KC_VOLD,      KC_VOLU,  _______),

// L_NUM
  	LAYOUT(
    _______,  XXXXXXX,     KC_F7,     KC_F8,     KC_F9,     KC_F12,         KC_MINS,    KC_7,     KC_8,     KC_9,                  KC_COMM,              _______,
    _______,  M4(KC_LSFT), M3(KC_F4), M2(KC_F5), M1(KC_F6), M0(KC_F11),     M0(KC_DOT), M1(KC_4), M2(KC_5), M3(KC_6),              M4(KC_0),             _______,
    _______,  XXXXXXX,     KC_F1,     KC_F2,     KC_F3,     KC_F10,         KC_PLUS,    KC_1,     KC_2,     KC_3,                  KC_DOT,               _______,
    _______,  _______,     _______,   _______,   _______,   _______,        _______,    _______,  _______,  KC_MEDIA_PREV_TRACK ,  KC_MEDIA_NEXT_TRACK,  KC_MEDIA_PLAY_PAUSE),

    LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CMD_TAB:
        if (record->event.pressed) {
            register_code(KC_LCMD);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            layer_on(2);
        } else {
            unregister_code(KC_LCMD);
            layer_off(2);
        }
        break;
    case KC_ESC:
        layer_clear();
  }
  return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Cancel task CTRL+C
    SEQ_ONE_KEY(KC_C) {
      SEND_STRING(SS_LCTL("c"));
    }
    // copy
    SEQ_ONE_KEY(KC_Y) {
      SEND_STRING(SS_LCMD("c"));
    }
    // cut
    SEQ_ONE_KEY(KC_X) {
      SEND_STRING(SS_LCMD("x"));
    }
    // paste
    SEQ_ONE_KEY(KC_P) {
      SEND_STRING(SS_LCMD("v"));
    }
    // undo
    SEQ_ONE_KEY(KC_U) {
      SEND_STRING(SS_LCMD("z"));
    }
    // redo
    SEQ_ONE_KEY(KC_R) {
      SEND_STRING(SS_LCMD(SS_LSFT("z")));
    }
    // delete line
    SEQ_TWO_KEYS(KC_D, KC_D) {
      register_code(KC_LGUI);

      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);

      register_code(KC_BSPACE);
      unregister_code(KC_BSPACE);

      unregister_code(KC_LGUI);
    }
    // go to the beginning of the string
    SEQ_ONE_KEY(KC_H) {
      register_code(KC_LCMD);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      unregister_code(KC_LCMD);
    }
    // go to the end of the string
    SEQ_ONE_KEY(KC_L) {
      register_code(KC_LCMD);
      register_code(KC_RIGHT);
      unregister_code(KC_RIGHT);
      unregister_code(KC_LCMD);
    }
  }
}
