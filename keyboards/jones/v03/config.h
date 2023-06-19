/*
Copyright 2020 Takeshi Nishio

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

#define MATRIX_ROWS 11
#define MATRIX_COLS 11

#define MATRIX_ROW_PINS { D4, D7, C7, F1, F4, F5, D6, D5, E6, B0, B1 }
#define MATRIX_COL_PINS { D4, D7, C7, F1, F4, F5, D6, D5, E6, B0, B1 }

/* Audio */
#ifdef AUDIO_ENABLE
  #define AUDIO_CLICKY
#endif
