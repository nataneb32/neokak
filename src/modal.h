#pragma once

typedef struct modal_t {
  void* data;
  void (*on_enter)(void* data);
  void (*on_exit)(void* data);
  void (*on_key_press)(void* data, int key);
  void (*on_render)(void* data);
} modal_t;

void modal_on_enter(modal_t* modal);
void modal_on_exit(modal_t* modal);
void modal_on_key_press(modal_t* modal, int key);
void modal_on_render(modal_t* modal);
