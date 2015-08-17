#include <iostream>
#include <string>
#include "ltexture.h"

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window	*window = SDL_CreateWindow("Tic tac toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, 0);

	SDL_Renderer	*ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	LTexture	tex(ren, "res/cross.bmp");

	bool	quit =false;
	while (!quit) {
		SDL_Event	e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN)
				quit = true;
		}
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(ren);
		tex.render(0, 0);
		SDL_RenderPresent(ren);
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}
