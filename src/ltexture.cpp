#include "ltexture.h"

SDL_Surface	*loadSurface(std::string path) {
	SDL_Surface	*tmp = SDL_LoadBMP(std::string(std::string(SDL_GetBasePath()) + path).c_str());
	if (!tmp)
		Log("Unable to load image %s, error : %s\n", path.c_str(), SDL_GetError());
	return tmp;
}

LTexture::LTexture(SDL_Renderer *ren, std::string path) : mRen(ren), mTexture(nullptr),
	mFlip(SDL_FLIP_NONE), w(0), h(0), angle(0.f), center(nullptr) {
	SDL_Surface	*tmp = loadSurface(path);
	if (!tmp)
		throw;
	SDL_SetColorKey(tmp, true, SDL_MapRGB(tmp->format, 0xFF, 0, 0xFF));
	mTexture = SDL_CreateTextureFromSurface(ren, tmp);
	w = tmp->w;
	h = tmp->h;
	SDL_FreeSurface(tmp);
	if (!mTexture) {
		Log("Unable to create texture from surface : %s\n", path.c_str());
		throw;
	}
}

LTexture::~LTexture() {
	if (mTexture) {
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
	}
}

void	LTexture::setFlip(SDL_RendererFlip flip) {
	mFlip = flip;
}

void	LTexture::render(int x, int y, SDL_Rect *clip) {
	SDL_Rect	tmp = {x, y, w, h};
	if (clip) {
		tmp.w = clip->w;
		tmp.h = clip->h;
	}
	SDL_RenderCopyEx(mRen, mTexture, clip, &tmp, angle, center, mFlip);
}

void	LTexture::setColor(uint8_t red, uint8_t green, uint8_t blue) {
	SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void	LTexture::setBlendMode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(mTexture, blending);
}

void	LTexture::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(mTexture, alpha);
}
