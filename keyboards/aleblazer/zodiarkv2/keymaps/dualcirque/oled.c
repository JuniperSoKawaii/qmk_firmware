/*
Copyright 2024 Spencer Deven
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef OLED_ENABLE

static void render_logo(void) {
  static const char PROGMEM zodiarm_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0x40, 0x60, 0x60, 0x60, 0x20, 0x30, 0x30, 0x30, 0x30, 0x10,
0x10, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x1c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7c, 0x7c, 0x7c, 0x7c,
0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x7c, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
0xc0, 0x80, 0x80, 0x20, 0x60, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8,
0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0,
0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x30, 0x98, 0x98, 0x8c, 0xc4, 0xc6,
0xc3, 0xc3, 0xc1, 0xc1, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x03, 0x0e, 0x1c, 0x70, 0xe0, 0x80, 0x01, 0x01, 0x03, 0x03, 0x07, 0x0f,
0x0f, 0x1f, 0x3f, 0x7f, 0xfe, 0xfe, 0xfc, 0xf9, 0xf3, 0xe7, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x03, 0x03, 0x83, 0xc1, 0xf1, 0xf9, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x0f, 0x07, 0x03, 0x03, 0x03, 0x01, 0xc1, 0xe1,
0xf0, 0xf8, 0xf9, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0,
0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x1c, 0xf0, 0xe0, 0xe0, 0xe0,
0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfd, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xed,
0xcf, 0x07, 0x07, 0x07, 0x07, 0x07, 0x87, 0x87, 0xc7, 0x47, 0x67, 0x67, 0x65, 0x7d, 0x79, 0x41,
0xc1, 0xc3, 0x87, 0x8f, 0x1f, 0x3f, 0x77, 0xcf, 0x9f, 0x1f, 0x3f, 0x3f, 0x7e, 0x7c, 0x7c, 0x78,
0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0xe0, 0x60, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x1c, 0x1e, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03,
0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x0f, 0x0f, 0x07,
0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x03, 0x07, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xe0, 0xfc, 0xff, 0xff, 0xff, 0x7f, 0x7f,
0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x03, 0x03, 0x0f, 0x1f, 0x1f, 0x3f, 0x7f, 0x7f, 0x7f,
0xff, 0xff, 0xfe, 0xfe, 0xe6, 0xe3, 0xe1, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
0xc0, 0xc0, 0xc1, 0xc1, 0xc3, 0xc6, 0xc6, 0xc7, 0x87, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0x38, 0x78, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0,
0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xf0, 0xf0, 0xe0,
0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xc0, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x07, 0x3f, 0xff, 0xff, 0xff, 0xfe, 0xfe,
0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 0xfe, 0xff,
0xff, 0xff, 0x7f, 0x7f, 0x67, 0xc7, 0x87, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x83, 0x83, 0xc3, 0x63, 0x63, 0xe3, 0xe1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x60, 0xe0, 0xe0, 0xc0, 0xc0, 0xc1, 0x83, 0x87, 0x9f, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x83, 0x87,
0x0f, 0x1f, 0x9f, 0xbf, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x07, 0x07,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0x38, 0x0f, 0x07, 0x07, 0x07,
0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 0xbf, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0xb7,
0xf3, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1, 0xe3, 0xe2, 0xe6, 0xe6, 0xa6, 0xbe, 0x9e, 0x82,
0x83, 0xc3, 0xe1, 0xf1, 0xf8, 0xfc, 0xee, 0xf3, 0xf9, 0xf8, 0xfc, 0xfc, 0x7e, 0x3e, 0x3e, 0x1e,
0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x0c, 0x19, 0x19, 0x31, 0x23, 0x63,
0xc3, 0xc3, 0x83, 0x83, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0xc0, 0x70, 0x38, 0x0e, 0x07, 0x01, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xf0,
0xf0, 0xf8, 0xfc, 0xfe, 0x7f, 0x7f, 0x3f, 0x9f, 0xcf, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x06, 0x04, 0x0c, 0x0c, 0x0c, 0x0c, 0x08,
0x08, 0x18, 0x18, 0x18, 0x18, 0x38, 0x38, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3e, 0x3e, 0x3e, 0x3e,
0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03,
0x03, 0x01, 0x01, 0x04, 0x06, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,
0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x03, 0x03,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(zodiarm_logo, sizeof(zodiarm_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
			oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Raise"), false);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            break;
        case 3:
            oled_write_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_90;
    }
    else 
    {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
