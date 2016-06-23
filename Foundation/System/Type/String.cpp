#include "String.h"

#ifdef USE_STRING

#include "../Stream/import.h"

using namespace sys;

String::String(const char* value)
:_value(nullptr)
, _size(0)
{
	if (value == nullptr)
	{
		return;
	}

	*this = value;
}

String::~String()
{
	StreamHelper::freeStream(_value);
}

String& String::operator=(const char* value)
{
	_size = strlen(value);
	_value = StreamHelper::mallocStream((char*)value, _size);
}

String& String::concat(const char* value)
{
	return *this;
}

bool String::compare(const char* value)
{
	return strcmp(_value, value) == 0;
}

bool String::endWith(const char* value)
{
	
}

bool String::startWith(const char* value)
{

}

char String::operator[](uint index)
{
	if (index >= _size)
	{
		return 0;
	}

	return _value[index];
}

String& String::remove(int offset, int count)
{

}

String& String::insert(int offset, const char* value)
{

}

String String::subString(int offset, int count)
{

}

String& String::trim()
{

}

String& String::trimLeft()
{

}

String& String::trimRight()
{

}

String& String::format(const char* format, ...)
{
}

void String::split(char spot, std::vector<String>& dest)
{

}

const char* String::getString()
{

}

uint String::getSize()
{

}

#endif