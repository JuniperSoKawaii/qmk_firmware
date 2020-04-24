#include QMK_KEYBOARD_H


bool is_alt_tab_active = false;    
uint16_t alt_tab_timer = 0;       

enum custom_keycodes {            
  ALT_TAB = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {              
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {     
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LAYER 0
     * ,-----------------------.
     * |   <<  |  MUTE |  >>   |  ENCODER - PRESS (MUTE) / KNOB (VOLUME CONTROL)
     * |-------+-------+-------|
     * |  STOP |  PLAY | MEDIA |
     * |-------+-------+-------|
     * | CALC  | MAIL  | PC/FN |
     * `-----------------------'
     */

    [0] = LAYOUT(
      LCA(KC_M), LT(2, LCA(KC_G)), LCA(KC_Q), 
      LCA(KC_R), LCA(KC_C), LCA(KC_B),
      LT(3,LCA(KC_N)), LCA(KC_K), LT(1, KC_MYCM)
      ),


    /* LAYER 1
     * ,-----------------------.
     * | MODE+ |RGB TOG| MODE- |  ENCODER - PRESS (NA) / KNOB (Hue Control)
     * |-------+-------+-------|
     * |  SPD- |  SPD+ |Bright |
     * |-------+-------+-------|
     * |  SAT+ |  SAT- |       |
     * `-----------------------'
     */
    
    [1] = LAYOUT(
      RGB_TOG, RGB_TOG, RGB_RMOD, 
      RGB_SPI, RGB_SPD, RGB_VAI, 
      RGB_SAI, RGB_SAD, KC_TRNS
      ),

      
    /* LAYER 2 (ENCODER)
     * ,-----------------------.
     * |       |       |       |  ENCODER - PRESS (NA) / KNOB (Arrow Left/Right)
     * |-------+-------+-------|
     * |       |       |       |
     * |-------+-------+-------|
     * |       |       |       |
     * `-----------------------'
     */
    
    [2] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS
      )

    /* LAYER 3 (Layers)
     * ,-----------------------.
     * |       |       |       |  ENCODER - PRESS (NA) / KNOB (Arrow Left/Right)
     * |-------+-------+-------|
     * |       |       |       |
     * |-------+-------+-------|
     * |       |       |       |
     * `-----------------------'
     */
    
    [2] = LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS, 
      KC_TRNS, KC_TRNS, KC_TRNS
      )



};

void encoder_update_user(uint8_t index, bool clockwise) {
    
  switch (biton32(layer_state)) {
      case 1: //Layer 2 Encoder
          if (clockwise) {
              rgblight_increase_hue();
          } else {
              rgblight_decrease_hue();
          }
          break;
      case 2: //Layer 1 Encoder
          if (clockwise) {
              tap_code(KC_RGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;


      default: //Layer 0 Encoder
          if (clockwise) {
              
              tap_code16(LALT(S(KC_TAB)));


          } else {
              tap_code16(ALT_TAB);
  
          }
          break;

  }
}
