
#ifndef _LTIMER_H_
# define _LTIMER_H_

#include <cstdint>

class	LTimer {
	public:
		LTimer();

		void	start();
		void	stop();
		void	pause();
		void	unpause();

		uint32_t	getTicks();

		bool	isStarted() const;
		bool	isPaused() const;

	protected:
		uint32_t	mStartTicks;
		uint32_t	mPausedTicks;

		bool	mPaused;
		bool	mStarted;
};

#endif /* !_LTIMER_H_ */
