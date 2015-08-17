#include "lsprite.h"

LSprite::LSprite(std::shared_ptr<LTexture> tex, int x, int y) :
	mTex(tex), mX(x), mY(y) {}

void	LSprite::render() {
	mTex->render(mX, mY);
}
