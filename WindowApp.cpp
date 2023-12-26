#include "WindowApp.h"

WindowApp::WindowApp(int width, int height, const char* name) : width(width), height(height),hInstance(GetModuleHandle(nullptr)) {

	WNDCLASS wc = {};
	wc.lpfnWndProc = WinProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = windowName;
	RegisterClass(&wc);


	RECT winRect;
	winRect.left = 100;
	winRect.right = width + winRect.left;
	winRect.top = 100;
	winRect.bottom = height + winRect.top;
	AdjustWindowRect(&winRect, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

	hWnd = CreateWindow(windowName, name, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
		CW_USEDEFAULT, CW_USEDEFAULT, winRect.right - winRect.left, winRect.bottom - winRect.top,
		nullptr, nullptr, hInstance, this);

	ShowWindow(hWnd, SW_SHOWDEFAULT);

}

WindowApp::~WindowApp() {
	UnregisterClass(windowName, hInstance);
	DestroyWindow(hWnd);
}

LRESULT __stdcall WindowApp::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}