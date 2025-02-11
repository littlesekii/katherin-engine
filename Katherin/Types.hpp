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


#endif // !_KATH_TYPES_HPP