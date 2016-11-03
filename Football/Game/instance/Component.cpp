#include "Component.h"

using namespace game;

Component::Component()
{
	m_pPropertySheet = new PropertySheet();
	m_pComponentSheet = new ComponentSheet();
}

Component::~Component()
{
	delete m_pPropertySheet;
	delete m_pComponentSheet;
}

PropertySheet* Component::getPropertySheet()
{
	return m_pPropertySheet;
}

ComponentSheet* Component::getComponentSheet()
{
	return m_pComponentSheet;
}

void Component::addComponent(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return;
	}

	m_pComponentSheet->addComponent(pComponent);
}

IComponent* Component::clone()
{
	IComponent* pComponent = new Component();
	getPropertySheet()->foreach([&](Property* handler){
		Property* pProperty = handler->clone();
		pComponent->getPropertySheet()->addProperty(pProperty);
	});
	getComponentSheet()->foreach([&](IComponent* handler){
		IComponent* pComponent = handler->clone();
		pComponent->getComponentSheet()->addComponent(pComponent);
	});

	return pComponent;
}

void Component::setPropertyValue(int key, float value)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		pProperty = new Property();
		pProperty->setType(key);
	}

	pProperty->setValue(value);
}

void Component::setPropertyChangedHandler(int key, PropertyHandler handler)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		pProperty = new Property();
		pProperty->setType(key);
	}

	pProperty->setChangedHandler(handler);
}

float Component::getPropertyValue(int key)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		return 0;
	}

	return pProperty->getValue();
}
