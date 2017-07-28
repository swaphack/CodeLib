#include "VertexSet.h"
#include <vector>
#include <algorithm>

using namespace acg;

VertexSet::~VertexSet()
{

}

VertexSet::VertexSet()
{

}

int VertexSet::count()
{
	return m_vecPoint.size();
}

void VertexSet::add(const sys::Vector2& point)
{
	m_vecPoint.push_back(point);
}

void VertexSet::remove(const sys::Vector2& point)
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

sys::Vector2* VertexSet::toArray()
{
	int count = m_vecPoint.size();
	sys::Vector2* pVectex = new sys::Vector2[count];
	for (int i = 0; i < count; i++)
	{
		pVectex[i] = m_vecPoint[i];
	}

	return pVectex;
}

sys::Vector2& VertexSet::operator[](int index)
{
	if (index < 0 || index >= m_vecPoint.size())
	{
		ASSERT(false);
	}

	return m_vecPoint[index];
}

sys::Vector2* VertexSet::head()
{
	if (m_vecPoint.size() == 0)
	{
		return nullptr;
	}

	return &(*this)[0];
}

sys::Vector2* VertexSet::tail()
{
	if (m_vecPoint.size() == 0)
	{
		return nullptr;
	}

	return &(*this)[m_vecPoint.size() - 1];
}

void VertexSet::append(const VertexSet& second)
{
	VertexSet* pVer = (VertexSet*)&second;
	for (int i = 0; i < pVer->count(); i++)
	{
		this->add((*pVer)[i]);
	}
}
