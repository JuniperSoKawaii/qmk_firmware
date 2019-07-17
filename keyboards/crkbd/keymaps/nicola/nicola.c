#include QMK_KEYBOARD_H
#include "nicola.h"

static uint8_t ncl_chrcount = 0; // 文字キー入力のカウンタ (シフトキー含む)
static uint8_t ncl_keycount = 0; // シフトキーも含めた入力のカウンタ
static bool ncl_rshift = false; // 右シフトキーの状態
static bool ncl_lshift = false; // 左シフトキーの状態

// 文字入力バッファ
static uint16_t ninputs[5];

// NICOLA配列のテーブル
typedef struct {
  char t[4]; // 単独
  char l[4]; // 左シフト
  char r[4]; // 右シフト
} ncl_keymap;

// NICOLA on QWERTY
const ncl_keymap nmap[] = {
  [KC_Q]    = {.t = ".",  .l = "la",  .r = ""},
  [KC_W]    = {.t = "ka", .l = "e",   .r = "ga"},
  [KC_E]    = {.t = "ta", .l = "ri",  .r = "da"},
  [KC_R]    = {.t = "ko", .l = "lya", .r = "go"},
  [KC_T]    = {.t = "sa", .l = "re",  .r = "za"},

  [KC_Y]    = {.t = "ra", .l = "pa",  .r = "yo"},
  [KC_U]    = {.t = "ti", .l = "di",  .r = "ni"},
  [KC_I]    = {.t = "ku", .l = "gu",  .r = "ru"},
  [KC_O]    = {.t = "tu", .l = "du",  .r = "ma"},
  [KC_P]    = {.t = ",",  .l = "pi",  .r = "le"},

  [KC_A]    = {.t = "u",  .l = "wo",  .r = "vu"},
  [KC_S]    = {.t = "si", .l = "a",   .r = "zi"},
  [KC_D]    = {.t = "te", .l = "na",  .r = "de"},
  [KC_F]    = {.t = "ke", .l = "lyu", .r = "ge"},
  [KC_G]    = {.t = "se", .l = "mo",  .r = "ze"},

  [KC_H]    = {.t = "ha", .l = "ba",  .r = "mi"},
  [KC_J]    = {.t = "to", .l = "do",  .r = "o"},
  [KC_K]    = {.t = "ki", .l = "gi",  .r = "no"},
  [KC_L]    = {.t = "i",  .l = "po",  .r = "lyo"},
  [KC_SCLN] = {.t = "nn", .l = "",    .r = "ltu"},

  [KC_Z]    = {.t = ".",  .l = "lu",  .r = ""},
  [KC_X]    = {.t = "hi", .l = "-",   .r = "bi"},
  [KC_C]    = {.t = "su", .l = "ro",  .r = "zu"},
  [KC_V]    = {.t = "hu", .l = "ya",  .r = "bu"},
  [KC_B]    = {.t = "he", .l = "li",  .r = "be"},

  [KC_N]    = {.t = "me", .l = "pu",  .r = "nu"},
  [KC_M]    = {.t = "so", .l = "zo",  .r = "yu"},
  [KC_COMM] = {.t = "ne", .l = "pe",  .r = "mu"},
  [KC_DOT]  = {.t = "ho", .l = "bo",  .r = "wa"},
  [KC_SLSH] = {.t = "/",  .l = "?",    .r = "lo"},
};

// シフトキーの状態に応じて文字をPCへ送る
void ncl_type(void) {
  for (int i = 0; i < ncl_chrcount; i++) {
    if (ninputs[i] == 0) break;
    if (ncl_lshift) {
      send_string(nmap[ninputs[i]].l);
    } else if (ncl_rshift) {
      send_string(nmap[ninputs[i]].r);
    } else {
      send_string(nmap[ninputs[i]].t);
    }
  }
  ncl_clear();
}

// バッファをクリアする
void ncl_clear(void) {
  for (int i = 0; i < 5; i++) {
    ninputs[i] = 0;
  }
  ncl_chrcount = 0;
  ncl_keycount = 0;
  ncl_lshift = false;
  ncl_rshift = false;
}

bool process_nicola(uint16_t keycode, keyrecord_t *record, uint8_t ncl_layer, uint16_t lshiftkey, uint16_t rshiftkey, uint16_t modkeys[3]) {

  bool is_modifier = false;
  // modifierが押されているか
  switch (keycode) {
    case KC_LCTRL:
    case KC_LSHIFT:
    case KC_LALT:
    case KC_LGUI:
    case KC_RCTRL:
    case KC_RSHIFT:
    case KC_RALT:
    case KC_RGUI:
      if (record->event.pressed) {
        is_modifier = true;
      } else {
        is_modifier = false;
      }
      break;
  }
  for (int i = 0; i < 3; i++) {
    if (keycode == modkeys[i]) {
      if (record->event.pressed) {
        is_modifier = true;
      } else {
        is_modifier = false;
      }
    }
  }

  if (layer_state_is(ncl_layer) & !is_modifier) {

    if (record->event.pressed) {
      if (keycode == lshiftkey) {
        ncl_lshift = true;
        ncl_keycount++;
        if (ncl_keycount > 1) ncl_type();
        return false;
      } else if (keycode == rshiftkey) {
        ncl_rshift = true;
        ncl_keycount++;
        if (ncl_keycount > 1) ncl_type();
        return false;
      }
      switch (keycode) {
        case KC_A ... KC_Z: // 親指シフト処理するキー
        case KC_SLSH:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
          ninputs[ncl_chrcount] = keycode;
          ncl_chrcount++;
          ncl_keycount++;
          if (ncl_keycount > 1) ncl_type();
          return false;
          break;
        default: // 親指シフトに関係ないキー
          ncl_clear();
          return true;
          break;
      }

    } else { // key release
      if (keycode == lshiftkey) {
        ncl_lshift = false;
        if (ncl_keycount > 0) ncl_type();
        return false;
      } else if (keycode == rshiftkey) {
        ncl_rshift = false;
        if (ncl_keycount > 0) ncl_type();
        return false;
      }
      switch (keycode) {
        case KC_A ... KC_Z: // 親指シフト処理するキー
        case KC_SLSH:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
          if (ncl_keycount > 0) ncl_type();
          return false;
          break;
      }
    }
  }

  return true;
}