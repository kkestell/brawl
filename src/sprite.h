#ifndef sprite_h
#define sprite_h

#include <SDL2/SDL.h>
#include <stdint.h>
#include <stdbool.h>

#define LEFT true
#define RIGHT false

typedef bool direction_t;

typedef struct
{
  uint8_t frame;
  uint16_t duration;
} sequence_frame_t;

typedef struct
{
  uint8_t num_frames;
  sequence_frame_t* frames;
} sequence_t;

typedef struct
{
  SDL_Texture* image;
  uint16_t x;
  uint16_t y;
  uint16_t width;
  uint16_t height;
  uint16_t origin_x;
  uint16_t origin_y;
} frame_t;

typedef struct
{
  uint8_t num_frames;
  frame_t* frames;
  uint8_t num_sequences;
  sequence_t* sequences;
} anim_t;

typedef struct
{
  SDL_Texture* image;
  anim_t* anim;
  uint8_t sequence;
  uint8_t frame;
  uint16_t tick;
} sprite_t;

sprite_t* load_sprite(SDL_Renderer* renderer, const char* filename);

void tick_sprite(sprite_t* sprite);

void draw_sprite(
  SDL_Renderer* renderer,
  sprite_t* sprite,
  int32_t x,
  int32_t y,
  direction_t direction
);

#endif