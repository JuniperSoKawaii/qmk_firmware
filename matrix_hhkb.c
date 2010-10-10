/*
 * scan matrix
 */
#include <avr/io.h>
#include <util/delay.h>
#include "keymap.h"
#include "matrix.h"
#include "print.h"

// matrix is active low. (key on: 0/key off: 1)
//
// HHKB has no ghost and no bounce.
// row: HC4051 select input channel(0-8)
//      PB0, PB1, PB2(A, B, C)
// col: LS145 select low output line(0-8)
//      PB3, PB4, PB5, PB6(A, B, C, D)
//      use D as ENABLE: (enable: 0/unenable: 1)
// key: KEY: (on: 0/ off:1)
//      UNKNOWN: unknown whether input or output
//      PE6,PE7(KEY, UNKNOWN)
#define COL_ENABLE              (1<<6)
#define KEY_SELELCT(ROW, COL)   (PORTB = COL_ENABLE|(((COL)&0x07)<<3)|((ROW)&0x07))
#define KEY_ENABLE              (PORTB &= ~COL_ENABLE)
#define KEY_UNABLE              (PORTB |=  COL_ENABLE)
#define KEY_ON                  ((PINE&(1<<6)) ? false : true)

// matrix state buffer
uint8_t *matrix;
uint8_t *matrix_prev;
static uint8_t _matrix0[MATRIX_ROWS];
static uint8_t _matrix1[MATRIX_ROWS];


// this must be called once before matrix_scan.
void matrix_init(void)
{
    // row & col output(PB0-6)
    DDRB = 0xFF;
    PORTB = KEY_SELELCT(0, 0);
    // KEY & VALID input w/o pullup(PE6,7)
    DDRE = 0x3F;
    PORTE = 0x00;

    // initialize matrix state: all keys off
    for (int i=0; i < MATRIX_ROWS; i++) _matrix0[i] = 0xFF;
    for (int i=0; i < MATRIX_ROWS; i++) _matrix1[i] = 0xFF;
    matrix = _matrix0;
    matrix_prev = _matrix1;
}

uint8_t matrix_scan(void)
{
    uint8_t state;
    uint8_t *tmp;

    tmp = matrix_prev;
    matrix_prev = matrix;
    matrix = tmp;

    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
//print("scan: "); phex(row); phex(col); print("\n");
            KEY_SELELCT(row, col);
            _delay_us(50);  // from logic analyzer chart
            KEY_ENABLE;
            _delay_us(10);  // from logic analyzer chart
//print("PINE: "); phex(PINE); print("\n");
            if (KEY_ON) {
                matrix[row] &= ~(1<<col);
            } else {
                matrix[row] |= (1<<col);
            }
            KEY_UNABLE;
            _delay_us(150);  // from logic analyzer chart
        }
    }
    return 1;
}

bool matrix_is_modified(void) {
    for (int i=0; i <MATRIX_ROWS; i++) {
        if (matrix[i] != matrix_prev[i])
            return true;
    }
    return false;
}

bool matrix_has_ghost(void) {
    return false;
}

bool matrix_has_ghost_in_row(uint8_t row) {
    return false;
}
