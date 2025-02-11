#define WIN32_LEAN_AND_MEAN
#ifndef _KATH_MAIN_CPP
#define _KATH_MAIN_CPP


/*  INCLUDES  */

#include <Windows.h>

#include "Engine.hpp"
#include "KatherinGameDemo.hpp"


/* FUNCTIONS */

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	Engine* engine = new Engine();
	int exitCode = engine->Run(new KatherinGame());
	delete engine;

	return exitCode;
}


#endif // !_KATH_MAIN_CPP