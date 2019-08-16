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

/* modified by Gun Pinyo */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  LY_0000, LY_0001, LY_0010, LY_0011,
  LY_0100, LY_0101, LY_0110, LY_0111,
  LY_1000, LY_1001, LY_1010, LY_1011,
  LY_1100, LY_1101, LY_1110, LY_1111,
  LY_SANDBOX, LY_RELAX, LY_THAI_A, LY_THAI_B, LY_THAI_C,
};

enum planck_keycodes {
  FN_A = SAFE_RANGE,
  FN_B,
  FN_C,
  FN_D,
  SANDBOX,
  RELAX,
  THAI_A,
  THAI_B,
  THAI_C,
  RESET_CONF,
  OS_LINUX,
  OS_WIN,
  OS_OSX,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

#define MFN_R1 XXXXXXX, KC_LEFT, KC_BSPC, KC_RGHT, KC_SPC,  KC_TAB
#define MFN_R2 XXXXXXX, THAI_A,  THAI_B,  THAI_C,  XXXXXXX, KC_ENT
#define MFN_R3 XXXXXXX, FN_A,    FN_B,    FN_C,    FN_D,    KC_LSFT
#define MFN_R4 RELAX, RESET_CONF, KC_APP, KC_LGUI, KC_LALT, KC_LCTL

#define UNUSED_LAYER {\
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MFN_R1},\
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MFN_R2},\
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MFN_R3},\
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MFN_R4}},

#define F1_F12_LAYER(M){\
 {S(M(KC_F7 )),S(M(KC_F8 )),M(KC_F7 ),M(KC_F8 ),M(KC_F9 ),S(M(KC_F9 )),MFN_R1},\
 {S(M(KC_F4 )),S(M(KC_F5 )),M(KC_F4 ),M(KC_F5 ),M(KC_F6 ),S(M(KC_F6 )),MFN_R2},\
 {S(M(KC_F1 )),S(M(KC_F2 )),M(KC_F1 ),M(KC_F2 ),M(KC_F3 ),S(M(KC_F3 )),MFN_R3},\
 {S(M(KC_F10)),S(M(KC_F11)),M(KC_F10),M(KC_F11),M(KC_F12),S(M(KC_F12)),MFN_R4}},

#define MC(kc)  LCTL(kc)
#define MA(kc)  LALT(kc)
#define MG(kc)  LGUI(kc)
#define MSC(kc) LSFT(LCTL(kc))

