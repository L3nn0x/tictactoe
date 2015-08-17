#include <iostream>
#include <string>
#include "ltexture.h"
#include <vector>
#include <memory>

class	Sprite {
	public:
		Sprite(std::shared_ptr<LTexture*> tex, int x, int y) {
			mX = x;
			mY = y;
			mTex = tex;
		}

		void	render() {
			(*mTex)->render(mX, mY);
		}
	protected:
		std::shared_ptr<LTexture*>	mTex;
		int	mX;
		int	mY;
};

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window	*window = SDL_CreateWindow("Tic tac toe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			640, 480, 0);

	SDL_Renderer	*ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	std::vector<Sprite*>	texts;
	std::shared_ptr<LTexture*>	tex = std::make_shared<LTexture*>(new LTexture(ren, "res/cross.bmp"));

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
				texts.push_back(new Sprite(tex, x, y));
			}
		}
		SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(ren);
		for (auto i : texts)
			i->render();
		SDL_RenderPresent(ren);
	}
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
    return 0;
}
