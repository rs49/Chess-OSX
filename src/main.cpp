#include <stdio.h>
#include <SDL2/SDL.h>

int main()
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Chess",
						SDL_WINDOWPOS_UNDEFINED,
						SDL_WINDOWPOS_UNDEFINED,
						640, 480,
						SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);	

	int run = 1;

	//while(run)
	//{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		SDL_Delay(2000);
	//}

	return 0;

}
