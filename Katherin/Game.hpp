#ifndef _KATH_GAME_HPP
#define _KATH_GAME_HPP


/* CLASS */

class Game
{

public:
	Game();
	virtual ~Game();

	virtual void Initialize()	= 0;
	virtual void Finalize()		= 0;

	virtual void Update(float)	= 0;
	virtual void Render()		= 0;
};


#endif // !_KATH_GAME_HPP

