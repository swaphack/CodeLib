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

float Component::getPropertyValue(int key)
{
	Property* pProperty = getPropertySheet()->getProperty(key);
	if (!pProperty)
	{
		return 0;
	}

	return pProperty->getValue();
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

bool Component::addComponent(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	return this->getComponentSheet()->addComponent(pComponent);
}

Component* Component::getComponent(const char* name)
{
	if (name == nullptr)
	{
		return false;
	}

	return this->getComponentSheet()->getComponent(name);
}

bool Component::copyTo(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	getPropertySheet()->foreach([&](Property* target){
		Property* pProperty = pComponent->getPropertySheet()->getProperty(target->getType());
		if (pProperty == nullptr)
		{
			pProperty = target->clone();
			pComponent->getPropertySheet()->addProperty(pProperty);
		}
		// 复制属性值
		pProperty->setValue(target->getValue());
		pProperty->setChangedHandler(target->getChangedHandler());
	});
	getComponentSheet()->foreach([&](Component* target){
		Component* pChild = pComponent->getComponentSheet()->getComponent(target->getType());
		if (pChild == nullptr)
		{
			pChild = target->clone();
			pComponent->getComponentSheet()->addComponent(pChild);
		}
		// 复制属性值和子组件
		target->copyTo(pChild);
	});

	return true;
}

bool Component::copy(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	pComponent->copyTo(this);

	return true;
}

PropertySheet* Component::getPropertySheet()
{
	return m_pPropertySheet;
}

ComponentSheet* Component::getComponentSheet()
{
	return m_pComponentSheet;
}