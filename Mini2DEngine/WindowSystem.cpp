#include "pch.h"
#include "WindowSystem.h"

#include "GraphicsSystem.h"

WindowSystem::WindowSystem()
{
	assert(!m_isCreate);
	m_isCreate = true;
}



bool WindowSystem::Initialize()
{
	WNDCLASS wc;
	memset(&wc, NULL, sizeof(WNDCLASS));
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInst;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_className.c_str();

	if (RegisterClass(&wc) == FALSE) {
		return false;
	}

	m_hWnd = CreateWindowEx(0, m_className.c_str(), m_title.c_str(), 0 | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, GetWindowPosition().x, GetWindowPosition().y, m_rc.right - m_rc.left, m_rc.bottom - m_rc.top, NULL, NULL, m_hInst, this);

	if (m_hWnd == nullptr) {
		UnregisterClass(m_className.c_str(), m_hInst);
		return false;
	}

	m_hHC = GetDC(m_hWnd);

	if (m_hHC == nullptr) {
		DestroyWindow(m_hWnd);
		UnregisterClass(m_className.c_str(), m_hInst);
		return false;
	}

	PIXELFORMATDESCRIPTOR pfd = { sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0 };

	m_format = ChoosePixelFormat(m_hHC, &pfd);
	if (m_format == 0) {
		Terminate();
		return false;
	}
	if (SetPixelFormat(m_hHC, m_format, &pfd) == FALSE) {
		Terminate();
		return false;
	}

	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);

	return true;
}

bool WindowSystem::Terminate()
{
	ReleaseDC(m_hWnd, m_hHC);
	DestroyWindow(m_hWnd);
	UnregisterClass(m_className.c_str(), m_hInst);

	return true;
}



const HWND WindowSystem::GetHWND() const
{
	return m_hWnd;
}



LRESULT CALLBACK WindowSystem::WndProc(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	if (_msg == WM_CREATE) {
		CREATESTRUCT *pCS = (CREATESTRUCT*)_lParam;
		SetWindowLongPtr(_hWnd, GWLP_USERDATA, (LONG_PTR)pCS->lpCreateParams);
	}
	else {
		WindowSystem* window = (WindowSystem*)(GetWindowLongPtr(_hWnd, GWLP_USERDATA));
		if (window != nullptr) {
			return window->HandleEvent(_hWnd, _msg, _wParam, _lParam);
		}
	}
	return DefWindowProc(_hWnd, _msg, _wParam, _lParam);
}

LRESULT WindowSystem::HandleEvent(HWND _hWnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)
{
	switch (_msg)
	{
	case WM_SIZE:
		if (GraphicsSystem::Instance()->GetRT() != nullptr) {
			GraphicsSystem::Instance()->GetRT()->Resize(D2D1::SizeU(LOWORD(_lParam), HIWORD(_lParam)));
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return S_OK;
	}
	return DefWindowProc(_hWnd, _msg, _wParam, _lParam);
}

const POINT WindowSystem::GetWindowPosition() const
{
	long width = m_rc.right - m_rc.left;
	long height = m_rc.bottom - m_rc.top;

	return POINT{ GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2 };
}

bool WindowSystem::m_isCreate = false;