#ifndef _KATH_WINDOW_HPP
#define _KATH_WINDOW_HPP


/* INCLUDES */

#include <windows.h>
#include <windowsx.h>

#include "Types.hpp"


/* CONSTANTS */

constexpr DWORD WSTYLE_FULLSCREEN = WS_EX_TOPMOST | WS_POPUP;
constexpr DWORD WSTYLE_WINDOWED = WS_EX_TOPMOST | WS_OVERLAPPED | WS_SYSMENU;

constexpr Dimension2D DEFAULT_SIZE = { 960, 540 };


/* ENUMS */

enum class WindowMode : short
{
	WINDOWED,
	FULLSCREEN
};


/* CLASS */

class Window
{

private:

	// id
	HINSTANCE instance;
	HWND handle;

	// metrics
	WindowMode mode;

	Vector2D position;
	Dimension2D size;
	Dimension2D clientSize;
	Dimension2D screenSize;

	// details
	char title[255];

	static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

public:

	Window();
	~Window();

	HWND GetHandle() const;
	
	bool Create();

};


/* INLINE FUNCTIONS */

inline HWND Window::GetHandle() const
{ return handle;}


#endif // !_KATH_WINDOW_HPP

