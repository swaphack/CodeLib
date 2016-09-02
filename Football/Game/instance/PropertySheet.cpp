#include "PropertySheet.h"

using namespace game;


void PropertySheet::removeProperty(int nPropertyType)
{
	Properties::const_iterator iter = m_mProperties.find(nPropertyType);
	if (iter != m_mProperties.end())
	{
		delete iter->second;

		m_mProperties.erase(iter);
	}
}

void PropertySheet::addProperty(IProperty* pProperty)
{
	if (pProperty == nullptr)
	{
		return;
	}

	removeProperty(pProperty->getType());

	m_mProperties[pProperty->getType()] = pProperty;
}

const IProperty* PropertySheet::getProperty(int nPropertyType) const
{
	Properties::const_iterator iter = m_mProperties.find(nPropertyType);
	if (iter == m_mProperties.end())
	{
		return nullptr;
	}

	return iter->second;
}

PropertySheet::PropertySheet()
{

}

PropertySheet::~PropertySheet()
{
	Properties::iterator iter = m_mProperties.begin;
	while (iter == m_mProperties.end())
	{
		delete iter->second;
		iter++;
	}

	m_mProperties.clear();
}
