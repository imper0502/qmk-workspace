#pragma once

enum layer_names {
    _BS,
    _QW,
    _NP,
    _MK,
    _FN
};

#ifdef KEY_OVERRIDE_ENABLE
#   include "features/key_overriding.h"
#endif

#ifdef TAP_DANCE_ENABLE
#   include "features/tap_dance.h"
#endif

#ifdef COMBO_ENABLE
#    include "features/key_combo.h"
#endif

#define MT_ESC  GUI_T(KC_ESC)
#define MT_BSPC ALT_T(KC_BSPC)
#define OS_LSFT OSM(MOD_LSFT)

#define LT_BTN3 LT(_FN, KC_BTN3)

#define LA_LCTL LALT(KC_LCTL)
#define RA_RCTL RALT(KC_RCTL)

#ifdef MINUS_DANCE_ENABLE
#define TD_MINS TD(MINUS_DANCE)
#endif
#ifdef BACKSLASH_DANCE_ENABLE
#define TD_BSLS TD(BACKSLASH_DANCE)
#endif
#ifdef TABLE_DANCE_ENABLE
#define TD_RTAB TD(TABLE_DANCE)
#endif

#ifdef INSERT_PLUS_DANCE_ENABLE
#define TD_INSP TD(INSERT_PLUS)
#endif
#ifdef ALT_TABLE_DANCE_ENABLE 
#define TD_TABA TD(ALT_TABLE)   
#endif
