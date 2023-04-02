#pragma once

typedef struct keymap_t {
  void* data;
  void (*on_key_press)(void* data, int key);
} keymap_t;

void keymap_init(keymap_t* keymap);

void keymap_on_key_press(keymap_t* keymap, int key);
