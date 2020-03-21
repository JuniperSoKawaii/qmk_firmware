#include QMK_KEYBOARD_H

/* 
 *  This keymap is for the split Plus and split 0 layout focusing on the "00" key.
 */

enum custom_keycodes {
  DBL_ZRO = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DBL_ZRO:
      if (record->event.pressed) {
        // when keycode DBL_ZRO is pressed
        SEND_STRING("00");
      } else {
        // when keycode DBL_ZRO is released
      }
      break;

  }
  return true;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Layer 0
 		* ,-------------------.
 		* |Mute|Vol-|Vol+| FN |
 		* |----|----|----|----|
 		* |Tab | /  | *  | BS |
 		* |----|----|----|----|
 		* | 7  | 8  | 9  | -  |
 		* |----|----|----|----|
 		* | 4  | 5  | 6  | +  |
 		* |----|----|----|----|
 		* | 1  | 2  | 3  |    |
 		* |----|----|----| En |
 		* | 00 | 0  | .  |    |
 		* `-------------------'
 		*/
        [0] = LAYOUT_numpad_6x4_split_plus_zero(
        	KC_MUTE, KC_VOLD, KC_VOLU, TT(2), 
        	KC_TAB, KC_PSLS, KC_PAST, KC_BSPC, 
        	KC_P7, KC_P8, KC_P9, KC_PMNS, 
        	KC_P4, KC_P5, KC_P6, KC_PPLS, 
        	KC_P1, KC_P2, KC_P3,
        	DBL_ZRO, KC_P0, KC_PDOT, KC_PENT
        ),
        
        [1] = LAYOUT_numpad_6x4_split_plus_zero(
        	RGB_TOG, RGB_RMOD, RGB_MOD, KC_TRNS, 
        	KC_NO, RGB_SPD, RGB_SPI, KC_NO, 
        	RGB_M_G, RGB_M_SW, RGB_M_K, RGB_M_SN, 
        	RGB_M_X, RGB_M_R, RGB_M_P, RGB_M_B, 
        	RGB_HUI, RGB_SAI, RGB_VAI, 
        	RGB_HUD, RGB_SAD, RGB_VAD, RESET
        ),
        
        [2] = LAYOUT_numpad_6x4_split_plus_zero(
        	KC_MPLY, KC_MPRV, KC_MNXT, TO(0), 
        	KC_F13, KC_F14, KC_F15, KC_F16, 
        	KC_F17, KC_F18, KC_F19, KC_F20, 
        	KC_F21, KC_F22, KC_F23, KC_F24, 
        	KC_NO, KC_NO, KC_NO,
        	KC_WAKE, KC_CALC, KC_NO, RESET
        )
};
