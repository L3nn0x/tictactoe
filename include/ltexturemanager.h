
#ifndef _LTEXTUREMANAGER_H_
# define _LTEXTUREMANAGER_H_

#include "ltexture.h"
#include <unordered_map>
#include <memory>
#include <string>

class	LTextureManager {
	public:
		LTextureManager(SDL_Renderer *ren);

		void	load(std::string& id, std::string& filename);

		LTexture&		get(std::string& id);
		const LTexture&	get(std::string& id) const;

	protected:
		SDL_Renderer	*mRen;
		std::unordered_map<std::string, std::unique_ptr<LTexture>>	mTextures;
};

#endif /* !_LTEXTUREMANAGER_H_ */
