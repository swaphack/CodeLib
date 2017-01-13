#include "PropertySheet.h"

using namespace game;


PropertySheet::PropertySheet()
{

}

PropertySheet::~PropertySheet()
{
	this->removeAllProperties();
}

Property* PropertySheet::getProperty(int nPropertyType)
{
	Properties::const_iterator iter = m_mProperties.find(nPropertyType);
	if (iter == m_mProperties.end())
	{
		return nullptr;
	}

	return iter->second;
}

void PropertySheet::addProperty(Property* pProperty)
{
	if (pProperty == nullptr)
	{
		return;
	}

	m_mProperties[pProperty->getType()] = pProperty;
}

void PropertySheet::removeProperty(int nPropertyType)
{
	Properties::const_iterator iter = m_mProperties.find(nPropertyType);
	if (iter != m_mProperties.end())
	{
		delete iter->second;

		m_mProperties.erase(iter);
	}
}

void PropertySheet::removeAllProperties()
{
	Properties::iterator iter = m_mProperties.begin();
	while (iter != m_mProperties.end())
	{
		delete iter->second;
		iter++;
	}

	m_mProperties.clear();
}

void PropertySheet::foreach(const std::function<void(Property*)>& handler)
{
	Properties::iterator iter = m_mProperties.begin();
	while (iter != m_mProperties.end())
	{
		handler(iter->second);
		iter++;
	}
}

PropertySheet* PropertySheet::clone()
{
	PropertySheet* pSheet = new PropertySheet();
	Properties::iterator iter = m_mProperties.begin();
	while (iter != m_mProperties.end())
	{
		pSheet->addProperty(iter->second->clone());
		iter++;
	}

	return pSheet;
}
