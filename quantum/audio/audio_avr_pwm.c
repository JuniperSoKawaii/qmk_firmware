/* Copyright 2016 Jack Humbert
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

#include <stdio.h>
#include <string.h>
//#include <math.h>
#if defined(__AVR__)
  #include <avr/pgmspace.h>
  #include <avr/interrupt.h>
  #include <avr/io.h>
#endif
#include "print.h"
#include "audio.h"

#include "wait.h"

//TODO: move into audio-common state
extern bool playing_notes;
extern float note_timbre;
extern uint8_t voices;

#define CPU_PRESCALER 8

// -----------------------------------------------------------------------------
// Timer Abstractions
// -----------------------------------------------------------------------------

//Currently we support timers 1 and 3 used at the same time, channels A-C,
//pins PB5, PB6, PB7, PC4, PC5, and PC6

#if defined(B5_AUDIO) || defined(B6_AUDIO) || defined(B7_AUDIO)
    #define AUDIO1_PIN_SET
    #define AUDIO1_TIMSKx TIMSK1
    #define AUDIO1_TCCRxA TCCR1A
    #define AUDIO1_TCCRxB TCCR1B
    #define AUDIO1_ICRx ICR1
    #define AUDIO1_WGMx0 WGM10
    #define AUDIO1_WGMx1 WGM11
    #define AUDIO1_WGMx2 WGM12
    #define AUDIO1_WGMx3 WGM13
    #define AUDIO1_CSx0 CS10
    #define AUDIO1_CSx1 CS11
    #define AUDIO1_CSx2 CS12

    #if defined(B5_AUDIO)
        #define AUDIO1_COMxy0 COM1A0
        #define AUDIO1_COMxy1 COM1A1
        #define AUDIO1_OCIExy OCIE1A
        #define AUDIO1_OCRxy OCR1A
        #define AUDIO1_PIN B5
        #define AUDIO1_TIMERx_COMPy_vect TIMER1_COMPA_vect
    #elif defined(B6_AUDIO)
        #define AUDIO1_COMxy0 COM1B0
        #define AUDIO1_COMxy1 COM1B1
        #define AUDIO1_OCIExy OCIE1B
        #define AUDIO1_OCRxy OCR1B
        #define AUDIO1_PIN B6
        #define AUDIO1_TIMERx_COMPy_vect TIMER1_COMPB_vect
    #elif defined(B7_AUDIO)
        #define AUDIO1_COMxy0 COM1C0
        #define AUDIO1_COMxy1 COM1C1
        #define AUDIO1_OCIExy OCIE1C
        #define AUDIO1_OCRxy OCR1C
        #define AUDIO1_PIN B7
        #define AUDIO1_TIMERx_COMPy_vect TIMER1_COMPC_vect
    #endif
#endif

#if defined(C4_AUDIO) || defined(C5_AUDIO) || defined(C6_AUDIO)
    #define AUDIO2_PIN_SET
    #define AUDIO2_TIMSKx TIMSK3
    #define AUDIO2_TCCRxA TCCR3A
    #define AUDIO2_TCCRxB TCCR3B
    #define AUDIO2_ICRx ICR3
    #define AUDIO2_WGMx0 WGM30
    #define AUDIO2_WGMx1 WGM31
    #define AUDIO2_WGMx2 WGM32
    #define AUDIO2_WGMx3 WGM33
    #define AUDIO2_CSx0 CS30
    #define AUDIO2_CSx1 CS31
    #define AUDIO2_CSx2 CS32

    #if defined(C6_AUDIO)
        #define AUDIO2_COMxy0 COM3A0
        #define AUDIO2_COMxy1 COM3A1
        #define AUDIO2_OCIExy OCIE3A
        #define AUDIO2_OCRxy OCR3A
        #define AUDIO2_PIN C6
        #define AUDIO2_TIMERx_COMPy_vect TIMER3_COMPA_vect
    #elif defined(C5_AUDIO)
        #define AUDIO2_COMxy0 COM3B0
        #define AUDIO2_COMxy1 COM3B1
        #define AUDIO2_OCIExy OCIE3B
        #define AUDIO2_OCRxy OCR3B
        #define AUDIO2_PIN C5
        #define AUDIO2_TIMERx_COMPy_vect TIMER3_COMPB_vect
    #elif defined(C4_AUDIO)
        #define AUDIO2_COMxy0 COM3C0
        #define AUDIO2_COMxy1 COM3C1
        #define AUDIO2_OCIExy OCIE3C
        #define AUDIO2_OCRxy OCR3C
        #define AUDIO2_PIN C4
        #define AUDIO2_TIMERx_COMPy_vect TIMER3_COMPC_vect
    #endif
#endif


// C6 seems to be the assumed default by many existing keyboard - but sill warn the user
#if !defined(AUDIO2_PIN_SET) && !defined(AUDIO1_PIN_SET)
#pragma message "audio feature enabled, but no pin selected - see docs/feature_audio for defines to set"
#endif
// -----------------------------------------------------------------------------


float place = 0;

#ifdef AUDIO1_PIN_SET
static float channel_1_frequency = 0.0f;
void channel_1_set_frequency(float freq) {

    if (freq < 0.0f)
        freq = 0.0f;

    if (freq == channel_1_frequency)
        return;

    channel_1_frequency = freq;

    // set pwm period
    AUDIO1_ICRx = (uint16_t)(((float)F_CPU) / (freq * CPU_PRESCALER));
    // and duty cycle
    AUDIO1_OCRxy = (uint16_t)((((float)F_CPU) / (freq * CPU_PRESCALER)) * note_timbre);
}

float channel_1_get_frequency(void) {
    return channel_1_frequency;
}

void channel_1_start(void) {
    // enable timer-counter ISR
    AUDIO1_TIMSKx |= _BV(AUDIO1_OCIExy);
    // enable timer-counter output
    AUDIO1_TCCRxA |= _BV(AUDIO1_COMxy1);
}

void channel_1_stop(void) {
    // disable timer-counter ISR
    AUDIO1_TIMSKx &= ~_BV(AUDIO1_OCIExy);
    // disable timer-counter output
    AUDIO1_TCCRxA &= ~(_BV(AUDIO1_COMxy1) | _BV(AUDIO1_COMxy0));
}
#endif

#ifdef AUDIO2_PIN_SET
static float channel_2_frequency = 0.0f;
void channel_2_set_frequency(float freq) {

    if (freq < 0.0f)
        freq = 0.0f;

    if (freq == channel_2_frequency)
        return;

    channel_2_frequency = freq;

    AUDIO2_ICRx = (uint16_t)(((float)F_CPU) / (freq * CPU_PRESCALER));
    AUDIO2_OCRxy = (uint16_t)((((float)F_CPU) / (freq * CPU_PRESCALER)) * note_timbre);
}

void channel_2_start(void) {
    AUDIO2_TIMSKx |= _BV(AUDIO2_OCIExy);
    AUDIO2_TCCRxA |= _BV(AUDIO2_COMxy1);
}

void channel_2_stop(void) {
    AUDIO2_TIMSKx &= ~_BV(AUDIO2_OCIExy);
    AUDIO2_TCCRxA &= ~(_BV(AUDIO2_COMxy1) | _BV(AUDIO2_COMxy0));
}
#endif


void audio_initialize_hardware() {

#ifdef AUDIO1_PIN_SET
    channel_1_stop();
    // Set audio ports as output
    setPinOutput(AUDIO1_PIN);
#endif

#ifdef AUDIO2_PIN_SET
    channel_2_stop();
    setPinOutput(AUDIO2_PIN);
#endif

    // TCCR3A / TCCR3B: Timer/Counter #3 Control Registers TCCR3A/TCCR3B, TCCR1A/TCCR1B
    // Compare Output Mode (COM3An and COM1An) = 0b00 = Normal port operation
    //   OC3A -- PC6
    //   OC3B -- PC5
    //   OC3C -- PC4
    //   OC1A -- PB5
    //   OC1B -- PB6
    //   OC1C -- PB7

    // Waveform Generation Mode (WGM3n) = 0b1110 = Fast PWM Mode 14. Period = ICR3, Duty Cycle OCR3A)
    //   OCR3A - PC6
    //   OCR3B - PC5
    //   OCR3C - PC4
    //   OCR1A - PB5
    //   OCR1B - PB6
    //   OCR1C - PB7

#ifdef AUDIO1_PIN_SET
    // initialize timer-counter
    AUDIO1_TCCRxA = (0 << AUDIO1_COMxy1) | (0 << AUDIO1_COMxy0) | (1 << AUDIO1_WGMx1) | (0 << AUDIO1_WGMx0);
    AUDIO1_TCCRxB = (1 << AUDIO1_WGMx3)  | (1 << AUDIO1_WGMx2)  | (0 << AUDIO1_CSx2)  | (1 << AUDIO1_CSx1) | (0 << AUDIO1_CSx0);

    //channel_1_set_frequency(440); // original code set this frequency here... why?
#endif


    // Clock Select (CS3n) = 0b010 = Clock / 8
#ifdef AUDIO2_PIN_SET
    AUDIO2_TCCRxA = (0 << AUDIO2_COMxy1) | (0 << AUDIO2_COMxy0) | (1 << AUDIO2_WGMx1) | (0 << AUDIO2_WGMx0);
    AUDIO2_TCCRxB = (1 << AUDIO2_WGMx3)  | (1 << AUDIO2_WGMx2)  | (0 << AUDIO2_CSx2)  | (1 << AUDIO2_CSx1) | (0 << AUDIO2_CSx0);

    //channel_2_set_frequency(440); // original code set this frequency here... why?
#endif

}

void audio_stop_hardware() {

    #ifdef AUDIO2_PIN_SET
        channel_2_stop();
    #endif

    #ifdef AUDIO1_PIN_SET
        channel_1_stop();
    #endif
}

void audio_start_hardware(void) {

    #ifdef AUDIO2_PIN_SET
    channel_2_start();
    #endif
    #ifdef AUDIO1_PIN_SET
        #ifdef AUDIO2_PIN_SET
        if (voices > 1) {
            channel_1_start();
        }
        #else
        channel_1_start();
        #endif
    #endif
}

#ifdef AUDIO2_PIN_SET
ISR(AUDIO2_TIMERx_COMPy_vect) {

    float freq, freq_alt;
    pwm_audio_timer_task(&freq, &freq_alt);

    // do polyphonic, if a second speaker is available
    #ifdef AUDIO1_PIN_SET
    if (playing_notes)
        channel_1_set_frequency(freq_alt);
    else
        channel_1_stop();
    #endif

    if (playing_notes)
        channel_2_set_frequency(freq);
    else
        channel_2_stop();
}
#endif

#ifdef AUDIO1_PIN_SET
ISR(AUDIO1_TIMERx_COMPy_vect) {

    #if defined(AUDIO1_PIN_SET) && !defined(AUDIO2_PIN_SET)
    float freq, freq_alt;
    pwm_audio_timer_task(&freq, &freq_alt);

    if (playing_notes)
        channel_1_set_frequency(freq);
    else
        channel_1_stop();
    #endif
}
#endif
