#include "ltexturemanager.h"
#include <functional>

LTextureManager::LTextureManager(SDL_Renderer *ren) : mRen(ren) {}

void	LTextureManager::load(std::string id, std::string filename) {
	std::hash<std::string>	str_hash;
	size_t	hash = str_hash(id);
	std::unique_ptr<LTexture>	tmp(new LTexture(mRen, filename));
	mTextures.insert(std::make_pair(hash, std::move(tmp)));
}

LTexture&		LTextureManager::get(std::string id) {
	std::hash<std::string>	str_hash;
	size_t	hash = str_hash(id);
	auto	tmp = mTextures.find(hash);
	return *tmp->second;
}

const LTexture&	LTextureManager::get(std::string id) const {
	std::hash<std::string>	str_hash;
	size_t	hash = str_hash(id);
	auto	tmp = mTextures.find(hash);
	return *tmp->second;
}
