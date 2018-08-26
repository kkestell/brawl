#include "level.h"
#include "config.h"


void draw_level(SDL_Renderer* renderer, level_t* l)
{
  SDL_Rect src;
  SDL_Rect dst;

  if(l->scroll % FRAMEBUFFER_WIDTH == 0)
  {
    uint8_t idx = l->scroll / FRAMEBUFFER_WIDTH;

    src.x = 25;
    src.y = 25;
    src.w = FRAMEBUFFER_WIDTH;
    src.h = FRAMEBUFFER_HEIGHT;

    SDL_RenderCopy(renderer, l->screens[idx].image, &src, NULL);
  }
  else
  {
    uint8_t left_idx = l->scroll / FRAMEBUFFER_WIDTH;
    uint8_t right_idx = (l->scroll / FRAMEBUFFER_WIDTH) + 1;

    uint16_t offset
      = FRAMEBUFFER_WIDTH - (l->scroll - (FRAMEBUFFER_WIDTH * left_idx));

    src.x = 25 + FRAMEBUFFER_WIDTH - offset;
    src.y = 25;
    src.w = offset;
    src.h = FRAMEBUFFER_HEIGHT;

    dst.x = 0;
    dst.y = 0;
    dst.w = offset;
    dst.h = FRAMEBUFFER_HEIGHT;

    SDL_RenderCopy(renderer, l->screens[left_idx].image, &src, &dst);

    src.x = 25;
    src.y = 25;
    src.w = FRAMEBUFFER_WIDTH - offset;
    src.h = FRAMEBUFFER_HEIGHT;

    dst.x = offset;
    dst.y = 0;
    dst.w = FRAMEBUFFER_WIDTH - offset;
    dst.h = FRAMEBUFFER_HEIGHT;

    SDL_RenderCopy(renderer, l->screens[right_idx].image, &src, &dst);
  }
}


void tick_level(level_t* level, uint16_t player_x)
{
  if(
    player_x >= FRAMEBUFFER_WIDTH / 2 &&
    player_x <= (FRAMEBUFFER_WIDTH * level->num_screens) - (FRAMEBUFFER_WIDTH / 2))
  {
    level->scroll = player_x - FRAMEBUFFER_WIDTH / 2;
  }
}
