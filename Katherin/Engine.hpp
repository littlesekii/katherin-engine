#ifndef _KATH_ENGINE_HPP
#define _KATH_ENGINE_HPP


/* INCLUDES */

#include "Window.hpp"
#include "Game.hpp"


/* CLASS */

class Engine
{

private:
	Game* game;

	int Loop();

public:
	static Window* window;

	//Engine();
	Engine();
	~Engine();

	int Run(Game*);
};

#endif // !_KATH_ENGINE_HPP
