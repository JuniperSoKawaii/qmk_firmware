 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
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
#include "enums.h"
#include "oled.h"
#include "process_record_user.h"

//#include "keymap_us_international.h"
//#include "sendstring_us_international.h"

extern uint8_t is_master;




// Layer quick names
#define LOWER MO(_LOWER)
#define UPPER MO(_UPPER)
#define MOD   TG(_MOD)
#define GAME  TG(_GAME)

// Key quick names
#define QC_AT   S(KC_2)     // @
#define QC_EUR  ALGR(KC_5)  // €
#define QC_SS   ALGR(KC_S)  // ß
#define QC_SECT S(ALGR(KC_S))    // §
#define QC_DEG  S(ALGR(KC_SCLN)) // °
#define QC_HAT  S(KC_6)  // ^

#define QC_UNDO LCTL(KC_Z)
#define QC_REDO LCTL(KC_Y)
#define QC_CTLX LCTL(KC_X)
#define QC_CTLC LCTL(KC_C)
#define QC_CTLV LCTL(KC_V)
#define GMESCN  LSFT(KC_F11)
#define CTALDEL LCTL(LALT(KC_DEL))  // CTRL+ALT+DEL
#define WINSCNS SGUI(KC_S)          // WIN+SHIFT+S

//HOME Row Modifiers
// Left-hand home row mods
#define GUI_S LGUI_T(KC_S)
#define ALT_D LALT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define ALT_K LALT_T(KC_K)
#define GUI_L RGUI_T(KC_L)


// Custom Keycodes / Keys  https://docs.qmk.fm/#/custom_quantum_functions?id=defining-a-new-keycode
enum custom_keycodes {
    CC_AE = SAFE_RANGE,
    CC_OE,
    CC_UE,
    CC_BckDel,
    CC_SLH,
    CC_QUOT,
    CC_APHO,
    CC_SCOLN,
    CC_COLN,
    CC_EXLM,
    CC_SAVRGB,
};

// Animation Speeds
//const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};
const uint8_t RGBLED_SNAKE_INTERVALS[] PROGMEM = {200, 150, 100};


#ifdef RGBLIGHT_LAYERS

 // Lightning Layers as status indicators. -> Array of segments
const rgblight_segment_t PROGMEM mod_indicator[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_GREEN}   // First segment: Turn on 5 LEDs starting with #4
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    mod_indicator   // 0
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;    // Enable the LED layers
}

