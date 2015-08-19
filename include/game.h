
#ifndef _GAME_H_
# define _GAME_H_

#include "lwindow.h"
#include "lsprite.h"
#include "ltexture.h"
#include <memory>
#include <vector>

class	Game {
	public:
		Game();

		void	run();

	protected:
		void	processEvents();
		void	update(uint32_t deltaTime);
		void	render();

	private:
		std::unique_ptr<LWindow>				mWindow;
		bool									quit;
		int										data[3][3];
		std::vector<std::unique_ptr<LSprite>>	sprites;
		bool									turn;
};

#endif /* !_GAME_H_ */
