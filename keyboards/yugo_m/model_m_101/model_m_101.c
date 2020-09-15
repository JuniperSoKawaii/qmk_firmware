/* Copyright 2020 Nidzo Tomic <tomicn8@hotmail.com>
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
#include "model_m_101.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    matrix_init_user();
    led_init_ports();
}

void led_init_ports() {
    // Set our LED pins as output
    palSetPadMode(GPIOA, 2, PAL_MODE_OUTPUT_PUSHPULL); // NumLock LED
    palClearPad(GPIOA, 2);
    palSetPadMode(GPIOA, 1, PAL_MODE_OUTPUT_PUSHPULL); // CapsLock LED
    palClearPad(GPIOA, 1);
    palSetPadMode(GPIOA, 0, PAL_MODE_OUTPUT_PUSHPULL); // ScrollLock LED
    palClearPad(GPIOA, 0);
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_NUM_LOCK)) {
        // Turn NumLock on (pin LOW)
        palClearPad(GPIOA, 2);
    } else {
        // Turn NumLock off (pin HIGH)
        palSetPad(GPIOA, 2);
    }

    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn CapsLock on
        palClearPad(GPIOA, 1);
    } else {
        // Turn CapsLock off
        palSetPad(GPIOA, 1);
    }

    if (usb_led & (1<<USB_LED_SCROLL_LOCK)) {
        // Turn ScrollLock on
        palClearPad(GPIOA, 0);
    } else {
        // Turn ScrollLock off
        palSetPad(GPIOA, 0);
    }
}
