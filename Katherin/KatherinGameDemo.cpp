#include "KatherinGameDemo.hpp"


void KatherinGame::Initialize()
{
	window = Engine::window;
	hdc = GetDC(window->GetHandle());
}

void KatherinGame::Finalize()
{
	ReleaseDC(window->GetHandle(), hdc);
}

void KatherinGame::Update()
{
	if (Input::GetKeyDown(VK_ESCAPE))
	{
		Engine::Stop();
	}
}

void KatherinGame::Render()
{
	RECT drawRect{};

	GetClientRect(window->GetHandle(), &drawRect);

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 255, 255));
	DrawText(hdc, "Katherin Game Demo", -1, &drawRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}
