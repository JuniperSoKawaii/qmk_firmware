/*
Copyright 2021 MisonoWorks

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

enum layers {
    DEFAULT,
    META,
    SUPER,
	CALC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
    [DEFAULT] = LAYOUT(
		KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 						KC_P7, KC_P8, KC_P9, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT, 	     						KC_P4, KC_P5, KC_P6, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, 	     KC_UP, 				KC_P1, KC_P2, KC_P3, 
		KC_LCTL, KC_LALT, MO(META), KC_SPC, KC_BSPC, MO(SUPER), KC_LCTL, 	KC_LEFT, KC_DOWN, KC_RGHT,			   KC_P0, MO(CALC)),

    [META] = LAYOUT(
		KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE, 		            KC_7, KC_8, KC_9, 
		KC_TRNS, KC_GRAVE, KC_MINUS, KC_EQUAL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 		        KC_4, KC_5, KC_6, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLASH, KC_BSLASH,		  KC_PGUP,				KC_1, KC_2, KC_3, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		 KC_WBAK, KC_PGDN, KC_WFWD,		KC_0, KC_NLCK),
		
	[SUPER] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 			    RGB_MOD, RGB_RMOD, RGB_SAI, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_LBRC, KC_RBRC, 							RGB_HUI, RGB_HUD, RGB_SAD, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COMM, KC_DOT, 			  KC_UP, 			RGB_VAI, RGB_VAD, KC_3, 
		KC_APP, KC_LALT, KC_TRNS, KC_SPC, KC_BSPC, KC_TRNS, KC_MENU,		 KC_LEFT, KC_DOWN, KC_RGHT, 	KC_0, RGB_TOG),
		
	[CALC] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,			    KC_PSLS, KC_PAST, KC_PMNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 				  	 			KC_KP_DOT, KC_NO, KC_PPLS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     	      KC_UP, 			    KC_BSPC, KC_NO, KC_PENT, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,		 KC_LEFT, KC_DOWN, KC_RGHT, 		     KC_NLCK),
		
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
  static const char PROGMEM base_logo[] = {
// 'choccy oled base', 32x128px
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x8f, 0xff, 0x7f, 0x1f, 0x0f, 0x0f, 0x1f, 0x3f, 
0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x7c, 0x38, 0x08, 0x04, 0x02, 0x03, 0xe3, 0x98, 0x08, 0x08, 0x0c, 0x00, 0x00, 
0x00, 0x0c, 0x0c, 0x9e, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x00, 0x00, 
0x00, 0x61, 0x63, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x7f, 0x30, 0x20, 0x20, 0x30, 0x3f, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
0x38, 0x38, 0x38, 0x3c, 0x30, 0x20, 0x20, 0x30, 0x3f, 0x3e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfc, 0xbc, 0x14, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 
0x00, 0x04, 0x04, 0x04, 0x04, 0x14, 0xbc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x3b, 0x30, 0x00, 0x00, 0x04, 0x04, 0x04, 
0x04, 0x04, 0x00, 0x00, 0x00, 0x43, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc3, 0xc3, 0xc2, 0xc2, 0xc2, 0xc3, 0xc2, 0xc0, 0xc0, 
0xc2, 0xc3, 0xc2, 0xc2, 0xc2, 0x42, 0x43, 0xc0, 0x80, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xbf, 0xdf, 0xef, 0x67, 0x9b, 0x9d, 
0x6e, 0x75, 0xb3, 0xc5, 0xce, 0x57, 0xbb, 0xdc, 0xed, 0xf3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xed, 0xce, 0xb7, 0x3a, 0xdc, 0xe8, 0x73, 0xa3, 0xcd, 
0xee, 0xf6, 0xf9, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x87, 0x87, 0x87, 0x87, 0x87, 0x86, 0x86, 0x07, 0x07, 0x07, 
0x07, 0x07, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x9f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x9f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x9f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 
0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x08, 
0x08, 0x08, 0x08, 0x88, 0x88, 0x80, 0x80, 0x80, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x00, 0x80, 0xf8, 0xf8, 0x78, 0x18, 0x00, 0x00, 0x00, 
0x80, 0x88, 0x88, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0xf8, 0xf8, 0xfd, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 
0xff, 0xff, 0xf9, 0xf1, 0xf1, 0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const char PROGMEM num_logo[] = {
// 'choccy num', 32x128px
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x8f, 0xff, 0x7f, 0x1f, 0x0f, 0x0f, 0x1f, 0x3f, 
0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x7c, 0x38, 0x08, 0x04, 0x02, 0x03, 0xe3, 0x98, 0x08, 0x08, 0x0c, 0x00, 0x00, 
0x00, 0x0c, 0x0c, 0x9e, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0x01, 0x01, 0xff, 0x00, 0x00, 
0x00, 0x61, 0x63, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x7f, 0x30, 0x20, 0x20, 0x30, 0x3f, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 
0x38, 0x38, 0x38, 0x3c, 0x30, 0x20, 0x20, 0x30, 0x3f, 0x3e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xfc, 0xbc, 0x14, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 
0x00, 0x04, 0x04, 0x04, 0x04, 0x14, 0xbc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x3b, 0x30, 0x00, 0x00, 0x04, 0x04, 0x04, 
0x04, 0x04, 0x00, 0x00, 0x00, 0x43, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x80, 0xc3, 0xc3, 0xc2, 0xc2, 0xc2, 0xc3, 0xc2, 0xc0, 0xc0, 
0xc2, 0xc3, 0xc2, 0xc2, 0xc2, 0xc2, 0xc3, 0xc0, 0x80, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0xfc, 0xfc, 0xfc, 0x1c, 0x0c, 0x0c, 
0x0c, 0x0c, 0x1c, 0xfc, 0xfc, 0xfc, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x30, 
0x30, 0x3e, 0x3f, 0x3f, 0x3f, 0x3f, 0x00, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x07, 0x07, 0x07, 
0x07, 0x07, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x9f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x9f, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x9f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 
0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x88, 0x08, 
0x08, 0x08, 0x08, 0x88, 0x88, 0x80, 0x80, 0x80, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x3f, 0x03, 0x00, 0x00, 0x80, 0xf8, 0xf8, 0x78, 0x18, 0x00, 0x00, 0x00, 
0x80, 0x88, 0x88, 0x88, 0x88, 0x08, 0x08, 0x08, 0x08, 0xf8, 0xf8, 0xfd, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xfd, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 
0xff, 0xff, 0xf9, 0xf1, 0xf1, 0xf0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

  switch (get_highest_layer(layer_state)) {
    case DEFAULT:
    if (host_keyboard_led_state().num_lock) {
        oled_write_raw_P(num_logo, sizeof(num_logo));
    } else {
        oled_write_raw_P(base_logo, sizeof(base_logo));
    }
        break;
      default:
        oled_write_raw_P(base_logo, sizeof(base_logo));
    }
}
#endif