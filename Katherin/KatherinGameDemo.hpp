#ifndef _KATH_KATHERINGAME_HPP
#define _KATH_KATHERINGAME_HPP

/* INCLUDES */

#include "Game.hpp"

#include "Engine.hpp"
#include "Input.hpp"


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

