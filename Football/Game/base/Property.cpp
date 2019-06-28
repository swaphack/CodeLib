#include "Property.h"

using namespace game;

Property::Property() 
{

}

Property::~Property()
{

}

void Property::setValue(const std::string& nType, bool value)
{
	this->setValue(nType, &value, sizeof(bool));
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
	m_mapValues[nType] = ValueItem(ptr, size);
}

#define GET_VALUE(nType, value) \
	{ \
		void* src = nullptr; \
		size_t size = 0; \
		if (getValue(nType, src, size)) \
		{ \
			return false; \
		} \
		memcpy(&value, src, size); \
		return true; \
	}

bool Property::getValue(const std::string& nType, bool& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, int8_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, uint8_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, int16_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, uint16_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, int32_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, uint32_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, int64_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, uint64_t& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, float& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, double& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, std::string& value)
{
	GET_VALUE(nType, value);
}

bool Property::getValue(const std::string& nType, void* src, size_t& size)
{
	auto it = m_mapValues.find(nType);
	if (it == m_mapValues.end())
	{
		return false;
	}

	src = it->second.ptr;
	size = it->second.size;

	return true;
}

void Property::setValue(const std::string& nType, const ValueItem& item)
{
	this->setValue(nType, item.ptr, item.size);
}

void Property::setValues(const std::map<std::string, Property::ValueItem>& values)
{
	for (auto it = values.begin(); it != values.end(); it++)
	{
		this->setValue(it->first, it->second);
	}
}

const std::map<std::string, Property::ValueItem>& Property::getValues()
{
	return m_mapValues;
}

Property* Property::clone()
{
	Property* pProperty = new Property();
	pProperty->setValues(m_mapValues);
	return pProperty;
}