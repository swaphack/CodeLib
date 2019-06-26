#include "String.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include "Stream/import.h"
#include <cctype>

#if _MSC_VER
#define snprint32f _snprint32f
#endif

using namespace sys;

String::String()
:_value(nullptr)
, _size(0)
{
	*this = "";
}

String::String(const String& value)
:_value(nullptr)
, _size(0)
{
	*this = value;
}

String::String(const std::string& value)
:_value(nullptr)
, _size(0)
{
	*this = value;
}

String::String(const char* value)
:_value(nullptr)
, _size(0)
{
	ASSERT(value != nullptr);

	*this = value;
}

String::String(const char* value, int32 count)
:_value(nullptr)
, _size(0)
{
	ASSERT(value != nullptr);

	*this = std::string(value, count);
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
	ASSERT(value != nullptr);

	StreamHelper::freeStream(_value);

	_size = strlen(value) + 1;
	_value = StreamHelper::mallocStream((char*)value, _size);

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
	if (value == nullptr)
	{
		return *this;
	}

	String temp = *this;
	temp.concat(value);

	return temp;
}

char String::operator[](int32 index)
{
	if (index >= _size || index < 0)
	{
		return 0;
	}

	return _value[index];
}

char& String::at(int32 index)
{
	if (index >= _size || index < 0)
	{
		ASSERT(false);
	}

	return _value[index];
}

// 尾部追加字符
void String::append(int32 count, char value)
{
	char str[2] = { "A" };
	for (int32 i = 0; i < count; i++)
	{
		str[0] = value;
		this->concat(str);
	}
}
void String::append(int32 count, char* value)
{
	if (value == nullptr)
	{
		return;
	}

	for (int32 i = 0; i < count; i++)
	{
		this->concat(value);
	}
}
String String::replace(char spot, char* value)
{
	String str;

	char* ptr = _value;
	while (*ptr != 0)
	{
		if (*ptr == spot)
		{
			str.append(1, value);
		}
		else
		{
			str.append(1, *ptr);
		}

		ptr++;
	}

	return str;
}

String String::replace(char* spot, char* value)
{
	String str;
	int32 len = strlen(spot);
	char* ptr = _value;
	while (*ptr != 0)
	{
		if (this->compare(ptr - _value, spot, len))
		{
			str.append(1, value);
			ptr += len;
		}
		else
		{
			str.append(1, *ptr);
			ptr++;
		}
	}

	return str;
}

