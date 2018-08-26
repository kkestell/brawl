#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

#include "config.h"
#include "sprite.h"
#include "level.h"
#include "entity.h"
#include "input.h"


int main(int argc, char *argv[])
{
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* framebuffer;

  SDL_Init(SDL_INIT_VIDEO);

  // init graphics

  window = SDL_CreateWindow(
    "Brawl",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    0
  );

  renderer = SDL_CreateRenderer(
    window,
    -1,
    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

  framebuffer = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    FRAMEBUFFER_WIDTH,
    FRAMEBUFFER_HEIGHT
  );

  // init input

  input_state_t input;
  memset(&input, 0, sizeof(input_state_t));

  // init level

  level_t level;

  level.scroll = 0;
  level.num_screens = 3;

  level.screens = (screen_t*)malloc(sizeof(screen_t) * level.num_screens);

  level.screens[0].type = SCROLLING;
  level.screens[0].image = IMG_LoadTexture(renderer, "bg1_1.png");

  level.screens[1].type = FIXED;
  level.screens[1].image = IMG_LoadTexture(renderer, "bg1_2.png");

  level.screens[2].type = SCROLLING;
  level.screens[2].image = IMG_LoadTexture(renderer, "bg1_3.png");

  // init player

  entity_t player;
  player.x = 0;
  player.y = FRAMEBUFFER_HEIGHT - 130;
  player.width = 81;
  player.height = 93;
  player.sprite.anim = load_anim(renderer, "haggar.spr");
  player.sprite.sequence = 0;
  player.sprite.frame = 0;
  player.sprite.tick = 0;

  // init roast

  /*
  entity_t roast;
  roast.x = 960;
  roast.y = FRAMEBUFFER_HEIGHT - 200;
  roast.width = 100;
  roast.height = 60;
  roast.sprite.anim = load_anim(renderer, "roast.spr");
  roast.sprite.sequence = 0;
  roast.sprite.frame = 0;
  roast.sprite.tick = 0;
  */

  // init font
  if(TTF_Init() == -1) {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(1);
  }
  TTF_Font* font = TTF_OpenFont("font.ttf", 16);
  SDL_Color white = { 255, 255, 255 };
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, "Hello World", white);
  SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

  int tw, th;
  TTF_SizeText(font, "Hello World", &tw, &th);

  // game loop

  bool running = true;
  while(running)
  {
    // input

    update_input(&input);

    if(input.quit == true)
      running = false;

    // move player

    if(input.right == 1)
    {
      player.x += 2;
      player.direction = RIGHT;
    }
    else if(input.left == 1)
    {
      player.x -= 2;
      player.direction = LEFT;
    }
    if(input.up == 1)
    {
      player.y -= 2;
    }
    else if(input.down == 1)
    {
      player.y += 2;
    }

    /*
    if(input.right + input.left + input.up + input.down > 0)
    {
      if(player.sprite.sequence == 0)
      {
        player.sprite.sequence = 1;
        player.sprite.frame = 0;
        player.sprite.tick = 0;
      }
    }
    else
    {
      if(player.sprite.sequence == 1)
      {
        player.sprite.sequence = 0;
        player.sprite.frame = 0;
        player.sprite.tick = 0;
      }
    }

    if(player.y < 280)
      player.y = 280;

    if(player.y > FRAMEBUFFER_HEIGHT - player.height)
      player.y = FRAMEBUFFER_HEIGHT - player.height;

    if(player.x < -100)
      player.x = -100;

    if(player.x > FRAMEBUFFER_WIDTH * level.num_screens + 100)
      player.x = FRAMEBUFFER_WIDTH * level.num_screens + 100;
    */

    // update

    tick_level(&level, player.x);

    tick_sprite(&player.sprite);
    //tick_sprite(&roast.sprite);

    // draw

    SDL_SetRenderTarget(renderer, framebuffer);

    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
    SDL_RenderClear(renderer);

    draw_level(renderer, &level);

    /*
    draw_entity(
      renderer,
      &roast,
      transform_entity(&roast, level.scroll),
      roast.y
    );
    */

    draw_entity(
      renderer,
      &player,
      transform_player(&player, level.num_screens),
      player.y
    );

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = tw;
    src.h = th;
    SDL_RenderCopy(renderer, message, &src, &src);

    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, framebuffer, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
