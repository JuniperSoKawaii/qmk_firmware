/* Copyright 2020 Purdea Andrei
 * Copyright 2021 Matthew J Wolf
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

#define CAPSENSE_DAC_MCP4921
#define CAPSENSE_DAC_NCS F6
#define CAPSENSE_DAC_SCK B1
#define CAPSENSE_DAC_SDI B2
#define CAPSENSE_DAC_MAX 4095

#define CAPSENSE_SHIFT_DIN  B2
#define CAPSENSE_SHIFT_OE   B6
#define CAPSENSE_SHIFT_SHCP B1
#define CAPSENSE_SHIFT_STCP F7
#define CAPSENSE_SHIFT_STCP_IO _SFR_IO_ADDR(PORTF)
#define CAPSENSE_SHIFT_STCP_BIT 7

// Rows:
// Physical position from left to right: (only the right-most are used for beamspring)
// 1    2    3    4    5    6    7    8
// TH schematic numbering (sense/row lines)
// 8    6    7    5    4    3    2    1
// F5,  B5,  F4,  B4,  D4,  C6,  D1,  D0

// pull-ups are only necessary for some variants of the TH controller design:
#if MATRIX_CAPSENSE_ROWS > 4
  #define SETUP_ROW_GPIOS() \
        do { \
            PORTF |= (1 << 5) | (1 << 4); \
            PORTB |= (1 << 5) | (1 << 4); \
            PORTD |= (1 << 4) | (1 << 1) | (1 << 0); \
            PORTC |= (1 << 6); \
        } while (0)
#else
  #define SETUP_ROW_GPIOS() \
        do { \
            PORTD |= (1 << 4) | (1 << 1) | (1 << 0); \
            PORTC |= (1 << 6); \
        } while (0)
#endif

#if 1
#define SETUP_UNUSED_PINS() do {} while (0)
#else
// TODO ENABLE THIS ONCE TESTED
#define SETUP_UNUSED_PINS() \
    do { \
        PORTB |= ~(DDRB | 0x77); \
        PORTC |= ~(DDRC | (1 << 6)); \
        PORTD |= ~(DDRD | 0x33); \
        PORTE |= ~(DDRE); \
        PORTF |= ~(DDRF | 0xf0); \
    } while (0)
#endif

#if MATRIX_CAPSENSE_ROWS <= 4
  #define CAPSENSE_READ_ROWS_NUMBER_OF_BYTES_PER_SAMPLE 2
  #define CAPSENSE_READ_ROWS_PIN_1 _SFR_IO_ADDR(PINC)
  #define CAPSENSE_READ_ROWS_PIN_2 _SFR_IO_ADDR(PIND)
  #define CAPSENSE_READ_ROWS_ASM_INSTRUCTIONS "in %[dest_row_1], %[ioreg_row_1]\n\tin %[dest_row_2], %[ioreg_row_2]"
  #define CAPSENSE_READ_ROWS_STORE_TO_ARRAY_INSTRUCTIONS \
            "st %a[arr]+, %[dest_row_1]"       "\n\t" \
            "st %a[arr]+, %[dest_row_2]"
  #define CAPSENSE_READ_ROWS_STORE_TO_ARRAY_INSTRUCTIONS_FAKE \
            "st %a[arr], %[dest_row_1]"       "\n\t" \
            "st %a[arr], %[dest_row_2]"
  #define CAPSENSE_READ_ROWS_OUTPUT_CONSTRAINTS [dest_row_1] "=&r" (dest_row_1), [dest_row_2] "=&r" (dest_row_2)
  #define CAPSENSE_READ_ROWS_INPUT_CONSTRAINTS [ioreg_row_1] "I" (CAPSENSE_READ_ROWS_PIN_1), [ioreg_row_2] "I" (CAPSENSE_READ_ROWS_PIN_2)
  #define CAPSENSE_READ_ROWS_LOCAL_VARS uint8_t dest_row_1, dest_row_2
  #define CAPSENSE_READ_ROWS_VALUE (((dest_row_1 >> 4) & 0x04) | (dest_row_2 & 0x03) | ((dest_row_2 >> 1) & 0x08))
  #define CAPSENSE_READ_ROWS_EXTRACT_FROM_ARRAY do { dest_row_1 = array[p0++]; dest_row_2 = array[p0++]; } while (0)
#else
  #define CAPSENSE_READ_ROWS_NUMBER_OF_BYTES_PER_SAMPLE 4
  #define CAPSENSE_READ_ROWS_PIN_1 _SFR_IO_ADDR(PINC)
  #define CAPSENSE_READ_ROWS_PIN_2 _SFR_IO_ADDR(PIND)
  #define CAPSENSE_READ_ROWS_PIN_3 _SFR_IO_ADDR(PINB)
  #define CAPSENSE_READ_ROWS_PIN_4 _SFR_IO_ADDR(PINF)
  #define CAPSENSE_READ_ROWS_ASM_INSTRUCTIONS "in %[dest_row_1], %[ioreg_row_1]\n\tin %[dest_row_2], %[ioreg_row_2]\n\tin %[dest_row_3], %[ioreg_row_3]\n\tin %[dest_row_4], %[ioreg_row_4]"
  #define CAPSENSE_READ_ROWS_STORE_TO_ARRAY_INSTRUCTIONS \
            "st %a[arr]+, %[dest_row_1]"       "\n\t" \
            "st %a[arr]+, %[dest_row_2]"       "\n\t" \
            "st %a[arr]+, %[dest_row_3]"       "\n\t" \
            "st %a[arr]+, %[dest_row_4]"
  #define CAPSENSE_READ_ROWS_STORE_TO_ARRAY_INSTRUCTIONS_FAKE \
            "st %a[arr], %[dest_row_1]"       "\n\t" \
            "st %a[arr], %[dest_row_2]"       "\n\t" \
            "st %a[arr], %[dest_row_3]"       "\n\t" \
            "st %a[arr], %[dest_row_4]"
  #define CAPSENSE_READ_ROWS_OUTPUT_CONSTRAINTS [dest_row_1] "=&r" (dest_row_1), [dest_row_2] "=&r" (dest_row_2), [dest_row_3] "=&r" (dest_row_3), [dest_row_4] "=&r" (dest_row_4)
  #define CAPSENSE_READ_ROWS_INPUT_CONSTRAINTS [ioreg_row_1] "I" (CAPSENSE_READ_ROWS_PIN_1), [ioreg_row_2] "I" (CAPSENSE_READ_ROWS_PIN_2), [ioreg_row_3] "I" (CAPSENSE_READ_ROWS_PIN_3), [ioreg_row_4] "I" (CAPSENSE_READ_ROWS_PIN_4)
  #define CAPSENSE_READ_ROWS_LOCAL_VARS uint8_t dest_row_1, dest_row_2, dest_row_3, dest_row_4
  #define CAPSENSE_READ_ROWS_VALUE (((dest_row_1 >> 4) & 0x04) | (dest_row_2 & 0x03) | ((dest_row_2 >> 1) & 0x08) | (dest_row_3 & 0x10) | ((dest_row_3 << 1) & 0x40) | ((dest_row_4 << 1) & 0x20) | ((dest_row_4 << 2) & 0x80))
  #define CAPSENSE_READ_ROWS_EXTRACT_FROM_ARRAY do { dest_row_1 = array[p0++]; dest_row_2 = array[p0++]; dest_row_3 = array[p0++]; dest_row_4 = array[p0++]; } while (0)
#endif

#define CAPSENSE_KEYMAP_ROW_TO_PHYSICAL_ROW(row) (MATRIX_CAPSENSE_ROWS-1-(row))
#define CAPSENSE_PHYSICAL_ROW_TO_KEYMAP_ROW(row) (MATRIX_CAPSENSE_ROWS-1-(row))

#ifndef CAPSENSE_KEYMAP_COL_TO_PHYSICAL_COL
  #define CAPSENSE_KEYMAP_COL_TO_PHYSICAL_COL(col) (col)
#endif

#if (!defined(CAPSENSE_CONDUCTIVE_PLASTIC_IS_PUSHED_DOWN_ON_KEYPRESS)) && (!defined(CAPSENSE_CONDUCTIVE_PLASTIC_IS_PULLED_UP_ON_KEYPRESS))
#  if defined(CONTROLLER_IS_THROUGH_HOLE_BEAMSPRING)
      #define CAPSENSE_CONDUCTIVE_PLASTIC_IS_PULLED_UP_ON_KEYPRESS
#  else
      #define CAPSENSE_CONDUCTIVE_PLASTIC_IS_PUSHED_DOWN_ON_KEYPRESS
#  endif
#endif
