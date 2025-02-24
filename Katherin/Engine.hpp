#ifndef _KATH_ENGINE_HPP
#define _KATH_ENGINE_HPP


/* INCLUDES */

#include "Window.hpp"
#include "Game.hpp"
#include "GameProperties.hpp"
#include "Graphics.hpp"
#include "Renderer.hpp"
#include "Timer.hpp"
#include <string>

/* CLASS */

class Engine
{

private:
	static Window	* window;
	static Renderer * renderer;
	
	Game			* game;
	Graphics		* graphics;
	Timer			* timer;

	float			frameTime;

	int Loop();

	void LoadWindowProperties();
	void LoadGraphicsProperties();

	float GetFrameTime();

public:


	//Engine();
	Engine();
	~Engine();

	static Renderer* GetRenderer();

	int				Run(Game*);
	static void		Stop();

};


/* INLINE FUNCTIONS */

inline void Engine::Stop()
{ window->Close(); }

inline Renderer* Engine::GetRenderer()
{ return renderer; }


#endif // !_KATH_ENGINE_HPP
