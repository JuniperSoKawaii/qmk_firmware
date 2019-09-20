/* Copyright 2019 @ninjonas
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
#include "ninjonas.h"		

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |     | Ctrl | /Space  /       \Enter \  |BackSP| Del  |LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT_wrapper(
	_____________________NUM_LEFT_______________________,                 _____________________NUM_RIGHT______________________,  \
	_____________________QWERTY_L1______________________,                 _____________________QWERTY_R1______________________,  \
	_____________________QWERTY_L2______________________,                 _____________________QWERTY_R2______________________,  \
	_____________________QWERTY_L3______________________, T_LBRC, T_RBRC, _____________________QWERTY_R3______________________,  \
                               ________MOD_LEFT_________, LT_RAI,   LT_LOW, ________MOD_RIGHT________ \
	),

/* DVORAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |                    |   F  |   G  |   C  |   R  |   L  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   O  |   E  |   U  |   I  |-------.    ,-------|   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   ;  |   Q  |   J  |   K  |   X  |-------|    |-------|   B  |   M  |   W  |   V  |   Z  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |     | Ctrl | /Space  /       \Enter \  |BackSP| Del  |LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_DVORAK] = LAYOUT_wrapper(
	_____________________NUM_LEFT_______________________,                 _____________________NUM_RIGHT______________________,  \
	_____________________DVORAK_L1______________________,                 _____________________DVORAK_R1______________________,  \
	_____________________DVORAK_L2______________________,                 _____________________DVORAK_R2______________________,  \
	_____________________DVORAK_L3______________________, T_LBRC, T_RBRC, _____________________DVORAK_R3______________________,  \
                               ________MOD_LEFT_________, LT_RAI,  LT_LOW, ________MOD_RIGHT________ \
	),

/* COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |   =  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  |     | Ctrl | /Space  /       \Enter \  |BackSP| Del  |LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_COLEMAK] = LAYOUT_wrapper(
	_____________________NUM_LEFT_______________________,                 _____________________NUM_RIGHT______________________,  \
	_____________________COLEMAK_L1_____________________,                 _____________________COLEMAK_R1_____________________,  \
	_____________________COLEMAK_L2_____________________,                 _____________________COLEMAK_R2_____________________,  \
	_____________________COLEMAK_L3_____________________, T_LBRC, T_RBRC, _____________________COLEMAK_R3_____________________,  \
                               ________MOD_LEFT_________, LT_RAI,  LT_LOW, ________MOD_RIGHT________ \
	),

/* LOWER
 * ,------------------------------------------.                    ,------------------------------------------.
 * | F11  |  F1  |  F2  |  F3   |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10  | F12  |
 * |------+------+------+-------+------+------|                    |------+------+------+------+-------+------|
 * |      |      |      |KC_BRIU| Play | Mute |                    | PgUp | Home |  Up  | End  |       |      |
 * |------+------+------+-------+------+------|                    |------+------+------+------+-------+------|
 * |      |      |      |KC_BRID| Next |VolUp |-------.    ,-------| PgDn | Left | Down |Right |K_LOCK |      |
 * |------+------+------+-------+------+------|       |    |       |------+------+------+------+-------+------|
 * |M_SHFT|      |      |       | Prev |VolDn |-------|    |-------|      |      |      |      |M_ZOOM |M_PYNV|
 * `------------------------------------------/       /     \      \------------------------------------------'
 *                    |      |      |      | /       /       \      \  |      |M_CODE|      |
 *                    |      |      |      |/       /         \      \ |      |      |      |
 *                    `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT_wrapper( \
	_____________________FUNC_LEFT______________________,                     _____________________FUNC_RIGHT_____________________, \
	_______, _______, _________MEDIA_1_________, _______,                     _______________NAV_1______________, _______, _______, \
	_______, _______, _________MEDIA_2_________, _______,                     _______________NAV_2______________, K_LOCK,  _______, \
	M_SHFT,  _______, _________MEDIA_3_________, _______, _______,   _______, _______, _______, _______, _______, M_ZOOM,  M_PYNV, \
	                           __________________________________,   _______, _______, M_CODE,  _______ \
	),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |K_CSCN|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MS_1 | MS_U | MS_2 | WH_U |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MS_L | MS_D | MS_R | WH_D |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT_wrapper( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   K_CSCN, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,  XXXXXXX, _____________MOUSE_1______________,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,  XXXXXXX, _____________MOUSE_2______________,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             __________________________________,      __________________________________ \
  ),

/* ADJUST
 * ,------------------------------------------.                    ,-----------------------------------------.
 * |EEP_RST|      |      |      |      |      |                    |      |      |      |COLMAK|DVORAK|QWERTY|
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |M_MAKE |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |M_VRSN |M_MALL|      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |M_FLSH |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `------------------------------------------/       /     \      \-----------------------------------------'
 *                    |      |      |      | /       /       \      \  |      |      |      |
 *                    |      |      |      |/       /         \      \ |      |      |      |
 *                    `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT_wrapper( \
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK,  DVORAK,  QWERTY, \
  M_MAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  M_VRSN, M_MALL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  M_FLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                            __________________________________,      __________________________________ \
  ),
};

// SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
extern uint8_t is_master;

void matrix_init_user(void) {
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    iota_gfx_init(!has_usb());   // turns on the display
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record); // Moved to process_records.h
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}