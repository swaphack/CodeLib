#include "TargetString.h"

using namespace search;

TargetString::TargetString(const char* text)
{
	
}

void TargetString::setString(const char* text)
{
	if (text == nullptr)
	{
		return;
	}

	_text = text;
}

const char* TargetString::getString()
{
	return _text.c_str();
}