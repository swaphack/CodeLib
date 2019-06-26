#include "PropertyComponent.h"

using namespace game;

PropertyComponent::PropertyComponent()
{

}

PropertyComponent::~PropertyComponent()
{

}

void PropertyComponent::setValue(int key, float value)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		pProperty = new Property();
		pProperty->setType(key);
		getPropertySheet()->addProperty(pProperty);
	}

	pProperty->setValue(value);
}

void PropertyComponent::setChangedHandler(int key, PropertyHandler handler)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		pProperty = new Property();
		pProperty->setType(key);
		getPropertySheet()->addProperty(pProperty);
	}

	pProperty->setChangedHandler(handler);
}

float PropertyComponent::getValue(int key)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		return 0;
	}

	return pProperty->getValue();
}


PropertySheet* PropertyComponent::getPropertySheet()
{
	return &m_PropertySheet;
}

