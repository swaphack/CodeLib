#include "ExtProperty.h"


ExtProperty::ExtProperty()
{

}

ExtProperty::~ExtProperty()
{

}

void ExtProperty::AddFixValue(int key, float value)
{
	SetFixValue(key, value + GetFixValue(key));
}

void ExtProperty::AddPercentValue(int key, float value)
{
	SetPercentValue(key, value + GetPercentValue(key));
}

void ExtProperty::SetFixValue(int key, float value)
{
	m_mapFixAttr[key] = value;
}

void ExtProperty::SetPercentValue(int key, float value)
{
	m_mapPercentAttr[key] = value;
}

float ExtProperty::GetFixValue(int key)
{
	if (m_mapFixAttr.find(key) == m_mapFixAttr.end())
	{
		return 0;
	}

	return m_mapFixAttr[key];
}

float ExtProperty::GetPercentValue(int key)
{
	if (m_mapPercentAttr.find(key) == m_mapPercentAttr.end())
	{
		return 0;
	}

	return m_mapPercentAttr[key];
}

float ExtProperty::GetValue(int key)
{
	float fixed = GetFixValue(key);
	float percent = GetPercentValue(key);

	return fixed * (1 + percent);
}

void ExtProperty::Clear()
{
	m_mapFixAttr.clear();
	m_mapPercentAttr.clear();
}