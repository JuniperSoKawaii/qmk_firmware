/* Copyright 2020 Alexander Tulloh
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

#include "oddball.h"
#include "pointing_device.h"
#include "adns.h"

void on_mouse_button(uint8_t mouse_button, bool pressed) {
    report_mouse_t report = pointing_device_get_report();

    if(pressed)
        report.buttons |= mouse_button;
    else
        report.buttons &= ~mouse_button;

    pointing_device_set_report(report);
}

void pointing_device_init(void){
    if(!is_keyboard_master())
        return;

    adns_init();
}

int8_t clamp_hid(int16_t value){
    return  value < -127 ? -127 : value > 127 ? 127 : value;
}

void pointing_device_task(void){
    if(!is_keyboard_master())
        return;

    report_mouse_t mouse_report = pointing_device_get_report();
    report_adns_t adns_report = adns_get_report();
    adns_clear_report();

    mouse_report.x = -clamp_hid(adns_report.x);
    mouse_report.y = clamp_hid(adns_report.y);

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {

    // handle mouse drag
    switch (keycode) {
        case KC_BTN1:
            on_mouse_button(MOUSE_BTN1, record->event.pressed);
            return false;

        case KC_BTN2:
            on_mouse_button(MOUSE_BTN2, record->event.pressed);
            return false;

        case KC_BTN3:
            on_mouse_button(MOUSE_BTN3, record->event.pressed);
            return false;

        case KC_BTN4:
            on_mouse_button(MOUSE_BTN4, record->event.pressed);
            return false;

        case KC_BTN5:
            on_mouse_button(MOUSE_BTN5, record->event.pressed);
            return false;

    default:
      return true;
  }
}
