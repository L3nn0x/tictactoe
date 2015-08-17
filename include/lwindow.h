
#ifndef _LWINDOW_H_
# define _LWINDOW_H_

#include <SDL2/SDL.h>
#include <string>

class	LWindow {
	public:
		LWindow(std::string name, int w, int h);
		~LWindow();

		SDL_Renderer	*getRenderer();

		void	handleEvent(SDL_Event &e);
		void	focus();
		void	render();

		int	w;
		int	h;

		bool	hasMouseFocus() const;
		bool	hasKeyboardFocus() const;
		bool	isMinimized() const;

		void	setFullScreen(bool fullscreen);

	protected:
		SDL_Window			*mWindow;
		SDL_Renderer		*mRenderer;
		bool				mMouseFocus;
		bool				mKeyboardFocus;
		bool				mFullScreen;
		bool				mMinimized;
		unsigned int		mWindowID;
		bool				mShown;
};

#endif /* !_LWINDOW_H_ */
