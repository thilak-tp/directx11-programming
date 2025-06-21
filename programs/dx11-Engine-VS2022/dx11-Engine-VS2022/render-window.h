#pragma once
#include "error-logger.h"

class RenderWindow {

	// Registering the WNDCLASSEX class
	void registerWindowClass();
	HWND handle = NULL;
	HINSTANCE hInstance = NULL;
	std::string windowTitle = "";
	std::wstring wideWindowTitle = L"";
	std::string windowClass = "";
	std::wstring wideWindowClass = L"";
	int width = 0;
	int height = 0;

public:
	// Initialize window class and create a window
	bool initializeWindow(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height);
	// Process messages from the window
	bool processMessages();
	// Unregister and destroy the window
	~RenderWindow();



};
