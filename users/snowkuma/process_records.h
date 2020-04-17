#pragma once
#include "snowkuma.h"

enum custom_keycodes {
  // Layer Macros
  COLEMAK = SAFE_RANGE,
  // Custom Macros
  M_BRAVE,
  M_CODE,
  
  // Secret Macros
  M_XXX1,
  M_XXX2,
  M_XXX3,
  M_XXX4,
  M_XXX5,
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef OLED_DRIVER_ENABLE
bool process_record_oled(uint16_t keycode, keyrecord_t *record);
#endif
