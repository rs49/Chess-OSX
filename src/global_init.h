#pragma once
#include "game.h"
#include <SDL2/SDL.h>

#define TILE_SIZE 60

extern SDL_Window *window;
extern SDL_Renderer *renderer;

extern int run;

extern Game game;

extern int tile_colour[64];



