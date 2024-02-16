#include "ws2812.h"

#include "gpio.h"
#include "chibios_config.h"

/* Adapted from https://github.com/bigjosh/SimpleNeoPixelDemo/ */

#ifndef NOP_FUDGE
#    if defined(STM32F0XX) || defined(STM32F1XX) || defined(GD32VF103) || defined(STM32F3XX) || defined(STM32F4XX) || defined(STM32L0XX) || defined(WB32F3G71xx) || defined(WB32FQ95xx)
#        define NOP_FUDGE 0.4
#    else
#        if defined(RP2040)
#            error "Please use `vendor` WS2812 driver for RP2040"
#        else
#            error "NOP_FUDGE configuration required"
#        endif
#        define NOP_FUDGE 1 // this just pleases the compile so the above error is easier to spot
#    endif
#endif

// Push Pull or Open Drain Configuration
// Default Push Pull
#ifndef WS2812_EXTERNAL_PULLUP
#    define WS2812_OUTPUT_MODE PAL_MODE_OUTPUT_PUSHPULL
#else
#    define WS2812_OUTPUT_MODE PAL_MODE_OUTPUT_OPENDRAIN
#endif

// The reset gap can be 6000 ns, but depending on the LED strip it may have to be increased
// to values like 600000 ns. If it is too small, the pixels will show nothing most of the time.
#ifndef WS2812_RES
#    define WS2812_RES (1000 * WS2812_TRST_US) // Width of the low gap between bits to cause a frame to latch
#endif

#define NUMBER_NOPS 6
#define CYCLES_PER_SEC (CPU_CLOCK / NUMBER_NOPS * NOP_FUDGE)
#define NS_PER_SEC (1000000000L) // Note that this has to be SIGNED since we want to be able to check for negative values of derivatives
#define NS_PER_CYCLE (NS_PER_SEC / CYCLES_PER_SEC)
#define NS_TO_CYCLES(n) ((n) / NS_PER_CYCLE)

#define wait_ns(x)                                  \
    do {                                            \
        for (int i = 0; i < NS_TO_CYCLES(x); i++) { \
            __asm__ volatile("nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t"              \
                             "nop\n\t");            \
        }                                           \
    } while (0)

void sendByte(uint8_t byte) {
    // WS2812 protocol wants most significant bits first
    for (unsigned char bit = 0; bit < 8; bit++) {
        bool is_one = byte & (1 << (7 - bit));
        // using something like wait_ns(is_one ? T1L : T0L) here throws off timings
        if (is_one) {
            // 1
            writePinHigh(WS2812_DI_PIN);
            wait_ns(WS2812_T1H);
            writePinLow(WS2812_DI_PIN);
            wait_ns(WS2812_T1L);
        } else {
            // 0
            writePinHigh(WS2812_DI_PIN);
            wait_ns(WS2812_T0H);
            writePinLow(WS2812_DI_PIN);
            wait_ns(WS2812_T0L);
        }
    }
}

void ws2812_init(void) {
    palSetLineMode(WS2812_DI_PIN, WS2812_OUTPUT_MODE);
}

// Setleds for standard RGB
void ws2812_setleds(rgb_led_t *ledarray, uint16_t leds) {
    static bool s_init = false;
    if (!s_init) {
        ws2812_init();
        s_init = true;
    }

    // this code is very time dependent, so we need to disable interrupts
    chSysLock();

    for (uint8_t i = 0; i < leds; i++) {
        // WS2812 protocol dictates grb order
#if (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_GRB)
        sendByte(ledarray[i].g);
        sendByte(ledarray[i].r);
        sendByte(ledarray[i].b);
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_RGB)
        sendByte(ledarray[i].r);
        sendByte(ledarray[i].g);
        sendByte(ledarray[i].b);
#elif (WS2812_BYTE_ORDER == WS2812_BYTE_ORDER_BGR)
        sendByte(ledarray[i].b);
        sendByte(ledarray[i].g);
        sendByte(ledarray[i].r);
#endif

#ifdef RGBW
        sendByte(ledarray[i].w);
#endif
    }

    wait_ns(WS2812_RES);

    chSysUnlock();
}
