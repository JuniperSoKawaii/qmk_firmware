/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

// matrix state buffer(1:on, 0:off)
static uint16_t *matrix;
static uint16_t *matrix_prev;
static uint16_t _matrix0[MATRIX_ROWS];
static uint16_t _matrix1[MATRIX_ROWS];

static uint16_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix0[i] = 0;
    for (uint8_t i=0; i < MATRIX_ROWS; i++) _matrix1[i] = 0;
    matrix = _matrix0;
    matrix_prev = _matrix1;
}

uint8_t matrix_scan(void)
{
    if (!debouncing) {
        uint16_t *tmp = matrix_prev;
        matrix_prev = matrix;
        matrix = tmp;
    }

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        unselect_rows();
        select_row(i);
        _delay_us(1);  // without this wait read unstable value.
        uint16_t cols = ~read_cols();
        if (matrix[i] != cols) {
            matrix[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); print("\n");
            }
            debouncing = DEBOUNCE;
        }
    }
    unselect_rows();

    if (debouncing) {
        debouncing--;
        _delay_ms(1); // improved affect on bouncing
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (matrix[i] != matrix_prev[i]) {
            return true;
        }
    }
    return false;
}

inline
bool matrix_has_ghost(void)
{
    return false;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & (1<<col));
}

inline
uint16_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 01234567\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 * pin: F0  F1  E6  C7  C6  B6  D4  B1  B0  B5  B4  D7  D6  B3
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRF  &= ~(1<<0 | 1<<1);
    PORTF |=  (1<<0 | 1<<1);
    DDRE  &= ~(1<<6);
    PORTE |=  (1<<6);
    DDRD  &= ~(1<<7 | 1<<6 | 1<<4);
    PORTD |=  (1<<7 | 1<<6 | 1<<4);
    DDRC  &= ~(1<<7 | 1<<6);
    PORTC |=  (1<<7 | 1<<6);
    DDRB  &= ~(1<<6 | 1<< 5 | 1<<4 | 1<<3 | 1<<1 | 1<<0);
    PORTB |=  (1<<6 | 1<< 5 | 1<<4 | 1<<3 | 1<<1 | 1<<0);
}

static uint16_t read_cols(void)
{
    return (PINF&(1<<0) ? (1<<0)  : 0) |
           (PINF&(1<<1) ? (1<<1)  : 0) |
           (PINE&(1<<6) ? (1<<2)  : 0) |
           (PINC&(1<<7) ? (1<<3)  : 0) |
           (PINC&(1<<6) ? (1<<4)  : 0) |
           (PINB&(1<<6) ? (1<<5)  : 0) |
           (PIND&(1<<4) ? (1<<6)  : 0) |
           (PINB&(1<<1) ? (1<<7)  : 0) |
           (PINB&(1<<0) ? (1<<8)  : 0) |
           (PINB&(1<<5) ? (1<<9)  : 0) |
           (PINB&(1<<4) ? (1<<10) : 0) |
           (PIND&(1<<7) ? (1<<11) : 0) |
           (PIND&(1<<6) ? (1<<12) : 0) |
           (PINB&(1<<3) ? (1<<13) : 0);
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: D0  D1  D2  D3  D5
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRD  &= ~0b00101111;
    PORTD &= ~0b00101111;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRD  |= (1<<0);
            PORTD &= ~(1<<0);
            break;
        case 1:
            DDRD  |= (1<<1);
            PORTD &= ~(1<<1);
            break;
        case 2:
            DDRD  |= (1<<2);
            PORTD &= ~(1<<2);
            break;
        case 3:
            DDRD  |= (1<<3);
            PORTD &= ~(1<<3);
            break;
        case 4:
            DDRD  |= (1<<5);
            PORTD &= ~(1<<5);
            break;
    }
}
