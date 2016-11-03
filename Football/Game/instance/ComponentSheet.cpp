#include "ComponentSheet.h"

#include "../interface/IComponent.h"

using namespace game;

ComponentSheet::ComponentSheet()
{

}

ComponentSheet::~ComponentSheet()
{
	this->removeAllComponents();
}

IComponent* ComponentSheet::getComponent(const char* pszType)
{
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.find(pszType);
	if (iter != m_mComponents.end())
	{
		return iter->second;
	}

	return nullptr;
}

void ComponentSheet::addComponent(IComponent* pComponent)
{
	if (pComponent == nullptr)
	{
		return;
	}
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.find(pComponent->getType());
	if (iter != m_mComponents.end())
	{
		return;
	}

	m_mComponents[pComponent->getType()] = pComponent;
}

void ComponentSheet::removeComponent(const char* pszType)
{
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.find(pszType);
	if (iter != m_mComponents.end())
	{
		delete iter->second;
		m_mComponents.erase(iter);
	}
}

void ComponentSheet::removeAllComponents()
{
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		delete iter->second;
		iter++;
	}

	m_mComponents.clear();
}

void ComponentSheet::foreach(std::function<void(IComponent*)> handler)
{
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		handler(iter->second);
		iter++;
	}
}

IComponentSheet* ComponentSheet::clone()
{
	ComponentSheet* pSheet = new ComponentSheet();
	std::map<std::string, IComponent*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		pSheet->addComponent(iter->second->clone());
		iter++;
	}

	return pSheet;
}
