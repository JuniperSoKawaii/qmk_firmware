/*
This is the keymap for the keyboard
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger
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
#include "drashna.h"



//enum more_custom_keycodes {
//    KC_P00 = NEW_SAFE_RANGE
//};


//define layer change stuff for underglow indicator
bool skip_leds = false;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   = +  |  1 ! | 2 @  | 3 #  | 4 $  | 5 %  | TG(4)|           | TG(4)| 6 ^  | 7 &  |  8 * | 9 (  |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  | TG(3)|           |TG(3) |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Bksp  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ' "   |
 * |--------+------+------+------+------+------| TG(2)|           | TG(2)|------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  ? / | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | `/SYM|  ' " | LGUI |  [ { | ] }  |                                       | LEFT | DOWN |  UP  |RIGHT | SYMB |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,--------------.       ,--------------.
 *                                        |Alt/Ap|  Win  |       | Alt  |Ctl/Esc|
 *                                 ,------|------|-------|       |------+-------+------.
 *                                 |      |      | Home  |       | PgUp |       |      |
 *                                 | Space| Bksp |-------|       |------|  DEL  |Enter |
 *                                 |      |      | End   |       | PgDn |       |      |
 *                                 `---------------------'       `---------------------'
 */
  [_QWERTY] = LAYOUT_ergodox_pretty_wrapper(
        // left hand                                                                       // right hand
<<<<<<< HEAD
             KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    OSL(_MOUS),           OSL(_MOUS), KC_6,    KC_7,    KC_8,    KC_9,     KC_0,   KC_MINS,
=======
             KC_EQL,  ________________NUMBER_LEFT________________, _______,                 _______, ________________NUMBER_RIGHT_______________, KC_MINS,
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36
             KC_TAB,  _________________QWERTY_L1_________________, TG(_DIABLO),         TG(_DIABLO), _________________QWERTY_R1_________________, KC_BSLS,
           TG(_MODS), _________________QWERTY_L2_________________,                                   _________________QWERTY_R2_________________, GUI_T(KC_QUOT),
             KC_MLSF, _________________QWERTY_L3_________________, TG(_GAMEPAD),       TG(_GAMEPAD), _________________QWERTY_R3_________________, KC_MRSF,
<<<<<<< HEAD
    LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
                                                    ALT_T(KC_APP), KC_LGUI,                 KC_RGUI, CTL_T(KC_ESCAPE),
                                                                   KC_HOME,                 KC_PGUP,
                                                 KC_SPACE,KC_BSPC, KC_END,                  KC_PGDN, KC_DEL,  KC_ENTER


=======
             KC_GRV,  ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, KC_CCCV,
                                                    __________________ERGODOX_THUMB_CLUSTER_____________________
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  |  L1  |           |  L1  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |O / L2|   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_COLEMAK] = LAYOUT_ergodox_pretty_wrapper(
        // left hand                                                                       // right hand
             KC_EQL,  ________________NUMBER_LEFT________________, _______,                 _______, ________________NUMBER_RIGHT_______________, KC_MINS,
             KC_TAB,  _________________COLEMAK_L1________________, TG(_DIABLO),         TG(_DIABLO), _________________COLEMAK_R1________________, KC_BSLS,
           TG(_MODS), _________________COLEMAK_L2________________,                                   _________________COLEMAK_R2________________, GUI_T(KC_QUOT),
             KC_MLSF, _________________COLEMAK_L3________________, TG(_GAMEPAD),       TG(_GAMEPAD), _________________COLEMAK_R3________________, KC_MRSF,
<<<<<<< HEAD
    LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
                                                    ALT_T(KC_APP), KC_LGUI,                 KC_RGUI, CTL_T(KC_ESCAPE),
                                                                   KC_HOME,                 KC_PGUP,
                                                 KC_SPACE,KC_BSPC, KC_END,                  KC_PGDN, KC_DEL,  KC_ENTER
=======
             KC_GRV,  ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, KC_CCCV,
                                                    __________________ERGODOX_THUMB_CLUSTER_____________________
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   \    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  L1  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |S / L2|   -    |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |:/Ctrl|   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |Z/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_DVORAK] = LAYOUT_ergodox_pretty_wrapper(
        // left hand        // right hand
             KC_EQL,  ________________NUMBER_LEFT________________, _______,                 _______, ________________NUMBER_RIGHT_______________, KC_BSLS,
             KC_TAB,  _________________DVORAK_L1_________________, TG(_DIABLO),         TG(_DIABLO), _________________DVORAK_R1_________________, KC_SLSH,
           TG(_MODS), _________________DVORAK_L2_________________,                                   _________________DVORAK_R2_________________, GUI_T(KC_MINS),
             KC_MLSF, _________________DVORAK_L3_________________, TG(_GAMEPAD),       TG(_GAMEPAD), _________________DVORAK_R3_________________, KC_MRSF,
<<<<<<< HEAD
    LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
                                                    ALT_T(KC_APP), KC_LGUI,                 KC_RGUI, CTL_T(KC_ESCAPE),
                                                                   KC_HOME,                 KC_PGUP,
                                                 KC_SPACE,KC_BSPC, KC_END,                  KC_PGDN, KC_DEL,  KC_ENTER
=======
             KC_GRV,  ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, KC_CCCV,
                                                    __________________ERGODOX_THUMB_CLUSTER_____________________
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36
    ),
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   D  |   R  |   W  |   B  |  L1  |           |  L1  |   J  |   F  |   U  |   P  |   ;  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   H  |   T  |   D  |------|           |------|   Y  |   N  |   E  |   O  |   I  |   '    |
 * |--------+------+------+------+------+------| OVER |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   M  |   C  |   V  |      |           |      |   K  |   L  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_WORKMAN] = LAYOUT_ergodox_pretty_wrapper(
        // left hand
             KC_EQL,  ________________NUMBER_LEFT________________, _______,                 _______, ________________NUMBER_RIGHT_______________, KC_MINS,
             KC_TAB,  _________________WORKMAN_L1________________, TG(_DIABLO),         TG(_DIABLO), _________________WORKMAN_R1________________, KC_BSLS,
           TG(_MODS), _________________WORKMAN_L2________________,                                   _________________WORKMAN_R2________________, GUI_T(KC_QUOT),
             KC_MLSF, _________________WORKMAN_L3________________, TG(_GAMEPAD),       TG(_GAMEPAD), _________________WORKMAN_R3________________, KC_MRSF,
<<<<<<< HEAD
    LT(_SYMB,KC_GRV), ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, TT(_SYMB),
                                                    ALT_T(KC_APP), KC_LGUI,                 KC_RGUI, CTL_T(KC_ESCAPE),
                                                                   KC_HOME,                 KC_PGUP,
                                                 KC_SPACE,KC_BSPC, KC_END,                  KC_PGDN, KC_DEL,  KC_ENTER
    ),

  [_MODS] = LAYOUT_ergodox_pretty(
=======
             KC_GRV,  ___________ERGODOX_BOTTOM_LEFT_____________,                                   ___________ERGODOX_BOTTOM_RIGHT____________, KC_CCCV,
                                                    __________________ERGODOX_THUMB_CLUSTER_____________________
    ),

