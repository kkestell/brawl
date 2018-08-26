#ifndef entity_h
#define entity_h

#include <stdint.h>
#include <SDL2/SDL.h>
#include "sprite.h"
#include "level.h"

typedef struct
{
  int32_t x;
  int32_t y;
  uint16_t width;
  uint16_t height;
  sprite_t sprite;
  direction_t direction;
} entity_t;

void draw_entity(
  SDL_Renderer* renderer,
  entity_t* entity,
  int32_t x,
  int32_t y
);

int32_t transform_entity(entity_t* entity, uint16_t level_scroll);
int32_t transform_player(entity_t* player, uint8_t num_screens);

#endif
