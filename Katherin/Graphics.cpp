#include "Graphics.hpp"


/* STATIC MEMBERS */

ID3D11Device* Graphics::d3dDevice{ nullptr };
ID3D11DeviceContext* Graphics::d3dDeviceContext{ nullptr };
D3D11_VIEWPORT Graphics::viewport{ 0 };


/* CONSTRUCTOR | DESTRUCTOR */

Graphics::Graphics()
{
	swapChain			= nullptr;
	renderTargetView	= nullptr;
	blendState			= nullptr;
	featureLevel		= D3D_FEATURE_LEVEL_11_0;

	bgColorRGBA[0]		= .0f;
	bgColorRGBA[1]		= .0f;
	bgColorRGBA[2]		= .0f;
	bgColorRGBA[3]		= .0f;

	vSync				= false;

}

Graphics::~Graphics()
{
	if (blendState)
	{
		blendState->Release();
		blendState = nullptr;
	}
	if (renderTargetView)
	{
		renderTargetView->Release();
		renderTargetView = nullptr;
	}

	if (swapChain)
	{
		swapChain->SetFullscreenState(false, NULL);
		swapChain->Release();
		swapChain = nullptr;
	}

	if (d3dDeviceContext)
	{
		d3dDeviceContext->ClearState();
		d3dDeviceContext->Release();
		d3dDeviceContext = nullptr;
	}

	if (d3dDevice)
	{
		d3dDevice->Release();
		d3dDevice = nullptr;
	}

}


/* FUNCTIONS */

bool Graphics::Initialize(HWND handle, Dimension2D clientSize, WindowMode windowMode, RGBColor backgroundColor)
{
	uint createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

	D3D11CreateDevice(
		NULL,                      
		D3D_DRIVER_TYPE_HARDWARE,  
		NULL,                      
		createDeviceFlags,			
		NULL,                      
		0,                         
		D3D11_SDK_VERSION,         
		&d3dDevice,                
		&featureLevel,             
		&d3dDeviceContext          
	);

	bgColorRGBA[0] = backgroundColor.r / 255.f;
	bgColorRGBA[1] = backgroundColor.g / 255.f;
	bgColorRGBA[2] = backgroundColor.b / 255.f;
	bgColorRGBA[3] = 1.f;


	DXGI_SWAP_CHAIN_DESC swapDesc{ 0 }; 

	swapDesc.BufferDesc.Width					= clientSize.width;     
	swapDesc.BufferDesc.Height					= clientSize.height;   
	swapDesc.BufferDesc.RefreshRate.Numerator	= 60;            
	swapDesc.BufferDesc.RefreshRate.Denominator = 1;           
	swapDesc.BufferDesc.Format					= DXGI_FORMAT_R8G8B8A8_UNORM;   
	swapDesc.SampleDesc.Count					= 1;                             
	swapDesc.SampleDesc.Quality					= 0;                           
	swapDesc.BufferUsage						= DXGI_USAGE_RENDER_TARGET_OUTPUT;    
	swapDesc.BufferCount						= 2;                                  
	swapDesc.OutputWindow						= handle;               
	swapDesc.Windowed							= windowMode == WindowMode::WINDOWED;         
	swapDesc.SwapEffect							= DXGI_SWAP_EFFECT_FLIP_DISCARD;       
	swapDesc.Flags								= DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;   


	// pega o ponteiro para o dispositivo gráfico
	IDXGIDevice* dxgiDevice{ nullptr };
	if FAILED(d3dDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice))
	{
		return false;
	}

	IDXGIAdapter* dxgiAdapter{ nullptr };
	if FAILED(dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter))
	{
		return false;
	}

	IDXGIFactory* dxgiFactory{ nullptr };
	if FAILED(dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory))
	{
		return false;
	}

	if (d3dDevice != NULL)
	{
		if FAILED(dxgiFactory->CreateSwapChain(d3dDevice, &swapDesc, &swapChain))
		{
			return false;
		}
	}

	if FAILED(dxgiFactory->MakeWindowAssociation(handle, DXGI_MWA_NO_ALT_ENTER))
	{
		return false;
	}

	ID3D11Texture2D* backBuffer{ nullptr };

	if FAILED(
		swapChain->GetBuffer(
			0,                          
			__uuidof(ID3D11Texture2D),  
			(void**)&backBuffer         
		)
	)
	{
		return false;
	}

	if FAILED(
		d3dDevice->CreateRenderTargetView(
			backBuffer,                
			NULL,                      
			&renderTargetView          
		)
	)
	{
		return false;
	}

	d3dDeviceContext->OMSetRenderTargets(1, &renderTargetView, nullptr);


	viewport.TopLeftX	= 0;
	viewport.TopLeftY	= 0;
	viewport.Width		= clientSize.width	* 1.f;
	viewport.Height		= clientSize.height * 1.f;
	viewport.MinDepth	= .0f;
	viewport.MaxDepth	= 1.0f;


	d3dDeviceContext->RSSetViewports(1, &viewport);

	D3D11_BLEND_DESC blendDesc						= { 0 };
	blendDesc.AlphaToCoverageEnable					= false;                                
	blendDesc.IndependentBlendEnable				= false;                               
	blendDesc.RenderTarget[0].BlendEnable			= true;                           
	blendDesc.RenderTarget[0].SrcBlend				= D3D11_BLEND_SRC_ALPHA;             
	blendDesc.RenderTarget[0].DestBlend				= D3D11_BLEND_INV_SRC_ALPHA;        
	blendDesc.RenderTarget[0].BlendOp				= D3D11_BLEND_OP_ADD;                 
	blendDesc.RenderTarget[0].SrcBlendAlpha			= D3D11_BLEND_ONE;              
	blendDesc.RenderTarget[0].DestBlendAlpha		= D3D11_BLEND_ZERO;            
	blendDesc.RenderTarget[0].BlendOpAlpha			= D3D11_BLEND_OP_ADD;            
	blendDesc.RenderTarget[0].RenderTargetWriteMask = 0x0F;                 

	if FAILED(d3dDevice->CreateBlendState(&blendDesc, &blendState))
	{
		return false;
	}

	d3dDeviceContext->OMSetBlendState(blendState, nullptr, 0xffffffff);

	dxgiDevice->Release();
	dxgiAdapter->Release();
	dxgiFactory->Release();
	backBuffer->Release();

	return true;

}