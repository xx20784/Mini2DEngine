#pragma once
#include "pch.h"

class WindowSystem;

class GraphicsSystem
{
public:
	// 반드시 WindowsSystem의 Initialize를 먼저 실행해야 합니다.
	bool Initialize(WindowSystem* _window);
	bool Terminate();

	// Get Method.
	IWICImagingFactory* GetiFactory() const;
	ID2D1HwndRenderTarget* GetRT() const;

public:
	// 이 Class는 Singleton Class입니다.
	static GraphicsSystem* Instance();

private:
	ID2D1Factory* m_d2dFactory = nullptr;
	IWICImagingFactory* m_iFactory = nullptr;
	ID2D1SolidColorBrush* m_cb = nullptr;
	ID2D1HwndRenderTarget* m_rt = nullptr;

private:
	static GraphicsSystem* m_Instance;
};