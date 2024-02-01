//  Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

#define MAC_OFF 0x1A  //disable mac layer indicator on LED display
#define MAC_ON 0x3B  //enable mac layer indicator on LED diaplay


uint8_t IND = 0;  //buffer of LED Display

#if defined(RGB_MATRIX_ENABLE)  /*&& defined(CAPS_LOCK_INDEX)*/
const aw20216s_led_t PROGMEM g_aw20216s_leds[AW20216S_LED_COUNT] = {
/* Each AW20216 channel is controlled by a register at some offset between 0x00
 * and 0xD7 inclusive.
 * See drivers/awinic/aw20216.h for the mapping between register offsets and
 * driver pin locations.
 *   driver
 *   |  R location
 *   |  |          G location
 *   |  |          |          B location
 *   |  |          |          | */
    {0, CS1_SW1,   CS2_SW1,   CS3_SW1},
    {0, CS1_SW3,   CS2_SW3,   CS3_SW3},
    {0, CS1_SW4,   CS2_SW4,   CS3_SW4},
    {0, CS1_SW5,   CS2_SW5,   CS3_SW5},
    {0, CS1_SW6,   CS2_SW6,   CS3_SW6},
    {0, CS1_SW7,   CS2_SW7,   CS3_SW7},
    {0, CS1_SW8,   CS2_SW8,   CS3_SW8},
    {0, CS1_SW9,   CS2_SW9,   CS3_SW9},
    {0, CS1_SW10,  CS2_SW10,  CS3_SW10},
    {0, CS1_SW11,  CS2_SW11,  CS3_SW11},
    {0, CS1_SW12,  CS2_SW12,  CS3_SW12},
    {0, CS10_SW2,  CS11_SW2,  CS12_SW2},
    {0, CS10_SW3,  CS11_SW3,  CS12_SW3},
      //encoder no led
    {0, CS10_SW5,  CS11_SW5,  CS12_SW5},
    {0, CS10_SW6,  CS11_SW6,  CS12_SW6},
    {0, CS10_SW7,  CS11_SW7,  CS12_SW7},
    {0, CS10_SW8,  CS11_SW8,  CS12_SW8},

    {0, CS4_SW1,   CS5_SW1,   CS6_SW1},
    {0, CS4_SW2,   CS5_SW2,   CS6_SW2},
    {0, CS4_SW3,   CS5_SW3,   CS6_SW3},
    {0, CS4_SW4,   CS5_SW4,   CS6_SW4},
    {0, CS4_SW5,   CS5_SW5,   CS6_SW5},
    {0, CS4_SW6,   CS5_SW6,   CS6_SW6},
    {0, CS4_SW7,   CS5_SW7,   CS6_SW7},
    {0, CS4_SW8,   CS5_SW8,   CS6_SW8},
    {0, CS4_SW9,   CS5_SW9,   CS6_SW9},
    {0, CS4_SW10,  CS5_SW10,  CS6_SW10},
    {0, CS4_SW11,  CS5_SW11,  CS6_SW11},
    {0, CS4_SW12,  CS5_SW12,  CS6_SW12},
    {0, CS13_SW2,  CS14_SW2,  CS15_SW2},
    {0, CS13_SW3,  CS14_SW3,  CS15_SW3},
    {0, CS13_SW4,  CS14_SW4,  CS15_SW4},
    {0, CS13_SW5,  CS14_SW5,  CS15_SW5},
    {0, CS13_SW6,  CS14_SW6,  CS15_SW6},
    {0, CS13_SW7,  CS14_SW7,  CS15_SW7},

    {0, CS7_SW1,   CS8_SW1,   CS9_SW1},
    {0, CS7_SW2,   CS8_SW2,   CS9_SW2},
    {0, CS7_SW3,   CS8_SW3,   CS9_SW3},
    {0, CS7_SW4,   CS8_SW4,   CS9_SW4},
    {0, CS7_SW5,   CS8_SW5,   CS9_SW5},
    {0, CS7_SW6,   CS8_SW6,   CS9_SW6},
    {0, CS7_SW7,   CS8_SW7,   CS9_SW7},
    {0, CS7_SW8,   CS8_SW8,   CS9_SW8},
    {0, CS7_SW9,   CS8_SW9,   CS9_SW9},
    {0, CS7_SW10,  CS8_SW10,  CS9_SW10},
    {0, CS7_SW11,  CS8_SW11,  CS9_SW11},
    {0, CS7_SW12,  CS8_SW12,  CS9_SW12},
    {0, CS16_SW2,  CS17_SW2,  CS18_SW2},
    {0, CS16_SW3,  CS17_SW3,  CS18_SW3},
    {0, CS16_SW4,  CS17_SW4,  CS18_SW4},
    {0, CS16_SW5,  CS17_SW5,  CS18_SW5},
    {0, CS16_SW6,  CS17_SW6,  CS18_SW6},
    {0, CS16_SW7,  CS17_SW7,  CS18_SW7},


    {1, CS1_SW1,   CS2_SW1,   CS3_SW1},
    {1, CS1_SW2,   CS2_SW2,   CS3_SW2},
    {1, CS1_SW3,   CS2_SW3,   CS3_SW3},
    {1, CS1_SW4,   CS2_SW4,   CS3_SW4},
    {1, CS1_SW5,   CS2_SW5,   CS3_SW5},
    {1, CS1_SW6,   CS2_SW6,   CS3_SW6},
    {1, CS1_SW7,   CS2_SW7,   CS3_SW7},
    {1, CS1_SW8,   CS2_SW8,   CS3_SW8},
    {1, CS1_SW9,   CS2_SW9,   CS3_SW9},
    {1, CS1_SW10,  CS2_SW10,  CS3_SW10},
    {1, CS1_SW11,  CS2_SW11,  CS3_SW11},
    {1, CS1_SW12,  CS2_SW12,  CS3_SW12},
    {1, CS10_SW3,  CS11_SW3,  CS12_SW3},
    {1, CS10_SW4,  CS11_SW4,  CS12_SW4},
    {1, CS10_SW5,  CS11_SW5,  CS12_SW5},
    {1, CS10_SW6,  CS11_SW6,  CS12_SW6},

    {1, CS4_SW1,   CS5_SW1,   CS6_SW1},
    {1, CS4_SW2,   CS5_SW2,   CS6_SW2},
    {1, CS4_SW3,   CS5_SW3,   CS6_SW3},
    {1, CS4_SW4,   CS5_SW4,   CS6_SW4},
    {1, CS4_SW5,   CS5_SW5,   CS6_SW5},
    {1, CS4_SW6,   CS5_SW6,   CS6_SW6},
    {1, CS4_SW7,   CS5_SW7,   CS6_SW7},
    {1, CS4_SW8,   CS5_SW8,   CS6_SW8},
    {1, CS4_SW9,   CS5_SW9,   CS6_SW9},
    {1, CS4_SW10,  CS5_SW10,  CS6_SW10},
    {1, CS4_SW11,  CS5_SW11,  CS6_SW11},
    {1, CS13_SW2,  CS14_SW2,  CS15_SW2},
    {1, CS13_SW3,  CS14_SW3,  CS15_SW3},
    {1, CS13_SW4,  CS14_SW4,  CS15_SW4},
    {1, CS13_SW5,  CS14_SW5,  CS15_SW5},
    {1, CS13_SW6,  CS14_SW6,  CS15_SW6},
    {1, CS13_SW7,  CS14_SW7,  CS15_SW7},


    {1, CS7_SW1,   CS8_SW1,   CS9_SW1},
    {1, CS7_SW2,   CS8_SW2,   CS9_SW2},
    {1, CS7_SW3,   CS8_SW3,   CS9_SW3},
    {1, CS7_SW5,   CS8_SW5,   CS9_SW5},
    {1, CS7_SW6,   CS8_SW6,   CS9_SW6},
    {1, CS7_SW8,   CS8_SW8,   CS9_SW8},
    {1, CS7_SW10,  CS8_SW10,  CS9_SW10},
    {1, CS7_SW11,  CS8_SW11,  CS9_SW11},
    {1, CS7_SW12,  CS8_SW12,  CS9_SW12},
    {1, CS16_SW2,  CS17_SW2,  CS18_SW2},
    {1, CS16_SW3,  CS17_SW3,  CS18_SW3},
    {1, CS16_SW4,  CS17_SW4,  CS18_SW4},
    {1, CS16_SW5,  CS17_SW5,  CS18_SW5},
    {1, CS16_SW6,  CS17_SW6,  CS18_SW6}
};

