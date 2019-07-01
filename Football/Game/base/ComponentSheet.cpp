#include "ComponentSheet.h"

#include "Component.h"

using namespace game;

ComponentSheet::ComponentSheet()
{

}

ComponentSheet::~ComponentSheet()
{
	this->removeAllChildren();
}

Component* ComponentSheet::getChild(const char* pszType)
{
	if (pszType == nullptr)
	{
		return nullptr;
	}

	std::map<std::string, Component*>::iterator iter = m_mapChildren.find(pszType);
	if (iter != m_mapChildren.end())
	{
		return iter->second;
	}

	return nullptr;
}

bool ComponentSheet::addChild(Component* pComponent)
{
	if (pComponent == nullptr)
	{
		return false;
	}
	return addChild(pComponent->getType(), pComponent);
}

bool ComponentSheet::addChild(const char* pszType, Component* pComponent)
{
	if (pszType == nullptr || pComponent == nullptr)
	{
		return false;
	}
	std::map<std::string, Component*>::iterator iter = m_mapChildren.find(pszType);
	if (iter != m_mapChildren.end())
	{
		return false;
	}

	m_mapChildren[pszType] = pComponent;

	return true;
}

void ComponentSheet::removeChild(const char* pszType)
{
	std::map<std::string, Component*>::iterator iter = m_mapChildren.find(pszType);
	if (iter != m_mapChildren.end())
	{
		delete iter->second;
		m_mapChildren.erase(iter);
	}
}

void ComponentSheet::removeAllChildren()
{
	std::map<std::string, Component*>::iterator iter = m_mapChildren.begin();
	while (iter != m_mapChildren.end())
	{
		delete iter->second;
		iter++;
	}

	m_mapChildren.clear();
}

void ComponentSheet::foreach(const std::function<void(Component*)>& handler)
{
	std::map<std::string, Component*>::iterator iter = m_mapChildren.begin();
	while (iter != m_mapChildren.end())
	{
		handler(iter->second);
		iter++;
	}
}

ComponentSheet* ComponentSheet::clone()
{
	ComponentSheet* pSheet = new ComponentSheet();
	std::map<std::string, Component*>::iterator iter = m_mapChildren.begin();
	while (iter != m_mapChildren.end())
	{
		pSheet->addChild(iter->second->clone());
		iter++;
	}

	return pSheet;
}

void ComponentSheet::setParent(Component* parent)
{
	m_pParent = parent;
}

Component* ComponentSheet::getParent()
{
	return m_pParent;
}
