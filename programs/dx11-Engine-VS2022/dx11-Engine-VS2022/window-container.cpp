#include "window-container.h"

LRESULT WindowContainer:: windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	OutputDebugStringA("Window Container Debug Window Proc\n");
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
