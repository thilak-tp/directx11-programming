#include "window-container.h"


bool RenderWindow::initializeWindow(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height) {
	// 
	this->hInstance = hInstance;
	this->windowTitle = windowTitle;
	this->windowClass = windowClass;
	this->width = width;
	this->height = height;
	this->wideWindowClass = StringConvertor::ToWString(windowClass);
	this->wideWindowTitle = StringConvertor::ToWString(windowTitle);

	this->registerWindowClass();
	this->handle = CreateWindowEx(0, 
		wideWindowClass.c_str(), 
		wideWindowTitle.c_str(), 
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 
		0,0,
		this->width, 
		this->height, 
		NULL, 
		NULL, 
		this->hInstance, 
		NULL);
	if (!this->handle) {
		ErrorLogger::Log(GetLastError(), "Window Creation failed for Window" + this->windowTitle);
		return false;
	}
	ShowWindow(this->handle, SW_SHOW);
	SetForegroundWindow(this->handle);
	SetFocus(this->handle);
	
	return true;
}

LRESULT CALLBACK windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	unsigned char letter;
	unsigned char keyCode;

	switch (uMsg) {
	case WM_CHAR: 
		letter = static_cast<unsigned char> (wParam); 
		return 0;
	case WM_KEYDOWN: 
		keyCode = static_cast<unsigned char> (lParam); 
		return 0;
	default: 
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	
}

void RenderWindow::registerWindowClass() {
	WNDCLASSEX wc; // This is to be filled before Window creation
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;//Redraw when width, height change
	wc.lpfnWndProc = windowProc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = this->hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.lpszClassName = this->wideWindowClass.c_str();
	wc.hbrBackground = NULL;
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	RegisterClassExW(&wc); // Register the window class
}

RenderWindow::~RenderWindow() {
	if (this->handle != NULL) {
		UnregisterClass(this->wideWindowClass.c_str(), this->hInstance);
		DestroyWindow(this->handle);
	}
}

bool RenderWindow::processMessages() {
	
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG)); //Initialize the msg structure
	// We use PeekMessage instead of GetMessage since PeekMessage is non blocking
	if (PeekMessage(&msg,
		this->handle,
		0, 0,
		PM_REMOVE
	)) {
		TranslateMessage(&msg);// Translate msg
		DispatchMessage(&msg);// Dispatch msg to our Window Proc
	}

	// Check if the window was closed
	if (msg.message == WM_NULL) {
		if (!IsWindow(this->handle)) {
			this->handle = NULL;
			UnregisterClass(this->wideWindowClass.c_str(), this->hInstance);
			return false;
		}
	}
	return true;
}