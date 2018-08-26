#include "sprite.h"
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


sprite_t* load_sprite(SDL_Renderer* renderer, const char* filename)
{
  sprite_t* sprite = (sprite_t*)malloc(sizeof(sprite_t));
  sprite->anim = (anim_t*)malloc(sizeof(anim_t));

  char sprite_sheet_filename[512];
  memset(&sprite_sheet_filename, 0, 512);
  strcat(sprite_sheet_filename, filename);
  strcat(sprite_sheet_filename, ".png");

  printf("loading %s / %s\n", filename, sprite_sheet_filename);

  sprite->image = IMG_LoadTexture(renderer, sprite_sheet_filename);

  FILE* fp;
  fp = fopen(filename, "rb");

  uint8_t num_frames;
  fread(&num_frames, sizeof(uint8_t), 1, fp);

  uint8_t num_sequences;
  fread(&num_sequences, sizeof(uint8_t), 1, fp);

  sprite->anim->num_frames = num_frames;
  sprite->anim->num_sequences = num_sequences;

  sprite->anim->frames = (frame_t*)malloc(sizeof(frame_t) * sprite->anim->num_frames);

  sprite->anim->sequences =
    (sequence_t*)malloc(sizeof(sequence_t) * sprite->anim->num_sequences);

  for(int f = 0; f < num_frames; f++)
  {
    uint16_t x;
    fread(&x, sizeof(uint16_t), 1, fp);

    uint16_t y;
    fread(&y, sizeof(uint16_t), 1, fp);

    uint16_t w;
    fread(&w, sizeof(uint16_t), 1, fp);

    uint16_t h;
    fread(&h, sizeof(uint16_t), 1, fp);

    uint16_t ox;
    fread(&ox, sizeof(uint16_t), 1, fp);

    uint16_t oy;
    fread(&oy, sizeof(uint16_t), 1, fp);

    // SDL_Texture* dst_tex = SDL_CreateTexture(
    //   renderer,
    //   SDL_PIXELFORMAT_RGBA8888,
    //   SDL_TEXTUREACCESS_TARGET,
    //   w,
    //   h
    // );
    // SDL_SetTextureBlendMode(dst_tex, SDL_BLENDMODE_BLEND);
    // SDL_SetRenderTarget(renderer, dst_tex);
    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    // SDL_RenderClear(renderer);
    // SDL_Rect src = { x, y, w, h };
    // SDL_RenderCopy(renderer, src_tex, &src, NULL);

    // sprite->anim->frames[f].image = dst_tex;

    sprite->anim->frames[f].x = x;
    sprite->anim->frames[f].y = y;
    sprite->anim->frames[f].width = w;
    sprite->anim->frames[f].height = h;
    sprite->anim->frames[f].origin_x = ox;
    sprite->anim->frames[f].origin_y = oy;
  }

  for(int s = 0; s < num_sequences; s++)
  {
    uint8_t num_frames;
    fread(&num_frames, sizeof(uint8_t), 1, fp);

    sprite->anim->sequences[s].num_frames = num_frames;

    sprite->anim->sequences[s].frames =
      (sequence_frame_t*)malloc(sizeof(sequence_frame_t) * num_frames);

    for(int f = 0; f < num_frames; f++)
    {
      uint8_t frame;
      fread(&frame, sizeof(uint8_t), 1, fp);

      uint16_t duration;
      fread(&duration, sizeof(uint16_t), 1, fp);

      sprite->anim->sequences[s].frames[f].frame = frame;
      sprite->anim->sequences[s].frames[f].duration = duration;
    }
  }

  sprite->sequence = 0;
  sprite->frame = 0;
  sprite->tick = 0;

  return sprite;
}


void tick_sprite(sprite_t* sprite)
{
  sprite->tick++;

  if(sprite->tick == 65535)
    sprite->tick = 0;

  sequence_t* current_sequence = &sprite->anim->sequences[sprite->sequence];
  sequence_frame_t* current_frame = &current_sequence->frames[sprite->frame];

  if(sprite->tick >= current_frame->duration)
  {
    sprite->frame++;
    sprite->tick = 0;
  }

  if(sprite->frame >= current_sequence->num_frames)
    sprite->frame = 0;
}


void draw_sprite(
  SDL_Renderer* renderer,
  sprite_t* sprite,
  int32_t x,
  int32_t y,
  direction_t direction)
{
  SDL_Rect src;
  SDL_Rect dst;

  src.x = sprite->anim->frames[sprite->frame].x;
  src.y = sprite->anim->frames[sprite->frame].y;
  src.w = sprite->anim->frames[sprite->frame].width;
  src.h = sprite->anim->frames[sprite->frame].height;

  dst.x = x;
  dst.y = y;
  dst.w = sprite->anim->frames[sprite->frame].width;
  dst.h = sprite->anim->frames[sprite->frame].height;

  SDL_RendererFlip flip = 0;

  if(direction == LEFT)
    flip = SDL_FLIP_HORIZONTAL;

  sequence_t* current_sequence = &sprite->anim->sequences[sprite->sequence];
  sequence_frame_t* current_frame = &current_sequence->frames[sprite->frame];

  SDL_RenderCopyEx(
    renderer,
    sprite->image,
    &src,
    &dst,
    0,
    NULL,
    flip
  );
}
