// this code from:
// http://www.pjrc.com/teensy/jump_to_bootloader.html
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void jump_bootloader(void) {
    cli();
    // disable watchdog, if enabled
    // disable all peripherals
    UDCON = 1;
    USBCON = (1<<FRZCLK);  // disable USB
    UCSR1B = 0;
    _delay_ms(5);
#if defined(__AVR_AT90USB162__)                // Teensy 1.0
    DDRB = 0; DDRC = 0; DDRD = 0;
    TIMSK0 = 0; TIMSK1 = 0;
    asm volatile("jmp 0x1F00");
#elif defined(__AVR_ATmega32U4__)              // Teensy 2.0
    DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
    TIMSK0 = 0; TIMSK1 = 0; TIMSK3 = 0; TIMSK4 = 0;
    ADCSRA = 0;
    asm volatile("jmp 0x3F00");
#elif defined(__AVR_AT90USB646__)              // Teensy++ 1.0
    DDRA = 0; DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
    TIMSK0 = 0; TIMSK1 = 0; TIMSK2 = 0; TIMSK3 = 0;
    ADCSRA = 0;
    asm volatile("jmp 0x7E00");
#elif defined(__AVR_AT90USB1286__)             // Teensy++ 2.0
    DDRA = 0; DDRB = 0; DDRC = 0; DDRD = 0; DDRE = 0; DDRF = 0;
    TIMSK0 = 0; TIMSK1 = 0; TIMSK2 = 0; TIMSK3 = 0;
    ADCSRA = 0;
    asm volatile("jmp 0xFE00");
#endif 
}
