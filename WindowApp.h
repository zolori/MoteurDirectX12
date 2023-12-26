#pragma once
#include <Windows.h>
#include <optional>

class WindowApp {
public:
	WindowApp(int width, int heigth, const char* name);
	~WindowApp();
	// static std::optional<uint32_t> ProcessMessage();

private:
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	int width;
	int height;
	HWND hWnd;
	const char* windowName = "Stone Engine";
	HINSTANCE hInstance;
};