#include "game.h"
#include <SDL2/SDL.h>
#include <iostream>

Game::Game() : mWindow(new LWindow("Tic tac toe", 640, 480)), quit(false), data{0} {
	auto	manager = mWindow->getManager();
	//manager.load("cross", "res/cross.bmp");
	//manager.load("circle", "res/circle.bmp");
	turn = true;
}

void	Game::run() {
	while (!quit) {
		processEvents();
		update(0);
		render();
	}
}

void	Game::processEvents() {
	auto	manager = mWindow->getManager();
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
				if (x < i * mWindow->w / 3) {
					x = i - 1;
					break;
				}
			for (int i = 0; i < 4; ++i)
				if (y < i * mWindow->h / 3) {
					y = i - 1;
					break;
				}
			if (x < 3 && y < 3 && !data[x][y]) {
				/*auto	tmp = std::unique_ptr<LSprite>(
						new LSprite(turn?manager.get("circle"):manager.get("cross"),
							x * mWindow->w / 3 + mWindow->w / 6,
							y * mWindow->h / 3 + mWindow->h / 6));
				tmp->setCenter({tmp->w / 2, tmp->h / 2});
				sprites.push_back(std::move(tmp));
				data[x][y] = turn?1:2;
				turn = 1 - turn;*/
			}
		}
		mWindow->handleEvent(e);
	}
}

static int	checkWin(int data[3][3]) {
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

void	Game::update(uint32_t deltaTime) {
	(void)deltaTime;
	int	win = checkWin(data);
	if (win) {
		std::cout << (win == 1?"Circle" : "Cross") << " wins!\n";
		quit = true;
	}
}

static void	drawGrid(SDL_Renderer *ren, int w, int h) {
	int	incW = w / 3;
	int	incH = h / 3;
	SDL_SetRenderDrawColor(ren, 0, 0, 0, 0xFF);
	for (int i = 0; i < w; i += incW)
		SDL_RenderDrawLine(ren, i, 1, i, h);
	for (int i = 1; i < h; i += incH)
		SDL_RenderDrawLine(ren, 0, i, w, i);
}

void	Game::render() {
	if (!mWindow->isMinimized()) {
		SDL_SetRenderDrawColor(mWindow->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(mWindow->getRenderer());
		drawGrid(mWindow->getRenderer(), mWindow->w, mWindow->h);
		for (auto &i : sprites)
			i->render();
		SDL_RenderPresent(mWindow->getRenderer());
	}
}
