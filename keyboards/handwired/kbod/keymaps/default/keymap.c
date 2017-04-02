#include "kbod.h"

#define _____ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  KEYMAP( /* Base */
      F(0), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQUAL, KC_BSPC,
      KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLASH,
      KC_CAPS,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOT, KC_ENTER,
      KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSPO,
      LT(1, KC_LEAD), KC_LCTL, KC_LALT, KC_SPACE, KC_RALT, KC_RGUI, KC_APP, KC_RCTL 
  ),
  KEYMAP( /* Cursor layer */
      KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, KC_INSERT,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, KC_HOME, KC_END, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, KC_PGUP, KC_PGDN, KC_UP, _____,
      _____,  _____, _____, _____, _____, KC_LEFT, KC_DOWN, KC_RIGHT, _____
  ),
  KEYMAP( /* Multimedia layer */
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, KC_MS_BTN1, KC_MS_UP, _____,
      LT(3, KC_LEAD),  _____, _____, _____, _____, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_BTN3
  ),
  KEYMAP( /* Multimedia layer */
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
      _____,  _____, _____, _____, _____, _____, _____, _____, _____, KC_MS_BTN1, KC_MS_WH_UP, _____,
      _____,  _____, _____, _____, _____, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, KC_MS_BTN3
  ),
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(0),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
    case 0:
      shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
      if (record->event.pressed) {
        if (shift_esc_shift_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (shift_esc_shift_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_B) {
      layer_switch(0);
    }
    SEQ_ONE_KEY(KC_C) {
      layer_switch(1);
    }
    SEQ_ONE_KEY(KC_M) {
      layer_switch(2);
    }
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    return MACRO_NONE;
};

void led_set_user(uint8_t usb_led) {

}