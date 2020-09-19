#include "railroad.h"

#define LSHFDEL LSFT_T(KC_DEL)
#define LSACALC LSA_T(KC_CALC)
#define RALTHOM RALT_T(KC_HOME)
#define RCTLEND RCTL_T(KC_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

KEYMAP(
/* Left Block */
   KC_ESC ,KC_PAUS,KC_ESC, KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,  
   KC_SLCK,KC_BSLS,    KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
   KC_CAPS,      KC_LCTL,          KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_PGUP,
   KC_CUT,   KC_LSFT,              KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_PGDN,
   KC_COPY,KC_PSTE,  KC_LCTL,    KC_LGUI,  KC_LALT,    KC_GRV,   KC_SPC,     LSHFDEL,
/* Center Block */
   KC_F1,  KC_F5,  KC_F9,  
   KC_F2,  KC_F6,  KC_F10,  
   KC_F3,  KC_F7,  KC_F11,  
   KC_F4,  KC_F8,  KC_F12,  
/* Right Block */
   KC_EQL, KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_BSPC,         KC_INS, KC_PSCR,  
   KC_RBRC,KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,     KC_DEL, /*   ISO */   
   KC_HOME,KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,  KC_ENT,      KC_ENT,    
   KC_END ,KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,          KC_UP,  
 LSACALC,  KC_NUBS,    KC_NUHS,  RALTHOM,    RCTLEND,       KC_LEFT,KC_DOWN,KC_RGHT 
  )

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    //keyevent_t event = record->event;

    switch (id) {

    }
    return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

void led_set_user(uint8_t usb_led) {

    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_COMPOSE)) {
        
    } else {
        
    }

    if (usb_led & (1 << USB_LED_KANA)) {
        
    } else {
        
    }

}