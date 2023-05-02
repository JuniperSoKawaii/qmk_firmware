/* Copyright 2023 Adophoxia <https://github.com/Adophoxia>
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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_kb(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(43, 0xFF, 0xFF, 0xFF);
    }
    return true;
}
#endif

#if defined(ENCODER_ENABLE)
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { 
        return false; 
    }
    if (clockwise) {
        tap_code_delay(KC_VOLU, 10);
    } else {
        tap_code_delay(KC_VOLD, 10);
    }
    return true;
}
#endif

{
    "manufacturer": "Fancytech",
    "keyboard_name": "FancyAlice66",
    "maintainer": "Adophoxia",
    "bootloader": "caterina",
    "diode_direction": "ROW2COL",
    "encoder": {
        "rotary": [
            {
                "pin_a": "F0",
                "pin_b": "F1",
                "resolution": 2
        	}
        ]
	},
    "features": {
        "bootmagic": true,
        "encoder": false,
        "extrakey": true,
        "lto": true,
        "mousekey": true,
        "nkro": true,
        "rgb_matrix": true
	},
    "matrix_pins": {
        "cols": ["C6", "E6", "B5", "B4", "D7", "D6", "D4", "D5", "D3", "D2", "D1", "D0", "B7", "B3", "B2", "B1"],
        "rows": ["F4", "F5", "F6", "F7", "C7"]
	},
    "processor": "atmega32u4",
    "rgb_matrix": {
        "animations": {
            "alphas_mods": true,
            "band_pinwheel_sat": true,
            "band_pinwheel_val": true,
            "band_sat": true,
            "band_spiral_sat": true,
            "band_spiral_val": true,
            "band_val": true,
            "breathing": true,
            "cycle_all": true,
            "cycle_left_right": true,
            "cycle_out_in": true,
            "cycle_out_in_dual": true,
            "cycle_pinwheel": true,
            "cycle_spiral": true,
            "cycle_up_down": true,
            "dual_beacon": true,
            "gradient_left_right": true,
            "gradient_up_down": true,
            "hue_breathing": true,
            "hue_pendulum": true,
            "hue_wave": true,
            "jellybean_raindrops": true,
            "multisplash": true,
            "pixel_fractal": true,
            "pixel_rain": true,
            "rainbow_beacon": true,
            "rainbow_moving_chevron": true,
            "rainbow_pinwheels": true,
            "raindrops": true,
            "solid_multisplash": true,
            "solid_reactive": true,
            "solid_reactive_cross": true,
            "solid_reactive_multicross": true,
            "solid_reactive_multinexus": true,
            "solid_reactive_multiwide": true,
            "solid_reactive_nexus": true,
            "solid_reactive_simple": true,
            "solid_reactive_wide": true,
            "solid_splash": true,
            "splash": true
    	},
        "driver": "WS2812",
        "layout": [
            { "flags": 1, "matrix": [0, 0], "x": 0, "y": 0},
            { "flags": 4, "matrix": [0, 1], "x": 15, "y": 0},
            { "flags": 4, "matrix": [0, 2], "x": 30, "y": 0},
            { "flags": 4, "matrix": [0, 3], "x": 45, "y": 0},
            { "flags": 4, "matrix": [0, 4], "x": 60, "y": 0},
            { "flags": 4, "matrix": [0, 5], "x": 75, "y": 0},
            { "flags": 4, "matrix": [0, 6], "x": 90, "y": 0},
            { "flags": 4, "matrix": [0, 7], "x": 105, "y": 0},
            { "flags": 4, "matrix": [0, 8], "x": 120, "y": 0},
            { "flags": 4, "matrix": [0, 9], "x": 135, "y": 0},
            { "flags": 4, "matrix": [0, 10], "x": 150, "y": 0},
            { "flags": 4, "matrix": [0, 11], "x": 164, "y": 0},
            { "flags": 4, "matrix": [0, 12], "x": 180, "y": 0},
            { "flags": 1, "matrix": [0, 13], "x": 194, "y": 0},
            { "flags": 4, "matrix": [0, 15], "x": 224, "y": 0},
            { "flags": 1, "matrix": [1, 0], "x": 0, "y": 16},
            { "flags": 4, "matrix": [1, 1], "x": 15, "y": 16},
            { "flags": 4, "matrix": [1, 2], "x": 30, "y": 16},
            { "flags": 4, "matrix": [1, 3], "x": 45, "y": 16},
            { "flags": 4, "matrix": [1, 4], "x": 60, "y": 16},
            { "flags": 4, "matrix": [1, 5], "x": 75, "y": 16},
            { "flags": 4, "matrix": [1, 7], "x": 105, "y": 16},
            { "flags": 4, "matrix": [1, 8], "x": 120, "y": 16},
            { "flags": 4, "matrix": [1, 9], "x": 135, "y": 16},
            { "flags": 4, "matrix": [1, 10], "x": 150, "y": 16},
            { "flags": 4, "matrix": [1, 11], "x": 164, "y": 16},
            { "flags": 4, "matrix": [1, 12], "x": 180, "y": 16},
            { "flags": 4, "matrix": [1, 13], "x": 194, "y": 16},
            { "flags": 4, "matrix": [1, 14], "x": 209, "y": 16},
            { "flags": 4, "matrix": [1, 15], "x": 224, "y": 16},
            { "flags": 1, "matrix": [2, 0], "x": 0, "y": 32},
            { "flags": 4, "matrix": [2, 1], "x": 15, "y": 32},
            { "flags": 4, "matrix": [2, 2], "x": 30, "y": 32},
            { "flags": 4, "matrix": [2, 3], "x": 45, "y": 32},
            { "flags": 4, "matrix": [2, 4], "x": 60, "y": 32},
            { "flags": 4, "matrix": [2, 5], "x": 75, "y": 32},
            { "flags": 4, "matrix": [2, 7], "x": 105, "y": 32},
            { "flags": 4, "matrix": [2, 8], "x": 120, "y": 32},
            { "flags": 4, "matrix": [2, 9], "x": 135, "y": 32},
            { "flags": 4, "matrix": [2, 10], "x": 150, "y": 32},
            { "flags": 4, "matrix": [2, 11], "x": 164, "y": 32},
            { "flags": 4, "matrix": [2, 12], "x": 180, "y": 32},
            { "flags": 1, "matrix": [2, 13], "x": 194, "y": 32},
            { "flags": 4, "matrix": [2, 15], "x": 224, "y": 32},
            { "flags": 1, "matrix": [3, 0], "x": 0, "y": 48},
            { "flags": 4, "matrix": [3, 1], "x": 15, "y": 48},
            { "flags": 4, "matrix": [3, 2], "x": 30, "y": 48},
            { "flags": 4, "matrix": [3, 3], "x": 45, "y": 48},
            { "flags": 4, "matrix": [3, 4], "x": 60, "y": 48},
            { "flags": 4, "matrix": [3, 5], "x": 75, "y": 48},
            { "flags": 4, "matrix": [3, 7], "x": 105, "y": 48},
            { "flags": 4, "matrix": [3, 8], "x": 120, "y": 48},
            { "flags": 4, "matrix": [3, 9], "x": 135, "y": 48},
            { "flags": 4, "matrix": [3, 10], "x": 150, "y": 48},
            { "flags": 4, "matrix": [3, 11], "x": 164, "y": 48},
            { "flags": 4, "matrix": [3, 12], "x": 180, "y": 48},
            { "flags": 4, "matrix": [3, 14], "x": 209, "y": 48},
            { "flags": 1, "matrix": [4, 0], "x": 0, "y": 64},
            { "flags": 1, "matrix": [4, 2], "x": 30, "y": 64},
            { "flags": 4, "matrix": [4, 3], "x": 45, "y": 64},
            { "flags": 1, "matrix": [4, 6], "x": 90, "y": 64},
            { "flags": 4, "matrix": [4, 7], "x": 105, "y": 64},
            { "flags": 1, "matrix": [4, 10], "x": 150, "y": 64},
            { "flags": 4, "matrix": [4, 13], "x": 194, "y": 64},
            { "flags": 4, "matrix": [4, 14], "x": 209, "y": 64},
            { "flags": 4, "matrix": [4, 15], "x": 224, "y": 64},
            { "flags": 2, "x": 37, "y": 64},
            { "flags": 2, "x": 75, "y": 64},
            { "flags": 2, "x": 112, "y": 64},
            { "flags": 2, "x": 149, "y": 64},
            { "flags": 2, "x": 187, "y": 64},
            { "flags": 2, "x": 224, "y": 64},
            { "flags": 2, "x": 224, "y": 32},
            { "flags": 2, "x": 224, "y": 0},
            { "flags": 2, "x": 187, "y": 0},
            { "flags": 2, "x": 149, "y": 0},
            { "flags": 2, "x": 112, "y": 0},
            { "flags": 2, "x": 75, "y": 0},
            { "flags": 2, "x": 37, "y": 0},
            { "flags": 2, "x": 0, "y": 0},
            { "flags": 2, "x": 0, "y": 32},
            { "flags": 2, "x": 0, "y": 64}
        ],
        "max_brightness": 200,
        "rgblight.pin": "B0"
	},
    "url": "https://www.aliexpress.com/item/1005004272392611.html",
    "usb": {
        "device_version": "0.0.1",
        "force_nkro": true,
        "pid": "0x3663",
        "vid": "0xECED"
	},
    "layouts": {
        "LAYOUT": {
            "layout": [
                { "matrix": [0, 0], "x": 0.75, "y": 0.5},
                { "matrix": [0, 1], "x": 1.75, "y": 0.5},
                { "matrix": [0, 2], "x": 2.75, "y": 0.25},
                { "matrix": [0, 3], "x": 3.75, "y": 0.5},
                { "matrix": [0, 4], "x": 4.75, "y": 0.5},
                { "matrix": [0, 5], "x": 5.75, "y": 0.5},
                { "matrix": [0, 6], "x": 6.75, "y": 0.5},
                { "matrix": [0, 7], "x": 8.75, "y": 0.5},
                { "matrix": [0, 8], "x": 9.75, "y": 0.5},
                { "matrix": [0, 9], "x": 10.75, "y": 0.5},
                { "matrix": [0, 10], "x": 11.75, "y": 0.5},
                { "matrix": [0, 11], "x": 12.75, "y": 0.25},
                { "matrix": [0, 12], "x": 13.75, "y": 0.5},
                { "matrix": [0, 13], "w": 2, "x": 14.75, "y": 0.5},
                { "matrix": [0, 15], "x": 17, "y": 0},
                { "matrix": [1, 0], "w": 1.5, "x": 0.5, "y": 1.5},
                { "matrix": [1, 1], "x": 2, "y": 1.5},
                { "matrix": [1, 2], "x": 3.25, "y": 1.5},
                { "matrix": [1, 3], "x": 4.25, "y": 1.5},
                { "matrix": [1, 4], "x": 5.25, "y": 1.5},
                { "matrix": [1, 5], "x": 6.25, "y": 1.5},
                { "matrix": [1, 7], "x": 8.5, "y": 1.5},
                { "matrix": [1, 8], "x": 9.5, "y": 1.5},
                { "matrix": [1, 9], "x": 10.5, "y": 1.5},
                { "matrix": [1, 10], "x": 11.5, "y": 1.5},
                { "matrix": [1, 11], "x": 12.5, "y": 1.5},
                { "matrix": [1, 12], "x": 13.5, "y": 1.5},
                { "matrix": [1, 13], "x": 14.5, "y": 1.5},
                { "matrix": [1, 14], "w": 1.5, "x": 15.5, "y": 1.5},
                { "matrix": [1, 15], "x": 17.25, "y": 1},
                { "matrix": [2, 0], "w": 1.75, "x": 0.25, "y": 2.5},
                { "matrix": [2, 1], "x": 2, "y": 2.5},
                { "matrix": [2, 2], "x": 3.5, "y": 2.5},
                { "matrix": [2, 3], "x": 4.5, "y": 2.5},
                { "matrix": [2, 4], "x": 5.5, "y": 2.5},
                { "matrix": [2, 5], "x": 6.5, "y": 2.5},
                { "matrix": [2, 7], "x": 8.75, "y": 2.5},
                { "matrix": [2, 8], "x": 9.75, "y": 2.5},
                { "matrix": [2, 9], "x": 10.75, "y": 2.5},
                { "matrix": [2, 10], "x": 11.75, "y": 2.5},
                { "matrix": [2, 11], "x": 13, "y": 2.5},
                { "matrix": [2, 12], "x": 14, "y": 2.5},
                { "matrix": [2, 13], "w": 2.25, "x": 15, "y": 2.5},
                { "matrix": [2, 15], "x": 17.5, "y": 2},
                { "matrix": [3, 0], "w": 2.25, "x": 0, "y": 3.5},
                { "matrix": [3, 1], "x": 2.25, "y": 3.5},
                { "matrix": [3, 2], "x": 3.75, "y": 3.5},
                { "matrix": [3, 3], "x": 4.75, "y": 3.5},
                { "matrix": [3, 4], "x": 5.75, "y": 3.5},
                { "matrix": [3, 5], "x": 6.75, "y": 3.5},
                { "matrix": [3, 7], "x": 9, "y": 3.5},
                { "matrix": [3, 8], "x": 10, "y": 3.5},
                { "matrix": [3, 9], "x": 11, "y": 3.5},
                { "matrix": [3, 10], "x": 12, "y": 3.5},
                { "matrix": [3, 11], "x": 13.25, "y": 3.5},
                { "matrix": [3, 12], "w": 1.75, "x": 14.25, "y": 3.5},
                { "matrix": [3, 14], "x": 16.25, "y": 3.75},
                { "matrix": [4, 0], "w": 1.5, "x": 0, "y": 4.5},
                { "matrix": [4, 2], "w": 1.5, "x": 3.5, "y": 4.5},
                { "matrix": [4, 3], "w": 2.25, "x": 5, "y": 4.5},
                { "matrix": [4, 6], "x": 7.25, "y": 4.5},
                { "matrix": [4, 7], "w": 2.75, "x": 8.75, "y": 4.5},
                { "matrix": [4, 10], "w": 1.5, "x": 11.5, "y": 4.5},
                { "matrix": [4, 13], "x": 15.25, "y": 4.75},
                { "matrix": [4, 14], "x": 16.25, "y": 4.75},
                { "matrix": [4, 15], "x": 17.25, "y": 4.75}
            ]
    	}
	}
}