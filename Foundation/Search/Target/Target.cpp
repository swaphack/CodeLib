#include "Target.h"

using namespace search;

StringTarget::StringTarget( const char* text )
{
	_text = "";
	this->setString(text);
}

void StringTarget::setString( const char* text )
{
	if (text == nullptr)
	{
		return;
	}

	_text = text;
}

const char* StringTarget::getString()
{
	return _text.c_str();
}
