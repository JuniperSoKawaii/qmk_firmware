#include QMK_KEYBOARD_H
#include "keymap_german.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTZ,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTZ = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwertz
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   +  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | AltGr| Alt  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTZ] = LAYOUT( \
  KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    KC_BSPC, \
  KC_ESC,  DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_PLUS, KC_ENT, \
  KC_LSFT, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT , \
  KC_LCTL, KC_LGUI, KC_ALGR, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   °  |   !  |   ?  |   §  |   €  |   ~  |   $  |   (  |   )  |   <  |   >  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |   &  |   @  |   {  |   }  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F5  |  F6  |  F7  |  F8  |   |  |   %  |   /  |   \  |   '  |   "  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  | F10  |  F11 |  F12 |             | Prev | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  DE_CIRC, DE_EXLM, DE_QST, DE_PARA, DE_EURO,  DE_TILD,  DE_DLR, DE_LPRN, DE_RPRN, DE_LESS, DE_MORE, KC_BSPC, \
   KC_DEL,   KC_F1,  KC_F2,   KC_F3,   KC_F4,  DE_AMPR,   DE_AT, DE_LCBR, DE_RCBR, DE_LBRC, DE_RBRC,  KC_ENT, \
  KC_LSFT,   KC_F5,  KC_F6,   KC_F7,   KC_F8,  DE_PIPE, DE_PERC, DE_SLSH, DE_BSLS, DE_QUOT, DE_DQOT, KC_RSFT, \
  KC_LCTL,   KC_F9, KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   /  |   7  |   8  |   9  |   *  |      |      |      |   #  |  Alt |   `  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   4  |   5  |   6  |   -  | Pos1 |  End |   ä  |   ö  |   ü  |   ß  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   1  |   2  |   3  |   +  |PageUp|PageDn|      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   .  |  0   |   =  | Enter|             | Prev | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  DE_SLSH,    KC_7,    KC_8,    KC_9, DE_ASTR, _______, _______, _______, DE_HASH, KC_LALT, DE_ACUT, KC_BSPC, \
   KC_DEL,    KC_4,    KC_5,    KC_6, DE_MINS, KC_HOME,  KC_END,   DE_AE,   DE_OE,   DE_UE,   DE_SS,  KC_ENT, \
  KC_LSFT,    KC_1,    KC_2,    KC_3, DE_PLUS, KC_PGUP, KC_PGDN, _______, _______, _______, _______, KC_LSFT, \
  _______,  DE_DOT,    KC_0,  DE_EQL,  KC_ENT, _______, _______, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwertz|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
   KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24, \
  _______, _______, _______,   AU_ON,  AU_OFF, AG_NORM, AG_SWAP,  QWERTZ, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

#ifdef AUDIO_ENABLE
float tone_qwertz[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTZ:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwertz);
        #endif
        persistent_default_layer_set(1UL<<_QWERTZ);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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
