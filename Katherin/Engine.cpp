#include "Engine.hpp"

/* STATIC MEMBERS */

Window* Engine::window = nullptr;


/* CONSTRUCTOR | DESTRUCTOR */

Engine::Engine()
{
	window = new Window();
	game = nullptr;
}

Engine::~Engine()
{
	delete window;
}


/* FUNCTIONS */

int Engine::Run(Game* game)
{
	this->game = game;

	window->Create();
	int result = Loop();
	return result;	
}

int Engine::Loop()
{
	MSG msg{};

	game->Initialize();

	do
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			game->Update();
			game->Render();

			Sleep(1000 / 60);
		}

	} while (msg.message != WM_QUIT);

	game->Finalize();

	return (int)msg.wParam;
}

