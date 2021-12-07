/* Copyright 2021 superuser
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
#pragma once

#include "quantum.h"

#define ___ KC_NO

/*
 *              ┌───┬───┐┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐┌───┬───┬───┐      ┌───────┐
 *              │00 │01 ││02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │0C │0D │0E │0F │2E ││0G │0H │0I │      │0F     │ 2u Backspace
 *              ├───┼───┤├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤├───┼───┼───┤      └─┬─────┤
 *              │10 │11 ││12   │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D │1E │1F   ││1G │1H │1I │        │     │
 *  2.25u       ├───┼───┤├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤└───┴───┴───┘     ┌──┴┐2F  │ ISO Enter
 *  LShift      │20 │21 ││22    │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C │2D │2F      │                  │1F │    │
 * ┌────────┐   ├───┼───┤├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤    ┌───┐       ┌─┴───┴────┤
 * │32      │   │30 │31 ││32  │33 │34 │35 │36 │37 │38 │39 │3A │3B │3C │3D │3E    │3F │    │3H │       │3E        │ 2.75u RShift
 * └────────┘   ├───┼───┤├────┴┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤┌───┼───┼───┐   └──────────┘
 *              │40 │41 ││42   │43 │44   │48                         │4D   │4E │4F   ││4G │4H │4I │
 *              └───┴───┘└─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘└───┴───┴───┘
 */

#define LAYOUT_all(\
    K00, K01,  K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K2E,    K0G, K0H, K0I,  \
    K10, K11,  K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F,         K1G, K1H, K1I,  \
    K20, K21,  K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F,                         \
    K30, K31,  K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F,              K3H,       \
    K40, K41,  K42, K43, K44,                K48,                     K4D, K4E, K4F,         K4G, K4H, K4I   \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, ___, ___, ___ }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, ___, K3H, ___ }, \
    { K40, K41, K42, K43, K44, ___, ___, ___, K48, ___, ___, ___, ___, K4D, K4E, K4F, K4G, K4H, K4I }  \
}

#define LAYOUT_ansi(\
    K00, K01,   K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F,   K0G, K0H, K0I, \
    K10, K11,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F,   K1G, K1H, K1I, \
    K20, K21,   K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F,                  \
    K30, K31,   K32,      K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3E,        K3H,      \
    K40, K41,   K42, K43, K44,                K48,                     K4D, K4E, K4F,   K4G, K4H, K4I  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, ___, K2F, ___, ___, ___ }, \
    { K30, K31, K32, ___, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, ___, ___, K3H, ___ }, \
    { K40, K41, K42, K43, K44, ___, ___, ___, K48, ___, ___, ___, ___, K4D, K4E, K4F, K4G, K4H, K4I }  \
}

#define LAYOUT_ansi_split_bs_rshift(\
    K00, K01,   K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K2E,   K0G, K0H, K0I, \
    K10, K11,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F,        K1G, K1H, K1I, \
    K20, K21,   K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F,                       \
    K30, K31,   K32,      K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F,             K3H,      \
    K40, K41,   K42, K43, K44,                K48,                     K4D, K4E, K4F,        K4G, K4H, K4I  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, ___, ___, ___ }, \
    { K30, K31, K32, ___, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, ___, K3H, ___ }, \
    { K40, K41, K42, K43, K44, ___, ___, ___, K48, ___, ___, ___, ___, K4D, K4E, K4F, K4G, K4H, K4I }  \
}

#define LAYOUT_iso(\
    K00, K01,   K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F,   K0G, K0H, K0I, \
    K10, K11,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E,        K1G, K1H, K1I, \
    K20, K21,   K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K1F, K2F,                  \
    K30, K31,   K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,      K3E,        K3H,      \
    K40, K41,   K42, K43, K44,                K48,                     K4D, K4E, K4F,   K4G, K4H, K4I  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, ___, K2F, ___, ___, ___ }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, ___, ___, K3H, ___ }, \
    { K40, K41, K42, K43, K44, ___, ___, ___, K48, ___, ___, ___, ___, K4D, K4E, K4F, K4G, K4H, K4I }  \
}

#define LAYOUT_iso_split_bs_rshift(\
    K00, K01,   K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K2E,   K0G, K0H, K0I, \
    K10, K11,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E,             K1G, K1H, K1I, \
    K20, K21,   K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K1F, K2F,                       \
    K30, K31,   K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F,             K3H,      \
    K40, K41,   K42, K43, K44,                K48,                     K4D, K4E, K4F,        K4G, K4H, K4I  \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, ___, ___, ___ }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, ___, K3H, ___ }, \
    { K40, K41, K42, K43, K44, ___, ___, ___, K48, ___, ___, ___, ___, K4D, K4E, K4F, K4G, K4H, K4I }  \
}
