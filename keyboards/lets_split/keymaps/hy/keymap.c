#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _GAME 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  GAME,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* default
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |Adjust|Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
/* [_QWERTY] = KEYMAP( \ */
  /* KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \ */
  /* KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \ */
  /* KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \ */
  /* KC_LCTRL,KC_LGUI,  KC_LALT, ADJUST,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \ */
/* ), */

/* Qwerty
 * ,-----------------------------------------.  ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  | ENT  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   '  | ESC  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | RAISE| LOWER|   \  | ALT  |GUI   |Space |  |Space |  GUI |   -  |   =  |   /  |LOWER |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTRL,KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_ESC , \
  RAISE,   ADJUST,  KC_RCBR, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_RGUI, KC_MINS, KC_EQL,  KC_SLSH, LOWER \
),

/* Lower default
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |   _  |   +  |      |   \  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      | Next | Vol- |  |   | Play |
 * `-----------------------------------------'  `-----------------------------------------'
 */
/* [_LOWER] = KEYMAP( \ */
  /* KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \ */
  /* KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DEL, \ */
  /* _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \ */
  /* _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_PIPE, KC_MPLY \ */
/* ), */

/* Lower
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  |  F1  |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   |  |   ^  |   &  |   *  |   (  |   )  |  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |   _  |   +  |   \  |   [  |   ]  |  |  F11 |  F12 |   -  |   =  |   `  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      | RESET|      |      |      |  |      | LEFT | DOWN |  UP  |RIGHT |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, \
  KC_PIPE, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  _______, KC_UNDS, KC_PLUS, KC_BSLS, KC_LBRC, KC_RBRC, KC_F11,  KC_F12,  KC_MINS, KC_EQL,  KC_GRV,  _______, \
  _______, _______, RESET,   _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______ \
),
/* Raise default
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |   -  |   =  |   [  |   ]  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      | Next | Vol- |   \  | Play |
 * `-----------------------------------------'  `-----------------------------------------'
 */
/* [_RAISE] = KEYMAP( \ */
  /* KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \ */
  /* KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_DEL, \ */
  /* _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______, \ */
  /* _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_BSLS, KC_MPLY \ */
/* ), */

/* Raise
 * ,-----------------------------------------.  ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |  |   -  |   =  |   7  |   8  |   9  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Del  |   6  |   7  |   8  |   9  |   0  |  |   +  |   /  |   4  |   5  |   6  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   0  |   1  |   2  |   3  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      | LEFT | DOWN |  UP  |RIGHT |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS, KC_EQL,  KC_7,    KC_8,    KC_9,    _______, \
  KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS, KC_SLSH, KC_4,    KC_5,    KC_6,    KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______ \
),

[_GAME] = KEYMAP( \
  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_T,    KC_R,    KC_E,    KC_W,    KC_Q,    _______, KC_BSPC, \
  _______, KC_L,    KC_K,    KC_J,    KC_H,    KC_G,    KC_F,    KC_A,    KC_S,    KC_D,    KC_LCTRL,KC_ENT, \
  _______, KC_M,    KC_N,    KC_B,    KC_V,    KC_B,    KC_V,    KC_C,    KC_X,    KC_Z,    _______, KC_ESC, \
  QWERTY,  _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, KC_LSHIFT \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |Qwerty|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Game |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, QWERTY, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, GAME,    _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
