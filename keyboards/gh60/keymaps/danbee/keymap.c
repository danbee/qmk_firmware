#include "gh60.h"
#include "action_layer.h"

// Name layers
#define _QW 0
#define _F1 1
#define _F2 2

// Extra Mac keys
#define KC_BRTU KC_F15
#define KC_BRTD KC_F14

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: qwerty */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bcksp │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ Ent │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
    │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ \ │    │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │Shft│ ` │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  Shift   │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │ Fn │Alt │Cmd │         Space          │Cmd │Alt │Hypr│Fn 2│
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_QW] = { /* Layer 0: Qwerty */
    {KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC},
    {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX},
    {KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT },
    {KC_LSFT, KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT},
    {MO(_F1), KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RGUI, KC_RALT, KC_HYPR, MO(_F2)}
  },
  /* 1: fn */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │ § │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │     │   │   │   │   │   │   │   │   │   │   │   │   │ Ins │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
    │      │   │   │   │   │   │ ◀ │ ▼ │ ▲ │ ▶ │   │   │   │    │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │    │   │   │   │   │   │   │   │   │   │   │   │          │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │    │    │    │                        │    │    │    │    │
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_F1] = { /* Layer 1: Functions */
    {KC_NUBS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______, KC_INS },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },
  /* 2: extra */
  /*┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
    │   │Br-│Br+│   │   │BL-│BL+│Pre│Pau│Nxt│Mut│Vo-│Vo+│ Eject │
    ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
    │     │   │   │   │   │   │   │   │   │   │   │   │   │ Pwr │
    ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    │
    │      │   │   │   │   │   │Hom│PgD│PgU│End│   │   │   │    │
    ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤
    │    │   │   │   │   │   │   │   │   │   │   │   │          │
    ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
    │    │    │    │                        │    │    │    │    │
    └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘*/
  [_F2] = { /* Layer 2: Functions */
    {_______, KC_BRTD, KC_BRTU, _______, _______, BL_DEC,  BL_INC,  KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, _______, KC_POWER},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
      break;
  }
  return MACRO_NONE;
};

void matrix_scan_user(void) {

  //Layer LED indicators
  uint32_t layer = layer_state;

  if (layer & (1<<1)) {
    gh60_wasd_leds_on();
    gh60_fn_led_on();
  } else {
    gh60_wasd_leds_off();
    gh60_fn_led_off();
  }

  if (layer & (1<<2)) {
    gh60_poker_leds_on();
    gh60_esc_led_on();
  } else {
    gh60_poker_leds_off();
    gh60_esc_led_off();
  }

};
