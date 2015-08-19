#include "ltexturemanager.h"

LTextureManager::LTextureManager(SDL_Renderer *ren) : mRen(ren) {}

void	LTextureManager::load(std::string& id, std::string& filename) {
	mTextures.insert(std::make_pair(id, std::unique_ptr<LTexture>
				(new LTexture(mRen, filename))));
}

LTexture&		LTextureManager::get(std::string& id) {
	auto	tmp = mTextures.find(id);
	return *tmp->second;
}

const LTexture&	LTextureManager::get(std::string& id) const {
	auto	tmp = mTextures.find(id);
	return *tmp->second;
}
