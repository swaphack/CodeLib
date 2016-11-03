#include "Property.h"

using namespace game;

Property::Property() 
:m_nType(0)
, m_nValue(0)
, m_pHandler(nullptr)
{

}

Property::~Property()
{

}


float Property::getValue() const
{
	return m_nValue;
}

void Property::setValue(float fValue)
{
	onChangedHandler(fValue);
	m_nValue = fValue;
}

int Property::getType() const
{
	return m_nType;
}

void Property::setType(int nType)
{
	m_nType = nType;
}

void Property::setChangedHandler(PropertyHandler handler)
{
	m_pHandler = handler;
}

void Property::onChangedHandler(float newValue)
{
	if (m_pHandler)
	{
		m_pHandler(m_nType, newValue, m_nValue);
	}
}

void Property::addValue(float value)
{
	onChangedHandler(m_nValue + value);
	m_nValue += value;
}

PropertyHandler Property::getChangedHandler()
{
	return m_pHandler;
}

Property* Property::clone()
{
	Property* pProperty = new Property();
	pProperty->setType(getType());
	pProperty->setValue(getValue());
	pProperty->setChangedHandler(getChangedHandler());
	return pProperty;
}
