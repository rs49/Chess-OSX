#include <stdio.h>
#include <SDL2/SDL.h>
#include "global_init.h"
#include "global_defs.h"

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Chess",
					SDL_WINDOWPOS_UNDEFINED,
					SDL_WINDOWPOS_UNDEFINED,
					640, 480,
					SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);	

	initBoard120to64();
	game.initAssets();
	game.newBoard();

	SDL_Event e;

	int run = 1;

	Uint32 startTick, elapsed;

	while(run)
	{
		startTick = SDL_GetTicks();

		// Parse Inputs/Events
	
		while( SDL_PollEvent(&e) != 0 )
		{
			if( e.type == SDL_QUIT )
			{
				run = 0;
			}

			if( e.type == SDL_KEYDOWN )
			{
				switch( e.key.keysym.sym )
				{
					case SDLK_q:
						{
							run = 0;
							break;
						}
				}
			}

		}

		// Draw the screen

		game.drawBoard();	

		// Run at 30 frames per second

		elapsed = SDL_GetTicks() - startTick;
		if( elapsed < 33 )
		{
			SDL_Delay( 33 - elapsed );
		}
	}

	return 0;

}
