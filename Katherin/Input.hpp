#ifndef _KATH_INPUT_HPP
#define _KATH_INPUT_HPP


/* INCLUDES */

#include "Types.hpp"
#include "Window.hpp"


/* CLASS */

class Input
{
private:
	static InputKeyPressed vkKeyPressed[256];

public:
	static bool GetKeyDown(int);
	static bool GetKeyUp(int);
	static bool GetKeyPressed(int);

	static Vector2D GetMousePos();
};


/* INLINE FUNCTIONS */

inline bool Input::GetKeyDown(int vkCode)
{ return Window::GetInput().vkKeys[vkCode]; }

inline bool Input::GetKeyUp(int vkCode)
{ return !Input::GetKeyDown(vkCode); }

inline Vector2D Input::GetMousePos()
{ return Window::GetInput().mousePos; }


#endif // !_KATH_INPUT_HPP
