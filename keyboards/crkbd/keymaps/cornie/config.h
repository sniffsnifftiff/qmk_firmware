#pragma once

#define MASTER_LEFT

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define TAPPING_TERM 200

#define SPLIT_WPM_ENABLE

// INFO: graphics ----LEFT----
#define INCLUDE_LAYERS

#define INCLUDE_LOGO // either logo or luna
// #define INCLUDE_LUNA //FIX: glitching when oled goes to sleep

// INFO: graphics ----RIGHT---- pick one only
#define INCLUDE_ARASAKA
// #define INCLUDE_CAT
// #define INCLUDE_OCEAN //FIX: glitching when oled goes to sleep


