#include "Component.h"

using namespace game;

Component::Component()
{
	m_pComponentSheet = new ComponentSheet();
	m_pProperty = new Property();
}

Component::~Component()
{
	delete m_pComponentSheet;
	delete m_pProperty;
}

bool Component::addComponent(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}

	pComponent->getComponentSheet()->setParent(this);
	
	return this->getComponentSheet()->addChild(pComponent);
}

void Component::removeComponent(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return;
	}

	pComponent->getComponentSheet()->setParent(nullptr);

	this->getComponentSheet()->removeChild(pComponent->getType());
}

Component* Component::getComponent(const char* name)
{
	if (name == nullptr)
	{
		return false;
	}

	if (this->getComponentSheet()->getParent() != nullptr)
	{
		auto item = this->getComponentSheet()->getParent()->getComponent(name);
		if (item)
		{
			return item;
		}
	}

	return this->getComponentSheet()->getChild(name);
}

void Component::removeAllComponents()
{
	this->getComponentSheet()->removeAllChildren();
}

bool Component::copyTo(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}
	pComponent->getProperty()->setValues(getProperty()->getValues());

	getComponentSheet()->foreach([&](Component* target){
		Component* pChild = pComponent->getComponent(target->getType());
		if (pChild == nullptr)
		{
			pChild = target->clone();
			pComponent->addComponent(pChild);
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

ComponentSheet* Component::getComponentSheet()
{
	return m_pComponentSheet;
}

Property* Component::getProperty()
{
	return m_pProperty;
}
