#include "Property.h"
#include <stdlib.h>
#include "Stream/StreamWriter.h"
#include "Stream/StreamReader.h"

#define TEXT_MAX 1024

using namespace game;

Property::ValueItem Property::ValueItem::clone()
{
	ValueItem item;
	item.size = size;
	item.ptr = malloc(size);
	memcpy(item.ptr, this->ptr, this->size);
	return item;
}

Property::ValueItem::ValueItem(void* ptr, size_t size) :ptr(ptr), size(size)
{
	bPtr = false;
}

Property::ValueItem::ValueItem(void* ptr) : ptr(ptr)
{
	bPtr = true;
}

Property::ValueItem::ValueItem()
{
	bPtr = true;
}

Property::ValueItem::~ValueItem()
{
	if (ptr && !bPtr)
	{
		free(ptr);
	}
}

//////////////////////////////////////////////////////////////////////////
Property::Property() 
{

}

Property::~Property()
{
	this->clear();
}

void Property::setValue(const std::string& nType, bool value)
{
	int8_t temp = value ? 1 : 0;
	this->setValue(nType, &temp, sizeof(int8_t));
}

void Property::setValue(const std::string& nType, int8_t value)
{
	this->setValue(nType, &value, sizeof(int8_t));
}

void Property::setValue(const std::string& nType, uint8_t value)
{
	this->setValue(nType, &value, sizeof(uint8_t));
}

void Property::setValue(const std::string& nType, int16_t value)
{
	this->setValue(nType, &value, sizeof(int16_t));
}

void Property::setValue(const std::string& nType, uint16_t value)
{
	this->setValue(nType, &value, sizeof(uint16_t));
}

void Property::setValue(const std::string& nType, int32_t value)
{
	this->setValue(nType, &value, sizeof(int32_t));
}

void Property::setValue(const std::string& nType, uint32_t value)
{
	this->setValue(nType, &value, sizeof(uint32_t));
}

void Property::setValue(const std::string& nType, int64_t value)
{
	this->setValue(nType, &value, sizeof(int64_t));
}

void Property::setValue(const std::string& nType, uint64_t value)
{
	this->setValue(nType, &value, sizeof(uint64_t));
}

void Property::setValue(const std::string& nType, float value)
{
	this->setValue(nType, &value, sizeof(float));
}

void Property::setValue(const std::string& nType, double value)
{
	this->setValue(nType, &value, sizeof(double));
}

void Property::setValue(const std::string& nType, const std::string& value)
{
	if (value.size() == 0)
	{
		return;
	}
	this->setValue(nType, value.c_str(), strlen(value.c_str()));
}

void Property::setValue(const std::string& nType, const void* src, size_t size)
{
	if (src == nullptr)
	{
		return;
	}
	void* ptr = malloc(size);
	memcpy(ptr, src, size);
	m_mapValues[nType] = new ValueItem(ptr, size);
}

void Property::setValue(const std::string& nType, const ValueItem& item)
{
	this->setValue(nType, item.ptr, item.size);
}

void Property::setValue(const std::string& nType, void* ptr)
{
	m_mapValues[nType] = new ValueItem(ptr);
}

void Property::setValues(const std::map<std::string, Property::ValueItem*>& values)
{
	for (auto it = values.begin(); it != values.end(); it++)
	{
		this->setValue(it->first, *it->second);
	}
}

bool Property::getValue(const std::string& nType, bool value)
{
	int8_t temp = 0;
	temp = getValue(nType, temp);
	return temp != 0;
}

int8_t Property::getValue(const std::string& nType, int8_t value)
{
	return getArithmetic<int8_t>(nType, value);
}

uint8_t Property::getValue(const std::string& nType, uint8_t value)
{
	return getArithmetic<uint8_t>(nType, value);
}

int16_t Property::getValue(const std::string& nType, int16_t value)
{
	return getArithmetic<int16_t>(nType, value);
}

uint16_t Property::getValue(const std::string& nType, uint16_t value)
{
	return getArithmetic<uint16_t>(nType, value);
}

int32_t Property::getValue(const std::string& nType, int32_t value)
{
	return getArithmetic<int32_t>(nType, value);
}

uint32_t Property::getValue(const std::string& nType, uint32_t value)
{
	return getArithmetic<uint32_t>(nType, value);
}

int64_t Property::getValue(const std::string& nType, int64_t value)
{
	return getArithmetic<int64_t>(nType, value);
}

uint64_t Property::getValue(const std::string& nType, uint64_t value)
{
	return getArithmetic<uint64_t>(nType, value);
}

float Property::getValue(const std::string& nType, float value)
{
	return getArithmetic<float>(nType, value);
}

double Property::getValue(const std::string& nType, double value)
{
	return getArithmetic<double>(nType, value);
}

std::string Property::getValue(const std::string& nType, const std::string& value)
{
	auto it = m_mapValues.find(nType);
	if (it == m_mapValues.end())
	{
		return "";
	}
	return std::string((char*)it->second->ptr, it->second->size);
}

void* Property::getPtr(const std::string& nType, void* value /*= nullptr*/)
{
	auto it = m_mapValues.find(nType);
	if (it == m_mapValues.end())
	{
		return value;
	}

	return it->second->ptr;
}

bool Property::getPtr(const std::string& nType, void* &src, size_t& size)
{
	auto it = m_mapValues.find(nType);
	if (it == m_mapValues.end())
	{
		return false;
	}

	src = it->second->ptr;
	size = it->second->size;

	return true;
}

const std::map<std::string, Property::ValueItem*>& Property::getValues() const
{
	return m_mapValues;
}

Property* Property::clone()
{
	Property* pProperty = new Property();
	pProperty->setValues(m_mapValues);
	return pProperty;
}

void Property::clear()
{
	for (auto it = m_mapValues.begin(); it != m_mapValues.end(); it++)
	{
		delete it->second;
	}

	m_mapValues.clear();
}
