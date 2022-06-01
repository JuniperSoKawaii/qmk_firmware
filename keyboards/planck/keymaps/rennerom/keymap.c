/* 

Max's Planck Layout

 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER, 
  _RAISE, 
  _ADJUST,
  _FN,
  _NAV
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ESCNAV LT(_NAV, KC_ESC)
#define WORDL LALT(KC_LEFT)
#define WORDR LALT(KC_RGHT)
#define EOL LGUI(KC_RIGHT)
#define BOL LGUI(KC_LEFT)
#define SPOTLT LGUI(KC_SPC)
#define VBA LSFT(LALT(KC_F11))
#define UNDO LGUI(KC_Z)
#define CUT LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PSTE LGUI(KC_V)
#define ALL LGUI(KC_A)
#define FIND LGUI(KC_F)
#define SAVE LGUI(KC_S)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ESCNAV|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |shfent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  fn  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    ESCNAV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT ,
    FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* fn
 * ,------------------------------------------------------------------------------------.
 * |      |  f1  |  f2  |  f3  |  f4  |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |  f5  |  f6  |  f7  |  f8  |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |  f9  |  f10 |  f11 |  f12 |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

	[_FN] = LAYOUT_planck_grid(
		_______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______

		),

/* NAV
 * ,------------------------------------------------------------------------------------.
 * |      |      | WORDL| WORDR|      |      |      |      |Insert|      |      |  Del |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | Left | Down |  Up  | Right|      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |OpenSpotlight|      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

[_NAV] = LAYOUT_planck_grid(
		_______,  _______,  WORDL,    WORDR,    _______,  _______,  _______,  KC_INS ,  _______,  _______,  _______,  KC_DEL,
    _______,  ALL,      SAVE,     _______,  FIND,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
    _______,  UNDO,     CUT,      COPY,     PSTE,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  SPOTLT,   SPOTLT,   _______,  _______,  _______,  _______,  _______


		), 
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | ` ~  | 1 !  | 2 @  | 3 #  | 4 $  | 5 %  | 6 ^  | 7 &  | 8 *  | 9 (  | 0 )  | Bksp |
*  ,------------------------------------------------------------------------------------.
 * | Del  |  { [ |  } ] |   (  |   )  |  - _ |   +  |   =  |   *  |   %  |   _  |  \ | |
 * ,------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

[_LOWER] = LAYOUT_planck_grid(
		KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
    KC_DEL,   KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_ASTR,  KC_PERC,  KC_UNDS,  KC_BSLS,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Raise
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * | Del  |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |Brite-|Brite+| Vol- | Vol+ |
 * ,------------------------------------------------------------------------------------.
 */

[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, VBA,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------------------------------------------.
 * |      |  f1  |  f2  |  f3  |  f4  |RGBTOG|      |HUE - |HUE + |      |Debug |Reset |
 * ,------------------------------------------------------------------------------------.
 * |      |  f5  |  f6  |  f7  |  f8  |RGBM -|RGBM +|SAT - |SAT + |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |  f9  |  f10 |  f11 |  f12 |RGBsp-|RGBsp+|VIB - |VIB + |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |             |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

[_ADJUST] = LAYOUT_planck_grid(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    RGB_TOG,  _______,  RGB_HUD,  RGB_HUI,  _______,  DEBUG,    RESET,
    _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    RGB_RMOD, RGB_MOD,  RGB_SAD,  RGB_SAI,  _______,  _______,  _______,
    _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_SPD,  RGB_SPI,  RGB_VAD,  RGB_VAI,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)


};

/* fn
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * ,------------------------------------------------------------------------------------.
 */

//#ifdef AUDIO_ENABLE
//  float plover_song[][2]     = SONG(PLOVER_SOUND);
//  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
//#endif


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}



/*stuff for later

void press_key(uint16_t key) {
  register_code(key);
  unregister_code(key);
}

void press_two_keys(uint16_t key1, uint16_t key2) {
  register_code(key1);
  register_code(key2);
  unregister_code(key2);
  unregister_code(key1);
}

void press_three_keys(uint16_t key1, uint16_t key2, uint16_t key3) {
  register_code(key1);
  register_code(key2);
  register_code(key3);
  unregister_code(key3);
  unregister_code(key2);
  unregister_code(key1);

  bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_BELW:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_RGHT);
        press_key(KC_ENT);
      }

      return false;

    case MY_ABVE:
      if (record->event.pressed) {
        press_two_keys(KC_LGUI, KC_LEFT);
        press_key(KC_ENT);
        press_key(KC_UP);
      }

      return false;

    case MY_TERM:
      if (record->event.pressed) {
        press_three_keys(KC_LGUI, KC_LSFT, KC_ENT);
      }

      return false;

    case MY_DEQL: // /=
      if (record->event.pressed) {
        press_key(KC_SLSH);
        press_key(KC_EQL);
      }

      return false;

    case MY_MEQL: // *=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_ASTR);
        press_key(KC_EQL);
      }

      return false;

    case MY_SEQL: // -=
      if (record->event.pressed) {
        press_key(KC_MINS);
        press_key(KC_EQL);
      }

      return false;

    case MY_PEQL: // +=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PLUS);
        press_key(KC_EQL);
      }

      return false;

    case MY_NEQL: // !=
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_EXLM);
        press_key(KC_EQL);
      }

      return false;

    case MY_LTGT: // <>
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_LABK);
        press_two_keys(KC_LSFT, KC_RABK);
      }

      return false;

    case MY_DPIP: // ||
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_PIPE);
        press_two_keys(KC_LSFT, KC_PIPE);
      }

      return false;

    case MY_DAMP: // &&
      if (record->event.pressed) {
        press_two_keys(KC_LSFT, KC_AMPR);
        press_two_keys(KC_LSFT, KC_AMPR);
      }

      return false;
  }

  return true;
}

*/