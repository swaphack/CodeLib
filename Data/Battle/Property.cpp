#include "Property.h"

Property::Property()
{

}

Property::~Property()
{

}

float Property::GetValue(int key)
{
	if (m_mapAttr.find(key) != m_mapAttr.end())
	{
		return m_mapAttr[key];
	}

	return 0;
}

void Property::SetValue(int key, float value)
{
	m_mapAttr[key] = value;
}


void Property::AddValue(int key, float value)
{
	SetValue(key, value + GetValue(key));
}

void Property::Clear()
{
	m_mapAttr.clear();
}
