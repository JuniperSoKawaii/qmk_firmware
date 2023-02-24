/*
Copyright 2022 <felix@fjlaboratories.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *         ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *å
*/
// Checked with Eagle Schematic
#define MATRIX_ROW_PINS { F7, F6, F5, F4, F1, F0}
#define MATRIX_COL_PINS { E6, B0, B1, B2, B3, B7, D2, D3, D5, D4, D6, C6, B4, B5, B6, E2}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Define less important options */

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO MAGIC_TOGGLE_NKRO
#define FORCE_NKRO
/*
 * Feature disable options
 * These options are also useful to firmware size reduction.
 */

/* disable debug print */
#define NO_DEBUG

/* disable print */
#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Encoders */
#define ENCODERS_PAD_A { C7 }
#define ENCODERS_PAD_B { D1 }

/* If your encoder’s clockwise directions are incorrect, you can swap the A & B pad definitions. They can also be flipped with a define */
//#define ENCODER_DIRECTION_FLIP

/* Additionally, the resolution, which defines how many pulses the encoder registers between each detent, can be defined with */
//#define ENCODER_RESOLUTION  4  


// The pin connected to the data pin of the LEDs
#define RGB_DI_PIN D7
// The number of LEDs connected
//#define DRIVER_LED_TOTAL 66
#define RGB_MATRIX_LED_COUNT 66

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_DISABLE_AFTER_TIMEOUT 0
//#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_LED_FLUSH_LIMIT 16
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200

//#define RGB_MATRIX_STARTUP_SAT 255
//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_ALPHAS_MODS
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects

//#define ENABLE_RGB_MATRIX_ALPHAS_MODS	        
//#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN    
//#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT 
#define ENABLE_RGB_MATRIX_BREATHING	            
//#define ENABLE_RGB_MATRIX_BAND_SAT            
//#define ENABLE_RGB_MATRIX_BAND_VAL            
//#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT   
//#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL   
//#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT     
//#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     
#define ENABLE_RGB_MATRIX_CYCLE_ALL             
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT      
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN           
//#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN          
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL       
//#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL        
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL            
//#define ENABLE_RGB_MATRIX_DUAL_BEACON           
//#define ENABLE_RGB_MATRIX_RAINBOW_BEACON        
//#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS     
//#define ENABLE_RGB_MATRIX_RAINDROPS             
//#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS   
//#define ENABLE_RGB_MATRIX_HUE_BREATHING         
//#define ENABLE_RGB_MATRIX_HUE_PENDULUM          
//#define ENABLE_RGB_MATRIX_HUE_WAVE              
//#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL         
#define ENABLE_RGB_MATRIX_PIXEL_FLOW              
//#define ENABLE_RGB_MATRIX_PIXEL_RAIN            


//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE	 
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE	         
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE	     
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE	 
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS	     
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS	
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS      
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS	
#define ENABLE_RGB_MATRIX_SPLASH	                
//#define ENABLE_RGB_MATRIX_MULTISPLASH	            
//#define ENABLE_RGB_MATRIX_SOLID_SPLASH	            
//#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH     

