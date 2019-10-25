#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BSpace|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   :  |Shift |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |Space |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  | Ctrl | GUI  | Alt  | SCMD |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |Lower |Enter |             |Enter |Raise |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
   KC_ESC, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,             KC_Y,  KC_U,  KC_I, KC_O,   KC_P, KC_BSPACE, \
   KC_TAB, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,             KC_H,  KC_J,  KC_K, KC_L,   KC_RGUI, KC_RSFT, \
   KC_SPC, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,             KC_N,  KC_M,  KC_RCTL, KC_RGUI, KC_RALT, RGUI(KC_RSFT), \
   _______, _______, _______, _______, LOWER, KC_ENT,    KC_ENT, RAISE, _______, _______, _______, _______ \
   ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |  ^   |  &   |  *   |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   <  |   >  |   (  |   )  |   `  |             |  -   |  {   |  }   |   [  |   ]  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |   =  |   ?  |             |  _   |  +   |  ,   |   .  |   /  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |------| TRSP |             | TRSP | GUI  |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_LOWER] =  LAYOUT_ortho_4x12( \
      KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,\
      _______, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_GRV,       KC_MINS, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE, \
      _______, _______, _______, _______, KC_EQL, KC_QUES,   KC_UNDS, KC_PLUS, KC_COMM, KC_DOT, KC_SLSH, _______, \
      _______, _______, _______, _______, _______, KC_TRNS,  ADJUST, KC_RGUI, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |   1  |   2  |   3  |  4   |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   :  |   ;  |  "   |  '   |  \   |             | Left | Down | Up   |Right |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |ADJUST|      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      | GUI  |Shift |             |Shift |------|      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  _______, \
  _______, KC_COLN, KC_SCLN, KC_DQT, KC_QUOT, KC_BSLS,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______, \
  _______, _______, _______, _______, _______, _______,        ADJUST, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_LGUI, KC_LSFT,        KC_LSFT, _______, _______, _______, _______, _______ \
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |RESET |             |------|      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, RESET,  _______, _______, _______, _______, _______, _______ \
      ),

};

// define variables for reactive RGB
bool TOG_STATUS = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_LOWER);
      } else {
        TOG_STATUS = false;
        layer_off(_LOWER);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
        }
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
        TOG_STATUS = false;
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;

  }
  return true;
}
