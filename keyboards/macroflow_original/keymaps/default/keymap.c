// Copyright 2024 Patrick Mathern (@Patrickemm)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Define the keycode, `QK_USER` avoids collisions with existing keycodes
enum keycodes {
  KC_CYCLE_LAYERS = QK_USER,
};

enum layer_names {
  one,
  two,
  three,
  four,
  five,
  six,
  seven,
  eight
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_macroflow_2x4(
        KC_0, KC_CYCLE_LAYERS,
        KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8
    ),
    [1] = LAYOUT_macroflow_2x4(
        KC_9, KC_CYCLE_LAYERS,
        KC_A, KC_B, KC_C, KC_D,
        KC_E, KC_F, KC_G, KC_H
    ),
    [2] = LAYOUT_macroflow_2x4(
        KC_I, KC_CYCLE_LAYERS,
        KC_J, KC_K, KC_L, KC_M,
        KC_N, KC_O, KC_P, KC_Q
    ),
    [3] = LAYOUT_macroflow_2x4(
        KC_R, KC_CYCLE_LAYERS,
        KC_S, KC_T, KC_U, KC_V,
        KC_W, KC_X, KC_Y, KC_Z
    ),
    [4] = LAYOUT_macroflow_2x4(
        KC_TRNS, KC_CYCLE_LAYERS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [5] = LAYOUT_macroflow_2x4(
        KC_TRNS, KC_CYCLE_LAYERS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [6] = LAYOUT_macroflow_2x4(
        KC_TRNS, KC_CYCLE_LAYERS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [7] = LAYOUT_macroflow_2x4(
        KC_TRNS, KC_CYCLE_LAYERS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END 8

// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_CYCLE_LAYERS:
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) { 
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }

      uint8_t current_layer = get_highest_layer(layer_state);

      // Check if we are within the range, if not quit
      if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
        return false;
      }

      uint8_t next_layer = current_layer + 1;
      if (next_layer > LAYER_CYCLE_END) {
          next_layer = LAYER_CYCLE_START;
      }
      layer_move(next_layer);
      return false;

    // Process other keycodes normally
    default:
      return true;
  }
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [1] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [2] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [3] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [4] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [5] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [6] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [7] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  }
};
#endif

#ifdef OLED_ENABLE

#ifndef SHOW_LOGO
#    define SHOW_LOGO 2500
#endif
static uint16_t oled_logo_timer = 0;
static bool has_startup_ran = false;

