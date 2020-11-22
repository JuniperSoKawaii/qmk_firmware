 /* Copyright 2020 Andrew Kannan
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

#include "sagittarius.h"

void keyboard_pre_init_kb(void) {
    setPinOutput(INDICATOR_PIN_0);
    setPinOutput(INDICATOR_PIN_1);
    setPinOutput(INDICATOR_PIN_2);

    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    bool runDefault = led_update_user(led_state);
    if (runDefault) {
      writePin(INDICATOR_PIN_0, led_state.num_lock);
      writePin(INDICATOR_PIN_1, led_state.caps_lock);
      writePin(INDICATOR_PIN_2, led_state.scroll_lock);
    }
    return runDefault;
}
