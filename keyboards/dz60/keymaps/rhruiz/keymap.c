#include QMK_KEYBOARD_H

#include "raw_hid.h"
#include "rhruiz_api.h"

#define MISCTRL LCTL(KC_UP)
#define CTRLESC LCTL_T(KC_ESC)

// arrow cluster
#define CLLEFT MT(MOD_LGUI, KC_LEFT)
#define CLDOWN MT(MOD_LALT, KC_DOWN)
#define CLUP MT(MOD_RCTL, KC_UP)
#define CLRIGHT LT(_FN1, KC_RIGHT)

void change_leds_to(uint16_t, uint8_t);
void rhruiz_rgblight_reset(void);

typedef struct {
  uint16_t hue;
  uint8_t sat;
} hue_sat_pair;

typedef union {
  uint32_t raw;
  struct {
    bool     version_1_1 :1;
  };
} user_config_t;

enum rhruiz_keys {
  KC_KBVSN = SAFE_RANGE
};

enum rhruiz_layers {
  _BL,
  _VIM_EMACS,
  _MOUSE,
  _KEY_OVERRIDE,
  _FN1,
  _FN2,
  _CFG
};

user_config_t user_config;
bool state_changed = false;
const hue_sat_pair hue_sat_pairs[][2] = {
  [_FN1] = {
    [false] = { 2, 255 },
    [true] = { 175, 255 }
  },

  [_FN2] = {
    [false] = { 275, 255 },
    [true] = { 2, 255 }
  },

  [_CFG] = {
    [false] = { 110, 255 },
    [true] = { 110, 255 }
  }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT(
		KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,   KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,   KC_DEL,
		KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,   KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
		CTRLESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,   KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
		KC_LSFT,  KC_NO,    KC_Z,     KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_FN2,
		KC_FN1,   KC_LALT,  KC_LGUI,  KC_SPC,  KC_FN2,  KC_BSPC,  CLLEFT,  CLDOWN,  KC_NO,  CLUP,     CLRIGHT
  ),

  [_VIM_EMACS] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,   KC_UP,    _______,  _______,  _______,
		_______,  _______,  _______,  _______,  KC_RIGHT,   _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  _______,  _______,  KC_PENT,
		_______,  _______,  _______,  _______,  _______,    _______,  KC_LEFT,  KC_DOWN,  KC_ENT,   _______,   _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,   _______
  ),

  [_MOUSE] = LAYOUT(
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_KEY_OVERRIDE] = LAYOUT(
		KC_GRV,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_EJCT,
		KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PENT,
		_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,  KC_DEL,   _______,  _______,  _______,  _______,  _______
  ),

  [_FN1] = LAYOUT(
		_______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,   _______,
		_______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MO(_CFG),
		_______,  _______,  _______,  _______,  MO(_CFG),  _______,  _______,  _______,  _______,  _______,  _______
  ),

  [_FN2] = LAYOUT(
		_______,   KC_SLCK,  KC_PAUS,  MISCTRL,  _______,  RGB_VAD,  RGB_VAI,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE,  KC__VOLDOWN,  KC__VOLUP,  _______,  _______,
		_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,    _______,
		_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,
		_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,    _______,
		MO(_CFG),  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MO(_CFG)
  ),

  [_CFG] = LAYOUT(
		_______,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW,  RGB_M_SN,  RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  _______,  RGB_SPD,  RGB_SPI,  _______,  KC_KBVSN,
		_______,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,   RGB_SAI,   RGB_SAD,  RGB_VAI,  RGB_VAD,  _______,  _______,  _______,  _______,  RESET,
		_______,  BL_TOGG,  BL_STEP,  BL_BRTG,  _______,   _______,   KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		_______,  _______,  _______,  _______,  _______,   _______,   _______,  _______,  _______,  _______,  _______
  ),
};

