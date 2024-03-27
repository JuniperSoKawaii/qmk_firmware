#include "chimera_ortho_plus.h"

void led_init(void) {
    gpio_set_pin_output(D1);
    gpio_set_pin_output(F4);
    gpio_set_pin_output(F5);
    gpio_write_pin_high(D1);
    gpio_write_pin_high(F4);
    gpio_write_pin_high(F5);
}


void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init();
}
