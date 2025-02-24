#ifndef _KATH_WINDOW_HPP
#define _KATH_WINDOW_HPP


/* INCLUDES */

#include <windows.h>
#include <windowsx.h>

#include "Types.hpp"


/* CONSTANTS */

constexpr DWORD WSTYLE_FULLSCREEN	= WS_EX_TOPMOST | WS_POPUP;
constexpr DWORD WSTYLE_WINDOWED		= WS_EX_TOPMOST | WS_OVERLAPPED | WS_SYSMENU;

constexpr Dimension2D DEFAULT_SIZE	= { 960, 540 };

/* CLASS */

class Window
{

private:

	// id
	HINSTANCE			instance;
	HWND				handle;

	// metrics
	WindowMode			mode;

	Vector2D			position;
	Dimension2D			size;
	Dimension2D			clientSize;
	Dimension2D			screenSize;

	// details
	char				title[256];

	HICON				icon;
	HCURSOR				cursor;
	RGBColor			backgroundColor;

	bool				showFPS;
	bool				showFrametime;

	// input
	static WindowInput	input;

	static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

public:

	Window();
	~Window();

	HWND GetHandle() const;

	WindowMode GetMode() const;

	Vector2D GetPosition() const;
	Dimension2D GetSize() const;
	Dimension2D GetClientSize() const;
	Dimension2D GetScreenSize() const;

	const char* GetTitle() const;
	RGBColor GetBackgroundColor() const;

	bool GetShowFPS() const;
	bool GetShowFrametime() const;


	void SetMode(WindowMode);
	void SetSize(Dimension2D);

	void SetTitle(const char*);

	void SetIcon(int);
	void SetCursor(int);
	void SetBackgroundColor(RGBColor);

	void SetShowFPS(bool);
	void SetShowFrametime(bool);

	bool Create();
	void Close() const;

	static WindowInput GetInput();
};


/* INLINE FUNCTIONS */

inline HWND Window::GetHandle() const
{ return handle; }

inline WindowMode Window::GetMode() const
{ return mode; }

inline Vector2D Window::GetPosition() const
{ return position; }

inline Dimension2D Window::GetSize() const
{ return size; }

inline Dimension2D Window::GetClientSize() const
{ return clientSize; }

inline Dimension2D Window::GetScreenSize() const
{ return screenSize; }

inline const char* Window::GetTitle() const
{ return title; }

inline RGBColor Window::GetBackgroundColor() const
{ return backgroundColor; }

inline bool Window::GetShowFPS() const
{ return showFPS; }

inline bool Window::GetShowFrametime() const
{ return showFrametime; }

inline void Window::SetMode(WindowMode mode)
{ this->mode = mode; }

inline void Window::SetSize(Dimension2D size)
{ this->size = size; }

inline void Window::SetTitle(const char* title)
{ strcpy_s(this->title, title); }

inline void Window::SetIcon(int resource)
{ this->icon = LoadIcon(instance, MAKEINTRESOURCE(resource)); }

inline void Window::SetCursor(int resource)
{ this->cursor = LoadCursor(instance, MAKEINTRESOURCE(resource)); }

inline void Window::SetBackgroundColor(RGBColor backgroundColor)
{ this->backgroundColor = backgroundColor; }

inline void Window::SetShowFPS(bool showFPS)
{ this->showFPS = showFPS; }

inline void Window::SetShowFrametime(bool showFrametime)
{ this->showFrametime = showFrametime; }

inline WindowInput Window::GetInput()
{ return input; }

inline void Window::Close() const
{ SendMessage(handle, WM_DESTROY, 0, 0); }


#endif // !_KATH_WINDOW_HPP

