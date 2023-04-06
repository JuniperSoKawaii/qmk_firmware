/* Copyright 2022 GSKY <gskyGit@gsky.com.tw>
 * Copyright 2023 SHVD3x
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

//#define TAP_CODE_DELAY 5

#define GPIO_INPUT_PIN_DELAY 0

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define RGB_MATRIX_LED_FLUSH_LIMIT 10

#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* External spi flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN B14
#define WEAR_LEVELING_BACKING_SIZE (8 * 1024)

/* SPI Config for LED Driver */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN A5
#define SPI_MOSI_PIN A7
#define SPI_MISO_PIN A6

#define DRIVER_1_CS A15
#define DRIVER_2_CS B15
#define DRIVER_1_EN C13
#define DRIVER_2_EN C13

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 67
#define DRIVER_2_LED_TOTAL 20
#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
//(Optional) LED current scaling value (0-255, higher values mean LED is brighter at full PWM). Default 150.
#define AW_SCALING_MAX 255
// (Optional) Driver global current limit (0-255, higher values means the driver may consume more power). Default 150.
#define AW_GLOBAL_CURRENT_MAX 255