void raw_hid_receive( uint8_t *data, uint8_t length ) {
	uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);

	switch ( *command_id ) {
		case id_get_keyboard_value: {
			if ( command_data[0] == id_uptime ) {
				uint32_t value = timer_read32();
				command_data[1] = (value >> 24 ) & 0xFF;
				command_data[2] = (value >> 16 ) & 0xFF;
				command_data[3] = (value >> 8 ) & 0xFF;
				command_data[4] = value & 0xFF;
			} else {
				*command_id = id_unhandled;
			}
			break;
		}

    case id_bootloader_jump: {
			raw_hid_send( data, length );
			wait_ms(100);
			bootloader_jump();
			break;
    }

    case id_rgblight_color: {
      uint16_t hue = ((uint16_t)command_data[0] << 8) | command_data[1];
      uint8_t sat = command_data[2];
      state_changed = true;
      change_leds_to(hue, sat);

      break;
    }

    case id_rgblight_reset: {
      rhruiz_rgblight_reset();
      break;
    }

    case id_backlight_toggle: {
      backlight_toggle();
      break;
    }

    case id_rgblight_toggle: {
      rgblight_toggle();
      break;
    }
  }

	raw_hid_send( data, length );
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	// keyevent_t event = record->event;
	return MACRO_NONE;
}

void matrix_init_user(void) {
  // Read the user config from EEPROM
  user_config.raw = eeconfig_read_user();
}

void matrix_scan_user(void) {
  if (biton32(layer_state) == _BL) {
    return;
  }

  uint16_t hue = 1;
  uint8_t sat = 0;

  const hue_sat_pair hue_sat = hue_sat_pairs[biton32(layer_state)][user_config.version_1_1];
  hue = hue_sat.hue;
  sat = hue_sat.sat;

  change_leds_to(hue, sat);
}

void rhruiz_layer_on(uint8_t layer) {
  layer_on(_VIM_EMACS);
  layer_on(_MOUSE);
  layer_on(_KEY_OVERRIDE);
  layer_on(layer);
}

void rhruiz_layer_off(uint8_t layer) {
  layer_off(_VIM_EMACS);
  layer_off(_MOUSE);
  layer_off(_KEY_OVERRIDE);
  layer_off(layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_KBVSN: {
      if (record->event.pressed) {
        user_config.version_1_1 ^= 1; // Toggles the version
        eeconfig_update_user(user_config.raw); // Writes version to EEPROM
      }
      return false;
    }

    case KC_FN1: {
      if (record->event.pressed) {
        rhruiz_layer_on(_FN1);
      } else {
        rhruiz_layer_off(_FN1);
      }

      return false;
    }

    case KC_FN2: {
      if (record->event.pressed) {
        rhruiz_layer_on(_FN2);
      } else {
        rhruiz_layer_off(_FN2);
      }

      return false;
    }
  }

  return true;
}

void change_leds_to(uint16_t hue, uint8_t sat) {
  rgblight_config_t eeprom_config;
  eeprom_config.raw = eeconfig_read_rgblight();

  if (state_changed) {
    if (!eeprom_config.enable) {
      rgblight_enable_noeeprom();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      for (uint8_t i = RGBLED_NUM ; i-- > 0 ; ) {
        if (i == 8 || i == 15) {
          continue;
        }

        sethsv(0, 0, 0, (LED_TYPE *)&led[i]);
      }
    }

    state_changed = false;
  }

  sethsv(hue, sat, eeprom_config.val, (LED_TYPE *)&led[8]);
  sethsv(hue, sat, eeprom_config.val, (LED_TYPE *)&led[15]);
  rgblight_set();
}

void eeconfig_init_user(void) {
  user_config.version_1_1 = false;
  eeconfig_update_user(user_config.raw);
}

void rhruiz_rgblight_reset(void) {
  rgblight_config_t eeprom_config;
  eeprom_config.raw = eeconfig_read_rgblight();

  if (!eeprom_config.enable) {
    rgblight_disable_noeeprom();
  }

  rgblight_mode_noeeprom(eeprom_config.mode);
  rgblight_sethsv_noeeprom(eeprom_config.hue, eeprom_config.sat, eeprom_config.val);
}

uint32_t layer_state_set_user(uint32_t state) {
  static uint32_t last_state = 0;
  if (state != last_state) {
    switch(biton32(state)) {
      case _BL:
        rhruiz_rgblight_reset();
        state_changed = false;
        break;

      case _FN1:
      case _FN2:
      case _CFG:
        state_changed = true;
        break;

      default:
        break;
    }

    last_state = state;
  }

  return state;
}
