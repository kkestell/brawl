#ifndef input_h
#define input_h

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
  bool quit;
  uint8_t up;
  uint8_t down;
  uint8_t left;
  uint8_t right;
  uint8_t a;
  uint8_t b;
  uint8_t select;
  uint8_t start;
} input_state_t;

void update_input(input_state_t* input_state);

#endif
