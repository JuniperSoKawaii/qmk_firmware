/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GINPUT_LLD_MOUSE_BOARD_H
#define _GINPUT_LLD_MOUSE_BOARD_H

// Resolution and Accuracy Settings
#define GMOUSE_FT5336_PEN_CALIBRATE_ERROR		8
#define GMOUSE_FT5336_PEN_CLICK_ERROR			6
#define GMOUSE_FT5336_PEN_MOVE_ERROR			4
#define GMOUSE_FT5336_FINGER_CALIBRATE_ERROR	14
#define GMOUSE_FT5336_FINGER_CLICK_ERROR		18
#define GMOUSE_FT5336_FINGER_MOVE_ERROR			14

// How much extra data to allocate at the end of the GMouse structure for the board's use
#define GMOUSE_FT5336_BOARD_DATA_SIZE			0

// Set this to GFXON if you want self-calibration.
//	NOTE:	This is not as accurate as real calibration.
//			It requires the orientation of the touch panel to match the display.
//			It requires the active area of the touch panel to exactly match the display size.
#define GMOUSE_FT5336_SELF_CALIBRATE			GFXOFF

static gBool init_board(GMouse* m, unsigned instance)
{
	(void)m;
	(void)instance;

	return gTrue;
}

static void write_reg(GMouse* m, gU8 reg, gU8 val)
{
	(void)m;
	(void)reg;
	(void)val;
}

static gU8 read_byte(GMouse* m, gU8 reg)
{
	(void)m;
	(void)reg;

	return (gU16)0x00;
}

static gU16 read_word(GMouse* m, gU8 reg)
{
	(void)m;
	(void)reg;

	return (gU16)0x0000;
}

#endif /* _GINPUT_LLD_MOUSE_BOARD_H */
