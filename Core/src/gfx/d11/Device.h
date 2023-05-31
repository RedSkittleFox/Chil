#pragma once
#include "../IDevice.h"
#include <Core/src/win/IWindow.h>
#include <wrl/client.h>
#include <d3d11_4.h>
#include <vector>
#include <mutex>

namespace chil::gfx::d11
{
	class IDevice : public gfx::IDevice
	{
	public:
		virtual void Execute(Microsoft::WRL::ComPtr<ID3D11CommandList> pCommandList) = 0;
		virtual Microsoft::WRL::ComPtr<ID3D11DeviceContext> CreateDeferredContext() = 0;
		virtual Microsoft::WRL::ComPtr<IDXGISwapChain1> CreateSwapChain(HWND hWnd, spa::DimensionsI size) = 0;
		virtual Microsoft::WRL::ComPtr<ID3D11RenderTargetView> CreateRenderTargetView(ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc) = 0;
	};

	class Device : public IDevice
	{
	public:
		Device();
		~Device() = default;
		void Execute(Microsoft::WRL::ComPtr<ID3D11CommandList> pCommandList) override;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> CreateDeferredContext() override;
		Microsoft::WRL::ComPtr<IDXGISwapChain1> CreateSwapChain(HWND hWnd, spa::DimensionsI size) override;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> CreateRenderTargetView(ID3D11Resource* pResource, const D3D11_RENDER_TARGET_VIEW_DESC* pDesc) override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> pDevice_;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> pImmediateContext_;
	};
}