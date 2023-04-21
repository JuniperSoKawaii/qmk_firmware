/*
Copyright 2023 SHVD3x
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

#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#define rows_bits   PAL_PORT_BIT(PAL_PAD(B0)) | PAL_PORT_BIT(PAL_PAD(B1)) | PAL_PORT_BIT(PAL_PAD(B2)) | PAL_PORT_BIT(PAL_PAD(B3)) | PAL_PORT_BIT(PAL_PAD(B4)) | PAL_PORT_BIT(PAL_PAD(B5)) | PAL_PORT_BIT(PAL_PAD(B6)) | PAL_PORT_BIT(PAL_PAD(B7)) | PAL_PORT_BIT(PAL_PAD(B8)) | PAL_PORT_BIT(PAL_PAD(B9)) | PAL_PORT_BIT(PAL_PAD(B10)) | PAL_PORT_BIT(PAL_PAD(B12))
#define cols_bits   PAL_PORT_BIT(PAL_PAD(A0)) | PAL_PORT_BIT(PAL_PAD(A1)) | PAL_PORT_BIT(PAL_PAD(A2)) | PAL_PORT_BIT(PAL_PAD(A3)) | PAL_PORT_BIT(PAL_PAD(A4)) | PAL_PORT_BIT(PAL_PAD(A8)) | PAL_PORT_BIT(PAL_PAD(A9)) | PAL_PORT_BIT(PAL_PAD(A10))

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

// matrix code
// ultra fast read_cols code
static inline matrix_row_t read_cols(void) {
    uint16_t portA_pin_state = (PAL_PORT(A0))->IDR;
    return (((portA_pin_state & ((1U << 5) - 1U)) ^ ((1U << 5) - 1U)) |
            (((portA_pin_state >> (PAL_PAD(A8) - 5)) & (((1U << 3) - 1U) << 5)) ^ ((((1U << 3) - 1U)) << 5)));
}


static inline void unselect_rows(void) {
    ATOMIC_BLOCK_FORCEON {
    pal_lld_setport(PAL_PORT(B0), rows_bits);
    }
}


static inline void select_row(uint8_t row) {
    if (row != 11)
        ATOMIC_BLOCK_FORCEON {
        pal_lld_clearport(PAL_PORT(B0), PAL_PORT_BIT(row));
        }
    else
        ATOMIC_BLOCK_FORCEON {
        pal_lld_clearport(PAL_PORT(B12), PAL_PORT_BIT(PAL_PAD(B12)));
        }
}


// Only need to init the pins. Debounce / raw matrix are initialized already for us.
void matrix_init_custom(void) {
    // initialize key pins
    ATOMIC_BLOCK_FORCEON {
        pal_lld_setgroupmode(PAL_PORT(B0), rows_bits, 0U, (PAL_WB32_MODE_OUTPUT | PAL_WB32_OTYPE_PUSHPULL | PAL_WB32_OSPEED_HIGH | PAL_WB32_CURRENT_LEVEL3));
        pal_lld_setport(PAL_PORT(B0), rows_bits);
        pal_lld_setgroupmode(PAL_PORT(A0), cols_bits, 0U, (PAL_WB32_MODE_INPUT | PAL_WB32_PUPDR_PULLUP | PAL_WB32_OSPEED_HIGH));
    }
}

// Only need to scan the result into current_matrix, and return changed.
uint8_t matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    // Set col, read rows
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        select_row(current_row);
        matrix_output_select_delay();
        matrix_row_t cols = read_cols();

        unselect_rows();

        changed |= (current_matrix[current_row] != cols);
        current_matrix[current_row] = cols;
 
        while ((((PAL_PORT(A0))->IDR) & ((((1U << 5) - 1U)) | (((1U << 3) - 1U) << 8))) != ((((1U << 5) - 1U)) | (((1U << 3) - 1U) << 8)))    // Wait for all Col signals to go HIGH
            chSysPolledDelayX(RTC2US(REALTIME_COUNTER_CLOCK, 48));
            //wait_us(1);
        //wait_us(MATRIX_IO_DELAY);

    }

    return changed;
}
