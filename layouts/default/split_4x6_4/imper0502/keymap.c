/* Copyright 2021 imper0502
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT_56keys(
        KC_DEL , KC_CIRC, KC_AT  , KC_HASH, KC_LPRN, KC_RPRN,                   KC_DLR , KC_AMPR, KC_ASTR, KC_QUES, KC_EXLM, KC_GRV ,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_MINS, KC_EQL ,
        MT_ESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , RGUI_T(KC_SLSH),
        KC_LALT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                   KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, KC_RALT,
                                   TD_INSP, TD_LCTL, OS_LSFT, MT_BSPC, TD_ENT , TD_SPC , TD_BSLS, TD_TABA
    ),
    [_QW] = LAYOUT_56keys(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        MT_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NP] = LAYOUT_42keys(
        XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN4,                   KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, XXXXXXX,
        XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                   KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PMNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_NP),                   KC_PERC, KC_1   , KC_2   , KC_3   , KC_EQL , XXXXXXX,
                                            KC_BTN1, KC_BTN3, KC_BTN2, KC_PENT, KC_0   , KC_DOT
    ),
    [_MK] = LAYOUT_56keys(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB , TG(_QW), CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BTN4, KC_MS_U, KC_BTN5, KC_WH_U, XXXXXXX,
        KC_ESC , KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG(_MK), KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
                                   XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_BTN1, LT_BTN3, KC_BTN2, KC_WH_D
    ),
    [_FN] = LAYOUT_54keys(
        KC_F1  , KC_F2  , KC_3   , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        KC_TAB , KC_LCBR, KC_7   , KC_8   , KC_9   , KC_CAPS,                   KC_INS , KC_HOME, KC_UP  , KC_END , KC_RCBR, KC_TAB ,
        KC_ESC , KC_LBRC, KC_4   , KC_5   , KC_6   , CW_TOGG,                   KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_ESC ,
        _______, KC_LPRN, KC_1   , KC_2   , KC_3   , TG(_NP),                   TG(_MK), KC_PGUP, KC_LABK, KC_RABK, KC_RPRN, _______,
                                            KC_DOT , KC_0   , KC_BSPC, KC_ENT , KC_PSCR, KC_PGDN
    )
};

bool is_idle_timeout = true;
void keyboard_pre_init_user(void) {
#if defined(LED_PIN_ON_STATE) && defined(TXLED) && defined(RXLED)
    setPinOutput(TXLED);
    setPinOutput(RXLED);
#endif
}

#if defined(LED_PIN_ON_STATE) && defined(TXLED) && defined(RXLED)
typedef enum {
    OFF, FLASH, ON
} led_status_t;

led_status_t  rx_led_status;
led_status_t  tx_led_status;
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _MK:
        tx_led_status = FLASH;
        break;
    case _NP:
    case _FN:
        tx_led_status = ON;
        break;
    default:
        tx_led_status = OFF;
        rx_led_status = OFF;
        break;
    }
  return state;
}
#endif

uint16_t is_idle_timer = 0;
#if defined(LED_PIN_ON_STATE) && defined(TXLED) && defined(RXLED)
uint16_t _timer = 0;
bool next_led_pins_state = !LED_PIN_ON_STATE;
#endif
void matrix_scan_user(void) {
    if (!is_idle_timeout) {
        is_idle_timeout = timer_elapsed(is_idle_timer) > TAPPING_TERM;
    }
#if defined(LED_PIN_ON_STATE) && defined(TXLED) && defined(RXLED)
    switch (tx_led_status) {
    case ON:
        next_led_pins_state = LED_PIN_ON_STATE;
        break;
    case FLASH:
        if (timer_elapsed(_timer) > TAPPING_TERM) {
            next_led_pins_state = !next_led_pins_state;
            _timer = timer_read();
        }
        break;
    default:
        next_led_pins_state = !LED_PIN_ON_STATE;
        break;
    }
    switch (rx_led_status) {
    case FLASH:
        writePin(RXLED, !next_led_pins_state);
        break;
    default:
        writePin(RXLED, !host_keyboard_led_state().caps_lock);
        break;
    }
    writePin(TXLED, next_led_pins_state);
#endif
}

/* Key Behavior */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#if defined(TAP_DANCE_ENABLE) && defined(ALT_TABLE_DANCE_ENABLE)
    case TD_TABA:
        return TAPPING_TERM * 4;
