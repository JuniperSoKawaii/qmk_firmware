/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_hungarian.h" 

enum preonic_layers {
  _QWERTY,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   Ö  |  Ü   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  Ő   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   É  |  Á   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  ALt |Lower |    Space    | Bksp | Enter|Raise | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  HU_0,                  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    HU_OE,   HU_UE, \
  KC_TAB,                KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    HU_Z,    KC_U,    KC_I,    KC_O,    KC_P,    HU_OEE,  \
  KC_ESC,                KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    HU_EE,   HU_AA, \
  MT(MOD_LSFT, KC_NUBS), HU_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    HU_COMM, HU_DOT,  HU_MINS, KC_RSFT,  \
  KC_LCTL,               KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  KC_ENT,  KC_BSPC, KC_RALT, RAISE,   KC_INS,  KC_DEL  \
),


/* Game
 * ,-----------------------------------------------------------------------------------.
 * |  0   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   Ö  |  Ü   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Z  |   U  |   I  |   O  |   P  |  Ő   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   É  |  Á   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Y  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   -  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  ALt |Raise |    Space    | Bksp | Enter|Lower | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_preonic_grid( \
  HU_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    HU_OE,   HU_UE, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    HU_Z,    KC_U,    KC_I,    KC_O,    KC_P,    HU_OEE,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    HU_EE,   HU_AA, \
  KC_LSFT, HU_Y,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    HU_COMM, HU_DOT,  HU_MINS, KC_RSFT,  \
  KC_LCTL, KC_LGUI, KC_LALT, RAISE,   KC_SPC,  KC_SPC,  KC_ENT,  KC_BSPC, KC_RALT, LOWER,   KC_INS,  KC_DEL  \
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      |      |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |   1  |   2  |   3  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Lnxcpy|Lnxpst|      |      |   0  |      |      |   /  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |PageDn|PageUp|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  _______, _______, _______, _______, _______, _______, _______, HU_7,    HU_8,    HU_9,    HU_PLUS,   _______, \
  _______, _______, KC_UP,   _______, _______, KC_HOME, KC_PGUP, HU_4,    HU_5,    HU_6,    HU_MINS,   _______,  \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_END,  KC_PGDN, HU_1,    HU_2,    HU_3,    HU_ASTR,   _______, \
  _______, _______, _______, _______, _______, _______, _______, HU_0,    _______, _______, HU_SLSH,   HU_EQL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_GAME), TO(_QWERTY)  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down | Right|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |PageDn|PageUp|  End |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11, \
  _______, _______, KC_UP,   _______, _______, KC_HOME, KC_PGUP, _______, _______, _______, _______,   _______,  \
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_END,  KC_PGDN, _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_GAME), TO(_QWERTY)  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, TO(_QWERTY)  \
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(STARTUP_SOUND); 
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_numpad[][2] = SONG(MARIO_THEME);
float tone_oneshot[][2] = SONG(MARIO_GAMEOVER);
float tone_dyn_macro_rec[][2] = SONG(ONE_UP_SOUND);
float tone_dyn_macro_stop[][2] = SONG(COIN_SOUND);
float music_scale[][2] = SONG(RICK_ROLL);
float tone_goodbye[][2] = SONG(TERMINAL_SOUND);
float tone_goodbye1[][2] = SONG(IMPERIAL_MARCH);
float tone_goodbye2[][2] = SONG(MARIO_MUSHROOM);
float tone_goodbye3[][2] = SONG(ZELDA_TREASURE);
float tone_goodbye4[][2] = SONG(ZELDA_PUZZLE);
float tone_goodbye5[][2] = SONG(E1M1_DOOM);
float tone_goodbye6[][2] = SONG(OVERWATCH_THEME);
float real_imp_mar[][2]    = {
  {NOTE_A4, 75}   ,{NOTE_REST, 25} ,{NOTE_A4, 75}   ,{NOTE_REST, 25} ,{NOTE_A4, 75}   ,{NOTE_REST, 25} ,
  {NOTE_F4, 75}   ,{NOTE_C5, 25}   ,{NOTE_A4, 75}   ,{NOTE_REST, 25} ,
  {NOTE_F4, 75}   ,{NOTE_C5, 25}   ,{NOTE_A4, 75}   ,{NOTE_REST, 25} ,
  {NOTE_REST, 30}
};

#endif



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
          }
          break;
        case LOWER:
          if (record->event.pressed) {
			#ifdef AUDIO_ENABLE
              PLAY_SONG(tone_goodbye);
            #endif
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
        case RAISE:
          if (record->event.pressed) {
			#ifdef AUDIO_ENABLE
              PLAY_SONG(tone_dyn_macro_rec);
            #endif
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE
void startup_user()
{
    PLAY_SONG(real_imp_mar);
}
void shutdown_user()
{
    PLAY_SONG(tone_oneshot);
    stop_all_notes();
}
void music_on_user(void)
{
    music_scale_user();
}
void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}
#endif
