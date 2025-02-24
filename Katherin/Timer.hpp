#ifndef _KATH_TIMER_HPP
#define _KATH_TIMER_HPP


/* INCLUDES */

#include "windows.h"
#include "Types.hpp"

class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER end;

	LARGE_INTEGER frequency;

	bool paused;

public:
	Timer();

	void Start();
	void Pause();
	float Reset();
	float GetTimeElapsed();
};

#endif // !_KATH_TIMER_HPP