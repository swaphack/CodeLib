#include "String.h"
#include "Stream/import.h"
#include "Base/macros.h"
#include "Memory/MemoryData.h"
#include <cstdarg>

#if _MSC_VER
#define snprint32f _snprint32f
#endif

using namespace sys;

String::String()
{
	this->initString(0, "");
}

String::String(const String& value)
{
	this->initString(value.getSize(), value.getString());
}

String::String(const std::string& value)
{
	this->initString(value.size(), value.c_str());
}

String::String(const char* value, size_t count)
{
	ASSERT(value != nullptr);

	this->initString(count, value);
}

String::String(const char* value, int32_t count)
{
	ASSERT(value != nullptr);

	this->initString(count, value);
}

String::~String()
{
	SAFE_DELETE(_data);
}

String& String::operator=(const String& value)
{
	this->initString(value.getSize(), value.getString());
	return *this;
}

String& String::operator=(const std::string& value)
{
	this->initString(value.size(), value.c_str());
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

char String::operator[](size_t index)
{
	ASSERT(index < getSize() && index >= 0);

	return _data->getValue(index);
}

char& String::at(size_t index)
{
	ASSERT(index < getSize() && index >= 0);

	return (char&)_data->getValue(index);
}

// 尾部追加字符
void String::append(size_t count, char value)
{
	char str[2] = { "A" };
	for (size_t i = 0; i < count; i++)
	{
		str[0] = value;
		this->concat(str);
	}
}
void String::append(size_t count, const std::string& value)
{
	for (size_t i = 0; i < count; i++)
	{
		this->concat(value);
	}
}
String String::replace(char spot, const std::string& value)
{
	String str;

	char* ptr = getString();
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

String String::replace(const std::string& spot, const std::string& value)
{
	String str;
	size_t len = spot.size();
	char* ptr = getString();
	while (*ptr != 0)
	{
		if (this->compare(ptr - getString(), spot, len))
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

String& String::concat(const std::string& value)
{
	size_t count = value.size();
	size_t len = getSize() + count;

	MemoryData data;
	allocString(len, data);
	data.set(0, getSize(), getString());
	data.set(getSize(), count, value.c_str());

	*_data = data;
	
	return *this;
}

String& String::concat(const std::string& value1, const std::string& value2)
{
	size_t count1 = value1.size();
	size_t count2 = value2.size();
	size_t len = getSize() + count1 + count2;

	MemoryData data;
	allocString(len, data);
	data.set(0, getSize(), getString());
	data.set(getSize(), count1, value1.c_str());
	data.set(getSize() + count1, count2, value2.c_str());

	*_data = data;

	return *this;
}

String& String::concat(const std::string& value1, const std::string& value2, const std::string& value3)
{
	size_t count1 = value1.size();
	size_t count2 = value2.size();
	size_t count3 = value3.size();

	size_t len = getSize() + count1 + count2 + count3;

	MemoryData data;
	allocString(len, data);
	data.set(0, getSize(), getString());
	data.set(getSize(), count1, value1.c_str());
	data.set(getSize() + count1, count2, value2.c_str());
	data.set(getSize() + count1 + count2, count3, value3.c_str());

	*_data = data;

	return *this;
}

bool String::contains(const std::string& value)
{
	if (getString() == nullptr || value.empty())
	{
		return false;
	}

	size_t len = value.size();
	size_t i = 0;
	size_t index = 0;
	char tempChar = 0;
	int32_t offset = -1;

	while (index < getSize())
	{
		for (i = 0; i < len; i++)
		{
			tempChar = *(getString() + index + i);
			if (tempChar == value.at(0))
			{
				offset = index + i;
			}
			if (value.at(i) != tempChar)
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


bool String::compare(const std::string& value)
{
	return this->compare(0, value);
}

bool String::compare(size_t offset, const std::string& value)
{
	if (this->getSize() != value.size())
	{
		return false;
	}
	return this->compare(0, value, value.size());
}

bool String::compare(size_t offset, const std::string& value, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		if (*(getString() + offset + i) != value.at(i))
		{
			return false;
		}
	}

	return true;
}

bool String::endWith(const std::string& value)
{
	if (value.empty())
	{
		return true;
	}

	size_t len = value.size();
	if (len	 > getSize())
	{
		return false;
	}

	for (size_t i = 0; i < len; i++)
	{
		if (*(getString() + getSize() - 1 - i) != value.at(len - 1 - i))
		{
			return false;
		}
	}

	return true;
}

bool String::startWith(const std::string& value)
{
	if (value.empty())
	{
		return true;
	}

	size_t len = value.size();
	if (len > getSize())
	{
		return false;
	}

	for (size_t i = 0; i < len; i++)
	{
		if (*(getString() +  i) != value.at(i))
		{
			return false;
		}
	}

	return true;
}

String& sys::String::removeAt(size_t offset)
{
	return this->remove(offset, 1);
}

sys::String sys::String::makeString(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	uint32_t size = _vscprintf(format, ap) + 1;
	MemoryData data(size);
	vsprintf(data.getPtr(), format, ap);
	va_end(ap);

	sys::String str(data.getValue(), data.getSize());
	return str;
}

String& String::remove(size_t offset, size_t count)
{
	if (offset >= getSize() || offset < 0)
	{
		return *this;
	}

	_data->remove(offset, count);

	return *this;
}

String& String::insert(size_t offset, const std::string& value)
{
	if (offset >= getSize() || offset < 0)
	{
		return *this;
	}

	_data->insert(offset, value.size(), value.c_str());
	
	return *this;
}

String String::subString(size_t offset, size_t count)
{
	if (offset >= getSize())
	{
		return String();
	}

	if (offset + count >= getSize())
	{
		count = getSize() - offset;
	}
	return String(getString() + offset, count);
}


int32_t String::findFirstOf(char value)
{
	int32_t offset = 0;

	for (; offset < getSize(); offset++)
	{
		if (*(getString() + offset) == value)
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

int32_t String::findFirstOf(const std::string& value)
{
	int32_t offset = 0;
	size_t index = 0;
	size_t len = value.size();
	size_t i = 0;

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
			if (value.at(0) == *(getString() + offset + i))
			{
				index = i;
			}
			if (value.at(i) != *(getString() + offset + i))
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

int32_t String::findLastOf(char value)
{
	int32_t offset = getSize() - 1;

	for (; offset >= 0; offset--)
	{
		if (*(getString() + offset) == value)
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

int32_t String::findLastOf(const std::string& value)
{
	int32_t offset = getSize() - 1;
	size_t index = 0;
	size_t len = value.size();
	size_t i = 0;

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
			if (value.at(len - 1) == *(getString() + offset - i))
			{
				index = i;
			}
			if (value.at(len - 1 - i) != *(getString() + offset - i))
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

	char* ptr = getString();
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
	char* ptr = getString();
	while (*ptr == ' ')
	{
		ptr++;
	}

	value.append(1, ptr);

	return value;
}

String String::trimRight()
{
	char* ptr = getString() + getSize() - 1;
	while (*ptr == ' ')
	{
		*ptr = 0;
		ptr--;
	}

	return String(getString(), getSize() - (getString() + getSize() - 1 - ptr));
}

String String::toLower()
{
	String text = getString();
	for (size_t i = 0; i < getSize(); i++)
	{
		text.at(i) = tolower(text.at(i));
	}
	return text;
}

String String::toUpper()
{
	String text = getString();
	for (size_t i = 0; i < getSize(); i++)
	{
		text.at(i) = toupper(text.at(i));
	}
	return text;
}

std::string String::makeCString(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	uint32_t size = _vscprintf(format, ap) + 1;
	MemoryData data(size);
	vsprintf(data.getPtr(), format, ap);
	va_end(ap);

	std::string str(data.getValue(), data.getSize() - 1);
	return str;
}

void String::split(char spot, std::vector<String>& dest)
{
	char* ptr = getString();
	size_t offset = 0;
	size_t count = 0;
	dest.clear();
	while (offset + count <= getSize())
	{
		if (*(ptr + offset + count) == spot || offset + count == getSize())
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

void String::split(const std::string& spot, std::vector<String>& dest)
{
	if (spot.empty())
	{
		return;
	}
	char* ptr = getString();
	size_t len = spot.size();
	int32_t offset = 0;
	size_t count = 0;
	size_t i = 0;
	int32_t beginIndex = -1;
	char tempChar = 0;
	dest.clear();
	while (offset + count <= getSize())
	{
		if (offset + count == getSize())
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
				tempChar = *(getString() + offset + count + i);
				if (tempChar == spot.at(0))
				{
					beginIndex = i;
				}
				if (spot.at(i) != tempChar)
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
	char* ptr = getString();
	int32_t offset = 0;
	size_t count = 0;
	dest.clear();
	while (offset + count <= getSize())
	{
		if (*(ptr + offset + count) == spot || offset + count == getSize())
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

void String::split(const std::string& spot, std::vector<std::string>& dest)
{
	if (spot.empty())
	{
		return;
	}
	char* ptr = getString();
	size_t len = spot.size();
	int32_t offset = 0;
	size_t count = 0;
	size_t i = 0;
	int32_t beginIndex = -1;
	char tempChar = 0;
	dest.clear();
	while (offset + count <= getSize())
	{
		if (offset + count == getSize())
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
				tempChar = *(getString() + offset + count + i);
				if (tempChar == spot.at(0))
				{
					beginIndex = i;
				}
				if (spot.at(i) != tempChar)
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
	return this->compare("") || getString() == nullptr;
}

String String::reverse()
{
	String value = *this;

	size_t half = getSize() / 2;
	char temp;
	for (size_t i = 0; i < half; i++)
	{
		temp = value[i];
		value.at(i) = value[getSize() - i];
		value.at(getSize() - i) = temp;
	}

	return value;
}

const char* String::getString() const
{
	return (const char*)_data->getValue();
}

char* String::getString()
{
	return _data->getPtr();
}

size_t String::getSize() const
{
	if (_data->getSize() == 0)
	{
		return 0;
	}
	return _data->getSize() - 1;
}

void sys::String::initString(size_t size, const char* value)
{
	if (_data == nullptr)
	{
		_data = new MemoryData(size + 1, value);
	}
	else
	{
		_data->init(size + 1, value);
	}

	_data->set(size, 1, "\0");
}

void sys::String::allocString(size_t size, MemoryData& data)
{
	data.resize(size + 1);
}