#endif



void suspend_power_down_kb() {
#    ifdef RGB_MATRIX_ENABLE
    writePinLow(SDB);
#    endif
    writePinLow(MAC_PIN);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb() {
#    ifdef RGB_MATRIX_ENABLE
    writePinHigh(SDB);
#    endif
    suspend_wakeup_init_user();
}

bool shutdown_kb(bool jump_to_bootloader) {
    writePinLow(SDB);
    return shutdown_user(jump_to_bootloader);
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        writePinLow(MAC_PIN);
        IND =& MAC_OFF;
        serial_to_parallel(IND);
        break;
    case 1:
        writePinHigh(MAC_PIN);
        IND =|| MAC_ON;
        serial_to_parallel(IND);
        break;
    }
  return state;
}


bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }

    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 255, 255, 255);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_INDEX, 0, 0, 0);
        }
    }

   switch (get_highest_layer(layer_state)) {
      case 2:{
        RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 255, 255, 255);
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
         }
      } break;
      case 3:{
        RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 255, 255, 255);
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
         }
      } break;

      case 0:{
       if (L_WIN) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 255, 255, 255);
            if (!rgb_matrix_get_flags()) {
               RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
            }
            }else{
                if (!rgb_matrix_get_flags()) {
                   RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
                 }
              }
         } break;

     case 1:{
       if (L_MAC) {
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 255, 255, 255);
            if (!rgb_matrix_get_flags()) {
               RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
            }
            }else{
                if (!rgb_matrix_get_flags()) {
                   RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
                 }
              }
         } break;

      default:{
         if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(WIN_MOD_INDEX, 0, 0, 0);
            RGB_MATRIX_INDICATOR_SET_COLOR(MAC_MOD_INDEX, 0, 0, 0);
         }
      }
    }
    return false;
}


