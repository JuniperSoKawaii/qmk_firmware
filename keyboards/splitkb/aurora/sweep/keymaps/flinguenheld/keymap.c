/* Copyright 2023 FLinguenheld
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
#include <stdio.h>


enum layers {
    _BASE,
    _NUMERIC,
    _ARROWS,
    _MOUSE,
    _ADJUST,
    _FN,
};

enum custom_keys {
    UNICODE = SAFE_RANGE, // Shortcut to write unicodes, see numeric layer

    /* See auto-shift */
    CS_E_ACUTE,

    CS_A_GRAVE,
    CS_E_GRAVE,
    CS_I_GRAVE,
    CS_O_GRAVE,
    CS_U_GRAVE,

    CS_C_CEDILLA,
    CS_AE,
    CS_OE,

    CS_A_CIRCUMFLEX,
    CS_E_CIRCUMFLEX,
    CS_I_CIRCUMFLEX,
    CS_O_CIRCUMFLEX,
    CS_U_CIRCUMFLEX,

    CS_A_DIAERESIS,
    CS_E_DIAERESIS,
    CS_I_DIAERESIS,
    CS_O_DIAERESIS,
    CS_U_DIAERESIS,
    CS_Y_DIAERESIS,
};

/* Features */
#include "features/auto_shift.c"
#include "features/combo.c"
#include "features/leader.c"
#include "features/oled.c"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* Macros */
    switch (keycode) {

        case UNICODE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code16(KC_U);
            }else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LSFT);
            }
            break;
    }

    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
      GUI_T(KC_ESC) ,     KC_B      ,     KC_O      ,     KC_W      ,      KC_K     ,             KC_J      ,      KC_P     ,      KC_D     ,      KC_L     ,     KC_BSPC   ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
          KC_A      ,     KC_I      ,     KC_E      ,     KC_U      ,     KC_TAB    ,             KC_F      ,      KC_T     ,      KC_S     ,      KC_R     ,      KC_N     ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         KC_LALT    ,     KC_X      ,     KC_Q      ,     KC_Y      ,      KC_Z     ,             KC_V      ,      KC_C     ,      KC_G     ,      KC_H     ,      KC_M     ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                        LT(_MOUSE, KC_COMM)  ,        KC_LCPO          ,    LT(_NUMERIC, KC_ENT)   ,  LT(_ARROWS, KC_DOT)
  //                               |-------------------------+----/* Space ctl */------| |-------------------------+-------------------------|
  ),

  [_NUMERIC] = LAYOUT(
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         _______    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,     KC_7      ,     KC_8      ,     KC_9      ,    _______    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         _______    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,              KC_0     ,     KC_4      ,     KC_5      ,     KC_6      ,    XXXXXXX    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,     KC_1      ,     KC_2      ,     KC_3      ,    XXXXXXX    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                              XXXXXXX        ,         UNICODE         ,          _______          ,       XXXXXXX
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
  ),

  [_MOUSE] = LAYOUT(
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
      KC_MS_WH_LEFT ,  KC_MS_WH_UP  , KC_MS_WH_DOWN , KC_MS_WH_RIGHT,    XXXXXXX    ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    _______    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
        KC_MS_LEFT  ,   KC_MS_UP    ,  KC_MS_DOWN   ,  KC_MS_RIGHT  ,    XXXXXXX    ,            XXXXXXX    ,  KC_MS_ACCEL0 ,  KC_MS_ACCEL1 ,  KC_MS_ACCEL2 ,    XXXXXXX    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
        KC_MS_BTN1  ,    XXXXXXX    ,  KC_MS_BTN3   ,  KC_MS_BTN2   ,    XXXXXXX    ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                              XXXXXXX        ,        _______          ,         KC_MS_BTN1        ,       KC_MS_BTN2
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
  ),

  [_ARROWS] = LAYOUT(
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,    KC_HOME    ,  KC_PAGE_DOWN ,   KC_PAGE_UP  ,     KC_END    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,    KC_LEFT    ,    KC_DOWN    ,     KC_UP     ,    KC_RIGHT   ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,    XXXXXXX    ,    C(KC_D)    ,    C(KC_U)    ,    XXXXXXX    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                              XXXXXXX        ,        _______          ,           XXXXXXX         ,       XXXXXXX
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
  ),

  [_ADJUST] = LAYOUT(
  //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+---------------+-----------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,  KC_PRINT_SCREEN ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    , KC_AUDIO_VOL_UP ,
  //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+---------------+-----------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,S(KC_PRINT_SCREEN),            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,KC_AUDIO_VOL_DOWN,
  //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+---------------+-----------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,     XXXXXXX      ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,  KC_AUDIO_MUTE  ,
  //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+---------------+-----------------|
  //                                  |-------------------------+-------------------------| |-------------------------+-------------------------|
                                                 XXXXXXX        ,        _______          ,           XXXXXXX         ,       XXXXXXX
  //                                  |-------------------------+-------------------------| |-------------------------+-------------------------|
  ),

  [_FN] = LAYOUT(
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,     KC_F7     ,     KC_F8     ,     KC_F9     ,     KC_F10    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,     KC_F4     ,     KC_F5     ,     KC_F6     ,     KC_F11    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
         XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,            XXXXXXX    ,     KC_F1     ,     KC_F2     ,     KC_F3     ,     KC_F12    ,
  //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                              XXXXXXX        ,        _______          ,           XXXXXXX         ,       XXXXXXX
  //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
  ),
};
