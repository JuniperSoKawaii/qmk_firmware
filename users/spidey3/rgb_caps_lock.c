#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;

uint32_t rgb_mode;
uint16_t rgb_hue;
uint8_t rgb_sat;
uint8_t rgb_val;
bool rgb_saved = 0;

void matrix_init_user_rgb(void)
{
  rgb_mode = rgblight_config.mode;
  rgb_hue = rgblight_config.hue;
  rgb_sat = rgblight_config.sat;
  rgb_val = rgblight_config.val;
  rgb_saved = 1;

#ifdef CONSOLE_ENABLE
  uprintf("matrix_init_user: Saved mode: %u, hue: %u, sat: %u, val: %u\n", rgb_mode, rgb_hue, rgb_sat, rgb_val);
#endif 
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    rgb_mode = rgblight_get_mode();

    rgb_hue = rgblight_get_hue();
    rgb_sat = rgblight_get_sat();
    rgb_val = rgblight_get_val();
    rgb_saved = 1;

    rgblight_mode_noeeprom(1);
    rgblight_setrgb(0xD3, 0x7F, 0xED);

#ifdef CONSOLE_ENABLE
    if (debug_enable) { uprintf("CAPS_LOCK ON: Saved mode: %u, hue: %u, sat: %u, val: %u\n", rgb_mode, rgb_hue, rgb_sat, rgb_val); }
#endif 

  } else if (rgb_saved) {
    rgblight_mode(rgb_mode);
    rgblight_sethsv(rgb_hue, rgb_sat, rgb_val);
    rgb_saved = 0;

#ifdef CONSOLE_ENABLE
    if (debug_enable) { uprintf("CAPS_LOCK OFF: Restored mode: %u, hue: %u, sat: %u, val: %u\n", rgb_mode, rgb_hue, rgb_sat, rgb_val); }
#endif 
  }
}
