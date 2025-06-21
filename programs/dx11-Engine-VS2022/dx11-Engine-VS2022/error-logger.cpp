#include "error-logger.h"
//Used for error reporting
#include<comdef.h>

void ErrorLogger::Log(std::string msg) {
	std::string errorMsg = "Error: " + msg;
	MessageBoxA(NULL, errorMsg.c_str(), "Error", MB_ICONERROR);
}

void ErrorLogger::Log(HRESULT hr, std::string msg) {
	_com_error error(hr);
	std::wstring errorMsg = L"Error: " + std::wstring(error.ErrorMessage()) + L"\n" + StringConvertor::ToWString(msg) + L"\n";
	MessageBoxW(NULL, errorMsg.c_str(), L"Error", MB_ICONERROR);
}