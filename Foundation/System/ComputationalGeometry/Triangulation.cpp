#include "Triangulation.h"
#include "Convex.h"

using namespace sys;

Triangulation::Triangulation()
:m_nIndiceCount(0)
, m_nCount(0)
, m_pIndices(nullptr)
, m_pPoints(nullptr)
{
}

Triangulation::~Triangulation()
{
}

int Triangulation::getIndiceCount()
{
	return m_nIndiceCount;
}

int* Triangulation::getIndices()
{
	return m_pIndices;
}

bool Triangulation::lower(const Vector2& src, const Vector2& dest)
{
	return src.y < dest.y || (src.y == dest.y && src.x > dest.x);
}

bool Triangulation::upper(const Vector2& src, const Vector2& dest)
{
	return src.y > dest.y || (src.y == dest.y && src.x < dest.x);
}

Triangulation::Vertex Triangulation::vertexOfIndex(int index)
{
	Triangulation::Vertex vertex;
	vertex.index = index;
	vertex.type = VertexType::eRegular;

	Vector2 cur = m_pPoints[(index + m_nCount) % m_nCount];
	Vector2 before = m_pPoints[(index + m_nCount - 1) % m_nCount];
	Vector2 after = m_pPoints[(index + m_nCount + 1) % m_nCount];

	if (lower(before, cur) && lower(after, cur))
	{
		float sinVal = Vector2::getRotateAngle(cur - before, after - cur);
		if (sinVal < 180)
		{
			vertex.type = VertexType::eStart;
		}
		else
		{
			vertex.type = VertexType::eSplit;
		}
	}
	else if (upper(before, cur) && upper(after, cur))
	{
		float sinVal = Vector2::getRotateAngle(cur - before, after - cur);
		if (sinVal < 180)
		{
			vertex.type = VertexType::eEnd;
		}
		else
		{
			vertex.type = VertexType::eMerge;
		}
	}

	return vertex;
}

bool Triangulation::indicesOfPolygon(Vector2* points, int count)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	m_pPoints = points;
	m_nCount = count;



	return false;
}
