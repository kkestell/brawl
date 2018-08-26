#ifndef level_h
#define level_h

#include <SDL2/SDL.h>
#include "config.h"

typedef enum
{
  FIXED,
  SCROLLING
} screen_type_t;

typedef struct
{
  SDL_Texture* image;
  screen_type_t type;
} screen_t;

typedef struct
{
  uint8_t num_screens;
  screen_t* screens;
  int16_t scroll;
} level_t;

void draw_level(SDL_Renderer* renderer, level_t* level);
void tick_level(level_t* level, uint16_t player_x);

#endif
