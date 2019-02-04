#ifdef SSD1306OLED

#include "ssd1306.h"
#include "i2c.h"
#include "common/glcdfont.c"

#include <string.h>

// Used commands from spec sheet: https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf
// Fundamental Commands
#define CONTRAST                0x81
#define DISPLAY_ALL_ON          0xA5
#define DISPLAY_ALL_ON_RESUME   0xA4
#define NORMAL_DISPLAY          0xA6
#define DISPLAY_ON              0xAF
#define DISPLAY_OFF             0xAE

// Scrolling Commands
#define DEACTIVATE_SCROLL       0x2E

// Addressing Setting Commands
#define MEMORY_MODE             0x20
#define COLUMN_ADDR             0x21
#define PAGE_ADDR               0x22

// Hardware Configuration Commands
#define DISPLAY_START_LINE      0x40
#define SEGMENT_REMAP           0xA0
#define SEGMENT_REMAP_INV       0xA1
#define MULTIPLEX_RATIO         0xA8
#define COM_SCAN_INC            0xC0
#define COM_SCAN_DEC            0xC8
#define DISPLAY_OFFSET          0xD3
#define COM_PINS                0xDA

// Timing & Driving Commands
#define DISPLAY_CLOCK           0xD5
#define PRE_CHARGE_PERIOD       0xD9
#define VCOM_DETECT             0xDB

// Charge Pump Commands
#define CHARGE_PUMP             0x8D


static struct DisplayBuffer display_buffer;


// Commands are expected to be in Flash memory
static void SendCommands(const uint8_t *commands, uint8_t length)
{
    i2c_start_write(SSD1306_ADDRESS);
    i2c_master_write(0x00);
    while (length--)
        i2c_master_write(pgm_read_byte(commands++));
    i2c_master_stop();
}

// Data is expected to be in SRAM
static void SendData(const uint8_t *data, uint16_t length)
{
    i2c_start_write(SSD1306_ADDRESS);
    i2c_master_write(0x40);
    while (length--)
        i2c_master_write(*data++);
    i2c_master_stop();
}

// Moves the cursor forward 1 character length
// Advances lines if there is not enough room for the next character
// Wraps to the begining when out of bounds
static void AdvanceCursor(void)
{
    display_buffer.cursor += OLED_FONT_WIDTH;

    // Room for next character?
    uint8_t colRemainder = OLED_DISPLAY_WIDTH - ((display_buffer.cursor - &display_buffer.display[0]) % OLED_DISPLAY_WIDTH);
    if (colRemainder < OLED_FONT_WIDTH)
        display_buffer.cursor += colRemainder;

    // Out of bounds?
    if (display_buffer.cursor - &display_buffer.display[0] > OLED_MATRIX_SIZE)
        display_buffer.cursor = &display_buffer.display[0];
}

// Moves the cursor to the begining of the next line
// Wraps to the begining when out of bounds
static void AdvancePage(void)
{
    uint8_t pageIndex = (display_buffer.cursor - &display_buffer.display[0]) / OLED_DISPLAY_WIDTH + 1;

    // Out of bounds?
    if (pageIndex > OLED_DISPLAY_HEIGHT / 8 - 1)
        pageIndex = 0;

    display_buffer.cursor = &display_buffer.display[pageIndex * OLED_DISPLAY_WIDTH];
}

// Flips the rendering bits for a character at the current cursor position
static void InvertCharacter(uint8_t *cursor)
{
    const uint8_t *end = cursor + OLED_FONT_WIDTH;
    while (cursor < end)
    {
        *cursor = ~(*cursor);
        cursor++;
    }
}