// Reverts OSM(Shift) to normal Shifts. However, may not need since we fixed the issue with RDP (LOCAL RESOURCES)
  [_MODS] = LAYOUT_ergodox_pretty_wrapper(
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36
             _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, _______,                                   _______, _______, _______, _______, _______, _______,
             KC_LSFT, _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______, KC_RSFT,
             _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                                          _______, _______,                 _______, _______,
                                                                   _______,                 _______,
                                                 _______, _______, _______,                 _______, _______, _______
            ),

<<<<<<< HEAD
    /* Keymap 3: Symbol Layer
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* |   ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |   F11  |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* | VERSION|   !  |   @  |  {   |   }  |  |   |      |           |      |  +   |   7  |   8  |   9  |  *   |   F12  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  MAKE  |   #  |   $  |  (   |   )  |  `   |------|           |------|  -   |   4  |   5  |   6  |  /   | PrtSc  |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* |  RESET |   %  |   ^  |  [   |   ]  |  ~   |      |           |      | NUM  |   1  |   2  |   3  |  =   |  PAUSE |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   |  LT0 |   &  |   *  |  :   |   ;  |                                       |      |   0  | NUM. | ENT  |  ENT |
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,-------------.
*                                        | RGBM | RED  |       | OFF  | SOLID|
*                                 ,------|------|------|       |------+------+------.
*                                 |      |      | GREEN|       |      |      |      |
*                                 | RGB  | RGB  |------|       |------| NUM0 | NUME |
*                                 | DARK |BRITE | BLUE |       |      |      |      |
*                                 `--------------------'       `--------------------'
*/
  [_SYMB] = LAYOUT_ergodox_pretty(
             EPRM,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_QWERTY,             KC_QWERTY, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
            KC_RESET, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_WORKMAN,            KC_DVORAK, KC_PPLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, KC_F12,
             KC_MAKE, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRAVE,                                  KC_PMNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, KC_PSCREEN,
             VRSN,    KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_COLEMAK,           KC_COLEMAK, KC_NLCK, KC_KP_1, KC_KP_2, KC_KP_3, KC_PEQL, KC_PAUSE,
             KC_TRNS, KC_AMPR, KC_ASTR, KC_COLN, KC_SCLN,                                                     KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, KC_TRNS,
                                                          RGB_SMOD, KC_RGB_T,               KC_TRNS, KC_TRNS,
                                                                    RGB_HUI,                KC_TRNS,
                                                 RGB_M_R, RGB_M_SW, RGB_HUD,                KC_PDOT, KC_KP_0, KC_PENT
            ),
