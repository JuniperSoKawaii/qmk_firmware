// Left side (front)
#ifdef CONVERT_TO_STEMCELL_UART_SWAP
#    define D3 PAL_LINE(GPIOA, 3)
#    define D2 PAL_LINE(GPIOA, 2)
#    ifndef SERIAL_USART_DRIVER
#        define SERIAL_USART_DRIVER SD2
#    endif
#else
#    define D3 PAL_LINE(GPIOA, 2)
#    define D2 PAL_LINE(GPIOA, 3)
#endif
//  GND
//  GND
#ifdef CONVERT_TO_STEMCELL_I2C_SWAP
#    define D1 PAL_LINE(GPIOB, 6)
#    define D0 PAL_LINE(GPIOB, 7)
#else
#    define D1 PAL_LINE(GPIOB, 7)
#    define D0 PAL_LINE(GPIOB, 6)
#endif

#define D4 PAL_LINE(GPIOA, 15)
#define C6 PAL_LINE(GPIOB, 3)
#define D7 PAL_LINE(GPIOB, 4)
#define E6 PAL_LINE(GPIOB, 5)
#define B4 PAL_LINE(GPIOB, 8)
#define B5 PAL_LINE(GPIOB, 9)

// Right side (front)
// RAW
// GND
// RESET
// VCC
#define F4 PAL_LINE(GPIOB, 10)
#define F5 PAL_LINE(GPIOB, 2)
#define F6 PAL_LINE(GPIOB, 1)
#define F7 PAL_LINE(GPIOB, 0)
#define B1 PAL_LINE(GPIOA, 5)
#define B3 PAL_LINE(GPIOA, 6)
#define B2 PAL_LINE(GPIOA, 7)
#define B6 PAL_LINE(GPIOA, 4)

// Extra elite-c compatible pinout
#define B7 PAL_LINE(GPIOC, 13)
#define D5 PAL_LINE(GPIOC, 14)
#define C7 PAL_LINE(GPIOC, 15)
#define F1 PAL_LINE(GPIOA, 0)
#define F0 PAL_LINE(GPIOA, 1)

#define B0 PAL_LINE(GPIOA, 9) // unconnected pin

#define I2C1_SCL_PIN D0
#define I2C1_SDA_PIN D1
#define FEE_PAGE_BASE_ADDRESS 0x08008000
