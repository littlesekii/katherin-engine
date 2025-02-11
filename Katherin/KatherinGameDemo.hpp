#ifndef _KATH_KATHERINGAME_HPP
#define _KATH_KATHERINGAME_HPP

/* INCLUDES */

#include "Engine.hpp"
#include "Game.hpp"


/* CLASS */

class KatherinGame : public Game
{
private:
	Window* window;

	HDC hdc;
	
public:
	
	void Initialize();
	void Finalize();

	void Update();
	void Render();
};


#endif // !_KATH_KATHERINGAME_HPP

