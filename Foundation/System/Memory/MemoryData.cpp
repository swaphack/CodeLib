#include "MemoryData.h"
#include "Base/macros.h"
#include <cstring>
using namespace sys;

MemoryData::MemoryData()
{

}

MemoryData::MemoryData(size_t length, const char* value, uint32_t typeSize)
{
	this->init(length, value, typeSize);
}

MemoryData::MemoryData(size_t length, const int8_t* value)
{
	this->init(length, value);
}

MemoryData::MemoryData(size_t length)
{
	this->init(length);
}

MemoryData::~MemoryData()
{
	this->clear();
}

void MemoryData::clear()
{
	SAFE_FREE(_value);
	_length = 0;
	_typeSize = 0;
}

size_t MemoryData::getSize() const
{
	return _length * _typeSize;
}

size_t MemoryData::getLength() const
{
	return _length;
}

const char* MemoryData::getValue() const
{
	return _value;
}

char MemoryData::getValue(size_t index) const
{
	ASSERT(index < _length && index >= 0);

	return _value[index];
}

char& MemoryData::getValue(size_t index)
{
	ASSERT(index < _length && index >= 0);

	return _value[index];
}

uint32_t MemoryData::getTypeSize() const
{
	return _typeSize;
}

char* MemoryData::getPtr(size_t offset /*= 0*/) const
{
	if (offset >= _length)
	{
		return nullptr;
	}

	return _value + offset * _typeSize;
}

MemoryData::MemoryData(const MemoryData& value)
{
	this->init(value.getLength(), value.getValue(), value.getTypeSize());
}

MemoryData::MemoryData(size_t length, const char* value)
{
	this->init(length, value);
}

MemoryData::MemoryData(size_t length, const uint8_t* value)
{
	this->init(length, value);
}

void MemoryData::init(size_t len, const void* value, uint32_t typeSize)
{
	this->clear();
	uint32_t size = typeSize * len;
	_typeSize = typeSize;
	_length = len;
	_value = (char*)malloc(size);
	if (value)
	{
		memcpy(_value, value, size);
	}
}

void MemoryData::init(size_t len, const char* value)
{
	this->init(len, value, sizeof(char));
}

void MemoryData::init(size_t len)
{
	this->init(len, nullptr, 1);
}

void MemoryData::init(size_t len, const double* value)
{
	this->init(len, value, sizeof(double));
}

void MemoryData::init(size_t len, const float* value)
{
	this->init(len, value, sizeof(float));
}

void MemoryData::init(size_t len, const uint32_t* value)
{
	this->init(len, value, sizeof(uint32_t));
}

void MemoryData::init(size_t len, const int32_t* value)
{
	this->init(len, value, sizeof(int32_t));
}

void MemoryData::init(size_t len, const uint16_t* value)
{
	this->init(len, value, sizeof(uint16_t));
}

void MemoryData::init(size_t len, const int16_t* value)
{
	this->init(len, value, sizeof(int16_t));
}

void MemoryData::init(size_t len, const uint8_t* value)
{
	this->init(len, value, sizeof(uint8_t));
}

void MemoryData::init(size_t len, const int8_t* value)
{
	this->init(len, value, sizeof(int8_t));
}

void MemoryData::set(size_t offset, int size, const char* value)
{
	ASSERT((offset + size <= _length) && (offset + size > 0));

	memcpy(_value + offset, value, size);
}

void MemoryData::insert(size_t offset, int size, const char* value)
{
	if (offset >= _length)
	{
		offset = _length;
	}
	size_t length = _length + size;
	char* val = (char*)malloc(length);

	uint32_t s1 = offset;
	memcpy(val, _value, s1);
	memcpy(val + s1, value, size);
	memcpy(val + s1 + size, _value + offset, _length - offset);

	this->clear();

	_value = val;
	_length = length;
	_typeSize = 1;
}

void MemoryData::remove(size_t offset, int size)
{
	ASSERT(offset >= _length);

	size_t length = _length - size;
	char* val = (char*)malloc(length);

	uint32_t s1 = offset;
	memcpy(val, _value, s1);
	memcpy(val + s1, _value + offset + size, length);

	this->clear();

	_value = val;
	_length = length;
	_typeSize = 1;
}

void MemoryData::resize(size_t len)
{
	char* val = (char*)malloc(len);
	memcpy(val, _value, _length);

	this->clear();

	_value = val;
	_length = len;
	_typeSize = 1;
}