#define XXX XXXXXXX

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LY_0000] = {
 {KC_DEL,  KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_K, KC_TAB},
 {KC_BSPC, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_ENT},
 {KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_M, FN_A, FN_B, FN_C, FN_D, KC_LSFT},
 {KC_LCTL, KC_LALT,    KC_PSCR,    KC_ESC,     KC_SPC,     KC_INS,     MFN_R4},
},
[LY_1000] = {
  {XXX, KC_PERC,  KC_QUES,  KC_EXLM,  KC_GRV,   XXXXXXX,  MFN_R1},
  {XXX, KC_AT,    KC_COMM,  KC_DOT,   KC_QUOT,  KC_EQL,   MFN_R2},
  {XXX, KC_DLR,   KC_SCLN,  KC_COLN,  KC_DQUO,  KC_UNDS,  MFN_R3},
  {XXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MFN_R4},
},
[LY_0010] = {
  {XXX, KC_AMPR,  KC_PIPE,  KC_TILD,  KC_CIRC,  XXXXXXX,  MFN_R1},
  {XXX, KC_LCBR,  KC_LBRC,  KC_LPRN,  KC_LT,    KC_SLSH,  MFN_R2},
  {XXX, KC_RCBR,  KC_RBRC,  KC_RPRN,  KC_GT,    KC_BSLS,  MFN_R3},
  {XXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MFN_R4},
},
[LY_1010] = {
  {XXX, KC_HASH,  KC_7,     KC_8,     KC_9,     XXXXXXX,  MFN_R1},
  {XXX, KC_ASTR,  KC_4,     KC_5,     KC_6,     KC_PLUS,  MFN_R2},
  {XXX, KC_0,     KC_1,     KC_2,     KC_3,     KC_MINS,  MFN_R3},
  {XXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  MFN_R4},
},
[LY_0100] = {
  {XXX, XXXXXXX,     KC_HOME,     KC_UP,     KC_END,      MC(KC_UP),   MFN_R1},
  {XXX, KC_PGUP,     KC_LEFT,     KC_DOWN,   KC_RGHT,     MC(KC_DOWN), MFN_R2},
  {XXX, KC_PGDN,     MC(KC_S),    MC(KC_A),  MC(KC_Z),    MSC(KC_Z),   MFN_R3},
  {XXX, XXXXXXX,     MC(KC_LEFT), MC(KC_F),  MC(KC_RGHT), XXXXXXX,     MFN_R4},
},
[LY_1100] = {
  {XXX, XXXXXXX,     S(KC_HOME),  S(KC_UP),  S(KC_END),   MSC(KC_UP),  MFN_R1},
  {XXX, S(KC_PGUP),  S(KC_LEFT),  S(KC_DOWN),S(KC_RGHT),  MSC(KC_DOWN),MFN_R2},
  {XXX, S(KC_PGDN),  MC(KC_X),    MC(KC_C),  MC(KC_V),    MC(KC_L),    MFN_R3},
  {XXX, XXXXXXX,     MSC(KC_LEFT),MC(KC_R),  MSC(KC_RGHT),XXXXXXX,     MFN_R4},
},
[LY_0110] = F1_F12_LAYER()
[LY_1110] = F1_F12_LAYER(MG)
[LY_1111] = {
  {XXXXXXX,    XXXXXXX,    KC_WH_L,  KC_MS_U,   KC_WH_R,   KC_ACL2,    MFN_R1},
  {KC_BRIU,    KC_WH_U,    KC_MS_L,  KC_MS_D,   KC_MS_R,   KC_ACL1,    MFN_R2},
  {KC_BRID,    KC_WH_D,    KC_VOLD,  KC_MUTE,   KC_VOLU,   KC_ACL0,    MFN_R3},
  {XXXXXXX,    KC_BTN4,    KC_BTN5,  KC_BTN3,   KC_BTN1,   KC_BTN2,    MFN_R4},
},
[LY_1101] = {
{KC_PWR,   KC_WAKE,  OS_WIN,    OS_LINUX,     OS_OSX,          RESET,   MFN_R1},
{KC_SLEP,  XXXXXXX,  SANDBOX,   KC_CAPS,      RELAX,           DEBUG,   MFN_R2},
{AU_ON, MU_ON,  DYN_REC_START1, XXXXXXX,      DYN_MACRO_PLAY2, RGB_TOG, MFN_R3},
{AU_OFF,MU_OFF, DYN_REC_START2, DYN_REC_STOP, DYN_MACRO_PLAY1, RGB_MOD, MFN_R4},
},
[LY_0101] = {
  {UC(L'ภ'),  UC(L'ฃ'),  UC(L'ข'),  UC(L'ฮ'),  UC(L'ฎ'),  UC(L'ฏ'),  MFN_R1},
  {UC(L'ถ'),  UC(L'จ'),  UC(L'ก'),  UC(L'อ'),  UC(L'ด'),  UC(L'ต'),  MFN_R2},
  {UC(L'ศ'),  UC(L'ษ'),  UC(L'ส'),  UC(L'ห'),  UC(L'บ'),  UC(L'ป'),  MFN_R3},
  {UC(L'ฯ'),  UC(L'ๆ'),  UC(L'ฐ'),  UC(L'ฉ'),  UC(L'ผ'),  UC(L'ฝ'),  MFN_R4},
},
[LY_0111] = {
  {UC(L'็'),  UC(L'์'),  UC(L'่'),  UC(L'้'),  UC(L'๊'), UC(L'๋'),   MFN_R1},
  {UC(L'โ'), UC(L'แ'), UC(L'เ'), UC(L'า'), UC(L'ั'), UC(L'ะ'),  MFN_R2},
  {UC(L'ใ'), UC(L'ไ'), UC(L'ิ'),  UC(L'ี'),  UC(L'ึ'), UC(L'ื'),   MFN_R3},
  {UC(L'ๅ'), UC(L'ฺ'),  UC(L'ํ'),  UC(L'ำ'), UC(L'ุ'), UC(L'ู'),   MFN_R4},
},
[LY_0011] = {
  {UC(L'ฌ'),  UC(L'ฅ'),  UC(L'ค'),  UC(L'ม'),  UC(L'ฤ'),  UC(L'ฦ'),  MFN_R1},
  {UC(L'ณ'),  UC(L'ว'),  UC(L'ง'),  UC(L'น'),  UC(L'ร'),  UC(L'ล'),  MFN_R2},
  {UC(L'ญ'),  UC(L'ธ'),  UC(L'ท'),  UC(L'ย'),  UC(L'ช'),  UC(L'ซ'),  MFN_R3},
  {UC(L'ฒ'),  UC(L'ฆ'),  UC(L'ฑ'),  UC(L'ฬ'),  UC(L'พ'),  UC(L'ฟ'),  MFN_R4},
},
/* mapping from US QWERTY to TH Kedmanee */
[LY_THAI_A] = {
  {KC_4,     KC_BSLS,  KC_MINS,  S(KC_V),  S(KC_E),  S(KC_D),  MFN_R1},
  {KC_5,     KC_0,     KC_D,     KC_V,     KC_F,     KC_9,     MFN_R2},
  {S(KC_L),  S(KC_K),  KC_L,     KC_S,     KC_LBRC,  KC_X,     MFN_R3},
  {S(KC_O),  KC_Q,     KC_LCBR,  S(KC_C),  KC_Z,     KC_SLSH,  MFN_R4},
},
[LY_THAI_B] = {
  {S(KC_H),  S(KC_N),  KC_J,     KC_H,     S(KC_U),  S(KC_J),  MFN_R1},
  {S(KC_F),  KC_C,     KC_G,     KC_K,     KC_Y,     KC_T,     MFN_R2},
  {KC_DOT,   KC_W,     KC_B,     KC_U,     KC_7,     KC_N,     MFN_R3},
  {KC_1,     S(KC_B),  S(KC_Y),  KC_E,     KC_6,     KC_CIRC,  MFN_R4},
},
[LY_THAI_C] = {
  {S(KC_G),  KC_PIPE,  KC_8,     KC_COMM,  S(KC_A),  KC_QUES,  MFN_R1},
  {S(KC_I),  KC_SCLN,  KC_QUOT,  KC_O,     KC_I,     KC_RBRC,  MFN_R2},
  {S(KC_P),  S(KC_T),  KC_M,     KC_P,     KC_EQL,   KC_COLN,  MFN_R3},
  {KC_LT,    S(KC_S),  S(KC_R),  KC_GT,    KC_R,     KC_A,     MFN_R4},
},
[LY_0001] = UNUSED_LAYER
[LY_1001] = UNUSED_LAYER
[LY_1011] = UNUSED_LAYER
[LY_SANDBOX] = {
 {KC_LCBR, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_K, KC_RCBR},
 {KC_LPRN, KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_RPRN},
 {KC_LBRC,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_M,KC_COMM,KC_DOT,KC_SCLN,KC_COLN,KC_RBRC},
 {KC_LT  , KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GT},
},
[LY_RELAX] = {
{KC_DEL,  KC_SPC,  KC_HOME, KC_UP,   KC_END,  KC_F6,   MFN_R1},
{KC_BSPC, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_F5,   MFN_R2},
{KC_F7,   KC_PGDN, KC_F1,   KC_F2,   KC_F3,   KC_F4,   MFN_R3},
{KC_F8,   KC_F9,   KC_ESC,  KC_LCTL, KC_LSFT, KC_LALT, MFN_R4},
},
};

