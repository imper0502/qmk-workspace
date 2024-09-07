/* Key Override */
#pragma once

const key_override_t circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX , KC_NO);               // ^
const key_override_t at_override   = ko_make_basic(MOD_MASK_SHIFT, KC_AT         , KC_AUDIO_MUTE);       // @  
const key_override_t hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH       , KC_AUDIO_VOL_DOWN);   // #
const key_override_t lprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN , KC_AUDIO_VOL_UP);     // (
const key_override_t rprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_PAREN, SWIN(KC_S));          // )

const key_override_t dlr_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR     , KC_CALCULATOR);       // $
const key_override_t ampr_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND  , KC_MEDIA_PREV_TRACK); // & 
const key_override_t astr_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK   , KC_MEDIA_PLAY_PAUSE); // * 
const key_override_t ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION   , KC_MEDIA_NEXT_TRACK); // ?
const key_override_t exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXCLAIM    , KC_NO);               // !

const key_override_t comm_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON, ~(1 << 1)); // ,;
const key_override_t dot_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT  , KC_COLON    , ~(1 << 1)); // .:
const key_override_t slsh_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT  , ~(1 << 1)); // /%

const key_override_t rgui_tap_slsh_override = ko_make_with_layers(MOD_MASK_SHIFT, RGUI_T(KC_SLASH), KC_PERCENT  , ~(1 << 1)); // /%

// const key_override_t lcbr_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE);// {}
// const key_override_t rcbr_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_CURLY_BRACE, KC_BRIGHTNESS_UP);    // }

const key_override_t **key_overrides = (const key_override_t *[]) {
    &circ_override,
    &at_override  ,
    &hash_override,
    &lprn_override,
    &rprn_override,

    &dlr_override ,
    &ampr_override,
    &astr_override,
    &ques_override,
    &exlm_override,

    &comm_override,
    &dot_override ,
    &slsh_override,
    &rgui_tap_slsh_override,

    NULL // Null terminate the array of overrides!
};
