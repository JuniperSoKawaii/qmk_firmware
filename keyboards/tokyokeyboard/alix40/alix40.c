#include "alix40.h"

void matrix_init_kb(void) {
  // Keyboard start-up code goes here
  // Runs once when the firmware starts up
  matrix_init_user();
  led_init_ports();
};

void matrix_scan_kb(void) {
  // Looping keyboard code goes here
  // This runs every cycle (a lot)
  matrix_scan_user();
};

void led_init_ports(void) {
  /* LEDs on */
  rgblight_enable();
  rgblight_sethsv(0,0,255);
  backlight_enable();
  breathing_enable();
}