#endif
#if defined(TAP_DANCE_ENABLE) && defined(INSERT_PLUS_DANCE_ENABLE)
    case TD_INSP:
        return TAPPING_TERM * 2;
#endif
    case MT_BSPC:
    case MLT_ENT:
    case LT_SPC:
    case LT_BTN3:
        return TAPPING_TERM - 32;
    default:
        return TAPPING_TERM;
    }
}

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
    debug_keyboard = true;
    debug_mouse = true;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    dprintf(
        "KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
        keycode,
        record->event.key.col,
        record->event.key.row,
        record->event.pressed,
        record->event.time,
        record->tap.interrupted,
        record->tap.count
    );
#endif
    
    switch (keycode) {
    case MLT_ENT:
        if (!record->tap.count) {
            if (record->event.pressed) {
                register_mods(MOD_LALT);
                layer_on(_FN);
            } else {
                layer_off(_FN);
                tap_code(KC_RCTL);
                unregister_mods(MOD_LALT);
            }
            return false;
        }
        break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        is_idle_timeout = false;
        is_idle_timer = timer_read();
    }
    switch (keycode) {
    case KC_ESC:
    case KC_CAPS:
    case TO(_BS):
        clear_mods();
    default:
        return;
    }
}

/* Tap Dance Behavior */
#ifdef TAP_DANCE_ENABLE
static td_state_t td_state;
#endif

#if defined(TAP_DANCE_ENABLE) && defined(CONTROL_DANCE_ENABLE)
static td_state_t td_control_state;

void td_left_control_finished(tap_dance_state_t *state, void *user_data) {
    td_control_state = current_dance(state);
    switch (td_control_state) {
        case JUST_TAP ... JUST_HOLD:
            register_mods(MOD_LCTL);
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            register_mods(MOD_LSFT|MOD_LCTL);
            break;
        case TRI_TAPPING ... TAP_TAP_HOLD:
            layer_invert(_MK);
            break;
        default:
            return;
    }
    return;
}

void td_left_control_plus_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_control_state) {
        case JUST_TAP ... JUST_HOLD: 
            unregister_mods(MOD_LCTL);
            break;
        case DUAL_TAP:    
            tap_code(KC_LCTL); 
            tap_code(KC_LCTL); 
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            unregister_mods(MOD_LSFT|MOD_LCTL); 
            break;
        case TRI_TAP ... TAP_TAP_HOLD: 
            layer_invert(_MK); 
            break;
        default:
            return;
    }
    return;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(MINUS_DANCE_ENABLE)
void td_minus_finished(tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case JUST_TAP:
            if (!state->pressed) {
                register_code(KC_MINUS); break;
            }
            td_state = JUST_HOLD;
        case JUST_HOLD:             
            register_mods(MOD_LCTL);
            layer_on(_FN);
            break;     
        case DUAL_TAP:     
            register_code(KC_EQUAL); break;
        case TAP_AND_HOLD: 
            register_mods(MOD_LSFT|MOD_LCTL);
            layer_on(_FN);
            break;
        default:
            return;
    }
    return;
}

void td_minus_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case JUST_TAP:                 
            unregister_code(KC_MINUS); break;
        case JUST_HOLD: 
            layer_off(_FN);
            unregister_mods(MOD_LCTL); break;
        case DUAL_TAP:               
            unregister_code(KC_EQUAL); break;
        case TAP_AND_HOLD: 
            layer_off(_FN);
            unregister_mods(MOD_LSFT|MOD_LCTL);
            break;
        default:
            return;
    }
    return;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(ENTER_DANCE_ENABLE)
static td_state_t td_enter_state;

