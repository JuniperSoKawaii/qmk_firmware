/* Copyright 2020 sets3n
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

#include "zx60.h"
void matrix_init_kb(void) {
    matrix_init_user();
    led_init_ports();
};

void led_init_ports(void) {
    setPinOutput(B0);
    writePinHigh(B0);
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        writePinLow(B0);
    } else {
        writePinHigh(B0);
    }

    led_set_user(usb_led);
}

