#ifndef RGBLIGHT_RECONFIG_H
#define RGBLIGHT_RECONFIG_H

#ifdef RGBLIGHT_ANIMATIONS
   // for backward compatibility
   #define RGBLIGHT_EFFECT_BREATHING
   #define RGBLIGHT_EFFECT_RAINBOW_MOOD
   #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
   #define RGBLIGHT_EFFECT_SNAKE
   #define RGBLIGHT_EFFECT_KNIGHT
   #define RGBLIGHT_EFFECT_CHRISTMAS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
   #define RGBLIGHT_EFFECT_RGB_TEST
   #define RGBLIGHT_EFFECT_ALTERNATING
#endif

#ifdef RGBLIGHT_STATIC_PATTERNS
   #define RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

#if defined(RGBLIGHT_IDLE_TIMEOUT)
  #define RGBLIGHT_USE_PROCESS
#endif

// check dynamic animation effects chose ?
#if defined(RGBLIGHT_EFFECT_BREATHING) || \
    defined(RGBLIGHT_EFFECT_RAINBOW_MOOD) || \
    defined(RGBLIGHT_EFFECT_RAINBOW_SWIRL) ||	\
    defined(RGBLIGHT_EFFECT_SNAKE) ||		\
    defined(RGBLIGHT_EFFECT_KNIGHT) ||		\
    defined(RGBLIGHT_EFFECT_CHRISTMAS) ||	\
    defined(RGBLIGHT_EFFECT_RGB_TEST) ||	\
    defined(RGBLIGHT_EFFECT_ALTERNATING) ||	\
    defined(RGBLIGHT_IDLE_ENABLE)
  #define RGBLIGHT_USE_TIMER
  #ifndef RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_ANIMATIONS  // for backward compatibility
  #endif
#endif

#endif // RGBLIGHT_RECONFIG_H
