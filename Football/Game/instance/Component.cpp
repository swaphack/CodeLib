#include "Component.h"

using namespace game;

Component::Component()
{
	m_pComponentSheet = new ComponentSheet();
}

Component::~Component()
{
	delete m_pComponentSheet;
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

ComponentSheet* Component::getComponentSheet()
{
	return m_pComponentSheet;
}