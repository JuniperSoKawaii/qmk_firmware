#include "pimoroni_trackball.h"
#include "i2c_master.h"

static uint8_t scrolling      = 0;
static int16_t x_offset       = 0;
static int16_t y_offset       = 0;
static int16_t h_offset       = 0;
static int16_t v_offset       = 0;
static uint8_t precisionSpeed = 1;

#ifndef I2C_TIMEOUT
#    define I2C_TIMEOUT 100
#endif

void trackball_set_rgbw(uint8_t red, uint8_t green, uint8_t blue, uint8_t white) {
    uint8_t data[] = {0x00, red, green, blue, white};
    i2c_transmit(TRACKBALL_WRITE, data, sizeof(data), I2C_TIMEOUT);
}

int16_t mouse_offset(uint8_t positive, uint8_t negative, int16_t scale) {
    int16_t offset    = (int16_t)positive - (int16_t)negative;
    int16_t magnitude = scale * offset * offset * precisionSpeed;
    return offset < 0 ? -magnitude : magnitude;
}

void update_member(int8_t* member, int16_t* offset) {
    if (*offset > 127) {
        *member = 127;
        *offset -= 127;
    } else if (*offset < -127) {
        *member = -127;
        *offset += 127;
    } else {
        *member = *offset;
        *offset = 0;
    }
}

__attribute__((weak)) void trackball_check_click(bool pressed, report_mouse_t* mouse) {
    if (pressed) {
        mouse->buttons |= MOUSE_BTN1;
    } else {
        mouse->buttons &= ~MOUSE_BTN1;
    }
}

uint8_t trackball_get_precision(void) { return precisionSpeed; }
void    trackball_set_precision(uint8_t precision) { precisionSpeed = precision; }
bool    trackball_is_scrolling(void) { return scrolling; }
void    trackball_set_scrolling(bool scroll) { scrolling = scroll; }

void pointing_device_init(void) {
    trackball_set_rgbw(0x00,0x00,0x00,0x00);
}

void pointing_device_task(void) {
    uint8_t state[5] = {};
    if (i2c_readReg(TRACKBALL_WRITE, 0x04, state, 5, I2C_TIMEOUT) == I2C_STATUS_SUCCESS) {
        if (scrolling) {
#ifdef PIMORONI_TRACKBALL_INVERT_X
            h_offset -= mouse_offset(state[2], state[3], 1);
#else
            h_offset += mouse_offset(state[2], state[3], 1);
#endif
#ifdef PIMORONI_TRACKBALL_INVERT_Y
            v_offset -= mouse_offset(state[1], state[0], 1);
#else
            v_offset += mouse_offset(state[1], state[0], 1);
#endif
        } else {
#ifdef PIMORONI_TRACKBALL_INVERT_X
            x_offset -= mouse_offset(state[2], state[3], 5);
#else
            x_offset += mouse_offset(state[2], state[3], 5);
#endif
#ifdef PIMORONI_TRACKBALL_INVERT_Y
            y_offset -= mouse_offset(state[1], state[0], 5);
#else
            y_offset += mouse_offset(state[1], state[0], 5);
#endif
        }
    }

    report_mouse_t mouse = pointing_device_get_report();

    trackball_check_click(state[4] & (1 << 7), &mouse);

    update_member(&mouse.x, &x_offset);
    update_member(&mouse.y, &y_offset);
    update_member(&mouse.v, &v_offset);
    update_member(&mouse.h, &h_offset);
    pointing_device_set_report(mouse);
    pointing_device_send();
}
