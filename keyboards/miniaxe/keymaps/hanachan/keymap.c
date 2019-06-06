#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUM 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

// common
#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RST RESET
#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

// layer
#define KC_L_SPC LT(_LOWER, KC_SPC)
#define KC_R_ENT LT(_RAISE, KC_ENT)

// shift_t
#define KC_S_Z LSFT_T(KC_Z)
#define KC_S_SLSH RSFT_T(KC_SLSH)

// cmd_t
#define KC_M_C LCMD_T(KC_C)
#define KC_M_COMM RCMD_T(KC_COMM)
#define KC_M_EN LCMD_T(KC_LANG2)
#define KC_M_JA RCMD_T(KC_LANG1)

// ctl_t
#define KC_C_V LCTL_T(KC_V)
#define KC_C_M RCTL_T(KC_M)
#define KC_C_BS LCTL_T(KC_BSPC)

// alt_t
#define KC_A_X ALT_T(KC_X)
#define KC_A_DOT ALT_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // M_ = LCMD_T(
  // A_ = ALT_T(
  // C_ = LCTL_T(
  // MS_ = SMD_T(
  // R_ = LT(_RAISE
  // L_ = LT(_LOWER

  [_QWERTY] = LAYOUT( \
  //,----+----+----+----+----.     ,----+----+----+----+----.
     KC_Q,KC_W,KC_E,KC_R,KC_T,      KC_Y,KC_U,KC_I,KC_O,KC_P,
  //|----+----+----+----+----|     |----+----+----+----+----|
     KC_A,KC_S,KC_D,KC_F,KC_G,      KC_H,KC_J,KC_K,KC_L,KC_SCLN,
  //|----+----+----+----+----+     |----+----+----+----+----|
     KC_S_Z,KC_A_X,KC_M_C,KC_C_V,KC_B,     KC_N,KC_C_M,KC_M_COMM,KC_A_DOT,KC_S_SLSH,
  //`----+----+----+----+----/     \----+----+----+----+----'
             KC_M_EN,KC_L_SPC,KC_C_BS,    KC_C_BS,KC_R_ENT,KC_M_JA
  //          `----+----+----'     `----+----+----'
  ),

  //   \ ! & |      = + * $
  // tab ` " ' ~  ← ↓ → esc
  //   # ^ { [ (  ) ] } @ %

  [_RAISE] = LAYOUT( \
  //,----+----+----+----+----.     ,----+----+----+----+----.
     KC_BSLS,KC_EXLM,KC_AMPR,KC_PIPE,KC_XXXX,      KC_XXXX,KC_EQL,KC_PLUS,KC_ASTR,KC_DLR,
  //|----+----+----+----+----|     |----+----+----+----+----|
     KC_TAB,KC_GRV,KC_DQT,KC_QUOT,KC_TILD,    KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_ESC,
  //|----+----+----+----+----|     |----+----+----+----+----|
     KC_HASH,KC_CIRC,KC_LCBR,KC_LBRC,KC_LPRN,   KC_RPRN,KC_RBRC,KC_RCBR,KC_AT,KC_PERC,
  //`----+----+----+----+----/     \----+----+----+----+----'
              KC_XXXX,KC_BSPC,KC_XXXX,       KC_XXXX,KC_XXXX,KC_RST
  //          `----+----+----'     `----+----+----'
  ),

  [_LOWER] = LAYOUT( \
  //,----+----+----+----+----.     ,----+----+----+----+----.
     KC_XXXX,KC_0,KC_1,KC_2,KC_3,     KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,
  //|----+----+----+----+----|     |----+----+----+----+----|
     KC_ASTR,KC_PLUS,KC_4,KC_5,KC_6,    KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,
  //|----+----+----+----+----|     |----+----+----+----+----|
     KC_SLSH,KC_MINS,KC_7,KC_8,KC_9,   KC_F11,KC_F12,KC_M_COMM,KC_A_DOT,KC_S_SLSH,
  //`----+----+--+-+----+----/     \----+----+----+----+----'
              KC_DOT,KC_RST,KC_EQL,  KC_XXXX,KC_DEL,KC_XXXX
  //          `----+----+----     ` ----+----+----'
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // persistant_default_layer_set(1UL<<_QWERTY);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
