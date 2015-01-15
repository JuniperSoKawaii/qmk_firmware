#ifndef RN42_H
#define RN42_H

#include <stdbool.h>

host_driver_t rn42_driver;
host_driver_t rn42_config_driver;

void rn42_init(void);
int16_t rn42_getc(void);
const char *rn42_gets(uint16_t timeout);
void rn42_putc(uint8_t c);
void rn42_puts(char *s);
bool rn42_autoconnecting(void);
void rn42_autoconnect(void);
void rn42_disconnect(void);
bool rn42_rts(void);
void rn42_cts_hi(void);
void rn42_cts_lo(void);
bool rn42_linked(void);
void rn42_set_leds(uint8_t l);

#endif
