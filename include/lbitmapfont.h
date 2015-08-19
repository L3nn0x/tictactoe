
#ifndef _LBITMAPFONT_H_
# define _LBITMAPFONT_H_

#include <string>
#include "ltexture.h"
#include <SDL2/SDL.h>

class	LBitmapFont {
	public:
		LBitmapFont(SDL_Renderer *ren);

		void	render(int x, int y, const std::string &text);

	protected:
		LTexture	*mFont;
};

#endif /* !_LBITMAPFONT_H_ */
