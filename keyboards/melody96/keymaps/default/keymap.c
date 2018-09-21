#include "mehkee96.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0, default layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
| ESC*   |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |   F7   |   F8   |   F9   |  F10   |  F11   |  F12   | P SCN  |  HOME  |   END  |  P UP  | P DOWN |  DEL   |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        | BACK   |  NUM   |        |        |        |
|  ~`    |   1    |   2    |   3    |   4    |   5    |   6    |   7    |   8    |   9    |   0    |  _ -   | =  +   |   \    | SPACE  |  LOCK  |   /    |  *     |   -    |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |        |        |        |        |        |        |        |        |        |        |  [     |   ]    |             |        |        |        |        |
|    TAB     |   Q    |   W    |   E    |   R    |   T    |   Y    |   U    |   I    |   O    |   P    |  {     |   }    |  |   \      |   7    |   8    |   9    |   -    |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
|              |        |        |        |        |        |        |        |        |        |   ;    |   '    |                    |        |        |        |        |
|   CAPS LOCK  |   A    |   S    |   D    |   F    |   G    |   H    |   J    |   K    |   L    |   :    |   "    |       ENTER        |   4    |   5    |   6    |   +    |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |        |        |        |        |        |   ,    |    .   |   /    |                |        |        |        |        |        |
|  SHIFT  |  NUBS  |   Z    |   X    |   C    |   V    |   B    |   N    |   M    |   <    |    >   |   ?    |       SHIFT    |   UP   |   1    |   2    |   3    | ENTER  |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |   MO   |   MO   |        |        |        |        |        |        |
| CTRL     |   LGUI   | L ALT    |                      SPACE                             | R ALT  |  _FN   |  _FN   |  LEFT  |  DOWN  | RIGHT  |   0    |   .    | ENTER  |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
*/



	LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, KC_DEL,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   MO(1),   KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT, KC_PENT),



  /* Layer 1, function layer
____________________________________________________________________________________________________________________________________________________________________________
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |  VOL   |  VOL   |        |        |        |
| RESET  |        |        |        |        |        |        |        |        |        |        |        |        | MUTE   |  DOWN  |   UP   |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|________|
|            |  RGB   |        |  RGB   |  HUE   |  HUE   | SATUR. | SATUR. | VALUE  | VALUE  |        |        |        |             |        |        |        |        |
|            | TOGGLE |        |  MODE  |INCREASE| DCRSE  |INCREASE| DCRSE  |INCREASE| DCRSE  |        |        |        |             |        |        |        |        |
|____________|________|________|________|________|________|________|________|________|________|________|________|________|_____________|________|________|________|________|
| BACKLIGHT    |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
| TOGGLE       |        |        |        |        |        |        |        |        |        |        |        |                    |        |        |        |        |
|______________|________|________|________|________|________|________|________|________|________|________|________|____________________|________|________|________|________|
|         |        |        |        |BACKLHT |BACKLHT |BACKLHT |        |        |        |        |        |                |        |        |        |        |        |
|         |        |        |        | DCRSE  |TOGGLE  |INCREASE|        |        |        |        |        |                |        |        |        |        |        |
|_________|________|________|________|________|________|________|________|________|________|________|________|________________|________|________|________|________|________|
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|          |          |          |                                                        |        |        |        |        |        |        |        |        |        |
|__________|__________|__________|________________________________________________________|________|________|________|________|________|________|________|________|________|
BL_TOGG, BL_DEC, BL_INC changes the in-switch LEDs
*/


	LAYOUT(
    RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, RGB_TOG, _______, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______,          _______, _______, _______, _______,
    BL_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______,
    _______, _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______, _______, _______, _______),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
