/* Copyright 2019 kratsyn
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
#include "syn_c.h"
#include "hal.h"
#include "eeconfig.h"
#include "backlight_led.h"

#define LED_ON()        palSetLine(C13);
#define LED_OFF()       palClearLine(C13);

keyboard_config_t	keyboard_config;

void keyboard_pre_init_kb(void) {
    // read kb settings from eeprom
    keyboard_config.raw = eeconfig_read_kb();

	// start blt
	backlight_init();
}

// initialization overloads
void matrix_init_kb(void) {
    // Intitialize the pins we need to initialize
    palSetLineMode(C13, PAL_MODE_OUTPUT_PUSHPULL);

    // flash the MCU LED
    blink_led(3);
    dprintf("[SYS] Startup complete.\n");
    LED_ON();
	
	// check if we're configured
	if(keyboard_config.status == 0)
		eeconfig_init_kb();

    // continue startup
    matrix_init_user();
}

void eeconfig_init_kb(void) { // EEPROM Reset
	// reset the config structure
    keyboard_config.raw = 0;
	keyboard_config.status = 1;

	// set backlight specific values
	keyboard_config.backlight.enable = 0;
    keyboard_config.backlight.level = 0;
	keyboard_config.backlight.breath_enable = 0;

	// write to eeprom
    eeconfig_update_kb(keyboard_config.raw);

	dprint("[SYS] EEPROM Reset to default values, forcing init again..\n");
	keyboard_pre_init_kb();
}

void blink_led(uint8_t times) {
    while ( times-- ) {
        LED_ON();
        wait_ms(200);
        LED_OFF();
        wait_ms(200);
    }
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
		case BL_ON:
			if (record->event.pressed) {
				backlight_on();
			}
			break;
		case BL_OFF:
			if (record->event.pressed) {
				backlight_off();
			}
			break;
		case BL_INC:
			if (record->event.pressed) {
				backlight_step(true);
			}
			break;
		case BL_DEC:
			if (record->event.pressed) {
				backlight_step(false);
			}
			break;
        case BL_STEP:
            if (record->event.pressed) {
				backlight_step(true);
			}
            break;
		case BL_BRTG:
			if (record->event.pressed) {
				backlight_breathing_toggle();
			}
			break;
		case BL_TOGG:
			if (record->event.pressed) {
				backlight_toggle();
			}
			break;
    }
    return process_record_user(keycode, record);
}
