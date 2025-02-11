#include "Window.hpp"

/* CONSTRUCTOR | DESTRUCTOR */

Window::Window()
{
	instance	= GetModuleHandle(NULL);
	handle		= NULL;

	mode		= WindowMode::WINDOWED;

	position	= { 0, 0 };
	screenSize	= { GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
	size		= (mode == WindowMode::WINDOWED ? DEFAULT_SIZE : screenSize);
	clientSize	= size;


	strcpy_s(title, "Katherin Game");
}

Window::~Window()
{
}


/* FUNCTIONS */

bool Window::Create()
{
	// create window class
	WNDCLASSEX windowClass{};

	windowClass.cbSize			= sizeof(WNDCLASSEX);
	windowClass.style			= CS_DBLCLKS | CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	windowClass.lpfnWndProc		= WindowProc;
	windowClass.cbClsExtra		= NULL;
	windowClass.cbWndExtra		= NULL;
	windowClass.hInstance		= instance;
	windowClass.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor			= LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground	= (HBRUSH) GetStockObject(BLACK_BRUSH);
	windowClass.lpszMenuName	= NULL;
	windowClass.lpszClassName	= "KathWindow";
	windowClass.hIconSm			= NULL;

	// register window class
	if (!RegisterClassEx(&windowClass))
	{
		MessageBox(NULL, "Failed to register \"KathWindow\" window class.", "Error", MB_ICONERROR);
		return 0;
	}

	// create window
	handle = CreateWindowEx(
		NULL,
		"KathWindow",
		title,
		(mode == WindowMode::WINDOWED ? WSTYLE_WINDOWED : WSTYLE_FULLSCREEN),
		position.x,
		position.y,
		size.width,
		size.height,
		NULL,
		NULL,
		instance,
		NULL
	);

	// adjust window size when on windowed mode
	if (mode == WindowMode::WINDOWED)
	{
		
		RECT windowRect{ 0, 0, size.width, size.height };
		AdjustWindowRectEx(
			&windowRect,
			GetWindowStyle(handle),
			GetMenu(handle) != NULL,
			GetWindowExStyle(handle)
		);

		size.width = windowRect.right - windowRect.left;
		size.height = windowRect.bottom - windowRect.top;

		position.x = screenSize.width / 2 - size.width / 2;
		position.y = screenSize.height / 2 - size.height / 2;

		MoveWindow(
			handle,
			position.x,
			position.y,
			size.width,
			size.height,
			true
		);
	}

	ShowWindow(handle, true);

	return (handle ? true : false);
}

/* STATIC FUNCTIONS */

LRESULT CALLBACK Window::WindowProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);

		return 0;
	}

	return DefWindowProc(handle, msg, wParam, lParam);
}