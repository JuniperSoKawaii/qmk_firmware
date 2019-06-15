#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#define MOUSEKEY_MAX_SPEED         8

// Must raise 5 halftones
/* #define CUSTOM_STARTUP \ */
/*  Q__NOTE(_FS7), \ */
/*  W__NOTE(_B7), */

#undef MUSICAL_NOTE
#define MUSICAL_NOTE(note, duration) {((NOTE##note) * 1.3348398541700344), duration}

#define CUSTOM_STARTUP \
    QD_NOTE(_A6),  \
    QD_NOTE(_C7),  \
    QD_NOTE(_A7),  \
    QD_NOTE(_F7),  \
    QD_NOTE(_G7),  \
    HD_NOTE(_C8),

#undef MUSICAL_NOTE
#define MUSICAL_NOTE(note, duration) {(NOTE##note), duration}

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(CUSTOM_STARTUP)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 440.f

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#endif
