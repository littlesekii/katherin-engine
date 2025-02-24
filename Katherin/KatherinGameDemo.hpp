#ifndef _KATH_KATHERINGAME_HPP
#define _KATH_KATHERINGAME_HPP

/* INCLUDES */

#include "Game.hpp"

#include "Engine.hpp"
#include "Input.hpp"
#include "Timer.hpp"

#include "DavyJones.hpp"

#include <string>


/* CLASS */

class KatherinGame : public Game
{
private:
	DavyJones* dava;

public:
	
	void Initialize();
	void Finalize();

	void Update(float);
	void Render();
};


#endif // !_KATH_KATHERINGAME_HPP

