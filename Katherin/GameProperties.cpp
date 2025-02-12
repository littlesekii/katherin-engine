#include "GameProperties.hpp"

bool		GameProperties::loadWindowProperties	= true;
Dimension2D GameProperties::windowSize				= { 960, 540 };
WindowMode	GameProperties::windowMode				= WindowMode::WINDOWED;

RGBColor	GameProperties::windowBackgroundColor	= { 25, 25, 25 };

char		GameProperties::windowTitle[256]		= "Katherin Game";

int			GameProperties::windowIconResource		= IDI_DEFAULT;
int			GameProperties::windowCursorResource	= IDC_INVERTED;