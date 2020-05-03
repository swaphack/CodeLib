#include "MemoryData.h"
#include "Base/macros.h"
#include <cstring>
using namespace sys;

sys::MemoryData::MemoryData()
{

}

sys::MemoryData::MemoryData(size_t length, const int8_t* value, uint32_t unitSize)
{
	this->init(length, value, unitSize);
}

sys::MemoryData::MemoryData(size_t length, const int8_t* value)
{
	this->init(length, value);
}

sys::MemoryData::MemoryData(size_t length)
{
	this->init(length);
}

sys::MemoryData::~MemoryData()
{
	this->clear();
}

void sys::MemoryData::clear()
{
	SAFE_FREE(_value);
	_length = 0;
	_uintSize = 0;
}

size_t sys::MemoryData::getSize() const
{
	return _length * _uintSize;
}

size_t sys::MemoryData::getLength() const
{
	return _length;
}

const int8_t* sys::MemoryData::getValue() const
{
	return _value;
}

int8_t sys::MemoryData::getValue(size_t index) const
{
	ASSERT(index < _length && index >= 0);

	return _value[index];
}

int8_t& sys::MemoryData::getValue(size_t index)
{
	ASSERT(index < _length && index >= 0);

	return _value[index];
}

uint32_t sys::MemoryData::getUnitSize() const
{
	return _uintSize;
}

int8_t* sys::MemoryData::getPtr(size_t offset /*= 0*/) const
{
	if (offset >= _length)
	{
		return nullptr;
	}

	return _value + offset * _uintSize;
}

sys::MemoryData::MemoryData(const MemoryData& value)
{
	this->init(value.getLength(), value.getValue(), value.getUnitSize());
}

sys::MemoryData::MemoryData(size_t length, const char* value)
{
	this->init(length, value);
}

sys::MemoryData::MemoryData(size_t length, const uint8_t* value)
{
	this->init(length, value);
}

void sys::MemoryData::init(size_t len, const void* value, uint32_t unitSize)
{
	this->clear();
	uint32_t size = unitSize * len;
	_uintSize = unitSize;
	_length = len;
	_value = (int8_t*)malloc(size);
	if (value)
	{
		memcpy(_value, value, size);
	}
}

void sys::MemoryData::init(size_t len, const char* value)
{
	this->init(len, value, sizeof(char));
}

void sys::MemoryData::init(size_t len)
{
	this->init(len, nullptr, 1);
}

void sys::MemoryData::init(size_t len, const double* value)
{
	this->init(len, value, sizeof(double));
}

void sys::MemoryData::init(size_t len, const float* value)
{
	this->init(len, value, sizeof(float));
}

void sys::MemoryData::init(size_t len, const uint32_t* value)
{
	this->init(len, value, sizeof(uint32_t));
}

void sys::MemoryData::init(size_t len, const int32_t* value)
{
	this->init(len, value, sizeof(int32_t));
}

void sys::MemoryData::init(size_t len, const uint16_t* value)
{
	this->init(len, value, sizeof(uint16_t));
}

void sys::MemoryData::init(size_t len, const int16_t* value)
{
	this->init(len, value, sizeof(int16_t));
}

void sys::MemoryData::init(size_t len, const uint8_t* value)
{
	this->init(len, value, sizeof(uint8_t));
}

void sys::MemoryData::init(size_t len, const int8_t* value)
{
	this->init(len, value, sizeof(int8_t));
}

void sys::MemoryData::set(size_t offset, int size, const int8_t* value)
{
	ASSERT((offset + size <= _length) && (offset + size > 0));

	memcpy(_value + offset, value, size);
}

void sys::MemoryData::set(size_t offset, int size, const char* value)
{
	ASSERT((offset + size <= _length) && (offset + size > 0));

	memcpy(_value + offset, value, size);
}

void sys::MemoryData::insert(size_t offset, int size, const int8_t* value)
{
	size_t length = _length + size;
	int8_t* val = (int8_t*)malloc(length);

	uint32_t s1 = offset;
	memcpy(val, _value, s1);
	memcpy(val + s1, value, size);
	memcpy(val + s1 + size, _value + offset, _length - offset);

	this->clear();

	_value = val;
	_length = length;
	_uintSize = 1;
}

void sys::MemoryData::insert(size_t offset, int size, const char* value)
{
	if (offset >= _length)
	{
		offset = _length;
	}
	size_t length = _length + size;
	int8_t* val = (int8_t*)malloc(length);

	uint32_t s1 = offset;
	memcpy(val, _value, s1);
	memcpy(val + s1, value, size);
	memcpy(val + s1 + size, _value + offset, _length - offset);

	this->clear();

	_value = val;
	_length = length;
	_uintSize = 1;
}

void sys::MemoryData::remove(size_t offset, int size)
{
	ASSERT(offset >= _length);

	size_t length = _length - size;
	int8_t* val = (int8_t*)malloc(length);

	uint32_t s1 = offset;
	memcpy(val, _value, s1);
	memcpy(val + s1, _value + offset + size, length);

	this->clear();

	_value = val;
	_length = length;
	_uintSize = 1;
}

void sys::MemoryData::resize(size_t len)
{
	int8_t* val = (int8_t*)malloc(len);
	memcpy(val, _value, _length);

	this->clear();

	_value = val;
	_length = len;
	_uintSize = 1;
}

