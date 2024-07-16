#include QMK_KEYBOARD_H

#ifdef INCLUDE_LAYERS
#   include "./animation/layers.h"
#endif

#ifdef INCLUDE_LOGO
#   include "./animation/corne_logo.h"
#endif

#ifdef INCLUDE_CAT
#   include "./animation/bongo.c"
#endif

#ifdef INCLUDE_OCEAN
#   include "./animation/ocean_dream.c"
#endif

#ifdef INCLUDE_ARASAKA
#   include "./animation/arasaka.c"
#endif

#ifdef INCLUDE_LUNA
#   include "./animation/luna.c"
#endif

#ifdef INCLUDE_BARS
#   include "./animation/music-bars.c"
#endif

enum layers {
    _BASE,
    _FIRST,
    _SECOND,
    _THIRD
};

enum {
    TD_RALT_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_RALT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_CAPS),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_ESC):
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MO(_THIRD):
            if (record->event.pressed) {
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
            }
            break;
        case KC_LCTL:
        case KC_RCTL:
#ifdef INCLUDE_OCEAN
            is_calm = (record->event.pressed) ? true : false;
#endif

#ifdef INCLUDE_LUNA
            if (record->event.pressed) {
              isSneaking = true;
            } else {
              isSneaking = false;
            }
#endif
            break;
        case KC_SPC:
#ifdef INCLUDE_LUNA
            if (record->event.pressed) {
              isJumping = true;
              showedJump = false;
            } else {
              isJumping = false;
            }
#endif
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LCTL_T(KC_ESC),KC_A, KC_S, KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH,TD(TD_RALT_CAPS),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LGUI,   MO(_FIRST),  KC_ENT,     KC_SPC,   KC_BSPC, MO(_SECOND)
                                        //`--------------------------'  `--------------------------'
  ),

  [_FIRST] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LALT, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_MINS, KC_EQL,  KC_GRV,  KC_LBRC, KC_RBRC, KC_PIPE,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                           KC_UNDS, KC_PLUS, KC_TILD, KC_LCBR, KC_RCBR, MO(_THIRD),
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  ),

  [_SECOND] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_MUTE, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_TOG, RGB_RMOD,RGB_MOD, RGB_VAD, RGB_VAI, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  ),

  [_THIRD] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_TRNS,  KC_TRNS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
                                        //`--------------------------'  `--------------------------'
  ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
#if defined(INCLUDE_ARASAKA) || defined(INCLUDE_OCEAN)
    return OLED_ROTATION_270;
#else
    return OLED_ROTATION_180;
#endif
    }
    return rotation;
}

bool oled_task_user(){
    oled_set_brightness(0);

#if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        // oled_clear();
        return oled_off();
    } else {
        oled_on();
    }
#endif

    if (is_keyboard_master()) {

#   ifdef INCLUDE_LAYERS
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_raw_P(qwerty_img, sizeof(qwerty_img));
                break;
            case _FIRST:
                oled_write_raw_P(lower_img, sizeof(lower_img));
                break;
            case _SECOND:
                oled_write_raw_P(raise_img, sizeof(raise_img));
                break;
            case _THIRD:
                oled_write_raw_P(adjust_img, sizeof(adjust_img));
                break;
        }
#   endif

#ifdef INCLUDE_LOGO
        oled_set_cursor(0, 12);
        oled_write_raw_P(corne_logo, sizeof(corne_logo));
#endif

#ifdef INCLUDE_LUNA

        led_usb_state = host_keyboard_led_state();
        render_luna(0, 13);
#endif

        // Display LED status
        // led_t led_state = host_keyboard_led_state();
        // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    } else {

#   ifdef INCLUDE_CAT
        draw_bongo(false);
#   endif

#   ifdef INCLUDE_OCEAN
        render_stars();
#   endif

#   ifdef INCLUDE_ARASAKA
        arasaka_draw();
#   endif

#   ifdef INCLUDE_BARS
        oled_render_anim();
#   endif
    }

    return false;
}
#endif