// Main handler that writes character data to the display buffer
static void WriteCharToBuffer(const char data, bool invert)
{
    static uint8_t oled_temp_buffer[OLED_FONT_WIDTH];
    if (data == '\n')
        AdvancePage();
    else if (data < OLED_FONT_START || data > OLED_FONT_END)
    {
        memcpy(&oled_temp_buffer, display_buffer.cursor, OLED_FONT_WIDTH);
        memset(display_buffer.cursor, invert, OLED_FONT_WIDTH);
        display_buffer.dirty |= memcmp(&oled_temp_buffer, display_buffer.cursor, OLED_FONT_WIDTH) != 0;
        AdvanceCursor();
        return;
    }
    else
    {
        const uint8_t *glyph = font + (data - OLED_FONT_START) * OLED_FONT_WIDTH;
        memcpy(&oled_temp_buffer, display_buffer.cursor, OLED_FONT_WIDTH);
        memcpy_P(display_buffer.cursor, glyph, OLED_FONT_WIDTH);
        if (invert) InvertCharacter(display_buffer.cursor);
        display_buffer.dirty |= memcmp(&oled_temp_buffer, display_buffer.cursor, OLED_FONT_WIDTH) != 0;
        AdvanceCursor();
    }
}

void iota_gfx_init(bool flip180)
{
    static const uint8_t PROGMEM display_setup1[] = {
        DISPLAY_OFF,
        DISPLAY_CLOCK, 0x80,
        MULTIPLEX_RATIO, OLED_DISPLAY_HEIGHT - 1,
        DISPLAY_OFFSET, 0x00,
        DISPLAY_START_LINE | 0x00,
        CHARGE_PUMP, 0x14,
        MEMORY_MODE, 0x00, };
    SendCommands(display_setup1, sizeof(display_setup1));

    if (!flip180)
    {
        static const uint8_t PROGMEM display_normal[] = {
            SEGMENT_REMAP_INV,
            COM_SCAN_DEC };
        SendCommands(display_normal, sizeof(display_normal));
    }
    else
    {
        static const uint8_t PROGMEM display_flipped[] = {
            SEGMENT_REMAP,
            COM_SCAN_INC };
        SendCommands(display_flipped, sizeof(display_flipped));
    }

    static const uint8_t PROGMEM display_setup2[] = {
        COM_PINS, 0x02,
        CONTRAST, 0x8F,
        PRE_CHARGE_PERIOD, 0xF1,
        VCOM_DETECT, 0x40,
        DISPLAY_ALL_ON_RESUME,
        NORMAL_DISPLAY,
        DEACTIVATE_SCROLL,
        DISPLAY_ON };
    SendCommands(display_setup2, sizeof(display_setup2));
}

void iota_gfx_clear(void)
{
    memset(display_buffer.display, 0, sizeof(display_buffer.display));
    display_buffer.cursor = &display_buffer.display[0];
    display_buffer.dirty = true;
}

void iota_gfx_set_cursor(uint8_t col, uint8_t line)
{
    uint16_t index = line * OLED_DISPLAY_WIDTH + col * OLED_FONT_WIDTH;
    display_buffer.cursor = &display_buffer.display[index];

    // Out of bounds?
    if (display_buffer.cursor - &display_buffer.display[0] > OLED_MATRIX_SIZE)
        display_buffer.cursor = &display_buffer.display[0];
}

void iota_gfx_render(void)
{
    static const uint8_t PROGMEM display_start[] = {
        COLUMN_ADDR, 0, OLED_DISPLAY_WIDTH - 1,
        PAGE_ADDR, 0, OLED_DISPLAY_HEIGHT / 8 - 1 };

    if (!display_buffer.dirty) return;
    SendCommands(display_start, sizeof(display_start));
    SendData(&display_buffer.display[0], sizeof(display_buffer.display));
    display_buffer.cursor = &display_buffer.display[0];
    display_buffer.dirty = false;
}

void iota_gfx_write(const char *data, bool invert)
{
    const char *end = data + strlen(data);
    while (data < end)
    {
        WriteCharToBuffer(*data, invert);
        data++;
    }
}

void iota_gfx_write_P(const char *data, bool invert)
{
    const char *end = data + strlen(data);
    while (data < end)
    {
        uint8_t c = pgm_read_byte(data);
        WriteCharToBuffer(c, invert);
        data++;
    }
}
#endif
