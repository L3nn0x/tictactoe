
#ifndef _LTEXTUREMANAGER_H_
# define _LTEXTUREMANAGER_H_

#include "ltexture.h"
#include <map>
#include <memory>
#include <string>

class	LTextureManager {
	public:
		LTextureManager(SDL_Renderer *ren);

		void	load(std::string id, std::string filename);

		LTexture&		get(std::string id);
		const LTexture&	get(std::string id) const;

	protected:
		SDL_Renderer	*mRen;
		std::map<size_t, std::unique_ptr<LTexture>>	mTextures;
};

#endif /* !_LTEXTUREMANAGER_H_ */
