#pragma once
#include "string-convertor.h"
#include <windows.h>
class ErrorLogger
{
public:
	// A function to log a string
	static void Log(std::string msg);
	// A function to log a string with HRESULT error code
	static void Log(HRESULT hr, std::string msg);
};