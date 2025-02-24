#ifndef _KATH_GRAPHICS_HPP
#define _KATH_GRAPHICS_HPP


/* INCLUDES */

#include <dxgi.h>
#include <d3d11.h>
#include "Types.hpp"

class Graphics
{
private:
	IDXGISwapChain				* swapChain;			
	ID3D11RenderTargetView		* renderTargetView;		
	ID3D11BlendState			* blendState;			
	D3D_FEATURE_LEVEL			featureLevel;			
	float						bgColorRGBA[4];		
	bool						vSync;				

public:
	Graphics();
	~Graphics();

	static ID3D11Device			* d3dDevice;			
	static ID3D11DeviceContext	* d3dDeviceContext;     
	static D3D11_VIEWPORT		viewport;				

	void SetVSync(bool);
	void Clear();									
	void Present();									
	bool Initialize(HWND, Dimension2D, WindowMode, RGBColor);						

};


/* INLINE FUNCTIONS */

inline void Graphics::SetVSync(bool vSync)
{ this->vSync = vSync; }

inline void Graphics::Clear()
{ d3dDeviceContext->ClearRenderTargetView(renderTargetView, bgColorRGBA); }

inline void Graphics::Present()
{
	swapChain->Present(vSync, NULL);
	d3dDeviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);
}

#endif // !_KATH_GRAPHICS_HPP