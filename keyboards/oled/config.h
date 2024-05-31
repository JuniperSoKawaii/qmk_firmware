// Copyright 2024 k-jun (@k-jun)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define OLED_DISPLAY_128X32
#define I2C_DRIVER SSD1306
#define I2C1_SDA_PIN D2
#define I2C1_SCL_PIN D3
