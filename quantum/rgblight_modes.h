#ifdef _RGBM_SINGLE_STATIC
  _RGBM_SINGLE_STATIC( STATIC_LIGHT )
  #ifdef RGBLIGHT_EFFECT_BREATHING
    _RGBM_MULTI_DYNAMIC( BREATHING )
    _RGBM_TMP_DYNAMIC( breathing_3 )
    _RGBM_TMP_DYNAMIC( breathing_4 )
    _RGBM_TMP_DYNAMIC( BREATHING_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_RAINBOW_MOOD
    _RGBM_MULTI_DYNAMIC( RAINBOW_MOOD )
    _RGBM_TMP_DYNAMIC( rainbow_mood_7 )
    _RGBM_TMP_DYNAMIC( RAINBOW_MOOD_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    _RGBM_MULTI_DYNAMIC( RAINBOW_SWIRL )
    _RGBM_TMP_DYNAMIC( rainbow_swirl_10 )
    _RGBM_TMP_DYNAMIC( rainbow_swirl_11 )
    _RGBM_TMP_DYNAMIC( rainbow_swirl_12 )
    _RGBM_TMP_DYNAMIC( rainbow_swirl_13 )
    _RGBM_TMP_DYNAMIC( RAINBOW_SWIRL_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_SNAKE
    _RGBM_MULTI_DYNAMIC( SNAKE )
    _RGBM_TMP_DYNAMIC( snake_16 )
    _RGBM_TMP_DYNAMIC( snake_17 )
    _RGBM_TMP_DYNAMIC( snake_18 )
    _RGBM_TMP_DYNAMIC( snake_19 )
    _RGBM_TMP_DYNAMIC( SNAKE_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_KNIGHT
    _RGBM_MULTI_DYNAMIC( KNIGHT )
    _RGBM_TMP_DYNAMIC( knight_22 )
    _RGBM_TMP_DYNAMIC( KNIGHT_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_CHRISTMAS
    _RGBM_SINGLE_DYNAMIC( CHRISTMAS )
  #endif
  #ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
    _RGBM_MULTI_STATIC( STATIC_GRADIENT )
    _RGBM_TMP_STATIC( static_gradient_26 )
    _RGBM_TMP_STATIC( static_gradient_27 )
    _RGBM_TMP_STATIC( static_gradient_28 )
    _RGBM_TMP_STATIC( static_gradient_29 )
    _RGBM_TMP_STATIC( static_gradient_30 )
    _RGBM_TMP_STATIC( static_gradient_31 )
    _RGBM_TMP_STATIC( static_gradient_32 )
    _RGBM_TMP_STATIC( static_gradient_33 )
    _RGBM_TMP_STATIC( STATIC_GRADIENT_end )
  #endif
  #ifdef RGBLIGHT_EFFECT_RGB_TEST
    _RGBM_SINGLE_DYNAMIC( RGB_TEST )
  #endif
  #ifdef RGBLIGHT_EFFECT_ALTERNATING
    _RGBM_SINGLE_DYNAMIC( ALTERNATING )
  #endif
  ////  Add a new mode here.
  // #ifdef RGBLIGHT_EFFECT_<name>
  //    _RGBM_<SINGLE|MULTI>_<STATIC|DYNAMIC>( <name> )
  // #endif
#endif

#undef _RGBM_SINGLE_STATIC
#undef _RGBM_SINGLE_DYNAMIC
#undef _RGBM_MULTI_STATIC
#undef _RGBM_MULTI_DYNAMIC
#undef _RGBM_TMP_STATIC
#undef _RGBM_TMP_DYNAMIC
