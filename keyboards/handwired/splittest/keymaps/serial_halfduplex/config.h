// Copyright 2022 dvermd (@dvermd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#if defined(BLUEPILL)

    #if defined(USE_SDI1_ON_STANDARD_ROLE_PINS)
        #define SOFT_SERIAL_PIN A9
    #elif defined(USE_SDI1_ON_ALTERNATE_ROLE_PINS)
        #define SOFT_SERIAL_PIN B6
        #define USART1_REMAP               // Remap USART TX and RX pins on STM32F103 MCUs
    #elif defined(USE_SDI2)
        #define SOFT_SERIAL_PIN A2
        #define SERIAL_USART_DRIVER SD2    // USART driver of TX and RX pin. default: SD1
    #else
        #error "splittest serial_halfduplex keymap is missing a configuration (USE_SDI1_ON_STANDARD_ROLE_PINS, USE_SDI1_ON_ALTERNATE_ROLE_PINS, USE_SDI2)"
    #endif
#else
    #error "splittest serial_halfduplex keymap not implemented for this MCU yet"
#endif
