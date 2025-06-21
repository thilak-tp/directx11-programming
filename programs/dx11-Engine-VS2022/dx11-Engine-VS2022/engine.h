#pragma once
#include "window-container.h"
class Engine : WindowContainer {

public:
	// Initialize window class and create a window
	bool initialize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height);
	// Process messages from the window
	bool processMessages();
};
