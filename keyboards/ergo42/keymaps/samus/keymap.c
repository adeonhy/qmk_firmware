#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "mousekey.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define NUM 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  TD_LRGUI = 0,
  TD_BTN23,
  TD_PM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  <   |   |  >   |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  [   |   |  ]   |   N  |   M  |   ,  |   .  |   /  |  \   |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |=/NUM |  `   | BTN2 |LALT  |LGUI/ |Space/|Enter |   |Back  |Space/| BTN3 | ESC/ | Copy | Paste| Enter|
 * |      |      |      |      |      |SYMB  |      |   |Space |META  |      | Alt  |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = LAYOUT( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,             S(KC_COMM),    S(KC_DOT),  KC_Y,             KC_U,    KC_I,     KC_O,     KC_P,     KC_MINS, \
  KC_LCTRL, KC_A,    KC_S,   KC_D,    KC_F,    KC_G,             S(KC_9),       S(KC_0),    KC_H,             KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,             KC_LBRC,       KC_RBRC,    KC_N,             KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  SFT_T(KC_BSLS), \
  LT(NUM, KC_EQL),   KC_GRV, KC_BTN2, KC_LALT, TD(TD_LRGUI), LT(SYMB, KC_SPC), KC_ENT,        KC_BSPC,    LT(META, KC_SPC), KC_ESC,  KC_BTN3,  LGUI(KC_C), LGUI(KC_V), TD(TD_PM)\
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |RESET |   1  |   2  |   3  |   4  |   5  |      |   |      |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   |      |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  {   |   |  }   |      |      |      | F11  | F12  |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = LAYOUT( \
  RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, KC_F6,   KC_BTN2,   KC_BTN1, KC_BTN3, KC_F10,  _______, \
  _______, _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_F12,  _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * |RESET |   !  |   @  |   #  |   $  |   %  |      |   |      |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      | LEFT | DOWN | UP   | RIGHT|      |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  |      |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      | LEFT | DOWN | RIGHT|
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = LAYOUT( \
  RESET,   S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), _______, _______, S(KC_6), S(KC_7), S(KC_8), S(KC_9),  S(KC_0), _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______, _______ , \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX, XXXXXXX, _______, _______,  KC_UP,   _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT,  KC_DOWN, KC_RGHT\
),

/* GAME
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |  ]   |   Y  |   U  |   7  |   8  |   9  |  @   |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |  )   |   H  |   J  |   4  |   5  |   6  |  :   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |  }   |   N  |   0  |   1  |   2  |   3  |\/Sft |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |   |Back  |Enter | Del  |PrtSc |=>GAME|=>SYMB|  \   |
 * |      |      |      |      |      |      |      |   |Space |      |      |      |      |      |      |
 * `------------------------------------------------'   `------------------------------------------------'
 */
[NUM] = LAYOUT( \
  KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,   KC_RBRC,    KC_BSLS,    KC_Y,   KC_7,    KC_8,     KC_9,    _______,    KC_WH_U, \
  KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,   S(KC_8),    S(KC_9),    KC_H,   KC_4,    KC_5,     KC_6,    KC_WH_L,    KC_WH_R, \
  KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,   S(KC_RBRC), S(KC_BSLS), KC_0,   KC_1,    KC_2,     KC_3,    KC_MS_U,    KC_WH_D, \
  _______, KC_LGUI, KC_APP, KC_PSCR, KC_ESC, KC_BTN2, KC_BTN1,     KC_BSPC,    KC_ENT, KC_DELT, KC_PSCR,  KC_MS_L,  KC_MS_D, KC_MS_R \
)

};

void dance_pm(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_ENT);
      unregister_code(KC_ENT);
      break;
    case 2:
      mousekey_on(KC_BTN2);
      mousekey_off(KC_BTN2);
      register_code(KC_LCTRL);
      register_code(KC_P);
      unregister_code(KC_P);
      unregister_code(KC_LCTRL);
      register_code(KC_ENT);
      unregister_code(KC_ENT);
      break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LRGUI] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_RGUI),
  [TD_BTN23] = ACTION_TAP_DANCE_DOUBLE(KC_BTN2, KC_BTN3),
  [TD_PM] = ACTION_TAP_DANCE_FN(dance_pm)
};
