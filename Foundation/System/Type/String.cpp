#include "String.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include "../Stream/import.h"

#if _MSC_VER
#define snprintf _snprintf
#endif

using namespace sys;

String::String()
:_value(nullptr)
, _size(0)
{
	*this = "";
}

String::String(const String& value)
:String()
{
	*this = value;
}

String::String(const char* value)
:String()
{
	if (value == nullptr)
	{
		return;
	}

	_size = strlen(value) + 1;
	_value = StreamHelper::mallocStream((char*)value, _size);
}

String::String(const char* value, int count)
:String()
{
	if (value == nullptr)
	{
		return;
	}

	_size = count + 1;
	_value = StreamHelper::mallocStream(_size);
	memcpy(_value, value, count);
}

String::~String()
{
	StreamHelper::freeStream(_value);
}

String& String::operator=(const String& value)
{
	*this = value.getString();
	return *this;
}

String& String::operator=(const std::string& value)
{
	*this = value.c_str();
	return *this;
}

String& String::operator=(const char* value)
{
	StreamHelper::freeStream(_value);

	if (value == nullptr)
	{
		_size = 0;
		_value = nullptr;
	}
	else
	{
		_size = strlen(value) + 1;
		_value = StreamHelper::mallocStream((char*)value, _size);
	}

	return *this;
}

String String::operator+(const String& value)
{
	String temp = *this;
	temp.concat(value.getString());

	return temp;
}

String String::operator+(const std::string& value)
{
	String temp = *this;
	temp.concat(value.c_str());

	return temp;
}

String String::operator+(const char* value)
{
	String temp = *this;
	temp.concat(value);

	return temp;
}

String& String::concat(const char* value)
{
	if (value == nullptr)
	{
		return *this;
	}

	int count = strlen(value);

	int len = _size + count;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int i = 0; i < count; i++)
	{
		*(_value + offset + i) = *(value + i);
	}
	_size = len;
	return *this;
}

String& String::concat(const char* value1, const char* value2)
{
	if (value1 == nullptr && value2 == nullptr)
	{
		return *this;
	}
	else if (value1 == nullptr)
	{
		return this->concat(value2);
	}
	else if (value2 == nullptr)
	{
		return this->concat(value1);
	}

	int count1 = strlen(value1);
	int count2 = strlen(value2);

	int len = _size + count1 + count2;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int i = 0; i < count1; i++)
	{
		*(_value + offset + i) = *(value1 + i);
	}

	offset += count1;
	for (int i = 0; i < count2; i++)
	{
		*(_value + offset + i) = *(value2 + i);
	}

	_size = len;
	return *this;
}

String& String::concat(const char* value1, const char* value2, const char* value3)
{
	if (value1 == nullptr && value2 == nullptr && value3 == nullptr)
	{
		return *this;
	}
	else if (value1 == nullptr)
	{
		return this->concat(value2, value3);
	}
	else if (value2 == nullptr)
	{
		return this->concat(value1, value3);
	}
	else if (value3 == nullptr)
	{
		return this->concat(value1, value2);
	}

	int count1 = strlen(value1);
	int count2 = strlen(value2);
	int count3 = strlen(value3);

	int len = _size + count1 + count2 + count3;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int i = 0; i < count1; i++)
	{
		*(_value + offset + i) = *(value1 + i);
	}

	offset += count1;
	for (int i = 0; i < count2; i++)
	{
		*(_value + offset + i) = *(value2 + i);
	}

	offset += count2;
	for (int i = 0; i < count3; i++)
	{
		*(_value + offset + i) = *(value3 + i);
	}

	_size = len;
	return *this;
}

bool String::contains(const char* value)
{
	if (value == nullptr && _value != nullptr)
	{
		return false;
	}

	int len = strlen(value);
	int i = 0;
	int index = 0;
	char tempChar = 0;
	int offset = -1;

	while (index < _size)
	{
		for (i = 0; i < len; i++)
		{
			tempChar = *(_value + index + i);
			if (tempChar == *value)
			{
				offset = index + i;
			}
			if (*(value + i) != tempChar)
			{
				break;
			}
		}

		if (i == len)
		{
			return true;
		}
		
		if (offset != -1)
		{
			index = offset + 1;
		}
		else
		{
			index++;
		}
		
		offset = -1;
	}

	return false;
}


bool String::compare(const char* value)
{
	return this->compare(0, value);
}

bool String::compare(int offset, const char* value)
{
	if (value == nullptr && _value != nullptr)
	{
		return false;
	}
	if (this->getSize() != strlen(value))
	{
		return false;
	}
	return this->compare(0, value, strlen(value));
}

