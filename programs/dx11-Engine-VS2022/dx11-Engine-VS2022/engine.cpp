#include "engine.h"

// Initialize window class and create a window
bool Engine::initialize(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height) {
	return this->renderWindow.initializeWindow(this, hInstance, windowTitle, windowClass, width, height);
}

// Process messages from the window
bool Engine::processMessages() {
	return this->renderWindow.processMessages();
}