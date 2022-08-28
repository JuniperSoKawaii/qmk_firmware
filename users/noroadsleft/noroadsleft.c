/* Copyright 2020-2022 James Young (@noroadsleft)
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

#include "noroadsleft.h"
#include "version.h"

__attribute__((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keymap(keycode, record)) {
        return false;
    }
#if defined(ANSI_NUBS_ROW) && defined(ANSI_NUBS_COL)
    // if ANSI_NUBS_ROW and ANSI_NUBS_COL are both defined, and Right Alt mod is active
    if ( record->event.key.row == ANSI_NUBS_ROW && record->event.key.col == ANSI_NUBS_COL && get_mods() & MOD_MASK_RALT ) {
        if (record->event.pressed) {
            register_code(KC_NUBS);
        } else {
            unregister_code(KC_NUBS);
        }
        return false;
    }
#endif
    switch (keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD ":" QMK_KEYMAP " # @ " QMK_VERSION);
            }
            return false;
        case G_PUSH:
            if (record->event.pressed) {
                SEND_STRING("git push origin ");
            };
            return false;
        case G_FTCH:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_SHIFT ) {
                    clear_mods();
                    SEND_STRING("git pull upstream ");
                } else {
                    SEND_STRING("git fetch upstream ");
                }
            };
            return false;
        case G_BRCH:
            if (record->event.pressed) {
                if ( get_mods() & MOD_MASK_SHIFT ) {
                    clear_mods();
                    SEND_STRING("master");
                } else {
                    SEND_STRING("$(git branch-name)");
                }
            };
            return false;
        case G_PWD:
            if (record->event.pressed) {
                clear_mods();
                SEND_STRING("$( pwd | sed -e 's;^.*/keyboards/;;' -e 's;/;_;g')");
            };
            return false;
        case M_SALL:
            if (record->event.pressed) {
                tap_code16(C(KC_A));
            }
            return false;
        case M_UNDO:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_Z);
            } else {
                unregister_code(KC_Z);
                unregister_code(KC_LCTL);
            }
            return false;
        case M_CUT:
            if (record->event.pressed) {
                tap_code16(C(KC_X));
            }
            return false;
        case M_COPY:
            if (record->event.pressed) {
                tap_code16(C(KC_C));
            }
            return false;
        case M_PASTE:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_V);
            } else {
                unregister_code(KC_V);
                unregister_code(KC_LCTL);
            }
            return false;
        case KC_1 ... KC_0:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_RALT) {
                    register_code(keycode + 0x3B);
                } else {
                    register_code(keycode);
                }
            } else {
                if (get_mods() & MOD_MASK_RALT) {
                    unregister_code(keycode + 0x3B);
                } else {
                    unregister_code(keycode);
                }
            }
            return false;
        case KC_F1 ... KC_F12:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_RALT) {
                    register_code(keycode + 0x2E);
                } else {
                    register_code(keycode);
                }
            } else {
                if (get_mods() & MOD_MASK_RALT) {
                    unregister_code(keycode + 0x2E);
                } else {
                    unregister_code(keycode);
                }
            }
            return false;
    }  // switch()
    return true;
};