=======
>>>>>>> 73ddb764ccbe47662ba4604a18818f003abd8d36

/* Keymap 4: Customized Overwatch Layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |      |      |      |      |      |      |           |      |  F9  | F10  | F11  |  F12 |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   F1   |  K   |  Q   |  W   |  E   |  R   |  T   |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TAB  |  G   |  A   |  S   |  D   |  F   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCTR  | LSHFT|  Z   |  X   |  C   |  V   |      |           |      |   N  |  M   |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   J  |  U   |  I   |  Y   |  T   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  O   |  P   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LGUI |       |      |      |      |
 *                                 |  V   | SPACE|------        |------|      | Enter|
 *                                 |      |      |  H   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_GAMEPAD] = LAYOUT_ergodox_pretty_wrapper(
             KC_ESC,  KC_NO,   KC_1,    KC_2,    KC_3, HYPR(KC_Q), HYPR(KC_GRV),            KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,
             KC_F1,   KC_K,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_TAB,  KC_G,    KC_A,    KC_S,    KC_D,    KC_F,                                      KC_I,    KC_O,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_LCTL, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_TRNS,            TG(_GAMEPAD), KC_N,    KC_M,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
<<<<<<< HEAD
             KC_G,    KC_U,    KC_I,    KC_Y,    KC_T,                                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
=======
             KC_GRV,  KC_U,    KC_I,    KC_Y,    KC_T,                                                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
>>>>>>> 1225120b92411f4fa1a9dc79af2fd85bd5aa6dcc
                                                          KC_O,    KC_P,                    KC_HYPR, MAGIC_TOGGLE_NKRO,
                                                                   KC_LGUI,                 KC_NO,
                                                 KC_V,    KC_SPC,  KC_H,                    KC_PGDN, KC_DEL,  KC_ENTER
            ),

/* Keymap 3:
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  V   |  D   | ALT  |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |  S   |  I   |  F   |  M   |  T   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    Q   |  1   |  2   |  3   |  4   |  G   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | NUMLOCK| NUM1 | NUM2 | NUM3 | NUM4 |  Z   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | MAC1 | MAC2 | MAC3 | MAC4 |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   L  |  J   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  G   |       |      |      |      |
 *                                 | SPACE|  Q   |------        |------|      |      |
 *                                 | SHIFT| ALT  | 0MAC |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [_DIABLO] = LAYOUT_ergodox_pretty_wrapper(
             KC_ESC,  KC_V,    KC_D,    KC_LALT, KC_NO,   KC_NO,   KC_NO,                   KC_TRNS, KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_NO,   KC_NO,
             KC_TAB,  KC_S,    KC_I,    KC_F,    KC_M,    KC_T,    KC_TRNS,                 KC_TRNS, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_Q,    KC_1,    KC_2,    KC_3,    KC_4,    KC_G,                                      KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_LCTL, KC_D3_1, KC_D3_2, KC_D3_3, KC_D3_4, KC_Z,    KC_NO,                   KC_NO,   KC_N,    KC_M,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                             KC_L,    KC_J,                 KC_NO,   KC_NO,
                                                                      KC_F,                 KC_NO,
                          SFT_T(KC_SPACE),  ALT_T(KC_Q),   KC_DIABLO_CLEAR,                 KC_PGDN, KC_DEL,  KC_ENT
            ),

  [_LOWER] = LAYOUT_ergodox_pretty_wrapper(
             KC_F12,  _________________FUNC_LEFT_________________, _______,                 _______, _________________FUNC_RIGHT________________, KC_F11,
             KC_TILD, _________________LOWER_L1__________________, _______,                 _______, _________________LOWER_R1__________________, _______,
             _______, ___________________BLANK___________________,                                   _________________LOWER_R2__________________, KC_PIPE,
             _______, ___________________BLANK___________________, _______,                 _______, _________________LOWER_R3__________________, KC_PSCR,
             _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, KC_PAUS,
                                                          _______, _______,                 _______, _______,
                                                                   _______,                 _______,
                                                 _______, _______, _______,                 _______, _______, _______
            ),

  [_RAISE] = LAYOUT_ergodox_pretty_wrapper(
             KC_F12,  _________________FUNC_LEFT_________________, _______,                 _______, _________________FUNC_RIGHT________________, KC_F11,
             KC_GRV,  _________________RAISE_L1__________________, _______,                 _______, _________________RAISE_R1__________________, _______,
             _______, _________________RAISE_L2__________________,                                   _________________RAISE_R2__________________, KC_BSLS,
             _______, _________________RAISE_L3__________________, _______,                 _______, _________________RAISE_R3__________________, KC_PSCR,
             _______, _______, _______, _______, _______,                                                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_SLCK,
                                                          _______, _______,                 _______, _______,
                                                                   _______,                 _______,
                                                 _______, _______, _______,                 _______, _______, _______
            ),

  [_ADJUST] = LAYOUT_ergodox_pretty_wrapper(
             KC_MAKE, _______, _______, _______, _______, _______, _______,                 KC_NUKE, _________________ADJUST_R1_________________, KC_RST,
             VRSN,    _________________ADJUST_L1_________________, _______,                 _______, _______, _______, _______, _______, _______, EPRM,
             _______, _________________ADJUST_L2_________________,                                   _________________ADJUST_R2_________________, TG(_MODS),
             _______, _________________ADJUST_L3_________________, _______,                 _______, _________________ADJUST_R3_________________, KC_MPLY,
             _______, _______, _______, _______, _______,                                                     _______, _______, _______, _______, _______,
                                                          _______, _______,                 _______, _______,
                                                                   _______,                 _______,
                                                 _______, _______, _______,                 _______, _______, _______
            ),

};


bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

  //switch (keycode) {
  //  case KC_P00:
  //    if (!record->event.pressed) {
  //      register_code(KC_KP_0);
  //      unregister_code(KC_KP_0);
  //      register_code(KC_KP_0);
  //      unregister_code(KC_KP_0);
  //    }
  //    return false;
  //    break;
  //}
  return true;
}



void matrix_init_keymap(void) { // Runs boot tasks for keyboard
};


void matrix_scan_keymap(void) {  // runs frequently to update info
  uint8_t modifiders = get_mods();
  uint8_t led_usb_state = host_keyboard_leds();
  uint8_t one_shot = get_oneshot_mods();

  if (!skip_leds) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Since we're not using the LEDs here for layer indication anymore,
    // then lets use them for modifier indicators.  Shame we don't have 4...
    // Also, no "else", since we want to know each, independently.
    if (modifiders & MODS_SHIFT_MASK || led_usb_state & (1<<USB_LED_CAPS_LOCK) || one_shot & MODS_SHIFT_MASK) {
      ergodox_right_led_2_on();
      ergodox_right_led_2_set( 10 );
    }
    if (modifiders & MODS_CTRL_MASK || one_shot & MODS_CTRL_MASK) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set( 10 );
    }
    if (modifiders & MODS_ALT_MASK || one_shot & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
      ergodox_right_led_3_set( 10 );
    }

  }

};


bool indicator_is_this_led_used_keyboard(uint8_t index) {
  switch (index) {
    case 13 ... 14:
      return true;
      break;
    default:
    return false;
  }
}