void td_enter_finished(tap_dance_state_t *state, void *user_data) {
    td_enter_state = current_dance(state);
    switch (td_enter_state) {
        case TAPPING ... JUST_HOLD:           
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LALT);
                layer_on(_FN);
            } else {
                register_code(KC_ENT);
            }
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LSFT|MOD_LALT);
                layer_on(_FN);
            } else {
                tap_code(KC_ENT);
                register_code(KC_ENT);
            }
            break;
        case TRI_TAPPING ... TAP_TAP_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LSFT);
                layer_on(_FN);
            } else {
                tap_code(KC_ENT);
                tap_code(KC_ENT);
                register_code(KC_ENT);
            }
            break;
        case TRI_TAP:
            tap_code(KC_ENT);
        case DUAL_TAP:
            tap_code(KC_ENT);
        case JUST_TAP:
        default:
            register_code(KC_ENT); 
            return;
    }
    return;
}

void td_enter_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_enter_state) {
        case TAPPING ... JUST_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN);
                tap_code(KC_RCTL);
                unregister_mods(MOD_LALT);
            } else {
                unregister_code(KC_ENT);
            }
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN);
                unregister_mods(MOD_LSFT|MOD_LALT);
            } else {
                unregister_code(KC_ENT);
            }
            break;
        case TRI_TAPPING ... TAP_TAP_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN);
                unregister_mods(MOD_LSFT);
            } else {
                unregister_code(KC_ENT);
            }
            break;
        default:
            unregister_code(KC_ENT);
            return;
    }
    return;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(SPACE_DANCE_ENABLE)
static td_state_t td_space_state;

void td_space_each_tap(tap_dance_state_t *state, void *user_data) {
    switch (state->count)
    {
    case 1 ... 2:
        /* code */
        break;
    case 3:
        tap_code(KC_SPACE);
    default:
        tap_code(KC_SPACE);
        break;
    }
    return;
}

void td_space_finished(tap_dance_state_t *state, void *user_data) {
    td_space_state = current_dance(state);
    switch (td_space_state)
    {
    case TAPPING:
        if (is_idle_timeout) {
            layer_on(_FN);
        } else {
            register_code(KC_SPC);
        }
    case JUST_HOLD:       
            layer_on(_FN);
        break;
    case DUAL_TAP:
        tap_code(KC_SPC);
        register_code(KC_SPC);
        break;
    case DUAL_TAPPING ... TAP_AND_HOLD:        
        register_mods(MOD_LSFT);
        layer_on(_FN);
        break;
    default:
        register_code(KC_SPC); 
        return;
    }
    return;
}

void td_space_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_space_state)
    {
    case TAPPING:
        if (is_idle_timeout) {
            layer_off(_FN);
        } else {
            unregister_code(KC_SPC);
        }
    case JUST_HOLD:
        if (IS_LAYER_OFF(_QW)) {
            layer_off(_FN);
        } else {
            unregister_code(KC_SPC);
        }
        break;
    case DUAL_TAPPING ... TAP_AND_HOLD:
        if (IS_LAYER_OFF(_QW)) {
            layer_off(_FN);
            unregister_mods(MOD_LSFT);
        } else {
            unregister_code(KC_SPC);
        }
        break;
    default:
        unregister_code(KC_SPC);
        return;
    }
    return;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(BACKSLASH_DANCE_ENABLE)
static td_state_t td_backslash_state;

void td_backslash_finished(tap_dance_state_t *state, void *user_data) {
    td_backslash_state = current_dance(state);
    switch (td_backslash_state) {
        case TAPPING ... JUST_HOLD:           
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LCTL);
                layer_on(_FN);
            } else {
                register_code(KC_BSLS);
            }
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LSFT|MOD_LCTL);
                layer_on(_FN);
            } else {
                tap_code(KC_BSLS);
                register_code(KC_BSLS);
            }
            break;
        case TRI_TAPPING ... TAP_TAP_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                register_mods(MOD_LSFT);
                layer_on(_FN);
            } else {
                tap_code(KC_BSLS);
                tap_code(KC_BSLS);
                register_code(KC_BSLS);
            }
            break;
        case TRI_TAP:
            tap_code(KC_BSLS);
        case DUAL_TAP:
            tap_code(KC_BSLS);
        case JUST_TAP:
        default:
            register_code(KC_BSLS); 
            return;
    }
    return;
}

