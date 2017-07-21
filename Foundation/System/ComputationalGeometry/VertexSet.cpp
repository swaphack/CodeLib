#include "VertexSet.h"
#include <vector>
#include <algorithm>

using namespace sys;


int VertexSet::count()
{
	return m_vecPoint.size();
}

void VertexSet::add(const Vector2& point)
{
	m_vecPoint.push_back(point);
}

void VertexSet::remove(const Vector2& point)
{
	for (int i = 0; i < m_vecPoint.size(); i++)
	{
		if (m_vecPoint[i] == point)
		{
			m_vecPoint.erase(m_vecPoint.begin() + i);
			return;
		}
	}
}

void VertexSet::remove(int index)
{
	if (index < 0 || index >= m_vecPoint.size())
	{
		return;
	}

	m_vecPoint.erase(m_vecPoint.begin() + index);
}

void VertexSet::clear()
{
	m_vecPoint.clear();
}

Vector2* VertexSet::toArray()
{
	int count = m_vecPoint.size();
	Vector2* pVectex = new Vector2[count];
	for (int i = 0; i < count; i++)
	{
		pVectex[i] = m_vecPoint[i];
	}

	return pVectex;
}

Vector2* VertexSet::operator[](int index)
{
	if (index < 0 || index >= m_vecPoint.size())
	{
		return nullptr;
	}

	return &m_vecPoint[index];
}

Vector2* VertexSet::head()
{
	if (m_vecPoint.size() == 0)
	{
		return nullptr;
	}

	return (*this)[0];
}

Vector2* VertexSet::tail()
{
	if (m_vecPoint.size() == 0)
	{
		return nullptr;
	}

	return (*this)[m_vecPoint.size() - 1];
}

void VertexSet::append(const VertexSet& second)
{
	VertexSet* pVer = (VertexSet*)&second;
	for (int i = 0; i < pVer->count(); i++)
	{
		this->add(*(*pVer)[i]);
	}
}