#include "MemoryData.h"
#include "Base/macros.h"
#include <cstring>
using namespace sys;

sys::MemoryData::MemoryData()
{

}

sys::MemoryData::MemoryData(uint32_t length, const int8_t* value, uint32_t unitSize)
{
	this->init(length, value, unitSize);
}

sys::MemoryData::MemoryData(uint32_t length, const int8_t* value)
{
	this->init(length, value);
}

sys::MemoryData::MemoryData(uint32_t length)
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

uint32_t sys::MemoryData::getSize() const
{
	return _length * _uintSize;
}

uint32_t sys::MemoryData::getLength() const
{
	return _length;
}

const int8_t* sys::MemoryData::getValue() const
{
	return _value;
}

uint32_t sys::MemoryData::getUnitSize() const
{
	return _uintSize;
}

int8_t* sys::MemoryData::getPtr(int offset /*= 0*/) const
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

void sys::MemoryData::init(uint32_t len, const void* value, uint32_t unitSize)
{
	this->clear();
	_uintSize = unitSize;
	_length = len;
	_value = (int8_t*)malloc(len * unitSize);
	if (value)
	{
		memcpy(_value, value, len * unitSize);
	}
}

void sys::MemoryData::init(uint32_t len, const char* value)
{
	this->init(len, value, sizeof(char));
}

void sys::MemoryData::init(uint32_t len)
{
	this->init(len, nullptr, 1);
}

void sys::MemoryData::init(uint32_t len, const double* value)
{
	this->init(len, value, sizeof(double));
}

void sys::MemoryData::init(uint32_t len, const float* value)
{
	this->init(len, value, sizeof(float));
}

void sys::MemoryData::init(uint32_t len, const uint32_t* value)
{
	this->init(len, value, sizeof(uint32_t));
}

void sys::MemoryData::init(uint32_t len, const int32_t* value)
{
	this->init(len, value, sizeof(int32_t));
}

void sys::MemoryData::init(uint32_t len, const uint16_t* value)
{
	this->init(len, value, sizeof(uint16_t));
}

void sys::MemoryData::init(uint32_t len, const int16_t* value)
{
	this->init(len, value, sizeof(int16_t));
}

void sys::MemoryData::init(uint32_t len, const uint8_t* value)
{
	this->init(len, value, sizeof(uint8_t));
}

void sys::MemoryData::init(uint32_t len, const int8_t* value)
{
	this->init(len, value, sizeof(int8_t));
}

