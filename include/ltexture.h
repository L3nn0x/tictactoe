
#ifndef _LTEXTURE_H_
# define _LTEXTURE_H_

#include <SDL2/SDL.h>
#include <string>
#include "log.h"

class	LTexture {
	public:
		LTexture(SDL_Renderer*, std::string path);
		~LTexture();

		void	setColor(uint8_t red, uint8_t green, uint8_t blue);
		void	render(int x, int y, SDL_Rect *clip=nullptr);

		void	setBlendMode(SDL_BlendMode blending);
		void	setAlpha(uint8_t alpha);

		void	setFlip(SDL_RendererFlip);

	protected:
		SDL_Renderer		*mRen;
		SDL_Texture			*mTexture;
		SDL_RendererFlip	mFlip;

	public:
		int			w;
		int			h;
		double		angle;
		SDL_Point	*center;
};

SDL_Surface	*loadSurface(std::string path);

#endif /* !_LTEXTURE_H_ */