void board_init(void) {
    // JTAG-DP Disabled and SW-DP Disabled
    AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk) | AFIO_MAPR_SWJ_CFG_DISABLE;
#   ifdef RGB_MATRIX_ENABLE
    setPinOutput(SDB);
    writePinHigh(SDB);
#   endif
    setPinOutput(MAC_PIN);
    writePinHigh(MAC_PIN);
}

/*
LED display driver
*/
#define ClockTime 15
#define HC595_ST_PIN A6  //74HC595 storage register clock input
#define HC595_SH_PIN A5  //74HC595 shift register clock input
#define HC595_DS A7   // 74HC595 serial data input

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinOutput_writeHigh(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinHigh(pin);
    }
}

static inline void select_delay(uint16_t n) {
    while (n-- > 0) {
        asm volatile("nop" ::: "memory");
    };
}

static inline void clockPulse(uint16_t n) {
    writePinHigh(HC595_SH_PIN);
    writePinHigh(HC595_ST_PIN);
    select_delay(n);
    writePinLow(HC595_SH_PIN);
    writePinLow(HC595_ST_PIN);
}

void serial_to_parallel(uint8_t data) { // 串口转并口函数
    setPinOutput_writeLow(HC595_DS);
    setPinOutput_writeLow(HC595_SH_PIN);
    setPinOutput_writeLow(HC595_ST_PIN);
    for(uint8_t i = 0; i < 8; i++) { // 循环8次，每次输出一位数据
        HC595_DS = (data & 0x01); // 将最低位写入串口数据输入端
        clockPulse(ClockTime);
        data >>= 1; // 将数据右移一位，准备输出下一位数据
    }
}