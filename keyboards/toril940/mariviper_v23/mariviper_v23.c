// Copyright <year> <name> <email> @<github_username>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "quantum.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

const is31fl3731_led_t PROGMEM g_is31fl3731_leds[IS31FL3731_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *    driver
 *    |  LED address
 *    |  | */
	{ 0, C1_1 }, { 0, C2_1 }, { 0, C3_1 }, // Lock Indicator
	{ 0, C4_1 }, { 0, C5_1 }, { 0, C6_1 }, { 0, C7_1 }, { 0, C8_1 } // Layer Indicator
};



void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	led_matrix_enable();
	matrix_init_user();
}

bool led_matrix_indicators_kb(void) {
	led_t led_state = host_keyboard_led_state();
	bool res = led_update_user(led_state);
	if (res)
	{
		led_matrix_set_value(0, led_state.caps_lock ? 0xFF : 0);
		led_matrix_set_value(1, led_state.num_lock ? 0xFF : 0);
		led_matrix_set_value(2, led_state.scroll_lock ? 0xFF : 0);
	}
	return res;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
	state = layer_state_set_user(state);
	for (uint8_t i = 3; i <= 7; ++i)
	{
		led_matrix_set_value(i, 0);
	}
	// may want to add `| default_layer_state`
	unsigned highest = get_highest_layer_state(state);
	if (highest == 0)
	{
		for (uint8_t i = 3; i <= 7; ++i)
		{
			led_matrix_set_value(i, 0xFF);
		}
	}
	else if (highest <= 5)
	{
		led_matrix_set_value(highest + 2, 0xFF);
	}
	else if (highest <= 9)
	{
		led_matrix_set_value(3, 0xFF);
		led_matrix_set_value(highest - 2, 0xFF);
	}
	else if (highest <= 12)
	{
		led_matrix_set_value(3, 0xFF);
		led_matrix_set_value(4, 0xFF);
		led_matrix_set_value(highest - 5, 0xFF);
	}
	else if (highest <= 14)
	{
		led_matrix_set_value(3, 0xFF);
		led_matrix_set_value(4, 0xFF);
		led_matrix_set_value(5, 0xFF);
		led_matrix_set_value(highest - 7, 0xFF);
	}
	return state;
}

void suspend_power_down_kb(void) {
	led_matrix_disable();
	suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
	led_matrix_enable();
	suspend_wakeup_init_user();
}
