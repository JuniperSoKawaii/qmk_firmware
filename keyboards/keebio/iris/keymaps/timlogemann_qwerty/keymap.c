#include QMK_KEYBOARD_H

#define _1L 0
#define _2L 1
#define _3L 2

#define SHFT_CPS LSFT_T(KC_CAPS)
#define SHFT_QT RSFT_T(KC_QUOT)
#define L_ALT KC_LAPO
#define R_ALT KC_RAPC
#define TAB_DANCE LT(2, KC_TAB)
#define _ KC_NO
#define VOLDOWN KC__VOLDOWN
#define VOLUP KC__VOLUP
#define PLPS KC_MEDIA_PLAY_PAUSE
#define FWD KC_MEDIA_FAST_FORWARD
#define RWD KC_MEDIA_REWIND

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_1L] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQUAL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SHFT_CPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_GRAVE, KC_Z,    KC_X,    KC_C,    KC_V,      _,                _,  KC_B,     KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_ALT,  KC_LGUI, KC_SFTENT,                 KC_SPC,   TT(_2L),  R_ALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_2L] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,     _,      _,      _,      _,      TO(_3L),                              _,       _,        _,    KC_LBRC, KC_RBRC, KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,   VOLDOWN,    VOLUP,   PLPS,   RWD,   FWD,                            KC_RBRC,   _,     KC_UP,     _,     KC_TRNS, KC_MINUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  _,       _,         _,      _,     KC_LPRN,                            KC_RPRN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_PAST,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS,  _,      KC_0,     _,     KC_PLUS,   _,                _,    KC_MINUS,   _,       _,       _,    KC_TRNS, KC_BSLASH,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LALT_T(KC_LBRC), KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS, RALT_T(KC_RBRC)
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_3L] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TO(_1L),  KC_1,     KC_2,    KC_3,     _,       _,                                  _,       _,       _,       _,       _,       _,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,   KC_4,    KC_5,    KC_6,     _,       _,                                  _,       _,       _,       _,       _,       _,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,   KC_7,    KC_8,    KC_9,     _,       _,                                  _,       _,       _,       _,       _,       _,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _,    KC_MINUS,  KC_0,  KC_PLUS,    _,       _,       _,                _,       _,       _,       _,       _,       _,       _,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       _,       _,     KC_TRNS,                     _,       _,       _
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

};
