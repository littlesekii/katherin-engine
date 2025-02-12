#ifndef _KATH_INPUT_HPP
#define _KATH_INPUT_HPP


/* INCLUDES */

#include "Types.hpp"
#include "Window.hpp"


/* CLASS */

class Input
{
public:
	static bool GetKeyDown(int);
	static Vector2D GetMousePos();
};

inline bool Input::GetKeyDown(int vkCode)
{ return Window::GetInput().vkKeys[vkCode]; }

inline Vector2D Input::GetMousePos()
{ return Window::GetInput().mousePos; }


#endif // !_KATH_INPUT_HPP
