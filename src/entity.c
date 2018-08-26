#include "entity.h"


void draw_entity(SDL_Renderer* renderer, entity_t* entity, int32_t x, int32_t y)
{
  draw_sprite(
    renderer,
    &entity->sprite,
    x,
    y,
    entity->direction
  );
}


int32_t transform_entity(entity_t* entity, uint16_t level_scroll)
{
  return (entity->x - (entity->width / 2)) - level_scroll;
}

int32_t transform_player(entity_t* player, uint8_t num_screens)
{
  int32_t x = 0;

  // player is on the left half of the first screen
  if(player->x < FRAMEBUFFER_WIDTH / 2)
  {
    x = player->x;
  }
  // player is on the right half of the last screen
  else if(player->x > (FRAMEBUFFER_WIDTH * num_screens) - (FRAMEBUFFER_WIDTH / 2))
  {
    x = player->x - (FRAMEBUFFER_WIDTH * (num_screens - 1));
  }
  // player is on the right half of the first screen,
  // left half of the last screen, or on any middle screens
  else if(
    player->x >= FRAMEBUFFER_WIDTH / 2 &&
    player->x <= (FRAMEBUFFER_WIDTH * num_screens) - (FRAMEBUFFER_WIDTH / 2))
  {
    x = FRAMEBUFFER_WIDTH / 2;
  }

  return x - (player->width / 2);
}