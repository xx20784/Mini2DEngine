#include "pch.h"
#include "GraphicsSystem.h"

#include "WindowSystem.h"

bool GraphicsSystem::Initialize(WindowSystem* _window)
{
	if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &m_d2dFactory))) {
		return false;
	}

	if (FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED))) {
		m_d2dFactory->Release();
		return false;
	}

	if (FAILED(CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_IWICImagingFactory, (LPVOID*)&m_iFactory))) {
		m_d2dFactory->Release();
		return false;
	}

	const HWND hWnd = _window->GetHWND();
	RECT rc;
	GetClientRect(hWnd, &rc);
	D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

	if (FAILED(m_d2dFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &m_rt))) {
		m_d2dFactory->Release();
		return false;
	}

	if (FAILED(m_rt->CreateSolidColorBrush((D2D1::ColorF) D2D1::ColorF::Black, &m_cb))) {
		m_rt->Release();
		m_d2dFactory->Release();
		return false;
	}

	return true;
}

bool GraphicsSystem::Terminate()
{
	m_d2dFactory->Release();
	m_iFactory->Release();
	m_cb->Release();
	m_rt->Release();

	return true;
}



IWICImagingFactory* GraphicsSystem::GetiFactory() const
{
	return m_iFactory;
}


ID2D1HwndRenderTarget* GraphicsSystem::GetRT() const
{
	return m_rt;
}



GraphicsSystem* GraphicsSystem::Instance()
{
	if (m_Instance == nullptr) {
		m_Instance = new GraphicsSystem();
		return m_Instance;
	}
	else {
		return m_Instance;
	}
}

GraphicsSystem* GraphicsSystem::m_Instance = nullptr;