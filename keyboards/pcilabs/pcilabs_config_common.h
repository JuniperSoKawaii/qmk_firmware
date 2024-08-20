/*
Copyright 2024 Mkass420 (@Mkass420)
SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once

#define DEBOUNCE 0
/*
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

#define MUXES 6
#define MUX_PINS { A2, A3, A6, A7, B12, B14 }
#define MUX_SELECTOR_BITS 4
#define MUX_SELECTOR_PINS { B11, B10, B1, B2 }

#define MUX_CHANNELS ( 1 << MUX_SELECTOR_BITS )
*/
#define EECONFIG_KEY_DATA_SIZE 6
#define EECONFIG_KB_DATA_SIZE EECONFIG_KEY_DATA_SIZE * MATRIX_ROWS * MATRIX_COLS + 1

#define DEBUG_ENABLE
#define DEBUG_MATRIX_SCAN_RATE
#define ADC_RESOLUTION ADC_CFGR1_RES_12BIT
#define ADC_SAMPLING_TIME ADC_SMPR_SMP_1P5
#define ADC_RESOLUTION_MAX 1 << 12

#define SMA_SAMPLE_EXP 5
#define SMA_SAMPLE_SIZE (1 << SMA_SAMPLE_EXP)

#ifdef RGB_MATRIX_ENABLE
#    define WS2812_PWM_TARGET_PERIOD 800000
#    define WS2812_PWM_DRIVER PWMD16
#    define WS2812_PWM_CHANNEL 1
#    define WS2812_PWM_PAL_MODE 1
#    define WS2812_DMA_STREAM STM32_DMA1_STREAM3
#    define WS2812_TIMING 1400
#    define WS2812_T1H 975
#    define WS2812_T0H 425
#    define WS2812_TRST_US 350
#endif
