#include "DavyJones.hpp"

#include "Input.hpp"

DavyJones::DavyJones()
{
	sprite = new Sprite("res\\dava.jpg");

	speed = 100.f;
}

DavyJones::~DavyJones()
{
	delete sprite;
}

void DavyJones::Update(float delta)
{
	if (Input::GetKeyDown(VK_UP))
	{ 
		y -= speed * delta;
	}
	if (Input::GetKeyDown(VK_DOWN))
	{
		y += speed * delta;
	}
	if (Input::GetKeyDown(VK_LEFT))
	{
		x -= speed * delta;
	}
	if (Input::GetKeyDown(VK_RIGHT))
	{
		x += speed * delta;
	}
}

void DavyJones::Render()
{
	sprite->Draw(x, y);
}
