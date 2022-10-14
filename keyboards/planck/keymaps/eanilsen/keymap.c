
/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

#include QMK_KEYBOARD_H
#include "customkeys.h"
#include "features/swapper.h"
#include "features/select_word.h"
#include "features/custom_shift_keys.h"

#define SYMBOL OSL(_SYMBOL)
#define FUNCTION OSL(_FUNCTION)
#define NAV TO(_NAV)
#define HOME TO(_ISRT)
#define NUM TO(_NUM)
#define MEH_SPC MT(MOD_MEH,KC_SPC)
#define BSP_DWRD LT(0,KC_BSPC)
#define LT_UP LT(0,KC_UP)
/* Home row mods */
#define HOME_R LALT_T(KC_R)
#define HOME_T LCTL_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_E RALT_T(KC_E)


enum planck_layers {
  _ISRT,
  _SYMBOL,
  _FUNCTION,
  _NAV,
  _NUM
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT, KC_EQL},
  {KC_COMM, KC_EXLM},
  {KC_QUOT, KC_QUES},
  {KC_SLSH, KC_BSLS},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
  sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  /* ISRT
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Y  |   C  |   L  |   M  |   K  |   Z  |   F  |   U  |   ,  |   '  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   I  |   S  |   R  |   T  |   G  |   P  |   N  |   E  |   A  |   O  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Q  |   V  |   W  |   D  |   J  |   B  |   H  |   /  |   .  |   X  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |CPSWRD| Ctrl | Alt  | GUI  |Space | Num  | Func |Bksp  | Nav  | GUI  | Left |Right |
   * `-----------------------------------------------------------------------------------'
   */

  [_ISRT] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,   KC_Z,     KC_F,     KC_U,    KC_COMM, KC_QUOT, KC_DEL,
    KC_ESC,  KC_I,    KC_S,    HOME_R,  HOME_T,  KC_G,   KC_P,     HOME_N,   HOME_E,  KC_A,    KC_O,    KC_ENT,
    KC_LSFT, KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,   KC_B,     KC_H,     KC_SLSH, KC_DOT,  KC_X,    KC_RSFT,
    CAPSWRD, KC_LCTL, KC_LALT, KC_LGUI, MEH_SPC, SYMBOL, FUNCTION, BSP_DWRD, NAV,     KC_LGUI, KC_LEFT, KC_RGHT
    ),

  /* SYMBOL
   * ,-----------------------------------------------------------------------------------.
   * |  --- |   !  |   <  |   >  |   +  |  --- |  --- |   _  |   |  |   ~  |   %  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   {  |   }  |   (  |   )  |   @  |  ->  |   &  |   *  |   "  |   $  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   :  |   ;  |   [  |   ]  |  --- |  --- |   -  |   #  |   `  |   ^  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  --- | Ctrl | Alt  | GUI  |Space |  --- | Home |  Num |  --- |  --- |  --- | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_SYMBOL] = LAYOUT_ortho_4x12(
    KC_NO,   KC_EXLM, KC_LT,   KC_GT,   KC_PLUS, KC_NO, KC_NO, KC_UNDS, KC_PIPE, KC_TILD, KC_PERC, KC_DEL,
    KC_ESC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, ARROW, KC_AMPR, KC_ASTR, KC_DQUO, KC_DLR,  KC_ENT,
    KC_LSFT, KC_COLN, KC_SCLN, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_MINS, KC_HASH, GRAVE,  KC_CIRC, KC_RSFT,
    KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_NO, HOME,  NUM,     KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),

  /* NUM
   * ,-----------------------------------------------------------------------------------.
   * | ---  |   /  |   1  |   2  |   3  |   +  | ---  | ---  | ---  | ---  | ---  | Del  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |   0  |   4  |   5  |   6  |   -  | ---  | ---  | ---  | ---  | ---  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   *  |   7  |   8  |   9  |   =  | ---  | ---  | ---  | ---  | ---  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | Ctrl | Alt  | GUI  |Space | Home | ---  |Bkspc | ---  | ---  | ---  | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_NUM] = LAYOUT_ortho_4x12(
    KC_NO,  KC_SLSH, KC_1,    KC_2,    KC_3,   KC_PLUS, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_DEL,
    KC_ESC, KC_0,    KC_4,    KC_5,    KC_6,   KC_MINS, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_ENT,
    KC_NO,  KC_ASTR, KC_7,    KC_8,    KC_9,   KC_EQL,  KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_RSFT,
    KC_NO,  KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, HOME,    KC_NO, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO
    ),

  /* FUNCTION
   * ,-----------------------------------------------------------------------------------.
   * |CG_TGL|  F1  |  F2  |  F3  |  F4  | ---  | ---  |PrnScr| ---  | ---  |   �  |Reset |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  |  F5  |  F6  |  F7  |  F8  | ---  | ---  | Copy |Paste |   �  |   �  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|  F9  | F10  | F11  | F12  | ---  | ---  |SelWrd| ---  | ---  | ---  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | Ctrl | Alt  | GUI  |Space | Home | Trns | Ctrl | ---  | ---  | ---  |  --- |
   * `-----------------------------------------------------------------------------------'
   */

  [_FUNCTION] = LAYOUT_ortho_4x12(
    CG_TOGG,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_NO, KC_NO,   KC_PSCR, KC_NO,    KC_NO, CT_AE, QK_BOOT,
    KC_NO,     KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_NO, KC_NO,   MW_COPY, MW_PSTE,  CT_AA, CT_OE, KC_NO,
    KC_LSFT,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_NO, KC_NO,   SEL_WRD, SEL_SRCH, KC_NO, KC_NO, KC_RSFT,
    KC_NO,     KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, HOME,  KC_TRNS, KC_RCTL, KC_NO,    KC_NO, KC_NO, KC_NO
    ),

  /* NAV
   * ,-----------------------------------------------------------------------------------.
   * | ---  |ScrlUp| ---  | MsUp | ---  | ---  | Mute |VolDwn|  Up  |VolUp | ---  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Esc  |ScrlDn|MsLft |MsDwn |MsRgt | ---  | Btn4 | Left | Down |Right | Btn5 |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  |SwApp |SwWin | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  | ---  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | ---  | ---  | ---  | Btn3 | Btn1 | Home | ---  | Btn2 | ---  | ---  | ---  | ---  |
   * `-----------------------------------------------------------------------------------'
   */

  [_NAV] = LAYOUT_ortho_4x12(
    KC_NO,  KC_WH_U, KC_NO,   KC_MS_U, KC_NO,   KC_NO, KC_MUTE, KC_VOLD, LT_UP,   KC_VOLU, KC_NO,   KC_NO,
    KC_ESC, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_BTN4, KC_LEFT, KC_DOWN, KC_RGHT, KC_BTN5, KC_ENT,
    KC_NO,  SW_APP,  SW_WIN,  KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO,   KC_NO,   KC_BTN3, KC_BTN1, HOME,  KC_NO,   KC_BTN2, KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

// Returns the value set by CG_TOGG
bool is_mac_the_default(void) { return keymap_config.swap_lctl_lgui; }

bool sw_app_active = false;
bool sw_win_active = false;

void send_mac_or_win(uint16_t mac_code, uint16_t win_code, bool is_pressed)
{
  uint16_t code = is_mac_the_default() ? mac_code : win_code;
  if (is_pressed) {
    register_code16(code);
  } else {
    unregister_code16(code);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  bool isPressed = record->event.pressed;
  bool isHeld = !record->tap.count && isPressed;
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  {
    uint16_t mod = is_mac_the_default() ? KC_LGUI : KC_LALT;
    update_swapper(&sw_app_active, mod, KC_TAB, SW_APP, keycode, record);
  }
  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record);

  if (!process_custom_shift_keys(keycode, record)) { return false; }
  if (!process_select_word(keycode, record, SEL_WRD, is_mac_the_default())) { return false; }

  switch (keycode) {
  case CT_AA:
    if (isPressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
	del_mods(MOD_MASK_SHIFT);
	del_oneshot_mods(MOD_MASK_SHIFT);
	tap_code16(KC_LCBR);
	set_mods(mods);
      } else {
	tap_code16(KC_LBRC);
      }
    }
    return false;
  case CT_OE:
    if (isPressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
	del_mods(MOD_MASK_SHIFT);
	del_oneshot_mods(MOD_MASK_SHIFT);
	tap_code16(KC_COLN);
	set_mods(mods);
      } else {
	tap_code16(KC_SCLN);
      }
    }
    return false;
  case CT_AE:
    if (isPressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
	del_mods(MOD_MASK_SHIFT);
	del_oneshot_mods(MOD_MASK_SHIFT);
	tap_code16(KC_DQUO);
	set_mods(mods);
      } else {
	tap_code16(KC_QUOT);
      }
    }
    return false;
  case GRAVE:
    if (isPressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
	del_mods(MOD_MASK_SHIFT);
	del_oneshot_mods(MOD_MASK_SHIFT);
	for (uint8_t i = 0; i < 3; i++) tap_code16(KC_GRV);
	set_mods(mods);
      } else {
	tap_code16(KC_GRV);
      }
    }
    return false;
  case SEL_SRCH:
    if (isPressed) {
      if (is_mac_the_default()) {
	SEND_STRING(SS_LGUI("ct") SS_DELAY(100) SS_LGUI("v") SS_TAP(X_ENTER));
      } else {
	SEND_STRING(SS_LCTL("ct") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));
      }
    }
    return false;
  case ARROW:
    if (isPressed) {
      if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
	del_mods(MOD_MASK_SHIFT);
	del_oneshot_mods(MOD_MASK_SHIFT);
	SEND_STRING("=>");
	set_mods(mods);
      } else {
	SEND_STRING("->");
      }
    }
    return false;
  case KC_PSCR:
    send_mac_or_win(G(S(KC_4)), KC_PSCR, isPressed);
    return false;
  case LT_UP:
    if (isHeld) {
      tap_code16(C(KC_UP));
      return false;
    }
    return true;
  case LT(0,KC_BSLS):
    if (isHeld) {
      tap_code16(KC_HOME);
      return false;
    }
    return true;
  case LT(0,KC_BSPC):
    if (isHeld) {
      uint16_t code = is_mac_the_default() ? A(KC_BSPC) : C(KC_BSPC);
      tap_code16(code);
      return false;
    }
    return true;
  case LT(0,CT_PIPE):
    if (record->tap.count && isPressed) {
      tap_code16(S(KC_BSLS));
    } else if (isHeld) {
      tap_code16(KC_END);
    }
    return false;
  case MW_PSTE:
    send_mac_or_win(G(KC_V), C(KC_V), isPressed);
    return false;
  case MW_UNDO:
    send_mac_or_win(G(KC_Z), C(KC_Z), isPressed);
    return false;
  case MW_CUT:
    send_mac_or_win(G(KC_X), C(KC_X), isPressed);
    return false;
  case MW_COPY:
    send_mac_or_win(G(KC_C), C(KC_C), isPressed);
    return false;
  case CLS_WIN:
    send_mac_or_win(G(KC_W), C(KC_W), isPressed);
    return false;
  case MW_REDO:
    send_mac_or_win(G(S(KC_Z)), C(KC_Y), isPressed);
    return false;
  }
  return true;
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode) {
  case HOME_R:
    return TAPPING_TERM + 200;
  case HOME_T:
    return TAPPING_TERM + 200;
  case HOME_N:
    return TAPPING_TERM + 200;
  case HOME_E:
    return TAPPING_TERM + 200;
  case LT_UP:
    return TAPPING_TERM + 200;
  case MEH_SPC:
    return TAPPING_TERM + 60;
  case BSP_DWRD:
    return TAPPING_TERM + 60;
  default:
    return TAPPING_TERM;
  }
}
#endif