bool oled_task_user(void) {
    if (!has_startup_ran) {
      static const char startUp [] PROGMEM = {
        // 'startUp', 128x32px
        0,  0,  0,128,192,192,128,128,  0,  0,192,192,  0,  0,  0,192,192,  0,  0,128,128,192,192,128,  0,  0,192,192,192,192,192,192,192,  0,  0,128,128,192,192,128,  0,  0,  0,192,192,128,  0,  0,  0,  0,192,192,128,  0,  0,  0,128,192,192,  0,  0,  0,  0,  0,128,128,192,192,128,  0,  0,128,192,192,192,192,128,128,  0,  0,  0,128,192,192,192,128,  0,  0,  0,128,128,192,192,128,  0,  0,  0,  0,  0,  0,  0,128,192,192,128,  0,  0,  0,  0,128,192,192,128,128,  0,  0,192,192,192,  0,  0,  0,  0,128,192,192,  0,0,
        0,  0,255,255,  1,  1,  1, 31, 30,  0,255,255,  0,  0,  0,255,255,  0, 30,127,241,193,129,  7, 15,  0,  1,  1,  1,255,255,  1,  1,  0,254,255,  1,  1,  1,255,255,  0,  0,255, 63,255,224,  0,128,254, 63,255,255,  0,  0,224,255, 15,127,255,192,  0,  0,254,255,  1,  1,  1, 31, 31,  0,255,255,129,129,129,255,127,  0,  0,255,255,  1,  1,  1,255,255,  0, 30,127,241,193,129,  7, 15,  0,  0,  0,  0,252,255,  3,  1,  1,  3, 31, 30,  0,255,255,  1,  1,  1,255,254,  0,255,255,127,252,  0,  0,240,255,255,255,  0,  0,  0,  0,255,255,128,128,192,252, 60,  0,127,255,128,128,128,255,127,  0,120,248,128,129,131,255,254,  0,  0,  0,  0,255,255,  0,  0,  0,127,255,128,128,128,255,255,  0,  0,255,  0,  3,255,248,255, 15,  0,255,255,  0,248,255, 27, 24, 24, 63,255,224,  0,127,255,128,128,128,252,124,  0,255,255,  3,  1,  3,127,254,240,  0,127,255,128,128,128,255,127,  0,120,248,128,129,131,255,254,  0,128,128,  0, 63,255,192,128,128,224,252, 60,  0,255,255,128,128,128,255,127,  0,255,255,  0, 31,255,252,127,  1,255,255,  0,  0,0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  1,  0,  0,  0,  1,  1,  0,  0,  1,  1,  0,  1,  1,  0,  0,  0,  0,  1,  1,  0,  0,  0,  1,  1,  1,  1,  0,  0,  1,  1,  0,  0,  0,  0,  1,  1,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  1,  1,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  0,  1,  1,  1,  1,  0,  0,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1,  1,  0,  0
    };
    oled_write_raw_P(startUp, sizeof(startUp));
        if (timer_elapsed(oled_logo_timer) >= SHOW_LOGO) {
            has_startup_ran = true;
            oled_clear();
        }
    } else {
  static const char PROGMEM layer[4][67+1] = {
    { 224,224,224,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,224,224,224,224,  0,  0,  0,  0,  0,224,224,224,128,  0,  0,  0,  0,128,224,224,224,  0,  0,  0,224,224,224,224,224,224,224,224,224,224,224,  0,  0,224,224,224,224,224,224,224,224,224,192,128,  0 },
    { 255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,240,255,255,127, 15,127,255,255,240,  0,  0,  0,  0,  3, 15,127,252,240,240,252,127, 15,  3,  0,  0,  0,  0,255,255,255,255,192,192,192,192,192,  0,  0,  0,  0,255,255,255,255,192,192,192,225,255,255,255,127 },
    { 255,255,255,255,192,192,192,192,192,192,192,  0,  0,192,254,255,255,127, 28, 28, 28,127,255,255,254,192,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,129,129,129,129,129,128,128,  0,  0,255,255,255,255,  1,  1,  7,127,255,255,248,192 },
    { 3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  0,  0,  3,  3,  3,  3,  0,  0,  0,  0,  3,  3,  3,  3 },
  };

  static const char PROGMEM layer1[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,248,120,120, 56, 56, 24, 24, 24,248,248,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,255,252,252,252,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 28, 28, 28, 28, 31, 31, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer2[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,120, 56, 24, 24, 24, 24, 24, 24, 56,120,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,248,248,248,254,255, 63,  6,  0,128,224,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255, 63, 15,  7,  1, 64,112,120,126,127,127,255,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 28, 28, 28, 28, 28, 28, 28, 28, 28, 28, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer3[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,120, 56, 24, 24, 24, 24, 24, 24, 56,120,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,248,248,248, 62, 63, 63, 30,  0,128,192,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255, 31, 31, 31,126,254,254,124,  0,  0,  1,255,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 30, 28, 24, 24, 24, 24, 24, 24, 28, 30, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer4[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,248,248,248,248,120, 24, 24, 24, 24,248,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,255, 63,  7,  1,192,240,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,192,192,192,194,195,195,  0,  0,  0,195,195,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 28, 28, 28, 31, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer5[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,143,143,143, 15, 15, 31,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,142, 14, 14, 30,127,127,127,  0,  0,  0,224,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 30, 28, 28, 28, 28, 28, 28, 30, 31, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer6[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,248, 56, 24, 24, 24, 24, 24, 24, 24, 56,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0, 31, 31, 31, 24, 24, 56,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,128,  0,  0,  0,127,127,127,  0,  0,  0,128,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 30, 28, 28, 28, 28, 28, 28, 28, 30, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer7[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, 31,  3,  0,128,248,255,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,255,255,127, 15,  1,  0,192,252,255,255,255,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 28, 28, 28, 28, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  static const char PROGMEM layer8[4][30+1] = {
    { 128,224,240,240,248,248,248,248,248,248,248, 56, 24, 24, 24, 24, 24, 24, 24, 56,248,248,248,248,248,248,240,240,224,128 },
    { 255,255,255,255,255,255,255,255,255,255,224,128,  0,  0, 31, 31, 31,  0,  0,128,224,255,255,255,255,255,255,255,255,255 },
    { 255,255,255,255,255,255,255,255,255,255,129,  0,  0,  0,126,126,126,  0,  0,  0,129,255,255,255,255,255,255,255,255,255 },
    { 1,  7, 15, 15, 31, 31, 31, 31, 31, 31, 31, 30, 28, 28, 28, 28, 28, 28, 28, 30, 31, 31, 31, 31, 31, 31, 15, 15,  7,  1 }
  };

  oled_set_cursor(1, 0);  // start pos
  oled_write_raw_P(layer[0], sizeof(layer[0]));
  oled_set_cursor(1, 1);  // move to next line
  oled_write_raw_P(layer[1], sizeof(layer[1]));
  oled_set_cursor(1, 2);  // move to next line
  oled_write_raw_P(layer[2], sizeof(layer[2]));
  oled_set_cursor(1, 3);  // move to next line
  oled_write_raw_P(layer[3], sizeof(layer[3]));

  switch (get_highest_layer(layer_state)) {
    case one :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer1[0], sizeof(layer1[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer1[1], sizeof(layer1[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer1[2], sizeof(layer1[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer1[3], sizeof(layer1[3]));
      break;
    case two :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer2[0], sizeof(layer2[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer2[1], sizeof(layer2[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer2[2], sizeof(layer2[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer2[3], sizeof(layer2[3]));
      break;
    case three :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer3[0], sizeof(layer3[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer3[1], sizeof(layer3[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer3[2], sizeof(layer3[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer3[3], sizeof(layer3[3]));
      break;
    case four :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer4[0], sizeof(layer4[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer4[1], sizeof(layer4[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer4[2], sizeof(layer4[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer4[3], sizeof(layer4[3]));
      break;
    case five :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer5[0], sizeof(layer5[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer5[1], sizeof(layer5[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer5[2], sizeof(layer5[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer5[3], sizeof(layer5[3]));
      break;
    case six :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer6[0], sizeof(layer6[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer6[1], sizeof(layer6[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer6[2], sizeof(layer6[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer6[3], sizeof(layer6[3]));
      break;
    case seven :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer7[0], sizeof(layer7[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer7[1], sizeof(layer7[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer7[2], sizeof(layer7[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer7[3], sizeof(layer7[3]));
      break;
    case eight :
      oled_set_cursor(16, 0); // move 20 columns out
      oled_write_raw_P(layer8[0], sizeof(layer8[0]));
      oled_set_cursor(16, 1); // move 20 columns out
      oled_write_raw_P(layer8[1], sizeof(layer8[1]));
      oled_set_cursor(16, 2); // move 20 columns out
      oled_write_raw_P(layer8[2], sizeof(layer8[2]));
      oled_set_cursor(16, 3); // move 20 columns out
      oled_write_raw_P(layer8[3], sizeof(layer8[3]));
      break;
  }
    }
  return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
  }

#endif