#pragma once
#include "render-window.h"
class WindowContainer {
protected:
	RenderWindow renderWindow;
public: 
	LRESULT windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

};