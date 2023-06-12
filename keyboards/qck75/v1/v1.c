// Copyright 2023 Andrian (@PoringH)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum {
	MAIN = 0,
	SECOND = 1,
	THIRD = 2,
	FOURTH = 3
};

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
	switch(get_highest_layer(layer_state)) {
		default: 
			if(clockwise) {
				tap_code(KC_VOLU);
			} else {
				tap_code(KC_VOLD);
			}
		case SECOND:
			if(clockwise) {
				tap_code(KC_MNXT);
			} else {
				tap_code(KC_MPRV);
			}
			break;
		case THIRD:
			if(clockwise) {
				tap_code(KC_MS_R);
			} else {
				tap_code(KC_MS_L);
			}
			break;
		case FOURTH:
			if(clockwise) {
				tap_code(KC_MS_U);
			} else {
				tap_code(KC_MS_D);
			}
			break;
	}
	return true;
}

#define		KB_STAT_SIZE 18
#define		WIN_STAT_SIZE 12
#define 	MIN_WALK_SPEED 	10
#define 	MIN_RUN_SPEED 	40
#define 	ANIM_FRAME_DURATION 200
#define 	ANIM_SIZE 96

uint32_t anim_timer = 0;
uint8_t current_frame = 0;
int current_wpm = 0;
led_t led_usb_state;

bool isguiDisabled = false;
bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

#ifdef OLED_ENABLE

static void render_animation(int ANIM_X, int ANIM_Y) {
	//sit animation 32 X 22
	static const char PROGMEM sit[2][3][ANIM_SIZE] = {
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
				0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9,
				0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			},	
			{
	   			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10,
				0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82,
				0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 	
			},
			{
		   		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
				0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
				0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
			},
		},
		
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
				0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9,
				0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 
				0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 
				0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
				0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 
				0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
			}
			
		}
	};
	
	//walk animation 32 X 22
	static const char PROGMEM walk[2][3][ANIM_SIZE] = {
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 
				0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80, 
				0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 
				0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
			},	
			{
	   			0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 
				0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 
				0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 
				0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,  	
			},
			{
		   		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
				0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03, 
				0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 
				0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	
			}
		},
		
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 
				0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 
				0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 
				0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 
				0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
				0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 
				0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
				0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 
				0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 
				0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			}
			
		}
	};
	
	//run animation 32 X 22
	static const char PROGMEM run[2][3][ANIM_SIZE] = {
		{
			{
				0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 
				0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
				0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 
				0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
			},	
			{
	   			0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 
				0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
				0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 	
			},
			{
		   		0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 
				0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 
				0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 
				0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,	
			}
		},
		
		{
			{
				0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
				0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 
				0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 
				0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
				0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
				0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 
				0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 
				0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			}
			
		}
	};
	
	//bark animation 32 X 22
	static const char PROGMEM bark[2][3][ANIM_SIZE] = {
		{
			{
				0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 
				0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 
				0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
			},	
			{
	   			0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 
				0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 
				0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 	
			},
			{
		   		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
				0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 
				0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 
				0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			},
		},
		
		{
			{
				0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 
				0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 
				0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 
				0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 
				0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 
				0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
				0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02, 
				0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 
				0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			}
			
		}
	};
	
	//sneak animation 32 X 22
	static const char PROGMEM sneak[2][3][ANIM_SIZE] = {
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 
				0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 
				0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 
				0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			},	
			{
	   			0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 
				0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04, 
				0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 
				0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,	
			},
			{
		   		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 
				0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06, 
				0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 
				0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,	
			},
		},
		
		{
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 
				0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
				0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 
				0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 
				0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04, 
				0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 
				0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00, 
			},
			{
				0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 
				0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04, 
				0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 
				0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
			}
			
		}
	};
   	
   	void animate_luna(void) {
   		
   		int anim_x;
   		int anim_y;
   		
   		if(isJumping || !showedJump) {
		   oled_set_cursor(ANIM_X, ANIM_Y + 2);
		   oled_write("     ", false);
		   anim_x = ANIM_X;
		   anim_y = ANIM_Y - 1;
		   showedJump = true;
		} else {
			oled_set_cursor(ANIM_X, ANIM_Y - 1);
			oled_write("     ", false);
			
			anim_x = ANIM_X;
			anim_y = ANIM_Y;
		}
   		
   		if(led_usb_state.caps_lock) {
   			oled_set_cursor(anim_x, anim_y);
		   	oled_write_raw_P(bark[current_frame][0], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 1);
		   	oled_write_raw_P(bark[current_frame][1], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 2);
		   	oled_write_raw_P(bark[current_frame][2], ANIM_SIZE);
		} else if(get_mods() & MOD_MASK_CS) {
			oled_set_cursor(anim_x, anim_y);
		   	oled_write_raw_P(sneak[current_frame][0], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 1);
		   	oled_write_raw_P(sneak[current_frame][1], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 2);
		   	oled_write_raw_P(sneak[current_frame][2], ANIM_SIZE);
		} else if(current_wpm <= MIN_WALK_SPEED) {
			oled_set_cursor(anim_x, anim_y);
		   	oled_write_raw_P(sit[current_frame][0], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 1);
		   	oled_write_raw_P(sit[current_frame][1], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 2);
		   	oled_write_raw_P(sit[current_frame][2], ANIM_SIZE);
		} else if(current_wpm <= MIN_RUN_SPEED) {
			oled_set_cursor(anim_x, anim_y);
		   	oled_write_raw_P(walk[current_frame][0], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 1);
		   	oled_write_raw_P(walk[current_frame][1], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 2);
		   	oled_write_raw_P(walk[current_frame][2], ANIM_SIZE);
		} else {
			oled_set_cursor(anim_x, anim_y);
		   	oled_write_raw_P(run[current_frame][0], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 1);
		   	oled_write_raw_P(run[current_frame][1], ANIM_SIZE);
		   	oled_set_cursor(anim_x, anim_y + 2);
		   	oled_write_raw_P(run[current_frame][2], ANIM_SIZE);
		}
	}
	
	
