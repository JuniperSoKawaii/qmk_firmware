#include QMK_KEYBOARD_H
#include "rgb_matrix_user.h"

enum alt_keycodes {
  L_BRI = SAFE_RANGE, //LED Brightness Increase
  L_BRD,              //LED Brightness Decrease
  L_PTN,              //LED Pattern Select Next
  L_PTP,              //LED Pattern Select Previous
  L_PSI,              //LED Pattern Speed Increase
  L_PSD,              //LED Pattern Speed Decrease
  L_T_MD,             //LED Toggle Mode
  L_T_ONF,            //LED Toggle On / Off
  L_ON,               //LED On
  L_OFF,              //LED Off
  L_T_BR,             //LED Toggle Breath Effect
  L_T_PTD,            //LED Toggle Scrolling Pattern Direction
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode
#define ______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [1] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
    _______, _______, _______,  KC_UP,  _______, _______, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______, _______, _______, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,          KC_VOLU, _______, \
    _______, _______, _______,                            KC_MPLY,                              MO(2), _______, KC_MRWD, KC_VOLD, KC_MFFD  \
  ),
  [2] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    L_T_BR,  L_PSD,   L_BRI,   L_PSI,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    L_T_PTD, L_PTP,   L_BRD,   L_PTN,   _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, L_T_MD,  L_T_ONF, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
  ),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  rgb_matrix_record_key_press(record);

  switch (keycode) {
    case L_BRI:
      if (record->event.pressed) {
        if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
        else gcr_desired += LED_GCR_STEP;
        if (led_animation_breathing) gcr_breathe = gcr_desired;
      }
      return false;
    case L_BRD:
      if (record->event.pressed) {
        if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
        else gcr_desired -= LED_GCR_STEP;
        if (led_animation_breathing) gcr_breathe = gcr_desired;
      }
      return false;
    case L_PTN:
      if (record->event.pressed) {
        if (led_animation_id == led_setups_count - 1) led_animation_id = 0;
        else led_animation_id++;
      }
      return false;
    case L_PTP:
      if (record->event.pressed) {
        if (led_animation_id == 0) led_animation_id = led_setups_count - 1;
        else led_animation_id--;
      }
      return false;
    case L_PSI:
      if (record->event.pressed) {
        led_animation_speed += ANIMATION_SPEED_STEP;
      }
      return false;
    case L_PSD:
      if (record->event.pressed) {
        led_animation_speed -= ANIMATION_SPEED_STEP;
        if (led_animation_speed < 0) led_animation_speed = 0;
      }
      return false;
    case L_T_MD:
      if (record->event.pressed) {
        led_lighting_mode++;
        if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
      }
      return false;
    case L_T_ONF:
      if (record->event.pressed) {
        led_enabled = !led_enabled;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_ON:
      if (record->event.pressed) {
        led_enabled = 1;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_OFF:
      if (record->event.pressed) {
        led_enabled = 0;
        I2C3733_Control_Set(led_enabled);
      }
      return false;
    case L_T_BR:
      if (record->event.pressed) {
        led_animation_breathing = !led_animation_breathing;
        if (led_animation_breathing) {
          gcr_breathe = gcr_desired;
          led_animation_breathe_cur = BREATHE_MIN_STEP;
          breathe_dir = 1;
        }
      }
      return false;
    case L_T_PTD:
      if (record->event.pressed) {
        led_animation_direction = !led_animation_direction;
      }
      return false;
    default:
      return true; //Process all other keycodes normally
  }
}
