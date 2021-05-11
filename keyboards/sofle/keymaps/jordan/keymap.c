#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_GRV,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER, KC_SPC,      KC_ENT,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |      |      |     | F11  | F12  |       |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   <  |   >  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_EQL,\
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______,   KC_F11,  KC_F12, _______, \
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_LT  , KC_GT  , KC_BSLS, _______, \
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______, \
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,_______, KC_BSPC, \
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC, \
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET  , XXXXXXX,KC_QWERTY,XXXXXXX,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE

int circle_edges[14] = {10,7,6,5,4,3,2,1,1,1,0,0,0,0};
int arrow_edges[14] = {15, 15, 15, 13, 12, 11, 10, 9, 8, 7, 15, 15, 15, 15};

enum icons {
    BASE,
    UPPER,
    LOWER,
    ADJUST
};

void draw_windows_icon(int offset_y) {
    for (int y = 0; y<14; y++) {
        for (int x = 0; x<14; x++) {
            bool on = x >= 2 && x <= 12 && y >= 2 && y <= 12;

            oled_write_pixel(x+2, y+2+offset_y, on);
            oled_write_pixel(x+2, 27-y+2+offset_y, on);
            oled_write_pixel(27-x+2, y+2+offset_y, on);
            oled_write_pixel(27-x+2, 27-y+2+offset_y, on);
        }
    }
}

int apple_edges[26][4] = {
    {17, 19, 30, 30},
    {16, 19, 30, 30},
    {15, 18, 30, 30},
    {14, 18, 30, 30},
    {14, 17, 30, 30},
    {14, 16, 30, 30},
    {7, 12, 16, 23},
    {5, 24, 30, 30},
    {4, 25, 30, 30},
    {4, 24, 30, 30},
    {3, 23, 30, 30},
    {3, 23, 30, 30},
    {3, 22, 30, 30},
    {3, 22, 30, 30},
    {3, 22, 30, 30},
    {3, 23, 30, 30},
    {3, 23, 30, 30},
    {3, 24, 30, 30},
    {4, 25, 30, 30},
    {4, 26, 30, 30},
    {4, 25, 30, 30},
    {5, 25, 30, 30},
    {5, 24, 30, 30},
    {6, 24, 30, 30},
    {7, 23, 30, 30},
    {8, 12, 18, 22},
};

int caps_on_edges[26][4] = {
    {12, 15, 30, 30},
    {11, 16, 30, 30},
    {11, 16, 30, 30},
    {10, 13, 14, 17},
    {10, 13, 14, 17},
    {10, 13, 14, 18},
    {9, 12, 15, 18},
    {9, 12, 15, 19},
    {9, 12, 15, 19},
    {8, 11, 16, 19},
    {8, 11, 16, 20},
    {7, 11, 16, 20},
    {7, 10, 17, 21},
    {7, 10, 17, 21},
    {6, 9, 18, 21},
    {6, 9, 18, 22},
    {6, 22, 30, 30},
    {5, 23, 30, 30},
    {5, 8, 19, 23},
    {4, 8, 20, 23},
    {4, 7, 20, 24},
    {4, 7, 20, 24},
    {3, 7, 21, 25},
    {3, 6, 21, 25},
    {3, 6, 22, 25},
    {2, 6, 22, 26},
};

int caps_off_edges[26][4] = {
    {30, 30, 30, 30},
    {30, 30, 30, 30},
    {30, 30, 30, 30},
    {30, 30, 30, 30},
    {12, 19, 30, 30},
    {10, 21, 30, 30},
    {9, 13, 17, 21},
    {8, 12, 18, 22},
    {8, 11, 19, 22},
    {19, 22, 30, 30},
    {19, 22, 30, 30},
    {15, 22, 30, 30},
    {10, 22, 30, 30},
    {8, 18, 20, 22},
    {8, 13, 20, 22},
    {7, 12, 20, 22},
    {7, 11, 20, 22},
    {7, 11, 19, 22},
    {7, 11, 19, 22},
    {8, 12, 17, 22},
    {8, 18, 20, 23},
    {10, 16, 20, 23},
    {30, 30, 30, 30},
    {30, 30, 30, 30},
    {30, 30, 30, 30},
    {30, 30, 30, 30},
};

void draw_icon_map(int icon_map[26][4], int offset_y) {
    for (int y = 0; y<26; y++) {
        int checking_index = 0;
        bool is_on = false;
        bool is_end_of_line = false;

        for (int x = 0; x<28; x++) {
            if (!is_end_of_line && x >= icon_map[y][checking_index]) {
                // move to the next stage
                is_on = !is_on;
                checking_index = checking_index + 1;

                if (checking_index > 3) {
                    is_end_of_line = true;
                    checking_index = 3;
                    is_on = false;
                }
            }

            oled_write_pixel(x+2, y+3+offset_y, is_on);
        }
    }
}

void draw_apple_icon(int offset_y) {
    draw_icon_map(apple_edges, offset_y);
}

void draw_caps_on_icon(int offset_y) {
    draw_icon_map(caps_on_edges, offset_y);
}

void draw_caps_off_icon(int offset_y) {
    draw_icon_map(caps_off_edges, offset_y);
}

void draw_layer_icon(int offset_y, bool is_filled, enum icons icon) {
    for (int y = 0; y<14; y++) {
        for (int x = 0; x<14; x++) {
            bool top_on;
            bool bottom_on;

            if (is_filled) {
                top_on = x >= circle_edges[y];
                bottom_on = x >= circle_edges[y];
            } else {
                int circle_to;

                if (y == 0) {
                    circle_to = 13;
                } else {
                    circle_to = circle_edges[y - 1] - 9;
                }

                if (circle_to <= circle_edges[y]) {
                    circle_to = circle_edges[y];
                }

                top_on = (x >= circle_edges[y]) && x <= circle_to;
                bottom_on = (x >= circle_edges[y]) && x <= circle_to;
            }

            // draw line
            if (y >= 13 && x >= 4) {
                top_on = !is_filled;
                bottom_on = !is_filled;
            }

            if (icon != BASE && x >= arrow_edges[y]) {
                if (icon != LOWER) {
                    top_on = !is_filled;
                }

                if (icon != UPPER) {
                    bottom_on = !is_filled;
                }

            }

            oled_write_pixel(x+2, y+2+offset_y, top_on);
            oled_write_pixel(x+2, 27-y+2+offset_y, bottom_on);
            oled_write_pixel(27-x+2, y+2+offset_y, top_on);
            oled_write_pixel(27-x+2, 27-y+2+offset_y, bottom_on);
        }
    }
}

static void print_status_narrow(void) {
    if (keymap_config.swap_lctl_lgui) {
        draw_apple_icon(16);
    } else {
        draw_windows_icon(16);
    }

    led_t led_usb_state = host_keyboard_led_state();

    if (led_usb_state.caps_lock == true) {
        draw_caps_on_icon(48);
    } else {
        draw_caps_off_icon(48);
    }

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            draw_layer_icon(80, false, BASE);
            break;
        case _RAISE:
            draw_layer_icon(80, true, UPPER);
            break;
        case _LOWER:
            draw_layer_icon(80, true, LOWER);
            break;
        case _ADJUST:
            draw_layer_icon(80, true, ADJUST);
            break;
        default:
            draw_layer_icon(80, false, BASE);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    print_status_narrow();
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif
