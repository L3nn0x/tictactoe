#include <iostream>
#include <SDL2/SDL.h>
#include <string>

SDL_Surface	*loadSurface(std::string path) {
	SDL_Surface	*tmp = SDL_LoadBMP(std::string(std::string(SDL_GetBasePath()) + path).c_str());
	if (!tmp)
		std::cout << "Unable to load image " << path << ", error : " << SDL_GetError() << std::endl;
	return tmp;
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface	*surface = loadSurface("res/sprite.bmp");
	SDL_Window	*window = SDL_CreateWindow("Tic tac toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, 0);
	SDL_Surface	*screen = SDL_GetWindowSurface(window);
	SDL_FillRect(screen, nullptr, SDL_MapRGB(screen->format, 255, 255, 255));
	bool	quit =false;
	while (!quit) {
		SDL_Event	e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN)
				quit = true;
		}
		SDL_Rect	tmp = {0, 0, 640, 480};
		SDL_BlitScaled(surface, nullptr, screen, &tmp);
		SDL_UpdateWindowSurface(window);
	}
	SDL_Quit();
    return 0;
}
