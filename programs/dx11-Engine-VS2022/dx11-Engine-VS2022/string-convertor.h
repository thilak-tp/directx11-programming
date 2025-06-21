#pragma once
#include <string>


class StringConvertor
{
public:
	// A function to convert a string to a wide string
	static std::wstring ToWString(const std::string& str);

	static std::string ToString(const std::wstring& wstr);
};