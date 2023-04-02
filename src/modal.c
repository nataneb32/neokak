#include "modal.h"

inline void modal_on_enter(modal_t* modal) {
  modal->on_enter(modal->data);
}

inline void modal_on_exit(modal_t* modal) {
  modal->on_exit(modal->data);
}

inline void modal_on_key_press(modal_t* modal, int key) {
  modal->on_key_press(modal->data, key);
}

inline void modal_on_render(modal_t* modal) {
  modal->on_render(modal->data);
}
