#ifndef USB_DEBUG_H
#define  USB_DEBUG_H 1

#include <stdint.h>
#include "usb_device.h"


#define DEBUG_INTERFACE		1
#define DEBUG_TX_ENDPOINT	4
#define DEBUG_TX_SIZE		32
#define DEBUG_TX_BUFFER		EP_DOUBLE_BUFFER


extern volatile uint8_t debug_flush_timer;


int8_t usb_debug_putchar(uint8_t c);	// transmit a character
void usb_debug_flush_output(void);	// immediately transmit any buffered output

#endif