String& String::concat(const char* value)
{
	if (value == nullptr)
	{
		return *this;
	}

	int32 count = strlen(value);

	int32 len = _size + count;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int32 offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int32 i = 0; i < count; i++)
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

	int32 count1 = strlen(value1);
	int32 count2 = strlen(value2);

	int32 len = _size + count1 + count2;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int32 offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int32 i = 0; i < count1; i++)
	{
		*(_value + offset + i) = *(value1 + i);
	}

	offset += count1;
	for (int32 i = 0; i < count2; i++)
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

	int32 count1 = strlen(value1);
	int32 count2 = strlen(value2);
	int32 count3 = strlen(value3);

	int32 len = _size + count1 + count2 + count3;

	char* temp = StreamHelper::mallocStream(len, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int32 offset = _size - 1;
	if (offset < 0)
	{
		offset = 0;
	}
	for (int32 i = 0; i < count1; i++)
	{
		*(_value + offset + i) = *(value1 + i);
	}

	offset += count1;
	for (int32 i = 0; i < count2; i++)
	{
		*(_value + offset + i) = *(value2 + i);
	}

	offset += count2;
	for (int32 i = 0; i < count3; i++)
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

	int32 len = strlen(value);
	int32 i = 0;
	int32 index = 0;
	char tempChar = 0;
	int32 offset = -1;

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

bool String::compare(int32 offset, const char* value)
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

bool String::compare(int32 offset, const char* value, int32 count)
{
	for (int32 i = 0; i < count; i++)
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

	int32 len = strlen(value) + 1;
	if (len	 > _size)
	{
		return false;
	}

	for (int32 i = 0; i < len; i ++)
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

	int32 len = strlen(value);
	if (len > _size)
	{
		return false;
	}

	for (int32 i = 0; i < len; i++)
	{
		if (*(_value +  i) != *(value +  i))
		{
			return false;
		}
	}

	return true;
}

String& String::remove(int32 offset, int32 count)
{
	if (offset >= _size || offset < 0)
	{
		return *this;
	}

	int32 i = 0;
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

String& String::insert(int32 offset, const char* value)
{
	if (offset >= _size || offset < 0)
	{
		return *this;
	}
	int32 len = strlen(value);
	int32 totalLen = len + _size;
	char* temp = nullptr;
	temp = StreamHelper::mallocStream(totalLen, _value, _size);
	StreamHelper::freeStream(_value);
	_value = temp;

	int32 i = 0;

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

String String::subString(int32 offset, int32 count)
{
	if (offset >= _size)
	{
		return String(nullptr);
	}

	if (offset + count >= _size)
	{
		count = _size - offset;
	}
	return String(_value + offset, count);
}


int32 String::findFirstOf(char value)
{
	int32 offset = 0;

	for (; offset < getSize(); offset++)
	{
		if (*(_value + offset) == value)
		{
			break;
		}
	}

	if (offset == getSize())
	{
		return -1;
	}

	return offset;
}

int32 String::findFirstOf(const char* value)
{
	int32 offset = 0;
	int32 index = 0;
	int32 len = strlen(value);
	int32 i = 0;

	while (offset < getSize())
	{
		if (offset + len >= getSize())
		{
			return -1;
		}
		index = 0;
		for (i = 0; i < len; i++)
		{
			// 下一次索引位置
			if (*value == *(_value + offset + i))
			{
				index = i;
			}
			if (*(value + i) != *(_value + offset + i))
			{
				break;
			}
		}

		if (i == len)
		{
			return offset;
		}
		offset += index + 1;
	}

	if (offset >= getSize())
	{
		return -1;
	}

	return offset;
}

int32 String::findLastOf(char value)
{
	int32 offset = getSize() - 1;

	for (; offset >= 0; offset--)
	{
		if (*(_value + offset) == value)
		{
			break;
		}
	}

	if (offset == -1)
	{
		return -1;
	}

	return offset;
}

int32 String::findLastOf(const char* value)
{
	int32 offset = getSize() - 1;
	int32 index = 0;
	int32 len = strlen(value);
	int32 i = 0;

	while (offset >= 0)
	{
		if (offset - len < 0)
		{
			return -1;
		}
		index = 0;
		for (i = 0; i < len; i++)
		{
			// 下一次索引位置
			if (*(value + len - 1) == *(_value + offset - i))
			{
				index = i;
			}
			if (*(value + len - 1 - i) != *(_value + offset - i))
			{
				break;
			}
		}

		if (i == len)
		{
			return offset;
		}
		offset -= index + 1;
	}

	if (offset < 0)
	{
		return -1;
	}

	return offset;
}

bool String::isLine()
{
	return this->endWith(LINE_MARK);
}

String String::trim()
{
	String value = "";

	char* ptr = _value;
	char val;
	while (*ptr != 0)
	{
		val = *ptr;
		if (val != ' ')
		{
			value.append(1, val);
		}
		ptr++;
	}

	return value;
}

String String::trimLeft()
{
	String value = "";
	char* ptr = _value;
	while (*ptr == ' ')
	{
		ptr++;
	}

	value.append(1, ptr);

	return value;
}

String String::trimRight()
{
	char* ptr = _value + _size - 1;
	while (*ptr == ' ')
	{
		*ptr = 0;
		ptr--;
	}

	return String(_value, _size - (_value + _size - 1 - ptr));
}

String String::toLower()
{
	String text = getString();
	for (int32 i = 0; i < _size; i++)
	{
		text.at(i) = tolower(text.at(i));
	}
	return text;
}

String String::toUpper()
{
	String text = getString();
	for (int32 i = 0; i < _size; i++)
	{
		text.at(i) = toupper(text.at(i));
	}
	return text;
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
	int32 offset = 0;
	int32 count = 0;
	dest.clear();
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
	int32 len = strlen(spot);
	int32 offset = 0;
	int32 count = 0;
	int32 i = 0;
	int32 beginIndex = -1;
	char tempChar = 0;
	dest.clear();
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

void String::split(char spot, std::vector<std::string>& dest)
{
	char* ptr = _value;
	int32 offset = 0;
	int32 count = 0;
	dest.clear();
	while (offset + count <= _size)
	{
		if (*(ptr + offset + count) == spot || offset + count == _size)
		{
			std::string str(ptr + offset, count);
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

void String::split(const char* spot, std::vector<std::string>& dest)
{
	char* ptr = _value;
	int32 len = strlen(spot);
	int32 offset = 0;
	int32 count = 0;
	int32 i = 0;
	int32 beginIndex = -1;
	char tempChar = 0;
	dest.clear();
	while (offset + count <= _size)
	{
		if (offset + count == _size)
		{
			std::string str(ptr + offset, count);
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
				std::string str(ptr + offset, count);
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

String String::reverse()
{
	String value = *this;

	int32 half = _size / 2;
	char temp;
	for (int32 i = 0; i < half; i++)
	{
		temp = value[i];
		value.at(i) = value[_size - i];
		value.at(_size - i) = temp;
	}

	return value;
}

const char* String::getString() const
{
	return _value;
}

int32 String::getSize() const
{
	if (_size == 0)
	{
		return 0;
	}
	return _size - 1;
}