#include "frosty_flake.h"
#define _______ KC_TRNS

//Tap Dance Declarations
enum {
  TD_CTCPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for CTRL, twice for Caps Lock
  [TD_CTCPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( I(1), D(LGUI), D(LCTL), D(D), U(LGUI), U(LCTL), U(D), END  ); // NEW DESKTOP
      }
      break;
    case 1: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( I(1), D(LGUI), D(LCTL), D(LEFT), U(LGUI), U(LCTL), U(LEFT), END  ); // LEFT DESKTOP
      }
      break;
    case 2: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( I(1), D(LGUI), D(LCTL), D(RGHT), U(LGUI), U(LCTL), U(RGHT), END  ); // RIGHT DESKTOP
      }
      break;
    case 3: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO( I(1), D(LGUI), D(LCTL), D(F4), U(LGUI), U(LCTL), U(F4), END  ); // CLOSE DESKTOP
      }
      break;
  }
  return MACRO_NONE;
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_A, KC_A) {
      register_code(KC_LCTL);
      register_code(KC_A);
      unregister_code(KC_A);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }

  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP(\
      KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_PAUS,                        \
      KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_INS,KC_HOME,KC_PGUP,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_DEL, KC_END,KC_PGDN,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      KC_LCTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSPO,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSPC,            KC_UP,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
 TD(TD_CTCPS),KC_LGUI,KC_LALT,                 KC_SPC,                                KC_LEAD,KC_RGUI, KC_APP,MO(1)  ,  KC_LEFT,KC_DOWN,KC_RGHT,    KC_P0,KC_PDOT),
[1] = KEYMAP(\
      KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_PAUS,                        \
      KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_MPRV,KC_MPLY,KC_MNXT,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
      KC_TAB,   KC_Q,   M(0),   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_MUTE,KC_VOLD,KC_VOLU,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      KC_LCTL,   M(1),   M(3),   M(2),   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,          KC_MS_U,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_BTN1,KC_BTN3,KC_BTN2,                 KC_SPC,                                KC_RALT,KC_RGUI, TG(2),_______  ,  KC_MS_L,KC_MS_D,KC_MS_R,    KC_P0,KC_PDOT),
[2] = KEYMAP(\
      KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,           KC_PSCR,KC_SLCK,KC_PAUS,                        \
      KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,KC_MINS, KC_EQL,KC_BSPC,   KC_MPRV,KC_MPLY,KC_MNXT,  KC_NLCK,KC_PSLS,KC_PAST,KC_PMNS, \
      KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,KC_LBRC,KC_RBRC,KC_BSLS,   KC_MUTE,KC_VOLD,KC_VOLU,    KC_P7,  KC_P8,  KC_P9,KC_PPLS, \
      KC_LCTL,   KC_D,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,KC_SCLN,KC_QUOT,         KC_ENT,                              KC_P4,  KC_P5,  KC_P6,      \
      KC_LSFT,KC_NUBS,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,KC_COMM, KC_DOT,KC_SLSH,        KC_RSFT,          KC_MS_U,            KC_P1,  KC_P2,  KC_P3,KC_PENT, \
      KC_BTN1,KC_BTN3,KC_BTN2,                 KC_SPC,                                KC_RALT,KC_RGUI, _______,_______  ,  KC_MS_L,KC_MS_D,KC_MS_R,    KC_P0,KC_PDOT),
};
