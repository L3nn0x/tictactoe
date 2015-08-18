#include <iostream>
#include <string>
#include "ltexture.h"
#include "lsprite.h"
#include "lwindow.h"
#include <memory>
#include <vector>

int		checkWin(int data[3][3]) {
	int	win = 0;
	for (int i = 0; i < 3; ++i) {
		int	countV = 0;
		int	countH = 0;
		for (int j = 0; j < 3; ++j) {
			if (data[i][j] == data[i][0])
				++countV;
			if (data[j][i] == data[0][i])
				++countH;
		}
		if (countV == 3) {
			win = data[i][0];
			break;
		} else if (countH == 3) {
			win = data[0][i];
			break;
		}
	}
	if (data[0][0] == data[1][1] && data[0][0] == data[2][2])
		win = data[0][0];
	else if (data[0][2] == data[1][1] && data[0][2] == data[2][0])
		win = data[0][2];
	return win;
}

void	drawGrid(SDL_Renderer *ren, int w, int h) {
	int	incW = w / 3;
	int	incH = h / 3;
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0xFF);
	for (int i = 0; i < w; i += incW)
		SDL_RenderDrawLine(ren, i, 1, i, h);
	for (int i = 1; i < h; i += incH)
		SDL_RenderDrawLine(ren, 0, i, w, i);
}

int main() {
	SDL_Init(SDL_INIT_VIDEO);
	LWindow	window("Tic tac toe", 640, 480);

	std::shared_ptr<LTexture>	cross(new LTexture(window.getRenderer(), "res/cross.bmp"));
	std::shared_ptr<LTexture>	circle(new LTexture(window.getRenderer(), "res/circle.bmp"));

	std::vector<std::unique_ptr<LSprite>>	sprites;
	int		data[3][3] = {0};
	bool	c = true;
	int		w = window.w / 3;
	int		h = window.h / 3;

	bool	quit =false;
	while (!quit) {
		SDL_Event	e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;
			else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				quit = true;
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				int	x, y;
				SDL_GetMouseState(&x, &y);
				for (int i = 0; i < 4; ++i)
					if (x < i * w) {
						x = i - 1;
						break;
					}
				for (int i = 0; i < 4; ++i)
					if (y < i * h) {
						y = i - 1;
						break;
					}
				if (x < 3 && y < 3 && !data[x][y]) {
					auto	tmp = std::unique_ptr<LSprite>(new LSprite(c?circle:cross, x * w + w / 2, y * h + h / 2));
					tmp->setCenter({tmp->w / 2, tmp->h / 2});
					sprites.push_back(std::move(tmp));
					data[x][y] = c?1:2;
					c = 1 - c;
				}
			}
			window.handleEvent(e);
		}
		if (!window.isMinimized()) {
			SDL_SetRenderDrawColor(window.getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(window.getRenderer());
			drawGrid(window.getRenderer(), window.w, window.h);
			for (auto &i : sprites)
				i->render();
			SDL_RenderPresent(window.getRenderer());
		}
		int	win = checkWin(data);
		if (win) {
			std::cout << (win == 1 ? "Circle" : "Cross") << " wins!" << std::endl;
			quit = true;
		}
	}
	SDL_Quit();
    return 0;
}
