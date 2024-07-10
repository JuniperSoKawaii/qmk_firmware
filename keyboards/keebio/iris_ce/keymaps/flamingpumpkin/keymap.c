// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#define LAYERLOCK MT(MOD_LCTL,KC_INS)
#include QMK_KEYBOARD_H
#include "features/layer_lock.h"

enum custom_layer {
    _MAIN,
    _FN1,
    _FN2,
    _FN3
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_layer_lock(keycode, record, KC_NO)) { return false; }

  switch (keycode) {
    case LAYERLOCK:  // Control on hold, Layer Lock on tap.
      if (record->tap.count) {
        if (record->event.pressed) {
          // Toggle the lock on the highest layer.
          layer_lock_invert(get_highest_layer(layer_state));
        }
        return false;  // Skip default handling on tap.
      }
      return true;  // Continue default handling on hold.

    // Other macros...
  }
  return true;
};

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {

    const bool caps_lock = host_keyboard_led_state().caps_lock;
    const bool num_lock = host_keyboard_led_state().num_lock;
    const uint8_t layer = get_highest_layer(layer_state);
    HSV matrix_hsv = rgb_matrix_get_hsv();

    if (!caps_lock && !layer)
        return false;

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            const uint8_t index = g_led_config.matrix_co[row][col];

            if (index < led_min || index >= led_max)
                continue;

            HSV hsv;
            hsv.s = 255;
            hsv.v = matrix_hsv.v;

            uint16_t kc = layer ?
                keymap_key_to_keycode(layer, (keypos_t){col,row}) : 0;

            if (kc >= QK_MOD_TAP && kc <= QK_LAYER_TAP_MAX)
                kc &= 0xff;

            switch (kc) {
            case KC_RIGHT ... KC_UP:
            case KC_ESC:
            case KC_INS:
            case KC_BSPC:
            case KC_DEL:
                hsv.h = 252;
                break;
            case KC_1 ... KC_0:
                hsv.h = 80;
                break;
            case KC_KP_1 ... KC_KP_0:
                if (!num_lock) {
                    hsv.h = 252;
                    hsv.v >>= 2;
                    break;
                }
                // fall through
            case KC_NUM:
                hsv.h = 149;
                break;
#ifdef MOUSEKEY_ENABLE
            case KC_MS_U ... KC_BTN2:
            case KC_WH_U ... KC_WH_D:
                hsv.h = 40;
                break;
#endif
            case RGB_TOG ... RGB_SPD:
                hsv.h = matrix_hsv.h + ((((kc + 3) >> 1) % 6) * 85 >> 1);
                hsv.s = matrix_hsv.s;
                uint8_t inc = (kc + !!(get_mods() & MOD_LSFT)) & 1;
                hsv.v >>= 1 - inc;
                break;
            default:
                if (caps_lock && (row == 0 ||
                            (row == 3 && (col == 0 || col == 9))
                            ))
                    hsv.h = matrix_hsv.h+128, hsv.s >>= 1,
                        hsv.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
                else
                    continue;
            }

            RGB rgb = hsv_to_rgb(hsv);
            rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
        }
    }

    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   QK_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                                  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_DEL,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                  KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_HOME,           KC_END,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
//└─────────┴─────────┴─────────┴────┬────┴────┬────┴────┬────┴────┬────┘        └────┬────┴────┬────┴────┬────┴────┬────┴─────────┴─────────┴─────────┘
                                      KC_LGUI,  TL_LOWR, KC_ENT,                       KC_SPC,   TL_UPPR,  KC_RALT
                                  // └─────────┴─────────┴─────────┘                  └─────────┴─────────┴─────────┘
  ),

  [_FN1] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                               KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PGUP,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_GRV,   _______,  KC_UP,    _______,  QK_BOOT,  _______,                               _______,  KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PGDN,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  KC_LBRC,                               KC_RBRC,  KC_P4,    KC_P5,    KC_P6,    KC_PLUS,  KC_PIPE,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   RGB_MOD,  EE_CLR,   _______,  _______,  _______,  KC_LCBR,  KC_LPRN,           KC_RPRN,  KC_RCBR,  KC_P1,    KC_P2,    KC_P3,    KC_MINS,  _______,
//└─────────┴─────────┴─────────┴────┬────┴────┬────┴────┬────┴────┬────┘        └────┬────┴────┬────┴────┬────┴────┬────┴─────────┴─────────┴─────────┘
                                      _______,  _______,  KC_DEL,                      KC_DEL,   _______,  KC_P0
                                  // └─────────┴─────────┴─────────┘                  └─────────┴─────────┴─────────┘
  ),

  [_FN2] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                 KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   RGB_TOG,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                               KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  QK_BOOT,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   RGB_MOD,  KC_MPRV,  KC_MNXT,  KC_VOLU,  KC_PGUP,  KC_UNDS,                               KC_EQL,   KC_HOME,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_BSLS,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   KC_MUTE,  KC_MSTP,  KC_MPLY,  KC_VOLD,  KC_PGDN,  KC_MINS,  KC_LPRN,           _______,  KC_PLUS,  KC_END,   RGB_HUD,  RGB_SAD,  RGB_VAD,  EE_CLR,
//└─────────┴─────────┴─────────┴────┬────┴────┬────┴────┬────┴────┬────┘        └────┬────┴────┬────┴────┬────┴────┬────┴─────────┴─────────┴─────────┘
                                      _______,  _______,  _______,                     _______,  _______,  _______
                                  // └─────────┴─────────┴─────────┘                  └─────────┴─────────┴─────────┘
  ),

  [_FN3] = LAYOUT(
//┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐                            ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
   _______,  _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,  _______,  _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   _______,  _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,  _______,  _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤                            ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   _______,  _______,  _______,  _______,  _______,  _______,                               _______,  _______,  _______,  _______,  _______,  _______,
//├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐        ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
   _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,  _______,  EE_CLR,
//└─────────┴─────────┴─────────┴────┬────┴────┬────┴────┬────┴────┬────┘        └────┬────┴────┬────┴────┬────┴────┬────┴─────────┴─────────┴─────────┘
                                      _______,  _______,  _______,                     _______,  _______,  _______
                                  // └─────────┴─────────┴─────────┘                  └─────────┴─────────┴─────────┘
  )
};
