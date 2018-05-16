#pragma once
#include "pch.h"

class WindowSystem;

class GraphicsSystem
{
public:
	// �ݵ�� WindowsSystem�� Initialize�� ���� �����ؾ� �մϴ�.
	bool Initialize(WindowSystem* _window);
	bool Terminate();

	// Get Method.
	IWICImagingFactory* GetiFactory() const;
	ID2D1HwndRenderTarget* GetRT() const;

public:
	// �� Class�� Singleton Class�Դϴ�.
	static GraphicsSystem* Instance();

private:
	ID2D1Factory* m_d2dFactory = nullptr;
	IWICImagingFactory* m_iFactory = nullptr;
	ID2D1SolidColorBrush* m_cb = nullptr;
	ID2D1HwndRenderTarget* m_rt = nullptr;

private:
	static GraphicsSystem* m_Instance;
};