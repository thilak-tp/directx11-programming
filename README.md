# DirectX11 - Graphics Programming
![screenshot](resources/dx11logo.svg)
This repo contains me learning Directx11 Graphics Programming

### What is DirectX11?
- DirectX 11 is a collection of APIs (Application Programming Interfaces) developed by Microsoft that allows software, particularly games, to interact directly with hardware, specifically graphics cards and sound cards, on Windows operating systems

### Getting started with the Engine Programming
**programs/dx11-Engine-VS2022** is the DirectX Game Engine Project by which i would be trying to Grasp the Graphics pipeline and programming.

#### Project Tracker
21st June 2025
- A class called **StringConvertor** in which i wrote two static functions, one to convert string to wstring that is wide string and the other to convert the wstring to string. This would mostly be required since a lot of strings used by Windows APIs in general.
```
// A function to convert a string to a wide string
static std::wstring ToWString(const std::string& str);
// A function to convert a wide string to a string
static std::string ToString(const std::wstring& wstr);
```

- A class called **ErrorLogger** in which i wrote two static functions. One that takes only a string as a msg and the other that takes a HRESULT value that would be used to catch error messages from the windows that are created as well as a string
```
// A function to log a string
static void Log(std::string msg);
// A function to log a string with HRESULT error code
static void Log(HRESULT hr, std::string msg);
```
```
#include<comdef.h>
void ErrorLogger::Log(HRESULT hr, std::string msg) {
	_com_error error(hr);
	std::wstring errorMsg = L"Error: " + std::wstring(error.ErrorMessage()) + L"\n" + StringConvertor::ToWString(msg) + L"\n";
	MessageBoxW(NULL, errorMsg.c_str(), L"Error", MB_ICONERROR);
}
```
Here we are using the comdef.h header for the _com_error class that will resolve the error hr that we get from windows into an error message that we used to print the error message in a MessageBox
NOTE: if(FAILED(hr)) is used to check if the hr failed, if it did we can write the error log in the if condition. Similarly if(SUCCEEDED(hr)) checks if the hr succeeeded, and if so, we can write the success log in the if condition.

- A class called **RenderWindow** that would be used to create the window. It has a initializeWindow function to initialize the window properties and create a window and a processMessage function to handle the message related to that created window. A destructor to unregister and destroy the window
```
bool initializeWindow(HINSTANCE hInstance, std::string windowTitle, std::string windowClass, int width, int height);
bool processMessages();
~RenderWindow();
```
- We Define a Custum windowProc() function to handle msges. In which WM_CHAR: wParam can we used to get the character that was pressed, either capital or small while using WM_KEYDOWN lparam is used to check for key press and which key pressed ignoring the case. WM_CHAR is useful where letter case is to be used and WM_KEYDOWN can be used to check for the keypress for example characte movement.