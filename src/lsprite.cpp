#include "lsprite.h"

LSprite::LSprite(LTexture& tex, int x, int y) :
	w(tex.w), h(tex.h), mTex(tex), mX(x), mY(y), mCenter({0, 0}) {}

void	LSprite::render() {
	int	x = mX, y = mY;
	x -= mCenter.x;
	y -= mCenter.y;
	mTex.render(x, y);
}

void	LSprite::setCenter(SDL_Point p) {
	mCenter = p;
}