// Callback when layer changes
layer_state_t layer_state_set_user(layer_state_t state) {
    // Set my_rgb_layer 0 when comparison is true (here: _MOD Layer active)
    rgblight_set_layer_state(0, layer_state_cmp(state, _MOD));
    return state;
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO UDATE IMAGES
/* QWERTY  
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |UPPER |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

//  [_QWERTY] = LAYOUT(
//   KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
//   KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
//   KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
//   KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
//                              KC_LALT, KC_LGUI,LOWER, KC_SPC,   KC_ENT,   UPPER,   KC_BSPC, KC_RGUI
// ),

[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                            KC_6,   KC_7,  KC_8,      KC_9,    KC_0,    CC_BckDel, 
  KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                            KC_Z,   KC_U,  KC_I,      KC_O,    KC_P,    CC_UE, 
  CC_QUOT,  KC_A,   GUI_S,  ALT_D,   CTL_F,   KC_G,                            KC_H,   CTL_J, ALT_K,     GUI_L,   CC_OE,   CC_AE, 
  CC_APHO,  KC_Y,   KC_X,   KC_C,    KC_V,     KC_B,  KC_MUTE,        _______, KC_N,   KC_M,  CC_SCOLN,  CC_COLN, CC_EXLM, KC_MINS, 
                            CC_SLH,  MOD,     LOWER, RSFT_T(KC_SPC), RSFT_T(KC_SPC),  UPPER,  KC_DEL,    KC_BSPC
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |UPPER |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
// [_LOWER] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
//   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//   KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
//   _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//                              _______, _______, _______, _______, _______,  _______, _______, _______
// ),

[_LOWER] = LAYOUT(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11, 
  _______,  XXXXXXX, WINSCNS, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_F12, 
  XXXXXXX,  KC_LGUI, QC_CTLX, QC_CTLC, QC_CTLV, XXXXXXX,                    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT,  KC_PGDN, XXXXXXX, 
  XXXXXXX,  KC_RGUI, KC_RSFT, KC_RALT, KC_RCTL, _______, _______, _______,  XXXXXXX, KC_BSPC, KC_DEL,  XXXXXXX,  XXXXXXX, KC_PENT, 
                              _______, _______, _______, _______, _______,  _______, _______, _______
),


/* UPPER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |UPPER |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

// [_UPPER] = LAYOUT(
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
//   KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
//   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
//                              _______, _______, _______,  _______, _______,  _______, _______, _______
// ),

[_UPPER] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,                     _______,  _______,  _______,  _______, _______, _______, 
  _______,  QC_AT,    KC_TILD,  QC_EUR,   KC_PSCR,  _______,                     KC_PAST,  KC_PPLS,  KC_LCBR,  KC_RCBR, QC_DEG, _______,
  XXXXXXX,  XXXXXXX,  QC_SS,    QC_UNDO,  QC_REDO,  CTALDEL,                     QC_HAT,   KC_PEQL,  KC_LPRN,  KC_RPRN, KC_LT,   KC_GT, 
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, _______, _______,   KC_PSLS,  KC_PMNS,  KC_LBRC,  KC_RBRC, KC_PIPE, KC_PENT,
                                _______,  _______,  _______, _______, _______,   _______,  _______,  _______
),

/* MOD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |UPPER |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
//   [_MOD] = LAYOUT(
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
//   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
//                              _______, _______, _______, _______, _______,  _______, _______, _______
//   )

  [_MOD] = LAYOUT(
  RGB_TOG,  RGB_M_P,  RGB_M_B,  RGB_M_SW, RGB_M_G,  RGB_M_SN,                      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  GAME, 
  RGB_MOD,  RGB_SAI,  RGB_SPI,  XXXXXXX,  XXXXXXX,  RGB_M_T,                       KC_PAST,  KC_P7,    KC_P8,    KC_P9,    KC_PPLS,  KC_PEQL,
  XXXXXXX,  RGB_SAD,  RGB_SPD,  XXXXXXX,  XXXXXXX,  XXXXXXX,                       KC_PSLS,  KC_P4,    KC_P5,    KC_P6,    KC_PMNS,  KC_PERC, 
  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_NUM,   XXXXXXX, CC_SAVRGB,  _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  KC_PENT, 
                                 XXXXXXX, _______,  _______, _______,    _______,  _______,  _______, _______
),

  [_GAME] = LAYOUT(
  KC_ESC,  KC_1,  KC_2,  KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,   KC_0,     GAME, 
  KC_TAB,  KC_Q,  KC_W,  KC_E,    KC_R,    KC_T,                     KC_Z,    KC_U,    KC_I,    KC_O,   KC_P,     KC_PGUP, 
  KC_LSFT, KC_A,  KC_S,  KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,   KC_GRV,   KC_PGDN, 
  KC_LCTL, KC_Y,  KC_X,  KC_C,    KC_V,    KC_B,   GMESCN,   KC_F12, KC_N,    KC_M,    KC_LEFT, KC_UP,  KC_RIGHT, KC_DOWN, 
                         KC_CAPS, KC_LALT, KC_SPC, KC_SPC,   KC_ENT, _______, _______, _______
)

};


// --------------------------------------------------------------------------------

// Rotary encoder related code
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {             // Encoder on master side
    if (IS_LAYER_ON(_MOD))          // _MOD LAYER
    {
        if ( get_mods() & MOD_MASK_SHIFT ) {
            if (clockwise) {
                rgblight_increase_sat_noeeprom();
            } else {
                rgblight_decrease_sat_noeeprom();
            }
        }
        else {
            if (clockwise) {
                rgblight_increase_hue_noeeprom();
            } else {
                rgblight_decrease_hue_noeeprom();
            }
        }
    }
    else {                          // _QWERTY LAYER and others
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
  }
  else if (index == 1) {        // Encoder on slave side
    if(IS_LAYER_ON(_LOWER)) {       // _LOWER LAYER
      if (clockwise) {
        tap_code(KC_PGDN);
      } else {
        tap_code(KC_PGUP);
      }
    }
    else if (IS_LAYER_ON(_MOD))     // _MOD LAYER
    {
        if ( get_mods() & MOD_MASK_SHIFT ) {
            if (clockwise) {
                rgblight_increase_speed_noeeprom();
            } else {
                rgblight_decrease_speed_noeeprom();
            }
        } else {
            if (clockwise) {
                rgblight_increase_val_noeeprom();
            } else {
                rgblight_decrease_val_noeeprom();
            }
        }
    }
    else {                          // _QWERTY LAYER and others
      if (clockwise) {
          tap_code(KC_DOWN);
      } else {
          tap_code(KC_UP);    
      }
    }
  }
  return true;
}
#endif  // ENCODER_ENABLE
