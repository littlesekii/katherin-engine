#include "KatherinGameDemo.hpp"


void KatherinGame::Initialize()
{
	dava = new DavyJones();
}

void KatherinGame::Finalize()
{
	delete dava;
}

void KatherinGame::Update(float delta)
{
	
	if (Input::GetKeyPressed(VK_ESCAPE))
	{
		Engine::Stop();
	}

	dava->Update(delta);

}

void KatherinGame::Render()
{
	dava->Render();
}