bool String::compare(int offset, const char* value, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (*(_value + offset + i) != *(value + i))
		{
			return false;
		}
	}

	return true;
}

bool String::endWith(const char* value)
{
	if (_value == nullptr && value == nullptr)
	{
		return true;
	}

	if (value == nullptr)
	{
		return false;
	}

	int len = strlen(value) + 1;
	if (len	 > _size)
	{
		return false;
	}

	for (int i = 0; i < len; i ++)
	{
		if (*(_value + _size - 1  - i) != *(value + len - 1 - i))
		{
			return false;
		}
	}

	return true;
}

bool String::startWith(const char* value)
{
	if (_value == nullptr && value == nullptr)
	{
		return true;
	}

	if (value == nullptr)
	{
		return false;
	}

	int len = strlen(value);
	if (len > _size)
	{
		return false;
	}

	for (int i = 0; i < len; i++)
	{
		if (*(_value +  i) != *(value +  i))
		{
			return false;
		}
	}

	return true;
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
	if (offset >= _size || offset < 0)
	{
		return *this;
	}

	int i = 0;
	while (offset + i < _size)
	{
		if (offset + count + i >= _size)
		{
			*(_value + offset + i) = '\0';
		}
		else
		{
			*(_value + offset + i) = *(_value + offset + count + i);
		}
		i++;
	}

	_size = _size - count;

	return *this;
}

String& String::insert(int offset, const char* value)
{
	if (offset >= _size || offset < 0)
	{
		return *this;
	}
	int len = strlen(value);
	int totalLen = len + _size;
	char* temp = nullptr;
	temp = StreamHelper::mallocStream(totalLen, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int i = 0;

	while (i < _size - offset)
	{
		*(_value + totalLen - 1 - i) = *(_value + _size - 1 - i);
		i++;
	}

	for (i = 0; i < len; i++)
	{
		*(_value + offset + i) = *(value + i);
	}
	_size = totalLen;
	return *this;
}

String String::subString(int offset, int count)
{
	if (offset >= _size)
	{
		return String(nullptr);
	}

	if (offset + count >= _size)
	{
		count = _size - offset;
	}
	String str = String(_value + offset, count);
	return str;
}

String& String::trim()
{
	this->trimLeft();
	this->trimRight();

	return *this;
}

String& String::trimLeft()
{
	char* ptr = _value;
	while (*ptr == ' ')
	{
		ptr++;
	}

	_size = _size - (ptr - _value);
	_value = ptr;

	return *this;
}

String& String::trimRight()
{
	char* ptr = _value + _size - 1;
	while (*ptr == ' ')
	{
		*ptr = 0;
		ptr--;
	}

	_size = _size - (_value + _size - 1 - ptr);
	_value = _value;

	return *this;
}

String& String::make(const char* format, ...)
{
	StreamHelper::freeStream(_value);

	va_list ap;
	va_start(ap, format);
	_size = _vscprintf(format, ap) + 1;
	_value = StreamHelper::mallocStream(_size);
	vsprintf(_value, format, ap);
	va_end(ap);

	return *this;
}

void String::split(char spot, std::vector<String>& dest)
{
	char* ptr = _value;
	int offset = 0;
	int count = 0;
	while (offset + count <= _size)
	{
		if (*(ptr + offset + count) == spot || offset + count == _size)
		{
			String str(ptr + offset, count);
			dest.push_back(str);
			offset = count + offset + 1;
			count = 0;
		}
		else
		{
			count++;
		}
	}
}

void String::split(const char* spot, std::vector<String>& dest)
{
	char* ptr = _value;
	int len = strlen(spot);
	int offset = 0;
	int count = 0;
	int i = 0;
	int beginIndex = -1;
	char tempChar = 0;
	while (offset + count <= _size)
	{
		if (offset + count == _size)
		{
			String str(ptr + offset, count);
			dest.push_back(str);
			offset = count + offset + 1;
			count = 0;
		}
		else
		{
			for (i = 0; i < len; i++)
			{
				tempChar = *(_value + offset + count + i);
				if (tempChar == *spot)
				{
					beginIndex = i;
				}
				if (*(spot + i) != tempChar)
				{
					if (beginIndex != -1)
					{
						count += beginIndex + 1;
					}
					else
					{
						count++;
					}
					break;
				}
			}

			if (i == len)
			{
				String str(ptr + offset, count);
				dest.push_back(str);
				offset = count + offset + len;
				count = 0;
			}
		}
	}
}

bool String::empty()
{
	return this->compare("") || _value == nullptr;
}

const char* String::getString() const
{
	return _value;
}

int String::getSize() const
{
	if (_size == 0)
	{
		return 0;
	}
	return _size - 1;
}