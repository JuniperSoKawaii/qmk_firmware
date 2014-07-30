#include "host.h"
#include "host_driver.h"
#include "serial.h"
#include "rn42.h"
#include "print.h"
#include "wait.h"


/* Host driver */
static uint8_t keyboard_leds(void);
static void send_keyboard(report_keyboard_t *report);
static void send_mouse(report_mouse_t *report);
static void send_system(uint16_t data);
static void send_consumer(uint16_t data);

host_driver_t rn42_driver = {
    keyboard_leds,
    send_keyboard,
    send_mouse,
    send_system,
    send_consumer
};


void rn42_init(void)
{
    // PF1: check RTS(active low)
    DDRF &= ~(1<<1);
    PORTF &= ~(1<<1);

    // PF7: BT connection control(HiZ: connect, low: disconnect)
    // JTAG disable for PORT F. write JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);
    rn42_autoconnect();

    // PD5: CTS    (low: allow to send, high:not allowed)
    DDRD |= (1<<5);
    PORTD &= ~(1<<5);

    serial_init();
}

void rn42_putc(uint8_t c)
{
    serial_send(c);
}

void rn42_autoconnect(void)
{
    DDRF &= ~(1<<7);
    PORTF &= ~(1<<7);
}

void rn42_disconnect(void)
{
    DDRF |= (1<<7);
    PORTF &= ~(1<<7);
}

bool rn42_ready(void)
{
    // RTS low
    return PINF&(1<<1) ? false : true;
}


static uint8_t keyboard_leds(void) { return 0; }

static void send_keyboard(report_keyboard_t *report)
{
    // wake from deep sleep
    PORTD |= (1<<5);    // high
    wait_ms(5);
    PORTD &= ~(1<<5);   // low

    serial_send(0xFD);  // Raw report mode
    serial_send(9);     // length
    serial_send(1);     // descriptor type
    serial_send(report->mods);
    serial_send(0x00);
    serial_send(report->keys[0]);
    serial_send(report->keys[1]);
    serial_send(report->keys[2]);
    serial_send(report->keys[3]);
    serial_send(report->keys[4]);
    serial_send(report->keys[5]);
}

static void send_mouse(report_mouse_t *report)
{
    // wake from deep sleep
    PORTD |= (1<<5);    // high
    wait_ms(5);
    PORTD &= ~(1<<5);   // low

    serial_send(0xFD);  // Raw report mode
    serial_send(5);     // length
    serial_send(2);     // descriptor type
    serial_send(report->buttons);
    serial_send(report->x);
    serial_send(report->y);
    serial_send(report->v);
}

static void send_system(uint16_t data)
{
    // Table 5-6 of RN-BT-DATA-UB
    // 81,82,83 scan codes can be used?
}


static uint16_t usage2bits(uint16_t usage)
{
    switch (usage) {
        case AC_HOME:               return 0x01;
        case AL_EMAIL:              return 0x02;
        case AC_SEARCH:             return 0x04;
        //case AL_KBD_LAYOUT:         return 0x08;  // Apple virtual keybaord toggle
        case AUDIO_VOL_UP:          return 0x10;
        case AUDIO_VOL_DOWN:        return 0x20;
        case AUDIO_MUTE:            return 0x40;
        case TRANSPORT_PLAY_PAUSE:  return 0x80;
        case TRANSPORT_NEXT_TRACK:  return 0x100;
        case TRANSPORT_PREV_TRACK:  return 0x200;
        case TRANSPORT_STOP:        return 0x400;
        case TRANSPORT_STOP_EJECT:  return 0x800;
        //case return 0x1000;   // Fast forward
        //case return 0x2000;   // Rewind
        //case return 0x4000;   // Stop/eject
        //case return 0x8000;   // Internet browser
    };
    return 0;
}

static void send_consumer(uint16_t data)
{
    uint16_t bits = usage2bits(data);
    serial_send(0xFD);  // Raw report mode
    serial_send(3);     // length
    serial_send(3);     // descriptor type
    serial_send(bits&0xFF);
    serial_send((bits>>8)&0xFF);
}


/* Null driver for config_mode */
static uint8_t config_keyboard_leds(void);
static void config_send_keyboard(report_keyboard_t *report);
static void config_send_mouse(report_mouse_t *report);
static void config_send_system(uint16_t data);
static void config_send_consumer(uint16_t data);

host_driver_t rn42_config_driver = {
    config_keyboard_leds,
    config_send_keyboard,
    config_send_mouse,
    config_send_system,
    config_send_consumer
};

static uint8_t config_keyboard_leds(void) { return 0; }
static void config_send_keyboard(report_keyboard_t *report) {}
static void config_send_mouse(report_mouse_t *report) {}
static void config_send_system(uint16_t data) {}
static void config_send_consumer(uint16_t data) {}
