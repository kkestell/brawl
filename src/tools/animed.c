#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "../sprite.h"

#define FRAMEBUFFER_WIDTH 1280
#define FRAMEBUFFER_HEIGHT 720
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

bool playing = false;

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    printf("USAGE: animed haggar.anim\n");
    exit(1);
  }

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Texture* framebuffer;

  sprite_t* sprite;

  SDL_Init(SDL_INIT_VIDEO);

  // init graphics

  window = SDL_CreateWindow(
    "AnimEd",
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

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

  framebuffer = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    FRAMEBUFFER_WIDTH,
    FRAMEBUFFER_HEIGHT
  );






  // init font

  if(TTF_Init() == -1)
  {
    printf("TTF_Init: %s\n", TTF_GetError());
    exit(1);
  }
  TTF_Font* font = TTF_OpenFont("bin/font.ttf", 20);
  SDL_Color white = { 255, 255, 255 };
  SDL_Surface* surfaceMessage;
  SDL_Texture* message;
  int tw, th;






  // init sprite

  sprite = load_sprite(renderer, argv[1]);





  // sheet preview

  int sheet_w, sheet_h;
  SDL_QueryTexture(sprite->image, NULL, NULL, &sheet_w, &sheet_h);

  SDL_Texture* sheet = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    sheet_w,
    sheet_h
  );





  bool running = true;
  while(running)
  {
    sequence_t* current_sequence = &sprite->anim->sequences[sprite->sequence];
    frame_t* current_frame = &sprite->anim->frames[current_sequence->frames[sprite->frame].frame];



    SDL_Event e;

    if(SDL_PollEvent(&e))
    {
      switch(e.type)
      {
        case SDL_QUIT:
          running = false;

        case SDL_KEYDOWN:
          switch(e.key.keysym.sym) {
            case SDLK_SPACE:
              playing = !playing;
              break;
            case SDLK_h:
              if(sprite->frame > 0)
                sprite->frame--;
              else
                sprite->frame = sprite->anim->sequences[sprite->sequence].num_frames - 1;
              break;
            case SDLK_l:
              if(sprite->frame < sprite->anim->sequences[sprite->sequence].num_frames - 1)
                sprite->frame++;
              else
                sprite->frame = 0;
              break;
            case SDLK_j:
              if(sprite->sequence < sprite->anim->num_sequences - 1)
              {
                sprite->sequence++;
                sprite->frame = 0;
              }
              break;
            case SDLK_k:
              if(sprite->sequence > 0)
              {
                sprite->sequence--;
                sprite->frame = 0;
              }
              break;
            case SDLK_LEFT:
              current_frame->x--;
              break;
            case SDLK_RIGHT:
              current_frame->x++;
              break;
            case SDLK_UP:
              current_frame->y--;
              break;
            case SDLK_DOWN:
              current_frame->y++;
              break;
            default:
                break;
          }

      }
    }



    // status text

    char buf[255];
    sprintf(
      buf,
      "Sequence %d/%d    Frame %d/%d     Position %d, %d    Size %d, %d",
      sprite->sequence + 1,
      sprite->anim->num_sequences,
      sprite->frame + 1,
      sprite->anim->sequences[sprite->sequence].num_frames,
      current_frame->x,
      current_frame->y,
      current_frame->width,
      current_frame->height
    );
    surfaceMessage = TTF_RenderText_Blended(font, buf, white);
    message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    TTF_SizeText(font, buf, &tw, &th);






    SDL_SetRenderTarget(renderer, framebuffer);

    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
    SDL_RenderClear(renderer);

    if(playing)
      tick_sprite(sprite);

    // sprite

    draw_sprite(renderer, sprite, 8, 8, RIGHT);

    SDL_Rect dst;
    SDL_Rect src;




    // SHEET

    // rendering to sheet preview
    SDL_SetRenderTarget(renderer, sheet);

    // clear
    SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
    SDL_RenderClear(renderer);

    // copy sheet image
    SDL_RenderCopy(renderer, sprite->image, NULL, NULL);

    // draw outline
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    dst.x = current_frame->x;
    dst.y = current_frame->y;
    dst.w = current_frame->width;
    dst.h = current_frame->height;

    SDL_RenderDrawRect(renderer, &dst);

    // blit half-sized sheet preview to the top right of the screen
    SDL_SetRenderTarget(renderer, framebuffer);

    dst.x = FRAMEBUFFER_WIDTH - (sheet_w / 2);
    dst.y = 0;
    dst.w = sheet_w / 2;
    dst.h = sheet_h / 2;

    SDL_RenderCopy(renderer, sheet, NULL, &dst);







    // animation preview


    for(int y = 0; y < sprite->anim->num_sequences; y++)
    {
      for(int x = 0; x < sprite->anim->sequences[y].num_frames; x++)
      {
        dst.x = x * 22 + 8;
        dst.y = y * 22 + 512;
        dst.w = 20;
        dst.h = 20;

        if(y == sprite->sequence && x == sprite->frame)
          SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        else
          SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderDrawRect(renderer, &dst);

      }
    }







    // text

    src.x = 0;
    src.y = 0;
    src.w = tw;
    src.h = th;

    dst.x = 8;
    dst.y = FRAMEBUFFER_HEIGHT - th - 8;
    dst.w = tw;
    dst.h = th;
    SDL_RenderCopy(renderer, message, &src, &dst);

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