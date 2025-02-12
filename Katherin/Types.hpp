#ifndef _KATH_TYPES_HPP
#define _KATH_TYPES_HPP


/* TYPE ALIAS DEFINITION */

using uchar		= unsigned char;
using ushort	= unsigned short;
using uint		= unsigned int;
using ulong		= unsigned long;
using ullong	= unsigned long long;
using llong		= long long;


/* STRUCT DEFINITIONS */

struct Vector2D
{
	int x;
	int y;
};

struct Dimension2D
{
	int width;
	int height;
};

struct RGBColor
{
	int r;
	int g;
	int b;
};

struct WindowInput
{
	bool vkKeys[256];
	Vector2D mousePos;
};


/* ENUM DEFINITIONS */

enum class WindowMode : short
{
	WINDOWED,
	FULLSCREEN
};

#endif // !_KATH_TYPES_HPP