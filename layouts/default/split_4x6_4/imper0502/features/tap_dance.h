/* Tap Dance */
#pragma once

enum tap_dance_names {
    CONTROL_DANCE,
    ENTER_DANCE,
    SPACE_DANCE,
#ifdef MINUS_DANCE_ENABLE
    MINUS_DANCE,
#endif
#ifdef GRAVE_DANCE_ENABLE
    GRAVE_DANCE,
#endif
#ifdef BACKSLASH_DANCE_ENABLE
    BACKSLASH_DANCE,
#endif
#ifdef TABLE_DANCE_ENABLE
    TABLE_DANCE,
#endif
#ifdef INSERT_PLUS_DANCE_ENABLE 
    INSERT_PLUS,
#endif
#ifdef ALT_TABLE_DANCE_ENABLE    
    ALT_TABLE,
#endif
    COMMA_DANCE,
    DOT_DANCE,
};

/* Tap Dance */
typedef enum {
    JUST_TAP, TAPPING     , JUST_HOLD   ,
    DUAL_TAP, DUAL_TAPPING, TAP_AND_HOLD,
    TRI_TAP , TRI_TAPPING , TAP_TAP_HOLD,
    QUAD_TAP,               TRI_TAP_HOLD, 
    OTHERWISE
} td_state_t;

td_state_t current_dance(tap_dance_state_t *state) {
#ifdef CONSOLE_ENABLE
    dprintf(
        "TD: pressed: %u, int: %u, count: %u\n",
        state->pressed,
        state->interrupted,
        state->count
    );
#endif
    switch (state->count) {
        case 1:
            return state->interrupted
                    ? TAPPING
                    : state->pressed 
                        ? JUST_HOLD
                        : JUST_TAP;
        case 2:  
            return state->interrupted
                    ? DUAL_TAPPING
                    : state->pressed 
                            ? TAP_AND_HOLD 
                            : DUAL_TAP;
        case 3:  
            return state->interrupted
                    ? TRI_TAPPING
                    : state->pressed
                            ? TAP_TAP_HOLD
                            : TRI_TAP;
        case 4:  
            return (state->interrupted || !state->pressed)
                    ? QUAD_TAP 
                    : TRI_TAP_HOLD;
        default:
            return OTHERWISE;
    }
}

void td_left_control_finished(tap_dance_state_t *state, void *user_data);
void td_left_control_plus_reset(tap_dance_state_t *state, void *user_data);

void td_enter_finished(tap_dance_state_t *state, void *user_data);
void td_enter_reset(tap_dance_state_t *state, void *user_data);

void td_space_each_tap(tap_dance_state_t *state, void *user_data);
void td_space_finished(tap_dance_state_t *state, void *user_data);
void td_space_reset(tap_dance_state_t *state, void *user_data);

#ifdef MINUS_DANCE_ENABLE
void td_minus_finished(tap_dance_state_t *state, void *user_data);
void td_minus_reset(tap_dance_state_t *state, void *user_data);
#endif
#ifdef GRAVE_DANCE_ENABLE
void td_grave_finished(tap_dance_state_t *state, void *user_data);
void td_grave_reset(tap_dance_state_t *state, void *user_data);
#endif
#ifdef BACKSLASH_DANCE_ENABLE
void td_backslash_finished(tap_dance_state_t *state, void *user_data);
void td_backslash_reset(tap_dance_state_t *state, void *user_data);
#endif
#ifdef TABLE_DANCE_ENABLE
void td_table_finished(tap_dance_state_t *state, void *user_data);
void td_table_reset(tap_dance_state_t *state, void *user_data);
#endif
#ifdef INSERT_PLUS_DANCE_ENABLE
void td_insert_plus_finished(tap_dance_state_t *state, void *user_data);
void td_insert_plus_reset(tap_dance_state_t *state, void *user_data);
#endif
#ifdef ALT_TABLE_DANCE_ENABLE
void td_alt_tab_each_tap(tap_dance_state_t *state, void *user_data);
void td_alt_tab_finished(tap_dance_state_t *state, void *user_data);
#endif

tap_dance_action_t tap_dance_actions[] = {
    [CONTROL_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_left_control_finished, td_left_control_plus_reset),
    [ENTER_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_enter_finished, td_enter_reset),
    [SPACE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(td_space_each_tap, td_space_finished, td_space_reset),
#ifdef MINUS_DANCE_ENABLE
    [MINUS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_minus_finished, td_minus_reset),
#endif
#ifdef GRAVE_DANCE_ENABLE
    [GRAVE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_grave_finished, td_grave_reset),
#endif
#ifdef BACKSLASH_DANCE_ENABLE
    [BACKSLASH_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_backslash_finished, td_backslash_reset),
#endif
#ifdef TABLE_DANCE_ENABLE
    [TABLE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_table_finished, td_table_reset),
#endif
#ifdef INSERT_PLUS_DANCE_ENABLE
    [INSERT_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_insert_plus_finished, td_insert_plus_reset),
#endif
#ifdef ALT_TABLE_DANCE_ENABLE
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL),
#endif
    [COMMA_DANCE] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_SEMICOLON),
    [DOT_DANCE] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLON)
};

#define TD_LCTL TD(CONTROL_DANCE)
#define TD_ENT  TD(ENTER_DANCE)
#define TD_SPC  TD(SPACE_DANCE)