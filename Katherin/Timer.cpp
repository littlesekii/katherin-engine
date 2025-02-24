#include "Timer.hpp"

Timer::Timer()
{ 
	// get clock frequency
	QueryPerformanceFrequency(&frequency);

	// clear the start and end
	ZeroMemory(&start, sizeof(start));
	ZeroMemory(&end, sizeof(end));

	paused = true;
}

void Timer::Start()
{
	if (!paused)
	{
		return;
	}

	llong timeElapsed{ 0 };

	if (paused)
	{
		// get time already elapsed before pause
		timeElapsed = end.QuadPart - start.QuadPart;
	}
	paused = false;
	QueryPerformanceCounter(&start);

	// include already elapsed time in the new start value
	start.QuadPart -= timeElapsed;
}

void Timer::Pause()
{
	if (paused)
	{
		return;
	}
	paused = true;
	QueryPerformanceCounter(&end);
}

float Timer::Reset()
{
	// get time elapsed
	float timeElapsed { GetTimeElapsed() };

	paused = false;
	QueryPerformanceCounter(&start);

	return timeElapsed;
}

float Timer::GetTimeElapsed()
{
	if (!paused)
	{
		QueryPerformanceCounter(&end);
	}

	llong clockTimeElapsed = end.QuadPart - start.QuadPart;

	return static_cast<float>(
		clockTimeElapsed / static_cast<double>(frequency.QuadPart)
	);
}