#ifdef AUDIO_ENABLE
  float tone_startup[][2]    = SONG(STARTUP_SOUND);
  float tone_goodbye[][2]    = SONG(GOODBYE_SOUND);

  float tone_ly_normal[][2]  = SONG(QWERTY_SOUND);
  float tone_ly_spacial[][2] = SONG(DVORAK_SOUND);

  float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

#ifdef RGB_MATRIX_ENABLE
  void rgb_matrix_indicators_kb(void) {
    // 42 is the index of the middle light at the bottom row (in planck light)
    // it is disabled because it does not have a cover, hence irritates my eyes
    rgb_matrix_set_color(42, 0, 0, 0);
  }
#endif

void startup_user() {
  _delay_ms(20); // gets rid of tick
  set_unicode_input_mode(UC_LNX);
#ifdef AUDIO_ENABLE
  PLAY_SONG(tone_startup);
#endif
}

void shutdown_user() {
#ifdef AUDIO_ENABLE
  PLAY_SONG(tone_goodbye);
  _delay_ms(150);
  stop_all_notes();
#endif
}

bool is_layer_persistant = false;

uint16_t cur_layer = 0;
void change_layer(uint16_t new_layer) {
  if(cur_layer != new_layer) {
    layer_off(cur_layer);
    layer_on(new_layer);
    cur_layer = new_layer;
  }
}

