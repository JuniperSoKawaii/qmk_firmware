/*
Copyright 2020 Michael Pio "Coarse" Mayol  <mfmayol@up.edu.ph>

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

#include "quantum.h"

#define ____ KC_NO

/* LAYOUT_all
 *                                                                           ┌───────┐
 *                                                                           │016    │2u Backspace
 *                                                                           └───────┘
 *              ┌───┬───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 *              │000│001││002│003│004│005│006│007│008│009│010│011│012│013│014│015│016│017│
 *              ├───┼───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤      ┌─────┐
 *              │100│101││102  │103│104│105│106│107│108│109│110│111│112│113│114│116  │117│      │     │ISO
 *  2.25u       ├───┼───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤   ┌──┴┐216 │Enter
 *  LShift      │200│201││202   │203│204│205│206│207│208│209│210│211│212│213│215     │217│   │214│    │
 * ┌────────┐   ├───┼───┤├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤   └───┴────┘
 * │302     │   │300│301││302 │303│304│305│306│307│308│309│310│311│312│313│314   │316│317│
 * └────────┘   ├───┼───┤├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 *              │400│401││402 │403 │404 │406     │408 │410       │412│413│414│415│416│417│
 *              └───┴───┘└────┴────┴────┴────────┴────┴──────────┴───┴───┴───┴───┴───┴───┘
 *                                      ┌────────────────────────┐   └───┬───┘
 *                                      │          408           │      (a)
 *                                      └────────────────────────┘
 *
 * (a) Positions 413 and 414 are present on the PCB, but inaccessible when using the standard Sunsetter top case.
 */

#define LAYOUT_all( \
    K000, K001,   K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, \
    K100, K101,   K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K116,       K117, \
    K200, K201,   K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, \
    K300, K301,   K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314,       K316, K317, \
    K400, K401,   K402, K403, K404,             K406, K408, K410,             K412, K413, K414, K415, K416, K417  \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____, K116, K117 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____, K316, K317 }, \
    { K400, K401, K402, K403, K404, ____, K406, ____, K408, ____, K410, ____, K412, K413, K414, K415, K416, K417 } \
}

#define LAYOUT_1065_ansi( \
    K000, K001,   K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K016, K017, \
    K100, K101,   K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K116, K117, \
    K200, K201,   K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       K215, K217, \
    K300, K301,   K302,       K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K316, K317, \
    K400, K401,   K402, K403, K404,                   K408,                   K412,       K415, K416, K417 \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, ____, K016, K017 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____, K116, K117 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, ____, K215, ____, K217 }, \
    { K300, K301, K302, ____, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____, K316, K317 }, \
    { K400, K401, K402, K403, K404, ____, ____, ____, K408, ____, ____, ____, K412, ____, ____, K415, K416, K417 } \
}

#define LAYOUT_1065_ansi_split_bs( \
    K000, K001,   K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, \
    K100, K101,   K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K116, K117, \
    K200, K201,   K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213,       K215, K217, \
    K300, K301,   K302,       K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K316, K317, \
    K400, K401,   K402, K403, K404,                   K408,                   K412,       K415, K416, K417 \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____, K116, K117 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, ____, K215, ____, K217 }, \
    { K300, K301, K302, ____, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____, K316, K317 }, \
    { K400, K401, K402, K403, K404, ____, ____, ____, K408, ____, ____, ____, K412, ____, ____, K415, K416, K417 } \
}

#define LAYOUT_1065_iso( \
    K000, K001,   K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K016, K017, \
    K100, K101,   K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       K117, \
    K200, K201,   K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K216, K217, \
    K300, K301,   K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K316, K317, \
    K400, K401,   K402, K403, K404,                   K408,                   K412,       K415, K416, K417 \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, ____, K016, K017 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____, ____, K117 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____, K216, K217 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____, K316, K317 }, \
    { K400, K401, K402, K403, K404, ____, ____, ____, K408, ____, ____, ____, K412, ____, ____, K415, K416, K417 } \
}

#define LAYOUT_1065_iso_split_bs( \
    K000, K001,   K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, \
    K100, K101,   K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114,       K117, \
    K200, K201,   K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K216, K217, \
    K300, K301,   K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K316, K317, \
    K400, K401,   K402, K403, K404,                   K408,                   K412,       K415, K416, K417 \
) { \
    { K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017 }, \
    { K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, ____, ____, K117 }, \
    { K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, ____, K216, K217 }, \
    { K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, ____, K316, K317 }, \
    { K400, K401, K402, K403, K404, ____, ____, ____, K408, ____, ____, ____, K412, ____, ____, K415, K416, K417 } \
}
