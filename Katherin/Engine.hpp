#ifndef _KATH_ENGINE_HPP
#define _KATH_ENGINE_HPP


/* INCLUDES */

#include "Window.hpp"
#include "Game.hpp"
#include "GameProperties.hpp"

/* CLASS */

class Engine
{

private:
	Game* game;

	int Loop();

	void LoadWindowProperties();

public:
	static Window* window;

	//Engine();
	Engine();
	~Engine();


	int Run(Game*);
	static void Stop();
};

inline void Engine::Stop()
{ window->Close(); }

#endif // !_KATH_ENGINE_HPP
