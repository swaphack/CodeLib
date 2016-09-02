#include "Property.h"

using namespace game;

Property::~Property()
{

}

Property::Property() :m_type(0), m_value(0)
{

}


float Property::getValue()
{
	return m_value;
}

void Property::setValue(float fValue)
{
	m_value = fValue;
}

int Property::getType()
{
	return m_type;
}

void Property::setType(int nType)
{
	m_type = nType;
}