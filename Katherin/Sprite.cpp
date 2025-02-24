#include "Sprite.hpp"
#include "Engine.hpp"


/* STATIC MEMBERS */

const float SpriteLayer::FRONT	= 0.f;
const float SpriteLayer::UPPER	= 0.25f;
const float SpriteLayer::MIDDLE	= 0.50f;
const float SpriteLayer::LOWER	= 0.75f;
const float SpriteLayer::BACK	= 0.99f;


/* CONSTRUCTOR | DESTRUCTOR */

Sprite::Sprite(const char* filename) : sprite({})
{
	image = new Image(filename);
	localImage = true;
}

Sprite::Sprite(Image* image) : sprite({})
{
	this->image = image;
	localImage = false;	
}

Sprite::~Sprite()
{
	if (localImage)
	{
		delete image;
	}
}

/* FUNCTIONS */

void Sprite::Draw(float x, float y, float z)
{
	sprite.x = x;
	sprite.y = y;
	sprite.z = z;
	sprite.scale = 1.f;
	sprite.rotation = 0.f;
	sprite.width = image->GetWidth();
	sprite.height = image->GetHeight();
	sprite.texture = image->GetView();

	// adiciona o sprite na lista de desenho
	Engine::GetRenderer()->Draw(&sprite);
}
