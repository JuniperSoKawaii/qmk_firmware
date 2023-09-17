/* Copyright 2023 HorrorTroll <https://github.com/HorrorTroll>
 * Copyright 2023 Harrison Chan (Xelus)
 * Copyright 2023 Dimitris Mantzouranis <d3xter93@gmail.com>
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

#include "is31fl3729-simple.h"
#include <string.h>
#include "i2c_master.h"
#include "wait.h"

// Registers
#define IS31FL3729_REG_SCALING 0x90
#define IS31FL3729_REG_CONFIGURATION 0xA0
#define IS31FL3729_REG_GLOBALCURRENT 0xA1
#define IS31FL3729_REG_PULLDOWNUP 0xB0
#define IS31FL3729_REG_SPREAD_SPECTRUM 0xB1
#define IS31FL3729_REG_PWM_FREQUENCY 0xB2
#define IS31FL3729_REG_RESET 0xCF

// Set defaults for Timeout and Persistence
#ifndef IS31FL3729_I2C_TIMEOUT
#    define IS31FL3729_I2C_TIMEOUT 100
#endif
#ifndef IS31FL3729_I2C_PERSISTENCE
#    define IS31FL3729_I2C_PERSISTENCE 0
#endif

// Set defaults for Registers
#ifndef IS31FL3729_CONFIGURATION
#    define IS31FL3729_CONFIGURATION 0x01
#endif
#ifndef IS31FL3729_GLOBALCURRENT
#    define IS31FL3729_GLOBALCURRENT 0x40
#endif
#ifndef IS31FL3729_PULLDOWNUP
#    define IS31FL3729_PULLDOWNUP 0x33
#endif
#ifndef IS31FL3729_SPREAD_SPECTRUM
#    define IS31FL3729_SPREAD_SPECTRUM 0x00
#endif
#ifndef IS31FL3729_PWM_FREQUENCY
#    define IS31FL3729_PWM_FREQUENCY 0x01
#endif

// Set buffer sizes
#define IS31FL3729_MAX_LEDS 143
#define IS31FL3729_MAX_SCALINGS 16

// Transfer buffer for TWITransmitData()
uint8_t g_twi_transfer_buffer[20];

// These buffers match the PWM & scaling registers.
// Storing them like this is optimal for I2C transfers to the registers.
uint8_t g_pwm_buffer[IS31FL3729_DRIVER_COUNT][IS31FL3729_MAX_LEDS];
bool    g_pwm_buffer_update_required[IS31FL3729_DRIVER_COUNT] = {false};

uint8_t g_scaling_registers[IS31FL3729_DRIVER_COUNT][IS31FL3729_MAX_SCALINGS];
bool    g_scaling_registers_update_required[IS31FL3729_DRIVER_COUNT] = {false};

void is31fl3729_write_register(uint8_t addr, uint8_t reg, uint8_t data) {
    // Set register address and register data ready to write
    g_twi_transfer_buffer[0] = reg;
    g_twi_transfer_buffer[1] = data;

#if IS31FL3729_I2C_PERSISTENCE > 0
    for (uint8_t i = 0; i < IS31FL3729_I2C_PERSISTENCE; i++) {
        if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 2, IS31FL3729_I2C_TIMEOUT) == 0) break;
    }
#else
    i2c_transmit(addr << 1, g_twi_transfer_buffer, 2, IS31FL3729_I2C_TIMEOUT);
#endif
}

bool is31fl3729_write_pwm_buffer(uint8_t addr, uint8_t *pwm_buffer) {
    // iterate over the pwm_buffer contents at IS31FL3729_MAX_SCALINGS byte intervals
    // datasheet does not mention it, but it auto-increments in 15x9 mode, and
    // hence does not require us to skip any addresses
    for (int i = 0; i <= IS31FL3729_MAX_LEDS; i += IS31FL3729_MAX_SCALINGS) {
        g_twi_transfer_buffer[0] = i;

        // copy the data from i to i+IS31FL3729_MAX_SCALINGS
        // device will auto-increment register for data after the first byte
        // thus this sets registers 0x01-0x10, 0x11-0x20, etc. in one transfer
        memcpy(g_twi_transfer_buffer + 1, pwm_buffer + i, IS31FL3729_MAX_SCALINGS);

#if IS31FL3729_I2C_PERSISTENCE > 0
        for (uint8_t i = 0; i < IS31FL3729_I2C_PERSISTENCE; i++) {
            if (i2c_transmit(addr << 1, g_twi_transfer_buffer, IS31FL3729_MAX_SCALINGS + 1, IS31FL3729_I2C_TIMEOUT) != 0) {
                return false;
            }
        }
#else
        if (i2c_transmit(addr << 1, g_twi_transfer_buffer, IS31FL3729_MAX_SCALINGS + 1, IS31FL3729_I2C_TIMEOUT) != 0) {
            return false;
        }
#endif
    }

    return true;
}

void is31fl3729_init(uint8_t addr) {
    // In order to avoid the LEDs being driven with garbage data
    // in the LED driver's PWM registers, shutdown is enabled last.
    // Set up the mode and other settings, clear the PWM registers,
    // then disable software shutdown.

    // Set Pull up & Down for SWx CSy
    is31fl3729_write_register(addr, IS31FL3729_REG_PULLDOWNUP, IS31FL3729_PULLDOWNUP);

    // Set Spread Spectrum Register if applicable
    is31fl3729_write_register(addr, IS31FL3729_REG_SPREAD_SPECTRUM, IS31FL3729_SPREAD_SPECTRUM);

    // Set PWM Frequency Register if applicable
    is31fl3729_write_register(addr, IS31FL3729_REG_PWM_FREQUENCY, IS31FL3729_PWM_FREQUENCY);

    // Set Golbal Current Control Register
    is31fl3729_write_register(addr, IS31FL3729_REG_GLOBALCURRENT, IS31FL3729_GLOBALCURRENT);

    // Set to Normal operation
    is31fl3729_write_register(addr, IS31FL3729_REG_CONFIGURATION, IS31FL3729_CONFIGURATION);

    // Wait 10ms to ensure the device has woken up.
    wait_ms(10);
}

void is31fl3729_set_value(int index, uint8_t value) {
    is31_led led;
    if (index >= 0 && index < LED_MATRIX_LED_COUNT) {
        memcpy_P(&led, (&g_is31_leds[index]), sizeof(led));

        if (g_pwm_buffer[led.driver][led.v] == value) {
            return;
        }

        g_pwm_buffer_update_required[led.driver] = true;
        g_pwm_buffer[led.driver][led.v]          = value;
    }
}

void is31fl3729_set_value_all(uint8_t value) {
    for (int i = 0; i < LED_MATRIX_LED_COUNT; i++) {
        is31fl3729_set_value(i, value);
    }
}

void is31fl3729_set_led_control_register(uint8_t index, bool value) {
    is31_led led;
    memcpy_P(&led, (&g_is31_leds[index]), sizeof(led));

    // need to do a bit of checking here since 3729 scaling is per CS pin.
    // not the usual per single LED key as per other ISSI drivers
    // only enable them, since they should be default disabled
    int cs_value = (led.v & 0x0F) - 1;

    if (value) {
        g_scaling_registers[led.driver][cs_value] = 0xFF;
    }

    g_scaling_registers_update_required[led.driver] = true;
}

void is31fl3729_update_pwm_buffers(uint8_t addr, uint8_t index) {
    if (g_pwm_buffer_update_required[index]) {
        is31fl3729_write_pwm_buffer(addr, g_pwm_buffer[index]);
    }

    g_pwm_buffer_update_required[index] = false;
}

void is31fl3729_update_led_control_registers(uint8_t addr, uint8_t index) {
    if (g_scaling_registers_update_required[index]) {
        for (int i = 0; i < IS31FL3729_MAX_SCALINGS; i++) {
            is31fl3729_write_register(addr, IS31FL3729_REG_SCALING + i, g_scaling_registers[index][i]);
        }

        g_scaling_registers_update_required[index] = false;
    }
}
