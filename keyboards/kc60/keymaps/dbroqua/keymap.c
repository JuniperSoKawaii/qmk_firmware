
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FNCAPS 1
#define _FNRIGHTSHIFT 2

// Fillers to make layering more clear
#define ______ KC_TRNS

/*
 * |     |     |
 * |       |   |
 * |        |  |
 * |         | |
 * |           |
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |
 * |-----------------------------------------------------------------------------------------+
 * | Caps/FN1|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     Up    | FN2 |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl  | Gui   | Alt   |               Space             | AltGr | Left  | Down  | Right |
 * `-----------------------------------------------------------------------------------------'
 */
  [0] = LAYOUT( /* Basic QWERTY */
      KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,  \
      LT(_FNCAPS, KC_CAPS),  KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,    KC_ENT,   \
      KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  MO(_FNRIGHTSHIFT),  KC_UP,  \
      KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_GRV,  KC_RALT,  KC_LEFT, KC_DOWN, KC_RIGHT \
      ),

/* Layer 1
 * ,-----------------------------------------------------------------------------------------.
 * |     | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     | Psc |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Led | Led+| Led-|     | Mute| Vol+| Vol-|     |     |     |    Play   |     |
 * |-----------------------------------------------------------------------------------------+
 * |       |       |       |                                 |       | Prev  | Stop  | Next  |
 * `-----------------------------------------------------------------------------------------'
 */
  [_FNCAPS] = LAYOUT( /* Layer 1 */
      ______,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_INS,  \
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,   ______, ______, ______, ______, ______, ______, KC_PSCR,______, ______, ______, ______, ______, ______,   \
      ______,   ______, BL_TOGG, BL_INC, BL_DEC, ______,KC_MUTE,KC_VOLU,KC_VOLD,______, ______, ______, ______,KC_MPLY,  \
      ______,   ______, ______,                 ______,         KC_DEL,         ______, KC_MPRV,    KC_MSTP,    KC_MNXT \
      ),

/* Layer 2
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |           |     |     |     |     |     |     |     |     |     |     |   PgUp    |     |
 * |-----------------------------------------------------------------------------------------+
 * |       |       |       |                                 |       | Home  | PgDown| End   |
 * `-----------------------------------------------------------------------------------------'
 */
  [_FNRIGHTSHIFT] = LAYOUT( /* Layer 2 */
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,   \
      ______,   ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, KC_PGUP,  \
      ______,   ______, ______,                 ______,         ______,                 ______, KC_HOME,KC_PGDN,KC_END \
      ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  return MACRO_NONE;
};
