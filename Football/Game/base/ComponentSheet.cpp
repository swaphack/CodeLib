#include "ComponentSheet.h"

#include "Component.h"

using namespace game;

ComponentSheet::ComponentSheet()
{

}

ComponentSheet::~ComponentSheet()
{
	this->removeAllComponents();
}

Component* ComponentSheet::getComponent(const char* pszType)
{
	if (pszType == nullptr)
	{
		return nullptr;
	}
	std::map<std::string, Component*>::iterator iter = m_mComponents.find(pszType);
	if (iter != m_mComponents.end())
	{
		return iter->second;
	}

	return nullptr;
}

bool ComponentSheet::addComponent(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}
	return addComponent(pComponent->getType(), pComponent);
}

bool ComponentSheet::addComponent(const char* pszType, Component* pComponent)
{
	if (pszType == nullptr || pComponent == nullptr)
	{
		return false;
	}
	std::map<std::string, Component*>::iterator iter = m_mComponents.find(pszType);
	if (iter != m_mComponents.end())
	{
		return false;
	}

	m_mComponents[pszType] = pComponent;

	return true;
}

void ComponentSheet::removeComponent(const char* pszType)
{
	std::map<std::string, Component*>::iterator iter = m_mComponents.find(pszType);
	if (iter != m_mComponents.end())
	{
		delete iter->second;
		m_mComponents.erase(iter);
	}
}

void ComponentSheet::removeAllComponents()
{
	std::map<std::string, Component*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		delete iter->second;
		iter++;
	}

	m_mComponents.clear();
}

void ComponentSheet::foreach(std::function<void(Component*)> handler)
{
	std::map<std::string, Component*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		handler(iter->second);
		iter++;
	}
}

ComponentSheet* ComponentSheet::clone()
{
	ComponentSheet* pSheet = new ComponentSheet();
	std::map<std::string, Component*>::iterator iter = m_mComponents.begin();
	while (iter != m_mComponents.end())
	{
		pSheet->addComponent(iter->second->clone());
		iter++;
	}

	return pSheet;
}
