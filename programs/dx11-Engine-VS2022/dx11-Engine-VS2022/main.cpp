#include "render-window.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "DirectXTK.lib")

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
	
	RenderWindow rw;
	rw.initializeWindow(hInstance, "DirectX 11: Game Engine", "MyWindowClass", 800, 600);
	while (rw.processMessages() == true) {
		Sleep(50);
	}
	return 0;
}