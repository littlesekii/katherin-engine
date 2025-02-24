#ifndef _KATH_SPRITE_HPP
#define _KATH_SPRITE_HPP


/* INCLUDES */

#include "Image.hpp"


/* STRUCTS DEFINITION */

struct SpriteData
{
	float x; 
	float y;
	float z;
	float scale;
	float rotation;
	uint width;
	uint height;
	ID3D11ShaderResourceView* texture;
};

struct SpriteLayer
{
	static const float FRONT;
	static const float UPPER;
	static const float MIDDLE;
	static const float LOWER;
	static const float BACK;
};


/* CLASS */

class Sprite
{

private:
	SpriteData sprite;
	bool localImage;
	const Image* image;

public:
	Sprite(const char* filename);
	Sprite(Image* image);
	~Sprite();

	uint GetWidth() const;
	uint GetHeight() const;

	void Draw(float, float, float = SpriteLayer::MIDDLE);

};

inline uint Sprite::GetWidth() const
{ return sprite.width; }

inline uint Sprite::GetHeight() const
{ return sprite.height; }

#endif // !_KATH_SPRITE_HPP