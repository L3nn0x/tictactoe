
#ifndef _LSPRITE_H_
# define _LSPRITE_H_

#include <memory>
#include "ltexture.h"
#include <SDL2/SDL.h>

class	LSprite {
	public:
		LSprite(std::shared_ptr<LTexture> tex, int x, int y);

		void	render();

	protected:
		std::shared_ptr<LTexture>	mTex;
		int	mX;
		int	mY;
};

#endif /* !_LSPRITE_H_ */
