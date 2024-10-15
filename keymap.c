#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

enum {
    TD_LALT_ESC
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TXT_COPY,
  TXT_PSTE,
  CEDILLE,
  QUOTE,
  DBQUOTE,
  EURO
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_LALT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_ESC)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case TXT_COPY:
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_LCTL("c")));
      }
      break;

   case TXT_PSTE:
      if (record->event.pressed) {
         SEND_STRING(SS_LCTL(SS_LSFT("v")));
      }
      break;

   case CEDILLE:
      if (record->event.pressed) {
         SEND_STRING(SS_RALT(","));
      }
      break;

   case QUOTE:
      if (record->event.pressed) {
         SEND_STRING("' ");
      }
      break;

   case DBQUOTE:
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT("' "));
      }
      break;

   case EURO:
      if (record->event.pressed) {
         SEND_STRING(SS_RALT("5"));
      }
      break;
   }
   return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_SLSH,
                         KC_PSCR,KC_LGUI,TD(TD_LALT_ESC),LT(_LOWER,KC_BSPC),LT(_RAISE,KC_SPC),KC_ALGR,KC_INS,KC_ALGR
  ),

  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  ,                     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, _______,                     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_EQL , QUOTE  ,
    _______, _______, _______,TXT_COPY,TXT_PSTE, _______,S(KC_LBRC), S(KC_RBRC), _______, _______, _______, _______, _______, KC_PIPE,
                               _______, _______, _______, _______,    KC_DEL , _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  ,                     KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, _______,                     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT, KC_PPLS, DBQUOTE,
    _______, _______, _______, _______, _______, _______, S(KC_9),    S(KC_0), _______, _______, _______, _______, _______, KC_BSLS,
                               _______, _______, _______, _______,    _______, _______, _______, _______
  ),


};
