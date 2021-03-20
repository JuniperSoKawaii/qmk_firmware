/* Copyright 2020 Neil Brian Ramirez
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

#include "n40_o.h"

void matrix_scan_kb(void) {
    encoder_action_unregister();
    matrix_scan_user();
}

void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    // encoder_update_user(index, clockwise);
};