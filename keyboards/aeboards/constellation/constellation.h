/* Copyright 2018 Jason Williams (Wilba)
 * Copyright 2021 Harrison Chan (Xelus)
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

#if defined(KEYBOARD_aeboards_constellation_rev1)
    #include "rev1.h"
#elif defined(KEYBOARD_aeboards_constellation_rev2)
    #include "rev2.h"
#elif defined(KEYBOARD_aeboards_constellation_rev3)
    #include "rev3.h"
#endif
