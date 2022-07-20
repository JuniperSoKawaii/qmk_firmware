#pragma once

#define NO_MUSIC_MODE
#define FORCE_NKRO

// I don't use a bunch of layers
#define LAYER_STATE_8BIT

// Disable the RGB Light (underglow) stuff
#undef RBGLIGHT_ANIMATIONS
#undef RBGLIGHT_EFFECT_BREATHING
#undef RBGLIGHT_EFFECT_RAINBOW_MOOD
#undef RBGLIGHT_EFFECT_RAINBOW_SWIRL
#undef RBGLIGHT_EFFECT_SNAKE
#undef RBGLIGHT_EFFECT_KNIGHT
#undef RBGLIGHT_EFFECT_CHRISTMAS
#undef RBGLIGHT_EFFECT_STATIC_GRADIENT
#undef RBGLIGHT_EFFECT_RGB_TEST
#undef RBGLIGHT_EFFECT_ALTERNATING
#undef RBGLIGHT_EFFECT_TWINKLE

// No Cherry MX Lock switch
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// No oneshot (Active until another key hit)
#define NO_ACTION_ONESHOT

// Remove some RGB
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN