#include "Image.hpp"
#include "Graphics.hpp"


/* CONSTRUCTOR | DESTRUCTOR */

Image::Image(const char* filename) : 
	textureView(nullptr), 
	width(0), 
	height(0)
{
	// cria uma sharer resource view da imagem em disco
	D3D11CreateTextureFromFile(
		Graphics::d3dDevice,
		Graphics::d3dDeviceContext,
		filename,
		nullptr,
		&textureView,
		width,
		height
	);
}

Image::~Image()
{
	//libera a memória ocupada pela textureview
	if (textureView)
	{
		// pega o ponteiro para recurso
		ID3D11Resource* resource = nullptr;
		textureView->GetResource(&resource);

		// liberando a view não libera automaticamente 
		// o recurso que foi criado junto com a view
		if (resource)
		{
			resource->Release();
			resource = nullptr;
		}

		textureView->Release();
		textureView = nullptr;
	}
}