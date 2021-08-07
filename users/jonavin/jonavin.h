
/* Copyright 2021 Jonavin Eng @Jonavin

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// DEFINE MACROS
#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])


// LAYERS
enum custom_user_layers {
    _BASE,
    _FN1,
    _LOWER,
    _RAISE,
};

// KEYCODES
enum custom_user_keycodes {
  KC_00 = SAFE_RANGE,
  ENCFUNC,
  KC_WINLCK,    //Toggles Win key on and off
  RGB_TOI,      // Timeout idle time up
  RGB_TOD,      // Timeout idle time down
};

#define KC_CAD	LALT(LCTL(KC_DEL))
#define KC_AF4	LALT(KC_F4)
#define KC_TASK	LCTL(LSFT(KC_ESC))


#ifdef TD_LSFT_CAPSLOCK_ENABLE
    // Tap Dance Definitions
    enum custom_tapdance {
        TD_LSFT_CAPSLOCK,
    };
    #define KC_LSFTCAPS TD(TD_LSFT_CAPSLOCK)
#else // regular Shift
    #define KC_LSFTCAPS KC_LSFT
#endif // TD_LSFT_CAPSLOCK_ENABLE



#ifdef RGB_MATRIX_ENABLE
//RGB custom colours
    #define RGB_GODSPEED 0x00, 0xE4, 0xFF // colour for matching keycaps
    #define RGB_NAUTILUS 0x00, 0xA4, 0xA9 // Nautilus Font colours
#endif
