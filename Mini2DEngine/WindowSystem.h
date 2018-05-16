#pragma once
#include "pch.h"

class WindowSystem
{
public:
	WindowSystem();

public:
	bool Initialize();
	bool Terminate();

	// Get Method.
	const HWND GetHWND() const;

private:
	static LRESULT CALLBACK WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);
	LRESULT HandleEvent(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);
	const POINT GetWindowPosition() const;

private:
	HDC m_hHC = nullptr;
	HWND m_hWnd = nullptr;
	HINSTANCE m_hInst = nullptr;

	std::tstring m_className = _T("2DEngine");
	std::tstring m_title = _T("2DEngine");

	RECT m_rc = { 0, 0, 1280, 720 };
	int m_format = 0;

private:
	// 한 객체만 생성됩니다.
	static bool m_isCreate;
};