#	if OLED_TIMEOUT > 0

	if(last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
		oled_off();
		return;
	} else {
		oled_on();
	}
#	endif
   	
   	if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
   		anim_timer = timer_read32();
   		current_frame = (current_frame + 1) % 2;
   		animate_luna();
	}
		
};

static void render_caps(int CAP_X, int CAP_Y) {
	if(led_usb_state.caps_lock == true) {
    	static const char PROGMEM caps[KB_STAT_SIZE] = {
	        0x00, 0xfe, 0xff, 0x07, 0xfb, 0xfb, 0x3b, 0xdb, 0xeb, 
			0xdb, 0x3b, 0xfb, 0xfb, 0x07, 0xff, 0xfe, 0x00, 0x00,  
    	};
	    static const char PROGMEM caps2[KB_STAT_SIZE] = {
	    	0x00, 0x3f, 0x7f, 0x70, 0x6f, 0x6f, 0x68, 0x6e, 0x6e, 
			0x6e, 0x68, 0x6f, 0x6f, 0x70, 0x7f, 0x3f, 0x00, 0x00
	    };
		oled_set_cursor(CAP_X, CAP_Y);
	    oled_write_raw_P(caps, KB_STAT_SIZE);
	    oled_set_cursor(CAP_X, CAP_Y + 1);
	    oled_write_raw_P(caps2, KB_STAT_SIZE);
		}
	else {
		static const char PROGMEM caps[KB_STAT_SIZE] = {
	        0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0xc4, 0x24, 0x14, 
			0x24, 0xc4, 0x04, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    	};
	    static const char PROGMEM caps2[KB_STAT_SIZE] = {
	    	0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x17, 0x11, 0x11, 
			0x11, 0x17, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
	    };
		oled_set_cursor(CAP_X, CAP_Y);
	    oled_write_raw_P(caps, KB_STAT_SIZE);
	    oled_set_cursor(CAP_X, CAP_Y + 1);
	    oled_write_raw_P(caps2, KB_STAT_SIZE);
	}
}

static void render_num(int NUM_X, int NUM_Y) {
	if(led_usb_state.num_lock == true) {
    	static const char PROGMEM num[KB_STAT_SIZE] = {
	        0x00, 0xfe, 0xff, 0x07, 0xfb, 0xfb, 0xfb, 0xdb, 0x0b, 
			0xfb, 0xfb, 0xfb, 0xfb, 0x07, 0xff, 0xfe, 0x00, 0x00, 
    	};
	    static const char PROGMEM num2[KB_STAT_SIZE] = {
	    	0x00, 0x3f, 0x7f, 0x70, 0x6f, 0x6f, 0x6f, 0x6b, 0x68, 
			0x6b, 0x6f, 0x6f, 0x6f, 0x70, 0x7f, 0x3f, 0x00, 0x00
	    };
		oled_set_cursor(NUM_X, NUM_Y);
	    oled_write_raw_P(num, KB_STAT_SIZE);
	    oled_set_cursor(NUM_X, NUM_Y + 1);
	    oled_write_raw_P(num2, KB_STAT_SIZE);
		}
	else {
		static const char PROGMEM num[KB_STAT_SIZE] = {
	        0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x04, 0x24, 0xf4, 
			0x04, 0x04, 0x04, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00,
    	};
	    static const char PROGMEM num2[KB_STAT_SIZE] = {
	    	0x00, 0x00, 0x00, 0x0f, 0x10, 0x10, 0x10, 0x14, 0x17, 
			0x14, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
	    };
		oled_set_cursor(NUM_X, NUM_Y);
	    oled_write_raw_P(num, KB_STAT_SIZE);
	    oled_set_cursor(NUM_X, NUM_Y + 1);
	    oled_write_raw_P(num2, KB_STAT_SIZE);
	}
}

