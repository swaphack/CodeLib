#include "Unit.h"
#include "Property.h"

int Unit::s_nID = 0;

Unit::Unit()
{
	m_pProperty = new Property();

	m_nID = ++s_nID;
}

Unit::~Unit()
{
	delete m_pProperty;
}

Property* Unit::getProperty()
{
	return m_pProperty;
}

void Unit::SetID(int nID)
{
	m_nID = nID;
}

int Unit::GetID()
{
	return m_nID;
}

void Unit::retain()
{
	m_nRefCount++;
}

void Unit::release()
{
	m_nRefCount--;
	if (m_nRefCount <= 0)
	{
		delete this;
	}
}
