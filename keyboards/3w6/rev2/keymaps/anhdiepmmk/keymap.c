/*
Copyright 2021 weteor

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// home row mod
#define HO_A MT(MOD_LCTL, KC_A)
#define HO_R MT(MOD_LSFT, KC_R)
#define HO_S MT(MOD_LALT, KC_S)
#define HO_T MT(MOD_LGUI, KC_T)
#define HO_N MT(MOD_LGUI, KC_N)
#define HO_E MT(MOD_LALT, KC_E)
#define HO_I MT(MOD_LSFT, KC_I)
#define HO_O MT(MOD_LCTL, KC_O)

// thumb
#define TH_NAV LT(NAV, KC_TAB)
#define TH_NUM LT(NUM, KC_BSPC)
#define TH_SYM LT(SYM, KC_ENT)
#define TH_MED LT(MED, KC_ESC)
#define TH_FUN LT(FUN, KC_DEL)
#define TH_MOU LT(MOU, KC_SPC)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
  _BASE,
  _NAV,
  _NUM,
  _SYM,
  _MED,
  _FUN,
  _MOU,
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NAV,
  NUM,
  SYM,
  MED,
  FUN,
  MOU,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * BASE
  */
  [_BASE] = LAYOUT(
    KC_Q, KC_W, KC_F  , KC_P  , KC_B  ,      KC_J  , KC_L         , KC_U   , KC_Y  , HO_SCLN,
    HO_A, HO_R, HO_S  , HO_T  , KC_G  ,      KC_M  , HO_N         , HO_E   , HO_I  , HO_O   ,
    KC_X, KC_C, KC_D  , KC_V  , KC_Z  ,      KC_K  , LT(FUN, KC_H), KC_COMM, KC_DOT, KC_SLSH,
                TH_MED, TH_NAV, TH_MOU,      TH_SYM, TH_NUM       , TH_FUN
  ),

  /* 
  * NAV
  */
  [_NAV] = LAYOUT(
    KC_PAGE_UP  , KC_HOME, KC_UP  , KC_END  , _______,      _______, KC_HOME, _______, KC_END  , KC_PAGE_UP  ,
    KC_PAGE_DOWN, KC_LEFT, KC_DOWN, KC_RIGHT, _______,      KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_PAGE_DOWN,
    _______     , _______, _______, _______ , _______,      _______, _______, _______, _______ , _______     ,
                           _______, _______ , _______,      _______, _______, _______
  ),
  /* 
  * NUM
  */
  [_NUM] = LAYOUT(
    KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC,      _______, _______, _______, _______, _______,
    KC_QUOT, KC_4   , KC_5   , KC_6   , KC_EQL ,      _______, _______, _______, _______, _______,
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS,      _______, _______, _______, _______, _______,
                      KC_DOT , KC_0   , KC_MINS,      _______, _______, _______
  ),
  /* 
  * SYM
  */
  [_SYM] = LAYOUT(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,      _______, _______, _______, _______, _______,
    KC_DQT , KC_DLR , KC_PERC, KC_CIRC, KC_PLUS,      _______, _______, _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE,      _______, _______, _______, _______, _______,
                      KC_LPRN, KC_RPRN, KC_UNDS,      _______, _______, _______
  ),
  /*
  * MED
  */
  [_MED] =  LAYOUT(
    QK_BOOT, _______, _______, _______, _______,      _______, _______          , _______        , _______, _______,
    _______, _______, _______, _______, _______,      KC_MPRV, KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MNXT, _______,
    _______, _______, _______, _______, _______,      _______, _______          , _______        , _______, _______,
                      _______, _______, _______,      KC_MSTP, KC_MPLY          , KC_KB_MUTE     
  ),
  /* 
  * FUN
  */
  [_FUN] = LAYOUT(
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR,      _______, _______, _______, _______, _______,
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL,      _______, _______, _______, _______, _______,
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS,      _______, _______, _______, _______, _______,
                      _______, _______, _______,      _______, _______, _______ 
  ),
  /* 
  * MOU
  */
  [_MOU] = LAYOUT(
    _______, _______, _______, _______, _______,      _______      , _______      , _______    , _______       , _______,
    _______, _______, _______, _______, _______,      KC_MS_LEFT   , KC_MS_DOWN   , KC_MS_UP   , KC_MS_RIGHT   , _______,
    _______, _______, _______, _______, _______,      KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, _______, 
                      _______, _______, _______,      KC_MS_BTN1   , KC_MS_BTN2   , KC_MS_BTN3
  ),
};
