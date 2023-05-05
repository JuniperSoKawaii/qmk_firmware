// Copyright 2023 @miketronic -- Mike B <mxb540@gmail.com>
// SPDX-License-Identifier: GPL-2.0+

#include "miketronic.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* WORKMAN
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      || Macro01 || Macro02 || Macro03 || Macro04 || Macro05 || OS SHFT || LEADER  ||         || Macro06 || Macro07 || Macro08 || Macro09 || Macro10 || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | TAB/ESC  || Q       || D       || R       || W       || B  SYM  ||    7    ||    8    ||    9    || J  SYM  || F       || U       || P       || BSPC    || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | TAB/SHFT || A       || S       || H       || T EX    || G       ||    4    ||    5    ||    6    || Y       || N       || E       || O       || I       || ENTER   |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | LSHIFT   || Z       || X       || M       || C       || V       ||    1    ||  2   0  ||    3    || K       || L       || , SPC   || . SPC   ||SHFT/ENT || Up/Rght |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | FN       || LCTRL   || GUI     || LALT    || LOWER   || Space   || Space   || . Enter || Enter   || Enter   || RAISE   || SS      || CLIP    ||CopyPaste|| Dn/Left |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_WM] = LAYOUT_ortho_5x15_wrapper (
    _____________WORKMAN_ID75_TOP_L____________,  ________3KEY_ID75_01_________,  _____________WORKMAN_ID75_TOP_R____________,
    _____________WORKMAN_412_001_L_____________,  ________3KEY_ID75_02_________,  _____________WORKMAN_412_001_R_____________,
    _____________WORKMAN_412_002_L_____________,  ________3KEY_ID75_03_________,  _____________WORKMAN_412_002_R_____________,
    _____________WORKMAN_412_003_L_____________,  ________3KEY_ID75_04_________,  _____________WORKMAN_412_003_R_____________,
    _____________WORKMAN_ID75_BOT_L____________,  ________3KEY_ID75_05_________,  _____________WORKMAN_ID75_BOT_R____________
 ),   


 [_QW] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC,   _________________QWERTY_L1_________________,  ________3KEY_ID75_01_________,  _________________QWERTY_R1_________________,  KC_BSPC,
    KC_TAB,   _________________QWERTY_L1_________________,  ________3KEY_ID75_02_________,  _________________QWERTY_R1_________________,  BRACES,
    KC_LSFT,  _________________QWERTY_L2_________________,  ________3KEY_ID75_03_________,  _________________QWERTY_R2_________________,  KC_QUOT,
    FN,       _________________QWERTY_L3_________________,  ________3KEY_ID75_04_________,  _________________QWERTY_R3_________________,  TD_UR,
              _____________WORKMAN_ID75_BOT_L____________,  ________3KEY_ID75_05_________,  _____________WORKMAN_ID75_BOT_R____________
 ),