static void render_scroll(int SCROLL_X, int SCROLL_Y) {
	if(led_usb_state.scroll_lock == true) {
    	static const char PROGMEM scroll[KB_STAT_SIZE] = {
	        0x00, 0xfe, 0xff, 0x07, 0xfb, 0xfb, 0x7b, 0xfb, 0x0b, 
			0xfb, 0x7b, 0xfb, 0xfb, 0x07, 0xff, 0xfe, 0x00, 0x00, 
    	};
	    static const char PROGMEM scroll2[KB_STAT_SIZE] = {
	    	0x00, 0x3f, 0x7f, 0x70, 0x6f, 0x6b, 0x6b, 0x6a, 0x68, 
			0x6a, 0x6b, 0x6b, 0x6f, 0x70, 0x7f, 0x3f, 0x00, 0x00
	    };
		oled_set_cursor(SCROLL_X, SCROLL_Y);
	    oled_write_raw_P(scroll, KB_STAT_SIZE);
	    oled_set_cursor(SCROLL_X, SCROLL_Y + 1);
	    oled_write_raw_P(scroll2, KB_STAT_SIZE);
		}
	else {
		static const char PROGMEM scroll[KB_STAT_SIZE] = {
	        0x00, 0x00, 0x00, 0xf8, 0x04, 0x04, 0x84, 0x04, 0xf4, 
			0x04, 0x84, 0x04, 0x04, 0xf8, 0x00, 0x00, 0x00, 0x00, 
    	};
	    static const char PROGMEM scroll2[KB_STAT_SIZE] = {
	    	0x00, 0x00, 0x00, 0x0f, 0x10, 0x14, 0x14, 0x15, 0x17, 
			0x15, 0x14, 0x14, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
	    };
		oled_set_cursor(SCROLL_X, SCROLL_Y);
	    oled_write_raw_P(scroll, KB_STAT_SIZE);
	    oled_set_cursor(SCROLL_X, SCROLL_Y + 1);
	    oled_write_raw_P(scroll2, KB_STAT_SIZE);
	}
}

static void render_winstat(int WIN_X, int WIN_Y)
{
	static const char PROGMEM winlogo[WIN_STAT_SIZE] = {
		0x7C, 0x7C, 0x7C, 0x7E, 0x00, 0x7E,
	    0x7E, 0x7E, 0x7F, 0x7F, 0x7F, 0x00,
	};
	static const char PROGMEM winlogo2[WIN_STAT_SIZE] = {
	    0x1F, 0x1F, 0x1F, 0x3F, 0x00, 0x3F,
	    0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x00,
	};
	
	oled_set_cursor(WIN_X, WIN_Y);
	oled_write_raw_P(winlogo, WIN_STAT_SIZE);
	oled_set_cursor(WIN_X, WIN_Y + 1);
	oled_write_raw_P(winlogo2, WIN_STAT_SIZE);
	
	oled_set_cursor(WIN_X + 2, WIN_Y);
	oled_write("WINKEY", false);
	
	oled_set_cursor(WIN_X + 2, WIN_Y + 1   );
	if(keymap_config.no_gui)
    {
    	oled_write("DISABLED", false);
	}
	else {
		oled_write("ENABLED  ", false);
	}
}

bool oled_task_user(void) {
	current_wpm = get_current_wpm();
	led_usb_state = host_keyboard_led_state();
	render_animation(13, 3);
	oled_set_cursor(0, 0);
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case MAIN:
            oled_write("MAIN  ", false);
            break;
        case SECOND:
            oled_write("SECOND", false);
            break;
        case THIRD:
            oled_write("THIRD ", false);
            break;
        default:
            oled_write("FOURTH", false);
    }
	render_caps(0, 2);
	render_num(3, 2);
    render_scroll(6, 2);
	render_winstat(1, 5);   
	
    
    oled_set_cursor(12, 0);
    oled_write("WPM: ", false);
    oled_write(get_u8_str(current_wpm, '0'), false);
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case KC_SPC:
			if(record->event.pressed) {
				isJumping = true;
				showedJump = false;
			} else {
				isJumping = false;
			}
			break;
	}
	return true;
}


