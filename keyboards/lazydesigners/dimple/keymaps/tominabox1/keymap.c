/* Copyright 2019 Erovia
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
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base COLEMAK layer
 * ,---------------------------------------------------------------.
 * |GEsc| Q  | W  | F  | P  | G  | J  | L  | U  | Y  | :  |  Bspc  |
 * |---------------------------------------------------------------|
 * |Tab-Ctl| A  | R  | S  | T  | D  | H  | N  | E  | I  | O  |Quote|
 * |---------------------------------------------------------------|
 * |Shft/Cap| Z  | X  | C  | V  | B  | K  | M  | ,  | Up |    .    |
 * |---------------------------------------------------------------|
 *      |Ctrl|Gui |Alt | Spc/Lwr |   Spc/Rse   |Left|Down|Rght|
 *      `-----------------------------------------------------'
 */

	[_BASE] = LAYOUT_wrapper(
    __________________DIMPLE1__________________,
    __________________DIMPLE2__________________,
		__________________DIMPLE3L_________________,__________________DIMPLE3R_________________,
		__________________DIMPLE4__________________
	),

/* Lower Symbol Layer
 * ,---------------------------------------------------------------.
 * | ~  | !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  |   Del  |
 * |---------------------------------------------------------------|
 * | Del  |    |    |    |    |    |    | _  | +  | {  | }  |  |   |
 * |---------------------------------------------------------------|
 * |        |    |    |    |    |    |    |    | ;  |PgUp|   ?     |
 * |---------------------------------------------------------------|
 *      |   |    |    |         |              |Home|PgDn|End |
 *      `-----------------------------------------------------'
 */

	[_LOWER] = LAYOUT_wrapper(
		_________________LOWER_1___________________,
    _________________LOWER_2___________________,
		_________________LOWER_3___________________,
		_________________LOWER_4___________________
	),

/* Raise Number Layer
 * ,---------------------------------------------------------------.
 * | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |   Bspc |
 * |---------------------------------------------------------------|
 * | Ins  |    |    |    |    |    |    | -  | =  | [  | ]  |  \   |
 * |---------------------------------------------------------------|
 * |        |    |    |    |    |    |    |    |    |  . |   /     |
 * |---------------------------------------------------------------|
 *      |VolD|Mute|VolU|         |             |    |    |    |
 *      `-----------------------------------------------------'
 */

	[_RAISE] = LAYOUT_wrapper(
	___________________RAISE1__________________,
	___________________RAISE2__________________,
	___________________RAISE3__________________,
	___________________RAISE4__________________

	),

/*  Adjust Layer
 * ,---------------------------------------------------------------.
 * |RST |EEP |    |    |    |    |    |    |    |    |    |        |
 * |---------------------------------------------------------------|
 * | MP   |    |    |    |    |    |    |    |    |    |    |      |
 * |---------------------------------------------------------------|
 * | MODE   | HUI| HUD|M_SN|    |    |    |    |    |    |         |
 * |---------------------------------------------------------------|
 *      |RGB-|RGB |RGB+|         |             |    |    |    |
 *      `-----------------------------------------------------'
 */

	[_ADJUST] = LAYOUT_wrapper(
	___________________ADJST1__________________,
	___________________ADJST2__________________,
	___________________ADJST3__________________,
 	___________________ADJST4__________________

  ),
/* Fkey Layer
* ,---------------------------------------------------------------.
* |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10|        |
* |---------------------------------------------------------------|
* |      |    |    |    |    |    |    |    |    | F11| F12|      |
* |---------------------------------------------------------------|
* |        |    |    |    |    |    |    |    |    |    |         |
* |---------------------------------------------------------------|
*      |    |    |    |         |             |FKEY|    |    |
*      `-----------------------------------------------------'
*/

  [_FKEY] = LAYOUT_wrapper(
	___________________FKEY1___________________,
	___________________FKEY2___________________,
	___________________FKEY3___________________,
	___________________FKEY4___________________
  ),
};

void led_set_user(uint8_t usb_led) {
if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
	dimple_led_off();
	} else {
	dimple_led_on();
	}
}
