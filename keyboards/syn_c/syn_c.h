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
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
	KA1, KA2, KA3, \
	KB1, KB2, KB3, \
	KC1, KC2, KC3 \
) \
{ \
	{ KA1, KA2, KA3 }, \
	{ KB1, KB2, KB3 }, \
	{ KC1, KC2, KC3 } \
}

typedef union {
	uint16_t raw;
	struct {
		bool			enable			:1;
		uint8_t         level       	:8;
		bool            breath_enable   :1;
	};
} keyboard_config_backlight;

typedef union {
	uint32_t raw;
	struct {
		bool						status		:1;
		keyboard_config_backlight	backlight;
	};
} keyboard_config_t;
extern keyboard_config_t keyboard_config;

void blink_led(uint8_t times);
