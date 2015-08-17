#include <iostream>
#include <string>
#include "ltexture.h"
#include "lsprite.h"
#include "lwindow.h"
#include <vector>
#include <memory>

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	LWindow	window("Tic tac toe", 640, 480);

	std::vector<LSprite*>	texts;
	std::shared_ptr<LTexture*>	tex = std::make_shared<LTexture*>
		(new LTexture(window.getRenderer(), "res/cross.bmp"));

	bool	quit =false;
	while (!quit) {
		SDL_Event	e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN)
				quit = true;
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				texts.push_back(new LSprite(tex, x, y));
			}
			window.handleEvent(e);
		}
		if (!window.isMinimized()) {
			SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(window.getRenderer());
			for (auto i : texts)
				i->render();
			SDL_RenderPresent(window.getRenderer());
		}
	}
	SDL_Quit();
    return 0;
}
