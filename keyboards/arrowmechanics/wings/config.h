/* Copyright 2024 Filip Strzałka <filip@arrowmechanics.com>
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

#define SPLIT_HAND_PIN_LOW_IS_LEFT

#define AUDIO_PIN GP4
#define AUDIO_PWM_DRIVER PWMD2
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_INIT_DELAY
#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(ROCK_A_BYE_BABY)
#endif
