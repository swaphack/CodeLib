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

bool Component::copyTo(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	getPropertySheet()->foreach([&](Property* handler){
		Property* pProperty = pComponent->getPropertySheet()->getProperty(handler->getType());
		if (pProperty == nullptr)
		{
			pProperty = handler->clone();
			pComponent->getPropertySheet()->addProperty(pProperty);
		}
		// 复制属性
		pProperty->setValue(handler->getValue());
		pProperty->setChangedHandler(handler->getChangedHandler());
	});
	getComponentSheet()->foreach([&](IComponent* handler){
		IComponent* pChild = pComponent->getComponentSheet()->getComponent(handler->getType());
		if (pChild == nullptr)
		{
			pChild = handler->clone();
			pComponent->getComponentSheet()->addComponent(pChild);
		}
		// 复制属性
		handler->copyTo(pChild);
	});

	return true;
}

bool Component::copy(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	pComponent->copyTo(this);

	return true;
}

bool Component::addCloneComponent(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	return this->getComponentSheet()->addComponent(pComponent->clone());
}

bool Component::addComponent(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	return this->getComponentSheet()->addComponent(pComponent);
}

IComponent* Component::getComponent(const char* name)
{
	if (name == nullptr)
	{
		return false;
	}

	return this->getComponentSheet()->getComponent(name);
}

void Component::setPropertyValue(int key, float value)
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

void Component::setPropertyChangedHandler(int key, PropertyHandler handler)
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

float Component::getPropertyValue(int key)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		return 0;
	}

	return pProperty->getValue();
}