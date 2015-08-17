
#ifndef _LTEXTURE_H_
# define _LTEXTURE_H_

#include <SDL2/SDL.h>
#include <string>
#include "log.h"

class	LTexture {
	public:
		LTexture(SDL_Renderer*, std::string path);
		LTexture(LTexture&) = delete;
		~LTexture();

		void	setColor(uint8_t red, uint8_t green, uint8_t blue);
		void	render(int x, int y, SDL_Rect *clip=nullptr, double angle=0.f,
				SDL_Point *center=nullptr, SDL_RendererFlip flip=SDL_FLIP_NONE);

		void	setBlendMode(SDL_BlendMode blending);
		void	setAlpha(uint8_t alpha);

	protected:
		SDL_Renderer		*mRen;
		SDL_Texture			*mTexture;

	public:
		int			w;
		int			h;
};

SDL_Surface	*loadSurface(std::string path);

#endif /* !_LTEXTURE_H_ */
