/* Copyright 2021 James Sa
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

#define _C(X) LCTL_T(X)
#define _A(X) LALT_T(X)
#define _S(X) LSFT_T(X)
#define _G(X) LGUI_T(X)
#define BSPC_A LALT_T(KC_BSPC)
#define SPC_FN LT(3, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_56keys(
        KC_INS , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
     _G(KC_ESC), KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LALT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
                                   XXXXXXX, KC_LCTL, KC_LSFT, BSPC_A , KC_ENT , SPC_FN , KC_BSLS, XXXXXXX
    ),
    [1] = LAYOUT_56keys(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_BTN4,                   KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, XXXXXXX,
        XXXXXXX, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,                   KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PMNS, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(1)  ,                   KC_PERC, KC_1   , KC_2   , KC_3   , KC_EQL , XXXXXXX,
                                   XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, KC_PENT, KC_0   , KC_DOT , XXXXXXX
    ),
    [2] = LAYOUT_56keys(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_BTN4, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_BTN5, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   TG(2)  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX
    ),
    [3] = LAYOUT_56keys(
        KC_F1  , KC_F2  , KC_3   , KC_F4  , KC_F5  , KC_F6  ,                   KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
        KC_TAB , KC_LCBR, KC_7   , KC_8   , KC_9   , KC_CAPS,                   KC_INS , KC_HOME, KC_UP  , KC_END , KC_RCBR, KC_TAB ,
        KC_ESC , KC_LBRC, KC_4   , KC_5   , KC_6   , CW_TOGG,                   KC_DEL , KC_LEFT, KC_DOWN, KC_RGHT, KC_RBRC, KC_RGUI,
        _______, KC_LPRN, KC_1   , KC_2   , KC_3   , TG(1)  ,                   TG(2)  , KC_PGUP, KC_LABK, KC_RABK, KC_RPRN, _______,
                                   XXXXXXX, KC_DOT , KC_0   , KC_BSPC, XXXXXXX, KC_PSCR, KC_PGDN, XXXXXXX
    ),
    [4] = LAYOUT_56keys(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [5] = LAYOUT_56keys(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
