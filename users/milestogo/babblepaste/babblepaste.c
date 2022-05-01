/*
 * Copyright 2022 milestogo
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

/*  Babblepaste: a library shortcuts that allow one key to do the same action in different OSes or applications.
 *
 * Given a global variable babble_mode to show the environment and a
 * key that calls the paste macro, do the right type of paste.
 * Huge thanks to https://en.wikipedia.org/wiki/Table_of_keyboard_shortcuts
 * and https://github.com/qmk/qmk_firmware/blob/master/keyboards/planck/keymaps/jeebak/keymap.c
 */

#include QMK_KEYBOARD_H

#ifdef USE_BABBLEPASTE
#    include "babblepaste.h"

// GLOBAL variable to determine mode.  Sets startup default if no eeppom
uint8_t babble_mode = 0;

// functions to tell the user that the mode has changed
__attribute__((weak)) void babble_modeswitch_user(uint8_t mode) {}
__attribute__((weak)) void babble_modeswitch_kb(uint8_t mode) {
    babble_modeswitch_user(mode);
}

void set_babble_mode(uint8_t id) {
    babble_mode = id;
}

void babble_mode_increment() {
    babble_mode += 1;
    if (babble_mode >= BABL_MODEMAX) {
        babble_mode = 0;
    }
    babble_modeswitch_kb(babble_mode);
}

void babble_mode_decrement() {
    if (babble_mode >= 1) {
        babble_mode -= 1;
    } else {
        babble_mode = BABL_MODEMAX - 1;
    }
    babble_modeswitch_kb(babble_mode);
}

// process babble_modswap
// rotate the mod keys so that the one used for cut & paste (eg. apple on mac, ctrl on windows),
// can always be put in the same place.
// Function is called in the main babblepaste loop.

bool process_babble_modswap(uint16_t keycode, keyrecord_t* record) {
#    ifdef BABL_MODSWAP
    bool mac = 0;

    // define safe way of setting is a mac
#        ifdef BABL_MAC
    if (babble_mode == BABL_MAC_MODE) {
        mac = 1;
    } else {
        mac = 0;
    }
#        endif

    // Primary OS MOD  is the key used for cut & paste (Propeller on Mac, Control elsewhere)
    if (keycode == BABL_PRIMARY_OS_MOD) {
        if (record->event.pressed) {
            if (mac) {
                register_code(KC_LGUI);
            } else {
                register_code(KC_LCTL);
            }
        } else { // key release
            if (mac) {
                unregister_code(KC_LGUI);
            } else {
                unregister_code(KC_LCTL);
            }
        }
    }

    // This is the os key not used in cut & paste. (CTRL on mac, GUI elsewhere)
    if (keycode == BABL_SECONDARY_OS_MOD) {
        if (record->event.pressed) {
            if (mac) {
                register_code(KC_LCTL);
            } else {
                register_code(KC_LGUI);
            }
        } else {
            if (mac) {
                unregister_code(KC_LCTL);
            } else {
                unregister_code(KC_LGUI);
            }
        }
    }

    // This is the alt key in most OSes. Mostly useful if you want to do hyper on one OS, Meh on another.
    if (keycode == BABL_TERTIARY_OS_MOD) {
        if (record->event.pressed) {
            if (mac) {
                register_code(KC_LALT);
            } else {
                register_code(KC_LALT);
            }
        } else {
            if (mac) {
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
            }
        }
    }

#    endif

    return true;
}