/* LOWER
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      || Macro01 || Macro02 || Macro03 || Macro04 || Macro05 || OS SHFT || LEADER  ||         || Macro06 || Macro07 || Macro08 || Macro09 || Macro10 || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          || ()      || []      || /\      ||         ||         ||    7    ||    8    ||    9    ||         || 7       || 8       || 9       ||         ||         |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          || @ #     || & %     ||         ||         ||         ||    4    ||    5    ||    6    ||         || 4       || 5       || 6       ||         ||         |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||         ||         ||         ||         ||         ||    1    ||  2   0  ||    3    || 0       || 1       || 2   0   || 3       ||         || Up/Rght |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||         ||         ||         ||         ||         || Space   || . Enter || Enter   ||         || BSPC    || SPC     || . Enter ||         || Dn/Left |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_LOWER] = LAYOUT_ortho_5x15_wrapper (
    _____________WORKMAN_ID75_TOP_L____________,  ________3KEY_ID75_01_________,  _____________WORKMAN_ID75_TOP_R____________,
    _______________LOWER_412_L1________________,  ________3KEY_ID75_02_________,  _______________LOWER_412_R1________________,
    _______________LOWER_412_L2________________,  ________3KEY_ID75_03_________,  _______________LOWER_412_R2________________,
    _______________LOWER_412_L3________________,  ________3KEY_ID75_04_________,  _______________LOWER_412_R3________________,
    _______________LOWER_412_L4________________,  ________3KEY_ID75_05_________,  _______________LOWER_412_R4________________
 ),



/* RAISE
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      || Macro01 || Macro02 || Macro03 || Macro04 || Macro05 || OS SHFT || LEADER  ||         || Macro06 || Macro07 || Macro08 || Macro09 || Macro10 || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | BOOT     || DEBUG   ||         ||         ||         || MAKE    ||    7    ||    8    ||    9    ||         ||         || F7      || F8      || F9      || F10     |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          || RGB TOG || RGB MOD || RGB HUI || RGB HUD ||         ||    4    ||    5    ||    6    ||         ||  / \    || F4      || F5      || F6      || F11     |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          || RGB SAI || RGB SAD || RGB VAI || RGB VAD ||         ||    1    ||  2   0  ||    3    ||         || _   -   || F1      || F2      || F3      || F12     |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||         ||         ||         ||         ||         || Space   || . Enter || Enter   ||         || RAISE   ||         ||         ||         ||         |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_RAISE] = LAYOUT_ortho_5x15_wrapper ( 
    _____________WORKMAN_ID75_TOP_L____________,  ________3KEY_ID75_01_________,  _____________WORKMAN_ID75_TOP_R____________,
    _______________RAISE_412_L1________________,  ________3KEY_ID75_02_________,  _______________RAISE_412_R1________________,
    _______________RAISE_412_L2________________,  ________3KEY_ID75_03_________,  _______________RAISE_412_R2________________,
    _______________RAISE_412_L3________________,  ________3KEY_ID75_04_________,  _______________RAISE_412_R3________________,
    _________________BLANK_6___________________,  ________3KEY_ID75_05_________,  _________________BLANK_6___________________
 ),



/* EXTRAS
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      || Macro01 || Macro02 || Macro03 || Macro04 || Macro05 || OS SHFT || LEADER  ||         || Macro06 || Macro07 || Macro08 || Macro09 || Macro10 || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||   !     ||         ||         ||         ||         ||    7    ||    8    ||    9    ||         ||   /\    ||   ()    ||   []    ||    ;    ||         |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |  SHIFT   ||         ||         ||         || EXTRAS  ||         ||    4    ||    5    ||    6    ||         ||  @ #    ||  & %    ||         ||    '    ||         |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||         ||         ||         ||         ||         ||    1    ||  2   0  ||    3    ||         ||         || ,       || .       ||    ?    || Up/Rght |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||         ||         ||         ||         ||         || Space   || . Enter || Enter   ||         ||         ||         ||         ||         ||         |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_EX] = LAYOUT_ortho_5x15_wrapper ( 
    _____________WORKMAN_ID75_TOP_L____________,  ________3KEY_ID75_01_________,  _____________WORKMAN_ID75_TOP_R____________,
    ______________EXTRAS_412_L1________________,  ________3KEY_ID75_02_________,  ______________EXTRAS_412_R1________________,
    ______________EXTRAS_412_L2________________,  ________3KEY_ID75_03_________,  ______________EXTRAS_412_R2________________,
    ______________EXTRAS_412_L3________________,  ________3KEY_ID75_04_________,  ______________EXTRAS_412_R3________________,
    ______________EXTRAS_412_L4________________,  ________3KEY_ID75_05_________,  ______________EXTRAS_412_R4________________
 ),


/* FUNCTION (_FN)
 * .--------------------------------------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC      || Macro01 || Macro02 || Macro03 || Macro04 || Macro05 || OS SHFT || LEADER  ||         || Macro06 || Macro07 || Macro08 || Macro09 || Macro10 || BSPC    |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | TAB      ||Macro 09 ||Macro 10 ||Macro 11 ||Macro 12 ||         ||    7    ||    8    ||    9    ||         ||   / \   ||   UP    ||         ||         || DEL     |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * | TAB SHFT ||Macro 05 ||Macro 06 ||Macro 07 ||Macro 08 ||         ||    4    ||    5    ||    6    ||         ||  LEFT   ||  DOWN   ||  RIGHT  ||         ||         |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||Macro 01 ||Macro 02 ||Macro 03 ||Macro 04 ||         ||    1    ||  2   0  ||    3    ||         ||         ||    ,    ||    .    ||    ?    || UP RIGHT|
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          ||  RGB1   ||  RGB2   ||  RGB3   ||  RBG4   ||         || Space   || . Enter || Enter   ||         ||         ||         ||         ||         || DN LEFT |
 * '--------------------------------------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FN] = LAYOUT_ortho_5x15_wrapper (
    _____________WORKMAN_ID75_TOP_L____________,  ________3KEY_ID75_01_________,  ____________FUNCTION_ID75_TOP_R____________,
    _____________FUNCTION_412_L1_______________,  ________3KEY_ID75_02_________,  _____________FUNCTION_412_L1_______________,
    _____________FUNCTION_412_L2_______________,  ________3KEY_ID75_03_________,  _____________FUNCTION_412_L2_______________,
    _____________FUNCTION_412_L3_______________,  ________3KEY_ID75_04_________,  _____________FUNCTION_412_L3_______________,
    _____________FUNCTION_412_L4_______________,  ________3KEY_ID75_05_________,  _____________FUNCTION_412_L4_______________
 ),



  /* SYMBOLS
  * ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
  * │     |  $  |  ^  |  <  |  >  │ SYMB│   │ SYMB│  |  |  [  |  ]  |  -  |     |
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────╆━━━━━╅─────┤   ├─────╆━━━━━╅─────┼─────┼─────┼─────┤
  * │     |  %  |  :  |  ;  ┃  +  ┃  =  │   │     ┃     ┃  (  |  )  |  _  |     |
  * │     │     │     │     ┃     ┃     │   │     ┃     ┃     │     │     │     │
  * ├─────┼─────┼─────┼─────╄━━━━━╃─────┤   ├─────╄━━━━━╃─────┼─────┼─────┼─────┤
  * |     |  &  |  '  |  "  |  *  |  #  │   │  !  |  ?  |  /  |  \  |  @  |     | 
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * │     │     │     │     │     │     │   │     │     │     │     │     │     │
  * └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
  */

  [_SYMB] = LAYOUT_ortho_5x15_wrapper (
    KC_ESC,  _______,   _______,  _______,  _______,  _______, ________3KEY_ID75_01_________, RGB1,     RGB2,     RGB3,      RGB4,     RGB5,     KC_DEL,
    _______,  KC_DLR,   KC_CIRC,  KC_LABK,  KC_RABK,  _______, ________3KEY_ID75_02_________, _______,  KC_PIPE,  KC_LBRC,   KC_RBRC,  KC_MINS,  _______,
    _______,  KC_PERC,  KC_COLN,  KC_SCLN,  KC_PLUS,  KC_EQL,  ________3KEY_ID75_03_________, _______, _______,   KC_LPRN,   KC_RPRN,  KC_UNDS,  _______,
    _______,  KC_AMPR,  KC_QUOT,  KC_DQUO,  KC_ASTR,  KC_HASH, ________3KEY_ID75_04_________,  KC_EXLM, KC_QUES,  KC_SLSH,   KC_BSLS,  KC_AT,    _______,
    _________________BLANK_6___________________,               ________3KEY_ID75_05_________,  _________________BLANK_6___________________
 ),


};

#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2] = SONG(RICK_ROLL);
#endif

void matrix_scan_user(void);

void leader_start_user(void) {
#ifdef AUDIO_ENABLE
    PLAY_SONG(leader_start_song);
#endif
}

bool did_leader_succeed;

void leader_end_user(void) {
    did_leader_succeed = false;

    if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(SS_LCTL(SS_LSFT("t")));
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(KC_E, KC_D)) {
        SEND_STRING(SS_LGUI("r") "cmd\n" SS_LCTL("c"));
        did_leader_succeed = true;    
    } else if (leader_sequence_two_keys(KC_A, KC_T)) {
        SEND_STRING("@guidehouse.com");
        did_leader_succeed = true;
    }


#ifdef AUDIO_ENABLE
    if (did_leader_succeed) {
        PLAY_SONG(leader_succeed_song);
    } else {
        PLAY_SONG(leader_fail_song);
    }
#endif
}