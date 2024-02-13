/* Copyright 2017 Jason Williams
 * Copyright 2018 Jack Humbert
 * Copyright 2018 Yiancar
 * Copyright 2020 MelGeek
 * Copyright 2023 HorrorTroll <https://github.com/HorrorTroll>
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

#include <stdint.h>
#include <stdbool.h>
#include "progmem.h"

typedef struct is31_led {
    uint32_t driver : 2;
    uint32_t r;
    uint32_t g;
    uint32_t b;
} __attribute__((packed)) is31_led;

extern const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT];

void is31fl3729_init(uint8_t addr);
void is31fl3729_write_register(uint8_t addr, uint8_t reg, uint8_t data);
bool is31fl3729_write_pwm_buffer(uint8_t addr, uint8_t *pwm_buffer);

void is31fl3729_set_color(int index, uint8_t red, uint8_t green, uint8_t blue);
void is31fl3729_set_color_all(uint8_t red, uint8_t green, uint8_t blue);

void is31fl3729_set_led_control_register(uint8_t index, bool red, bool green, bool blue);

// This should not be called from an interrupt
// (eg. from a timer interrupt).
// Call this while idle (in between matrix scans).
// If the buffer is dirty, it will update the driver with the buffer.
void is31fl3729_update_pwm_buffers(uint8_t addr, uint8_t index);
void is31fl3729_update_led_control_registers(uint8_t addr, uint8_t index);
void is31fl3729_set_scaling_registers(const is31_led *pled, uint8_t red, uint8_t green, uint8_t blue);

void is31fl3729_set_pwm_buffer(const is31_led *pled, uint8_t red, uint8_t green, uint8_t blue);

// Map CS SW locations to order in PWM / Scaling buffers
// This matches the ORDER in the Datasheet Register not the POSITION
// It will always count from 0x01 to (ISSI_MAX_LEDS - 1)
#ifdef ISSI_MATRIX_16X8
#    define CS1_SW1 0x01
#    define CS2_SW1 0x02
#    define CS3_SW1 0x03
#    define CS4_SW1 0x04
#    define CS5_SW1 0x05
#    define CS6_SW1 0x06
#    define CS7_SW1 0x07
#    define CS8_SW1 0x08
#    define CS9_SW1 0x09
#    define CS10_SW1 0x0A
#    define CS11_SW1 0x0B
#    define CS12_SW1 0x0C
#    define CS13_SW1 0x0D
#    define CS14_SW1 0x0E
#    define CS15_SW1 0x0F
#    define CS16_SW1 0x10

#    define CS1_SW2 0x11
#    define CS2_SW2 0x12
#    define CS3_SW2 0x13
#    define CS4_SW2 0x14
#    define CS5_SW2 0x15
#    define CS6_SW2 0x16
#    define CS7_SW2 0x17
#    define CS8_SW2 0x18
#    define CS9_SW2 0x19
#    define CS10_SW2 0x1A
#    define CS11_SW2 0x1B
#    define CS12_SW2 0x1C
#    define CS13_SW2 0x1D
#    define CS14_SW2 0x1E
#    define CS15_SW2 0x1F
#    define CS16_SW2 0x20

#    define CS1_SW3 0x21
#    define CS2_SW3 0x22
#    define CS3_SW3 0x23
#    define CS4_SW3 0x24
#    define CS5_SW3 0x25
#    define CS6_SW3 0x26
#    define CS7_SW3 0x27
#    define CS8_SW3 0x28
#    define CS9_SW3 0x29
#    define CS10_SW3 0x2A
#    define CS11_SW3 0x2B
#    define CS12_SW3 0x2C
#    define CS13_SW3 0x2D
#    define CS14_SW3 0x2E
#    define CS15_SW3 0x2F
#    define CS16_SW3 0x30

#    define CS1_SW4 0x31
#    define CS2_SW4 0x32
#    define CS3_SW4 0x33
#    define CS4_SW4 0x34
#    define CS5_SW4 0x35
#    define CS6_SW4 0x36
#    define CS7_SW4 0x37
#    define CS8_SW4 0x38
#    define CS9_SW4 0x39
#    define CS10_SW4 0x3A
#    define CS11_SW4 0x3B
#    define CS12_SW4 0x3C
#    define CS13_SW4 0x3D
#    define CS14_SW4 0x3E
#    define CS15_SW4 0x3F
#    define CS16_SW4 0x40

#    define CS1_SW5 0x41
#    define CS2_SW5 0x42
#    define CS3_SW5 0x43
#    define CS4_SW5 0x44
#    define CS5_SW5 0x45
#    define CS6_SW5 0x46
#    define CS7_SW5 0x47
#    define CS8_SW5 0x48
#    define CS9_SW5 0x49
#    define CS10_SW5 0x4A
#    define CS11_SW5 0x4B
#    define CS12_SW5 0x4C
#    define CS13_SW5 0x4D
#    define CS14_SW5 0x4E
#    define CS15_SW5 0x4F
#    define CS16_SW5 0x50

#    define CS1_SW6 0x51
#    define CS2_SW6 0x52
#    define CS3_SW6 0x53
#    define CS4_SW6 0x54
#    define CS5_SW6 0x55
#    define CS6_SW6 0x56
#    define CS7_SW6 0x57
#    define CS8_SW6 0x58
#    define CS9_SW6 0x59
#    define CS10_SW6 0x5A
#    define CS11_SW6 0x5B
#    define CS12_SW6 0x5C
#    define CS13_SW6 0x5D
#    define CS14_SW6 0x5E
#    define CS15_SW6 0x5F
#    define CS16_SW6 0x60

#    define CS1_SW7 0x61
#    define CS2_SW7 0x62
#    define CS3_SW7 0x63
#    define CS4_SW7 0x64
#    define CS5_SW7 0x65
#    define CS6_SW7 0x66
#    define CS7_SW7 0x67
#    define CS8_SW7 0x68
#    define CS9_SW7 0x69
#    define CS10_SW7 0x6A
#    define CS11_SW7 0x6B
#    define CS12_SW7 0x6C
#    define CS13_SW7 0x6D
#    define CS14_SW7 0x6E
#    define CS15_SW7 0x6F
#    define CS16_SW7 0x70

#    define CS1_SW8 0x71
#    define CS2_SW8 0x72
#    define CS3_SW8 0x73
#    define CS4_SW8 0x74
#    define CS5_SW8 0x75
#    define CS6_SW8 0x76
#    define CS7_SW8 0x77
#    define CS8_SW8 0x78
#    define CS9_SW8 0x79
#    define CS10_SW8 0x7A
#    define CS11_SW8 0x7B
#    define CS12_SW8 0x7C
#    define CS13_SW8 0x7D
#    define CS14_SW8 0x7E
#    define CS15_SW8 0x7F
#    define CS16_SW8 0x80

#else

#    define CS1_SW1 0x01
#    define CS2_SW1 0x02
#    define CS3_SW1 0x03
#    define CS4_SW1 0x04
#    define CS5_SW1 0x05
#    define CS6_SW1 0x06
#    define CS7_SW1 0x07
#    define CS8_SW1 0x08
#    define CS9_SW1 0x09
#    define CS10_SW1 0x0A
#    define CS11_SW1 0x0B
#    define CS12_SW1 0x0C
#    define CS13_SW1 0x0D
#    define CS14_SW1 0x0E
#    define CS15_SW1 0x0F

#    define CS1_SW2 0x11
#    define CS2_SW2 0x12
#    define CS3_SW2 0x13
#    define CS4_SW2 0x14
#    define CS5_SW2 0x15
#    define CS6_SW2 0x16
#    define CS7_SW2 0x17
#    define CS8_SW2 0x18
#    define CS9_SW2 0x19
#    define CS10_SW2 0x1A
#    define CS11_SW2 0x1B
#    define CS12_SW2 0x1C
#    define CS13_SW2 0x1D
#    define CS14_SW2 0x1E
#    define CS15_SW2 0x1F

#    define CS1_SW3 0x21
#    define CS2_SW3 0x22
#    define CS3_SW3 0x23
#    define CS4_SW3 0x24
#    define CS5_SW3 0x25
#    define CS6_SW3 0x26
#    define CS7_SW3 0x27
#    define CS8_SW3 0x28
#    define CS9_SW3 0x29
#    define CS10_SW3 0x2A
#    define CS11_SW3 0x2B
#    define CS12_SW3 0x2C
#    define CS13_SW3 0x2D
#    define CS14_SW3 0x2E
#    define CS15_SW3 0x2F

#    define CS1_SW4 0x31
#    define CS2_SW4 0x32
#    define CS3_SW4 0x33
#    define CS4_SW4 0x34
#    define CS5_SW4 0x35
#    define CS6_SW4 0x36
#    define CS7_SW4 0x37
#    define CS8_SW4 0x38
#    define CS9_SW4 0x39
#    define CS10_SW4 0x3A
#    define CS11_SW4 0x3B
#    define CS12_SW4 0x3C
#    define CS13_SW4 0x3D
#    define CS14_SW4 0x3E
#    define CS15_SW4 0x3F

#    define CS1_SW5 0x41
#    define CS2_SW5 0x42
#    define CS3_SW5 0x43
#    define CS4_SW5 0x44
#    define CS5_SW5 0x45
#    define CS6_SW5 0x46
#    define CS7_SW5 0x47
#    define CS8_SW5 0x48
#    define CS9_SW5 0x49
#    define CS10_SW5 0x4A
#    define CS11_SW5 0x4B
#    define CS12_SW5 0x4C
#    define CS13_SW5 0x4D
#    define CS14_SW5 0x4E
#    define CS15_SW5 0x4F

#    define CS1_SW6 0x51
#    define CS2_SW6 0x52
#    define CS3_SW6 0x53
#    define CS4_SW6 0x54
#    define CS5_SW6 0x55
#    define CS6_SW6 0x56
#    define CS7_SW6 0x57
#    define CS8_SW6 0x58
#    define CS9_SW6 0x59
#    define CS10_SW6 0x5A
#    define CS11_SW6 0x5B
#    define CS12_SW6 0x5C
#    define CS13_SW6 0x5D
#    define CS14_SW6 0x5E
#    define CS15_SW6 0x5F

#    define CS1_SW7 0x61
#    define CS2_SW7 0x62
#    define CS3_SW7 0x63
#    define CS4_SW7 0x64
#    define CS5_SW7 0x65
#    define CS6_SW7 0x66
#    define CS7_SW7 0x67
#    define CS8_SW7 0x68
#    define CS9_SW7 0x69
#    define CS10_SW7 0x6A
#    define CS11_SW7 0x6B
#    define CS12_SW7 0x6C
#    define CS13_SW7 0x6D
#    define CS14_SW7 0x6E
#    define CS15_SW7 0x6F

#    define CS1_SW8 0x71
#    define CS2_SW8 0x72
#    define CS3_SW8 0x73
#    define CS4_SW8 0x74
#    define CS5_SW8 0x75
#    define CS6_SW8 0x76
#    define CS7_SW8 0x77
#    define CS8_SW8 0x78
#    define CS9_SW8 0x79
#    define CS10_SW8 0x7A
#    define CS11_SW8 0x7B
#    define CS12_SW8 0x7C
#    define CS13_SW8 0x7D
#    define CS14_SW8 0x7E
#    define CS15_SW8 0x7F

#    define CS1_SW9 0x81
#    define CS2_SW9 0x82
#    define CS3_SW9 0x83
#    define CS4_SW9 0x84
#    define CS5_SW9 0x85
#    define CS6_SW9 0x86
#    define CS7_SW9 0x87
#    define CS8_SW9 0x88
#    define CS9_SW9 0x89
#    define CS10_SW9 0x8A
#    define CS11_SW9 0x8B
#    define CS12_SW9 0x8C
#    define CS13_SW9 0x8D
#    define CS14_SW9 0x8E
#    define CS15_SW9 0x8F
#endif
