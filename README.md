# DirectX11 - Graphics Programming
![screenshot](resources/dx11logo.svg)
This repo contains me learning Directx11 Graphics Programming

### What is DirectX11?
- DirectX 11 is a collection of APIs (Application Programming Interfaces) developed by Microsoft that allows software, particularly games, to interact directly with hardware, specifically graphics cards and sound cards, on Windows operating systems

### Getting started with the Engine Programming
programs/dx11-Engine-VS2022 is the DirectX Game Engine Project by which i would be trying to Grasp the Graphics pipeline and programming.

#### Project Tracker
21st June 2025
- A class called StringConvertor in which i wrote two static functions, one to convert string to wstring that is wide string and the other to convert the wstring to string. This would mostly be required since a lot of strings used by Windows APIs in general.

- A class called ErrorLogger in which i wrote two static functions. One that takes only a string as a msg and the other that takes a HRESULT value that would be used to catch error messages from the windows that are created as well as a string
```
#include<comdef.h>
void ErrorLogger::Log(HRESULT hr, std::string msg) {
	_com_error error(hr);
	std::wstring errorMsg = L"Error: " + std::wstring(error.ErrorMessage()) + L"\n" + StringConvertor::ToWString(msg) + L"\n";
	MessageBoxW(NULL, errorMsg.c_str(), L"Error", MB_ICONERROR);
}
```
Here we are using the comdef for the _com_error class that will resolve the error hr that we get from windows into an error message that we used to print the error message in a MessageBox