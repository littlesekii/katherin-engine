#ifndef _KATH_GAMEPROPERTIES_HPP
#define _KATH_GAMEPROPERTIES_HPP


/* INCLUDES */

#include "Types.hpp"
#include "Resource.hpp"

class GameProperties
{
public:

	//window properties
	static bool loadWindowProperties;

	static char windowTitle[256];
	static Dimension2D windowSize;
	static WindowMode windowMode;

	static RGBColor windowBackgroundColor;

	static int windowIconResource;
	static int windowCursorResource;
};

#endif // !_KATH_GAMEPROPERTIES_HPP

