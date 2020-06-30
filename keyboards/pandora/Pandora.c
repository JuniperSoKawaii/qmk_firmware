/* Copyright 2020 Koobaczech
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

#include "pandora.h"

void matrix_init_kb(void) {
    matrix_init_user();
    led_init_ports();
};

void led_init_ports(void) {
    setPinOutput(E6);
    writePinHigh(E6);
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        writePinLow(E6);
    } else {
        writePinHigh(E6);
    }

    led_set_user(usb_led);
}
