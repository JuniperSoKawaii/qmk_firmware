/* Copyright 2019 @haswellep
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

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};


#define xxxx KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
	KC_ESC	,	KC_1	,	KC_2	,	KC_3	,	KC_4	,	KC_5	,					KC_6	,	KC_7	,	KC_8	,	KC_9	,	KC_0	,	KC_MINS	,	KC_EQL	,	KC_GRV	,	KC_BSPC	,	\
	KC_TAB	,	KC_Q	,	KC_W	,	KC_E	,	KC_R	,	KC_T	,					KC_Y	,	KC_U	,	KC_I	,	KC_O	,	KC_P	,	KC_LBRC	,	KC_RBRC	,			KC_BSLS	,	\
	KC_LCTL	,	KC_A	,	KC_S	,	KC_D	,	KC_F	,	KC_G	,					KC_H	,	KC_J	,	KC_K	,	KC_L	,	KC_SCLN	,	KC_QUOT	,					KC_ENT	,	\
	KC_LSFT	,	KC_Z	,	KC_X	,	KC_C	,	KC_V	,	KC_B	,	KC_DEL	,	KC_LGUI	,	KC_N	,	KC_M	,	KC_COMM	,	KC_DOT	,	KC_SLSH	,							KC_RSFT	,	\
							MO(_FN1)	,	KC_LALT	,	KC_SPC	,	CTL_T(KC_F13)	,	LSFT_T(KC_ENT)	,	LT(_FN2, KC_BSPC)	,	KC_RSFT	,	MO(_FN3)														\
 ),

[_FN1] = LAYOUT(
	_______	,	xxxx	,	KC_P7	,	KC_P8	,	KC_P9	,	KC_SLSH	,					KC_SLSH	,	KC_P7	,	KC_P8	,	KC_P9	,	_______	,	_______	,	_______	,	_______	,	_______	,	\
	_______	,	xxxx	,	KC_P4	,	KC_P5	,	KC_P6	,	KC_ASTR	,					KC_ASTR	,	KC_P4	,	KC_P5	,	KC_P6	,	_______	,	_______	,	_______	,			_______	,	\
	_______	,	xxxx	,	KC_P1	,	KC_P2	,	KC_P3	,	KC_MINUS	,					KC_MINUS	,	KC_P1	,	KC_P2	,	KC_P3	,	_______	,	_______	,					_______	,	\
	_______	,	KC_EQL	,	KC_COMM	,	KC_DOT	,	KC_P0	,	KC_PLUS	,	_______	,	KC_NLCK	,	KC_PLUS	,	KC_P0	,	KC_COMM	,	KC_DOT	,	_______	,							_______	,	\
							_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______														\
),

[_FN2] = LAYOUT(
	_______	,	KC_F1	,	KC_F2	,	KC_F3	,	KC_F4	,	KC_F5	,					KC_F6	,	KC_F7	,	KC_F8	,	KC_F9	,	KC_F10	,	KC_F11	,	KC_F12	,	KC_INS	,	A(KC_PSCR)	,	\
	_______	,	xxxx	,	xxxx	,	KC_UP	,	xxxx	,	xxxx	,					KC_PGDN	,	KC_PGUP	,	KC_UP	,	xxxx	,	xxxx	,	xxxx	,	KC_BRK	,			KC_PSCR	,	\
	_______	,	xxxx	,	KC_LEFT	,	KC_DOWN	,	KC_RIGHT	,	xxxx	,					xxxx	,	KC_LEFT	,	KC_DOWN	,	KC_RIGHT	,	xxxx	,	xxxx	,					_______	,	\
	_______	,	xxxx	,	KC_HOME	,	KC_DOWN	,	KC_END	,	xxxx	,	_______	,	xxxx	,	KC_HOME	,	KC_END	,	KC_DOWN	,	C(LWIN(KC_LEFT))	,	C(LWIN(KC_RIGHT))	,							_______	,	\
							TO(_FN1)	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______														\
),

[_FN3] = LAYOUT(
RESET	,	xxxx	,	RGB_TOG	,	RGB_MOD	,	RGB_RMOD	,	xxxx	,					xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	\
xxxx	,	xxxx	,	RGB_VAD	,	RGB_VAI	,	KC_ASON	,	KC_ASOFF	,					xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,			xxxx	,	\
xxxx	,	xxxx	,	RGB_SAD	,	RGB_SAI	,	KC_ASUP	,	KC_ASDN	,					xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,					xxxx	,	\
xxxx	,	xxxx	,	RGB_HUD	,	RGB_HUI	,	KC_ASRP	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,	xxxx	,							xxxx	,	\
						_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______														\
)


};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
  return true;}

void keyboard_post_init_user(void) {
 //   rgblight_enable_noeeprom();
 //   rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
#endif

}


