#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
    _BS,
    _QW,
    _NP,
    _MK,
    _FN
};

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#ifdef KEY_OVERRIDE_ENABLE
#   include "features/key_overriding.h"
#endif
