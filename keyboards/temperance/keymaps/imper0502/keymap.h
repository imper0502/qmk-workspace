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

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#define MT_ESC  GUI_T(KC_ESC)
#define MT_BSPC ALT_T(KC_BSPC)
#define OS_LSFT OSM(MOD_LSFT)

#define MLT_ENT LT(_BS, KC_ENT)
#define LT_SPC  LT(_FN, KC_SPC)
#define LT_BTN3 LT(_FN, KC_BTN3)

#define TD_SPC TD(SPACE_DANCE)

#ifdef CONTROL_DANCE_ENABLE  
#define TD_LCTL TD(CONTROL_DANCE)
#endif
#ifdef MINUS_DANCE_ENABLE
#define TD_MINS TD(MINUS_DANCE)
#endif
#ifdef ENTER_DANCE_ENABLE
#define TD_ENT  TD(ENTER_DANCE)
#endif
#ifdef SPACE_DANCE_ENABLE
#define TD_SPC TD(SPACE_DANCE)
#endif
#ifdef BACKSLASH_DANCE_ENABLE
#define TD_BSLS TD(BACKSLASH_DANCE)
#endif
#ifdef INSERT_PLUS_DANCE_ENABLE
#define TD_INSP TD(INSERT_PLUS)
#endif
#ifdef ALT_TABLE_DANCE_ENABLE 
#define TD_TABA TD(ALT_TABLE)   
#endif
