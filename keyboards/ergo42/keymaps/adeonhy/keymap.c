#include "ergo42.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  | ESC  | Bksp |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      |  Ctrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   '  | Enter|
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * |      | (LSft|   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |   \  | RSft)|
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | [    |  ]   | META |  ESC | LAlt | LGUI |Space |   |Space | RGUI | DOWN | RIGHT|   `  |   -  |   =  |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[BASE] = KEYMAP( \
  KC_ESC,   KC_TAB,  KC_Q,     KC_W,   KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,   KC_P,    KC_ESC, KC_BSPC, \
  _______,  KC_LCTL, KC_A,     KC_S,   KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT, \
  _______,  KC_LSPO, KC_Z,     KC_X,   KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, KC_RSPC, \
  KC_LBRC,  KC_RBRC, MO(META), MO(SYMB), KC_LALT, KC_LGUI, LT(SYMB, KC_SPC), LT(META, KC_SPC), KC_RGUI, KC_DOWN, KC_RGHT,KC_GRV,  KC_MINS, KC_EQL \
),

/* META
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | Reset|      |   1  |   2  |   3  |   4  |  5   |   |  6   |   7  |   8  |   9  |   0  |      | Bksp |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Del  |      |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  |  F10 |      | Enter|
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | SYMB |      |      |      |      |      |      |   |      |      |      |  F11 |  F12 | PGUP | ESC  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | META | LCtrl| META | ESC  | LAlt | LGUI |Space |   |Space | RGUI | RALT |      | HOME |PGDOWN| END  |
 * `------------------------------------------------'   `------------------------------------------------'
 */

[META] = KEYMAP( \
  RESET,   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    _______, _______, \
  _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, \
  _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   S(KC_LBRC), S(KC_RBRC), KC_F7,   KC_F8,   KC_F11,  KC_F12,  KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______, KC_HOME, KC_PGDN, KC_END \
),

/* SYMB
 * ,------------------------------------------------.   ,------------------------------------------------.
 * | RESET|      |   !  |   @  |   #  |   $  |  %   |   |  ^   |   &  |   *  |   (  |   )  |      | Bksp |
 * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | SYMB |      |      |      |      |      |      |   |      |      |      |      |      |  UP  | ESC  |
 * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
 * | META | LCtrl|   `  |   \  | LAlt | LGUI |Space |   |Space | RGUI | RALT |      | LEFT | DOWN | RIGHT|
 * `------------------------------------------------'   `------------------------------------------------'
 */

[SYMB] = KEYMAP( \
  _______, _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),    S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   _______, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT \
)
};

