 /* Copyright 2023 Red Oral
  * Based on the via keymap and modified it to my own keymap and OLED display preference
  * TotK logo byte array from https://www.reddit.com/r/MechanicalKeyboards/comments/15v1o4b/made_a_totk_pic_for_my_oled/
  */

//Sets up what the OLED screens display.
#ifdef OLED_ENABLE 

static void render_logo(void) {
    static const char PROGMEM totk_logo[] = {
        0x46, 0x41, 0x80, 0x00, 0x18, 0x18, 0x20, 0xc0, 0x40, 0x24, 0x2a, 0x11, 0x00, 0x00, 0x01, 0x02, 
        0x1d, 0x05, 0xc2, 0x21, 0x00, 0x80, 0x80, 0x40, 0x40, 0xc1, 0x61, 0x22, 0x02, 0x04, 0x88, 0x50, 
        0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xe8, 0x48, 0x48, 0x90, 0x20, 0x40, 0x80, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18, 0xc0, 
        0x31, 0x4e, 0x06, 0x69, 0x06, 0x91, 0x71, 0x09, 0x06, 0x06, 0x01, 0xfd, 0x08, 0xc8, 0xd0, 0x90, 
        0xa0, 0x20, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x06, 0x06, 
        0x08, 0x77, 0x90, 0x28, 0x91, 0x47, 0x88, 0x31, 0xc6, 0x68, 0x20, 0xc0, 0x00, 0x00, 0x01, 0x06, 
        0x0b, 0x0b, 0x04, 0x0b, 0x88, 0xcc, 0xc3, 0xe0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 
        0xf0, 0x5c, 0x25, 0x27, 0x26, 0x5c, 0xf1, 0x06, 0xe2, 0x41, 0x40, 0x80, 0x80, 0x83, 0x84, 0x0b, 
        0x0b, 0x04, 0x03, 0x80, 0x40, 0x00, 0x80, 0x40, 0xc0, 0x20, 0x80, 0x20, 0x60, 0x40, 0xa0, 0x10, 
        0x10, 0x30, 0x20, 0x20, 0x30, 0x20, 0x60, 0x60, 0x21, 0x13, 0x2c, 0x9b, 0xa4, 0x3a, 0x25, 0x63, 
        0x41, 0x40, 0x40, 0x40, 0x40, 0x20, 0x20, 0x40, 0x40, 0x80, 0x00, 0xf0, 0x01, 0xf2, 0x0f, 0x80, 
        0x4d, 0xa2, 0x82, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x7f, 0x7f, 
        0x3f, 0x1f, 0x1e, 0x0e, 0x0c, 0x05, 0x01, 0xfa, 0xf4, 0xf4, 0xe8, 0xc8, 0xd0, 0x90, 0xa0, 0x40, 
        0x40, 0x80, 0x80, 0x0f, 0xf2, 0x20, 0x92, 0x51, 0x90, 0x0f, 0xf0, 0x10, 0xe7, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x80, 0x40, 0x21, 0x13, 0xa3, 0x47, 0xa7, 0xa7, 0x43, 0x83, 0x03, 0x01, 0x01, 0x01, 
        0x0f, 0x3a, 0xa4, 0xe4, 0x64, 0x3a, 0x8f, 0x60, 0x47, 0x82, 0x02, 0x01, 0x01, 0xc1, 0x21, 0xd0, 
        0xd0, 0x20, 0xc1, 0x00, 0x01, 0x01, 0x02, 0x02, 0x01, 0x04, 0x01, 0x04, 0x07, 0x06, 0x04, 0x08, 
        0x08, 0x0c, 0x04, 0x04, 0x0c, 0x04, 0x06, 0x06, 0x84, 0xc8, 0x34, 0xd9, 0x25, 0x5c, 0xa4, 0xc6, 
        0x82, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x07, 0x98, 0x1f, 0xe1, 0x20, 
        0x42, 0x99, 0x40, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0xfe, 0xfe, 
        0xfc, 0xfc, 0x78, 0x70, 0x30, 0xa0, 0x80, 0x5f, 0x2f, 0x2f, 0x17, 0x13, 0x0b, 0x09, 0x05, 0x02, 
        0x02, 0x01, 0x01, 0xe0, 0x1f, 0xc2, 0x58, 0x21, 0x1c, 0xe0, 0x1f, 0xa0, 0x67, 0x00, 0x00, 0x00, 
        0x60, 0x80, 0x01, 0x06, 0x08, 0x10, 0x21, 0x42, 0x45, 0x85, 0x02, 0x01, 0x00, 0x00, 0x80, 0x40, 
        0xb8, 0xa0, 0x43, 0x84, 0x00, 0x01, 0x01, 0x02, 0x02, 0x83, 0x86, 0x44, 0x40, 0x20, 0x11, 0x0a, 
        0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x17, 0x12, 0x12, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x08, 0x4b, 
        0x8c, 0x30, 0x4c, 0xb2, 0x0c, 0x41, 0x8e, 0x30, 0x40, 0x40, 0x80, 0xbf, 0x10, 0x13, 0x0b, 0x09, 
        0x05, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x40, 
        0x30, 0xce, 0x09, 0x44, 0x84, 0x48, 0x32, 0x8c, 0x4b, 0x30, 0x02, 0x01, 0x00, 0x00, 0x80, 0x60
    };

    oled_write_raw_P(totk_logo, sizeof(totk_logo));
}

static void print_status_narrow(void) {
    // Print name
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Red"), false);
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer                                              
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("MO(1)"), false);
            break;
        case 2:
            oled_write_P(PSTR("MO(2)"), false);
            break;
        case 3:
            oled_write_P(PSTR("MO(3)"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    // CAPSLOCK
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
