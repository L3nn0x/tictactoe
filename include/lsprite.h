
#ifndef _LSPRITE_H_
# define _LSPRITE_H_

#include "ltexture.h"
#include <SDL2/SDL.h>

class	LSprite {
	public:
		LSprite(LTexture& tex, int x, int y);

		void	render();

		void	setCenter(SDL_Point);

		int	w;
		int	h;

	protected:
		LTexture&	mTex;
		int			mX;
		int			mY;
		SDL_Point	mCenter;
};

#endif /* !_LSPRITE_H_ */
