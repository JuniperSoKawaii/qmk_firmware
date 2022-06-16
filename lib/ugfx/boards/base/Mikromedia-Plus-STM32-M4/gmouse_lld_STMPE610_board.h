/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GINPUT_LLD_MOUSE_BOARD_H
#define _GINPUT_LLD_MOUSE_BOARD_H

// Resolution and Accuracy Settings
#define GMOUSE_STMPE610_PEN_CALIBRATE_ERROR		8
#define GMOUSE_STMPE610_PEN_CLICK_ERROR			6
#define GMOUSE_STMPE610_PEN_MOVE_ERROR			4
#define GMOUSE_STMPE610_FINGER_CALIBRATE_ERROR	14
#define GMOUSE_STMPE610_FINGER_CLICK_ERROR		18
#define GMOUSE_STMPE610_FINGER_MOVE_ERROR		14

// How much extra data to allocate at the end of the GMouse structure for the board's use
#define GMOUSE_STMPE610_BOARD_DATA_SIZE			0

// Options - Leave these commented to make it user configurable in the gfxconf.h
//#define GMOUSE_STMPE610_READ_PRESSURE		GFXOFF
//#define GMOUSE_STMPE610_SELF_CALIBRATE	GFXOFF
//#define GMOUSE_STMPE610_TEST_MODE			GFXOFF

// If GFXON this board has the STMPE610 IRQ pin connected to a GPIO.
// Note: Although this board has such a pin its reliability has not been tested on this board!!!!!
#define GMOUSE_STMPE610_GPIO_IRQPIN				GFXOFF

// If GFXON this is a really slow CPU and we should always clear the FIFO between reads.
#define GMOUSE_STMPE610_SLOW_CPU				GFXOFF

// Slave address
#define STMPE610_ADDR				(0x88 >> 1)

// Maximum timeout
#define STMPE610_TIMEOUT			0x3000

static const I2CConfig i2ccfg = {
	OPMODE_I2C,
	390625,						// Conservative please
	FAST_DUTY_CYCLE_2,
};

static gBool init_board(GMouse* m, unsigned driverinstance) {
	(void)		m;

	// This board only supports one touch panel
	if (driverinstance)
		return gFalse;

    palSetPadMode(GPIOA, 0, PAL_MODE_INPUT | PAL_STM32_PUDR_FLOATING);          /* TP IRQ */
    palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN); /* SCL */
    palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN); /* SDA */

	i2cStart(&I2CD1, &i2ccfg);

	return gTrue;
}

#if GMOUSE_STMPE610_GPIO_IRQPIN
	static gBool getpin_irq(GMouse* m) {
		(void)		m;

		return !palReadPad(GPIOA, 0);
	}
#endif

static GFXINLINE void aquire_bus(GMouse* m) {
	(void)		m;

}

static GFXINLINE void release_bus(GMouse* m) {
	(void)		m;

}

static void write_reg(GMouse* m, gU8 reg, gU8 val) {
	gU8		txbuf[2];
	(void)		m;

	txbuf[0] = reg;
	txbuf[1] = val;

	i2cAcquireBus(&I2CD1);
	i2cMasterTransmitTimeout(&I2CD1, STMPE610_ADDR, txbuf, 2, 0, 0, MS2ST(STMPE610_TIMEOUT));
	i2cReleaseBus(&I2CD1);
}

static gU8 read_byte(GMouse* m, gU8 reg) {
	gU8		rxbuf[1];
	(void)		m;

	rxbuf[0] = 0;

	i2cAcquireBus(&I2CD1);
	i2cMasterTransmitTimeout(&I2CD1, STMPE610_ADDR, &reg, 1, rxbuf, 1, MS2ST(STMPE610_TIMEOUT));
	i2cReleaseBus(&I2CD1);

	return rxbuf[0];
}

static gU16 read_word(GMouse* m, gU8 reg) {
	gU8		rxbuf[2];
	(void)		m;

	rxbuf[0] = 0;
	rxbuf[1] = 0;

	i2cAcquireBus(&I2CD1);
	i2cMasterTransmitTimeout(&I2CD1, STMPE610_ADDR, &reg, 1, rxbuf, 2, MS2ST(STMPE610_TIMEOUT));
	i2cReleaseBus(&I2CD1);

	return (((gU16)rxbuf[0]) << 8) | rxbuf[1];
}

#endif /* _GINPUT_LLD_MOUSE_BOARD_H */
