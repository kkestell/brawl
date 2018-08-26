#include "input.h"
#include <SDL2/SDL.h>


void update_input(input_state_t* input_state)
{
  SDL_Event e;

  if(SDL_PollEvent(&e))
  {
    switch(e.type)
    {
      case SDL_QUIT:
        input_state->quit = true;
        break;
      case SDL_KEYDOWN:
        switch(e.key.keysym.sym)
        {
          case SDLK_UP:
            input_state->up = 1;
            break;
          case SDLK_DOWN:
            input_state->down = 1;
            break;
          case SDLK_LEFT:
            input_state->left = 1;
            break;
          case SDLK_RIGHT:
            input_state->right = 1;
            break;
        }
        break;
      case SDL_KEYUP:
        switch(e.key.keysym.sym)
        {
          case SDLK_UP:
            input_state->up = 0;
            break;
          case SDLK_DOWN:
            input_state->down = 0;
            break;
          case SDLK_LEFT:
            input_state->left = 0;
            break;
          case SDLK_RIGHT:
            input_state->right = 0;
            break;
        }
        break;
    }
  }
}