#define NUM_LANGS 2
#define LANG_ENG  0
#define LANG_THAI 1
uint16_t cur_lang = LANG_ENG;
void change_lang(uint16_t lang) {
  while(lang != cur_lang) {
    SEND_STRING(SS_LGUI(" "));
    cur_lang = (cur_lang + 1) % NUM_LANGS;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(!process_record_dynamic_macro(keycode, record))
    return false;

  if(!is_layer_persistant && FN_A <= keycode && keycode <= FN_D) {
    uint16_t mask = 1 << (3 - (keycode - FN_A));
    uint16_t cur_layer_code = cur_layer - LY_0000;
    if(!(cur_layer_code & mask) == record->event.pressed)
      change_layer((mask ^ cur_layer_code) + LY_0000);
    return false;
  }
  
  switch(keycode) {
    case OS_LINUX: set_unicode_input_mode(UC_LNX);      return false;
    case OS_WIN:   set_unicode_input_mode(UC_WINC);     return false;
    case OS_OSX:   set_unicode_input_mode(UC_OSX);      return false;

    case RESET_CONF:
      change_layer(LY_0000);
      change_lang(LANG_ENG);
      is_layer_persistant = false;
      return false;

    case SANDBOX:
      change_layer(LY_SANDBOX);
      change_lang(LANG_ENG);
      is_layer_persistant = true;
      return false;
      
    case RELAX:
      change_layer(LY_RELAX);
      change_lang(LANG_ENG);
      is_layer_persistant = true;
      return false;

    case THAI_A:
    case THAI_B:
    case THAI_C:
      if(is_layer_persistant) {
        change_layer(keycode - THAI_A + LY_THAI_A);
        change_lang(LANG_THAI);
        is_layer_persistant = true;
        return false;
      }

    case FN_A:
    case FN_B:
    case FN_C:
    case FN_D:
      if(is_layer_persistant) {
        switch(keycode) {
          case FN_A: change_layer(LY_1000); break;
          case FN_B: change_layer(LY_1010); break;
          case FN_C: change_layer(LY_0010); break;
          case FN_D: change_layer(LY_1111); break;        
        }
        change_lang(LANG_ENG);
        is_layer_persistant = true;
        return false;
      }
  }

  return true;
}
