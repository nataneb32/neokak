#pragma once

#include "keymap.h"

void keymap_init(keymap_t *keymap) {
}

void keymap_on_key_press(keymap_t* keymap, int key) {
  keymap->on_key_press(keymap->data, key);
}
