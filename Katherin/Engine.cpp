#include "Engine.hpp"


/* STATIC MEMBERS */

Window*		Engine::window		= nullptr;
Renderer*	Engine::renderer	= nullptr;


/* CONSTRUCTOR | DESTRUCTOR */

Engine::Engine()
{

	window		= new Window();
	game		= nullptr;
	graphics	= new Graphics();
	renderer	= new Renderer();
	timer		= new Timer();

	frameTime	= 0.f;

	if (GameProperties::loadWindowProperties)
	{
		LoadWindowProperties();
	}
	if (GameProperties::loadGraphicsProperties)
	{
		LoadGraphicsProperties();
	}
}

Engine::~Engine()
{
	delete timer;
	delete renderer;
	delete graphics;
	delete game;
	delete window;
}


/* FUNCTIONS */

int Engine::Run(Game* game)
{
	this->game = game;

	if (!window->Create())
	{
		return 0;
	}

	graphics->Initialize(
		window->GetHandle(), 
		window->GetClientSize(),
		window->GetMode(), 
		window->GetBackgroundColor()
	);

	renderer->Initialize(window, graphics);

	timer->Start();
	
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
			frameTime = GetFrameTime();
			game->Update(frameTime);

			graphics->Clear();
			game->Render();
			renderer->Render();
			graphics->Present();
		}

	} while (msg.message != WM_QUIT);

	game->Finalize();

	return (int)msg.wParam;
}


float Engine::GetFrameTime()
{
	frameTime = timer->Reset();

	static float	totalTimeElapsed{};
	static ushort	frameCount{};

	if (totalTimeElapsed >= 1.f)
	{
		char title[256]{};
		char fpsTitle[256]{};
		char frametimeTitle[256]{};

		if (window->GetShowFPS())
		{			
			sprintf_s(
				fpsTitle,
				"  |  FPS: %d",
				frameCount
			);
			
		}
		if (window->GetShowFrametime())
		{
			sprintf_s(
				frametimeTitle,
				"  |  Frame Time: %.2fms",
				frameTime * 1000
			);

		}
		sprintf_s(
			title,
			"%s%s%s",
			window->GetTitle(),
			fpsTitle,
			frametimeTitle
		);

		if (window->GetShowFPS() || window->GetShowFrametime())
		{
			SetWindowText(window->GetHandle(), title);
		}
		
		frameCount = 0;
		totalTimeElapsed = 0;

	}
	++frameCount;
	totalTimeElapsed += frameTime;

	return frameTime;
}

void Engine::LoadWindowProperties()
{
	window->SetMode(GameProperties::windowMode);
	window->SetSize(GameProperties::windowSize);

	window->SetBackgroundColor(GameProperties::windowBackgroundColor);

	window->SetIcon(GameProperties::windowIconResource);
	window->SetCursor(GameProperties::windowCursorResource);

	window->SetTitle(GameProperties::windowTitle);

	window->SetShowFPS(GameProperties::windowShowFPS);
	window->SetShowFrametime(GameProperties::windowShowFrameTime);
}

void Engine::LoadGraphicsProperties()
{
	graphics->SetVSync(GameProperties::graphicsVerticalSync);
}


