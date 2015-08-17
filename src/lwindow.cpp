#include "lwindow.h"
#include "log.h"

LWindow::LWindow(std::string name, int w, int h) : w(w), h(h), mWindow(nullptr),
	mRenderer(nullptr), mMouseFocus(false), mKeyboardFocus(false), mFullScreen(false),
	mMinimized(false) {
	mWindow = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, w, h, 0);
	if (!mWindow) {
		Log("Error creating window : %s\n", SDL_GetError());
		throw;
	}
	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer) {
		Log("Error creating renderer : %s\n", SDL_GetError());
		SDL_DestroyWindow(mWindow);
		throw;
	}
	mMouseFocus = true;
	mKeyboardFocus = true;
}

LWindow::~LWindow() {
	if (mRenderer)
		SDL_DestroyRenderer(mRenderer);
	if (mWindow)
		SDL_DestroyWindow(mWindow);
}

SDL_Renderer	*LWindow::getRenderer() {
	return mRenderer;
}

void	LWindow::handleEvent(SDL_Event &e) {
	if (e.type != SDL_WINDOWEVENT)
		return;
	switch (e.window.event) {
		case	SDL_WINDOWEVENT_SIZE_CHANGED:
			w = e.window.data1;
			h = e.window.data2;
			SDL_RenderPresent(mRenderer);
			break;
		case	SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(mRenderer);
			break;
		case	SDL_WINDOWEVENT_ENTER:
			mMouseFocus = true;
			break;
		case	SDL_WINDOWEVENT_LEAVE:
			mMouseFocus = false;
			break;
		case	SDL_WINDOWEVENT_FOCUS_GAINED:
			mKeyboardFocus = true;
			break;
		case	SDL_WINDOWEVENT_FOCUS_LOST:
			mKeyboardFocus = false;
			break;
		case	SDL_WINDOWEVENT_MINIMIZED:
			mMinimized = true;
			break;
		case	SDL_WINDOWEVENT_MAXIMIZED:
			mMinimized = false;
			break;
		case	SDL_WINDOWEVENT_RESTORED:
			mMinimized = false;
			break;
	}
}

void	LWindow::setFullScreen(bool fullscreen) {
	if (fullscreen && !mFullScreen) {
		mFullScreen = true;
		SDL_SetWindowFullscreen(mWindow, false);
	} else {
		mFullScreen = false;
		SDL_SetWindowFullscreen(mWindow, true);
	}
}

bool	LWindow::hasMouseFocus() const {
	return mMouseFocus;
}

bool	LWindow::hasKeyboardFocus() const {
	return mKeyboardFocus;
}

bool	LWindow::isMinimized() const {
	return mMinimized;
}