bool process_babblepaste(uint16_t keycode, keyrecord_t* record) {
    /* this function runs the appropriate babblepaste macro, given
    the global babble_mode and a keycode defined in the babble_keycodes enum.

    This could be made faster by splitting into functions sorted by keycode range
    But that makes for a *lot* of ifdefs.
    */

#    ifdef BABL_MODSWAP
    if (!process_babble_modswap(keycode, record)) {
        return false;
    }
#    endif

    // select needs to see non babble keys to exit.
#    ifdef BABL_SELECT
    if (!process_babble_select(keycode, record)) {
        return false;
    }
#    endif

    if (keycode < BABBLE_START || keycode > BABBLE_END_RANGE) {
        // not one of ours.
        return true;
    }

    // below here we are only running macros - don't serve any key up events.
    if (!record->event.pressed) {
        return false;
    }

    // handle increment functions.

    if (keycode == BABL_MODE_INCREMENT) {
        babble_mode_increment();
        return false;
    }

    if (keycode == BABL_MODE_DECREMENT) {
        babble_mode_decrement();
        return false;
    }

#    ifdef BABL_LINUX
    if (keycode == BABL_DO_LINUX) {
        set_babble_mode(BABL_LINUX_MODE);
#        if defined UNICODE_ENABLE || defined UNICODEMAP_ENABLE || defined UCIS_ENABLE
        set_unicode_input_mode(UC_LNX);
#        endif
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_LINUX_MODE) {
        babblePaste_linux(keycode);
    }
#    endif

#    ifdef BABL_MAC
    if (keycode == BABL_DO_MAC) {
        set_babble_mode(BABL_MAC_MODE);

#        if defined UNICODE_ENABLE || defined UNICODEMAP_ENABLE || defined UCIS_ENABLE
        set_unicode_input_mode(UC_MAC);
#        endif
        babble_modeswitch_kb(babble_mode);
    }

    if (babble_mode == BABL_MAC_MODE) {
        dprint("Mac ");
        babblePaste_mac(keycode);
    }
#    endif

#    ifdef BABL_WINDOWS
    if (keycode == BABL_DO_WINDOWS) {
        set_babble_mode(BABL_WINDOWS_MODE);
#        if defined UNICODE_ENABLE || defined UNICODEMAP_ENABLE || defined UCIS_ENABLE
        set_unicode_input_mode(UC_WINC);
#        endif
        dprint("Win! ");
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_WINDOWS_MODE) {
        babblePaste_win(keycode);
    }
#    endif

#    ifdef BABL_CHROMEOS
    if (keycode == BABL_DO_CHROMEOS) {
        set_babble_mode(BABL_CHROMEOS_MODE);
#        if defined UNICODE_ENABLE || defined UNICODEMAP_ENABLE
        dprint("chrome! ");
        set_unicode_input_mode(UC_LNX);
#        endif
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_CHROMEOS_MODE) {
        babblePaste_chromeos(keycode);
    }
#    endif

#    ifdef BABL_VI
    if (keycode == BABL_DO_VI) {
        set_babble_mode(BABL_VI_MODE);
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_VI_MODE) {
        babblePaste_vi(keycode);
    }
#    endif

#    ifdef BABL_EMACS
    if (keycode == BABL_DO_EMACS) {
        set_babble_mode(BABL_EMACS_MODE);
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_EMACS_MODE) {
        babblePaste_emacs(keycode);
    }
#    endif

#    ifdef BABL_READMUX
    if (keycode == BABL_DO_READMUX) {
        set_babble_mode(BABL_READMUX_MODE);
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_READMUX_MODE) {
        babblePaste_readmux(keycode);
    }
#    endif

#    ifdef BABL_KITTY
    if (keycode == BABL_DO_KITTY) {
        set_babble_mode(BABL_KITTY_MODE);
        babble_modeswitch_kb(babble_mode);
    }
    if (babble_mode == BABL_KITTY_MODE) {
        babblePaste_kitty(keycode);
    }
#    endif

#    ifdef BABL_NANO
    if (keycode == BABL_DO_NANO) {
        set_babble_mode(BABL_NANO_MODE);
        babble_modeswitch_kb(babble_mode);
        dprint("NANO! ");
        return false;
    }
    if (babble_mode == BABL_NANO_MODE) {
        babblePaste_nano(keycode);
        return false;
    }
#    endif

    // fall through of non-babble keys.
    return true;
}

#endif // USE_BABBLEPASTE