void td_backslash_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_backslash_state) {
        case TAPPING ... JUST_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN); 
                unregister_mods(MOD_LCTL);
            } else {
                unregister_code(KC_BSLS);
            }
            break;
        case DUAL_TAPPING ... TAP_AND_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN);
                unregister_mods(MOD_LSFT|MOD_LCTL);
            } else {
                unregister_code(KC_BSLS);
            }
            break;
        case TRI_TAPPING ... TAP_TAP_HOLD:
            if (IS_LAYER_OFF(_QW)) {
                layer_off(_FN);
                unregister_mods(MOD_LSFT);
            } else {
                unregister_code(KC_BSLS);
            }
            break;
        default:
            unregister_code(KC_BSLS);
            return;
    }
    return;
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(INSERT_PLUS_DANCE_ENABLE)
static uint8_t mod_state;
void td_insert_plus_finished(tap_dance_state_t *state, void *user_data) {
    mod_state = get_mods();
    td_state = current_dance(state);
    if (mod_state == 0) {
        switch (td_state) {
            case JUST_TAP: register_code16(C(KC_V)); return;
            case DUAL_TAP: register_code16(C(KC_A)); return;
            case TRI_TAP:       tap_code16(C(KC_A)); return;
            default:            tap_code16(C(KC_X)); return;
        }
    } else if (mod_state & (MOD_MASK_GUI | MOD_MASK_SHIFT)) {
        switch (td_state) {
            case JUST_TAP: register_code16(SWIN(KC_S)); return;
            default:      /* This line is necessary. */ return;
        }
    }
    register_code(KC_INS);
}

void td_insert_plus_reset(tap_dance_state_t *state, void *user_data) {
    if (mod_state == 0) {
        switch (td_state) {
            case JUST_TAP: unregister_code16(C(KC_V)); return;
            case DUAL_TAP: unregister_code16(C(KC_A)); return;
            default:              tap_code16(C(KC_V)); return;
        }
    } else if (mod_state & (MOD_MASK_GUI | MOD_MASK_SHIFT))  {
        switch (td_state) {
            case JUST_TAP: unregister_code16(SWIN(KC_S)); return;
            default:      /* This line is necessary. */   return;
        }
    }
    unregister_code(KC_INS);
}
#endif

#if defined(TAP_DANCE_ENABLE) && defined(ALT_TABLE_DANCE_ENABLE)
void td_alt_tab_each_tap(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: add_mods(MOD_LALT);
        default:  tap_code(KC_TAB);
    }
}

void td_alt_tab_finished(tap_dance_state_t *state, void *user_data) {
    del_mods(MOD_LALT);
}
#endif

/* Leader Key */
#ifdef LEADER_ENABLE
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }
}
#endif

/* Retry Encoders */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    mod_state = get_mods();
    switch (index) {
    case 0:
        if (IS_LAYER_ON(_FN)) {
            if (mod_state & MOD_MASK_CS) {
                clockwise ? tap_code(KC_BRIU) : tap_code(KC_BRID);
            } else {
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            }
        } else {
            if (mod_state == (MOD_LCTL | MOD_LSFT) ||
                mod_state == (MOD_LCTL | MOD_RSFT) ||
                mod_state == (MOD_RCTL | MOD_LSFT) ||
                mod_state == (MOD_RCTL | MOD_RSFT)) {
                del_mods(MOD_MASK_CS);
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_ALT) {
                del_mods(MOD_MASK_ALT);
                clockwise ? tap_code(KC_BTN5) : tap_code(KC_BTN4);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_SG) {
                clockwise ? tap_code16(C(KC_RGHT)) : tap_code16(C(KC_LEFT));
            } else if (mod_state & MOD_MASK_CTRL) {
                clockwise ? tap_code(KC_Y) : tap_code(KC_Z);
            } else {
                clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
            }
        }
        break;
    }
    return false;
}
#endif
