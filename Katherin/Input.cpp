#include "Input.hpp"


/* STATIC MEMBERS */

InputKeyPressed Input::vkKeyPressed[256]{};


/* FUNCTIONS */

bool Input::GetKeyPressed(int vkCode)
{
	// if key went down
	if (vkKeyPressed[vkCode].down)
	{
		// check if went up
		vkKeyPressed[vkCode].up = GetKeyUp(vkCode);
	}
	else
	{
		// check if went down
		vkKeyPressed[vkCode].down = GetKeyDown(vkCode);
	}

	// if key went down and up then it got pressed
	if (vkKeyPressed[vkCode].down && vkKeyPressed[vkCode].up)
	{
		// restart keypressed handler
		vkKeyPressed[vkCode].down = false;
		vkKeyPressed[vkCode].up = false;

		//key got pressed
		return true;
	}
	
	return false;
}