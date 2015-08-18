#include <iostream>
#include "game.h"

int main() {
	SDL_Init(SDL_INIT_VIDEO);

	Game	app();

	app.run();

	SDL_Quit();
    return 0;
}
