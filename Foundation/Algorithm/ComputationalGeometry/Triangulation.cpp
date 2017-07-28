#include "Triangulation.h"
#include "Convex.h"

using namespace acg;

// 临时二叉树
static std::map<int, Edge> m_mapTemporaryEdge;

Triangulation::Triangulation()
{
	m_pIndices[3] = nullptr;
}

Triangulation::~Triangulation()
{
	SAFE_DELETE_ARRAY(m_pIndices[3]);
}

bool Triangulation::lower(const sys::Vector2& src, const sys::Vector2& dest)
{
	return src.y < dest.y || (src.y == dest.y && src.x > dest.x);
}

bool Triangulation::upper(const sys::Vector2& src, const sys::Vector2& dest)
{
	return src.y > dest.y || (src.y == dest.y && src.x < dest.x);
}

VertexInfo Triangulation::typeOfVertex(int index, const sys::Vector2* points, int count)
{
	VertexInfo vertex;
	vertex.index = index;
	vertex.point = points[index];
	vertex.type = VertexType::eRegular;

	sys::Vector2 cur = points[(index + count) % count];
	sys::Vector2 before = points[(index + count - 1) % count];
	sys::Vector2 after = points[(index + count + 1) % count];

	if (lower(before, cur) && lower(after, cur))
	{
		float sinVal = sys::Vector2::getRotateAngle(cur - before, after - cur);
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
		float sinVal = sys::Vector2::getRotateAngle(cur - before, after - cur);
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

int Triangulation::getNearEdge(const sys::Vector2& point)
{
	int index = -1;
	float distance = 0;
	std::map<int, Edge>::iterator it = m_mapTemporaryEdge.begin();
	while (it != m_mapTemporaryEdge.end())
	{
		Edge& pCurEdge = it->second;
		if (pCurEdge.isVertex(point) || !pCurEdge.onLeftSide(point))
		{
			it++;
			continue;
		}
		else if (index == -1)
		{
			index = it->first;
			distance = pCurEdge.distance(point);
		}
		else
		{
			float d = pCurEdge.distance(point);
			if (d < distance)
			{
				index = it->first;
				distance = d;
			}
		}
		it++;
	}

	return index;
}

bool Triangulation::hasRightVertex(const sys::Vector2& point, const sys::Vector2* points, int count)
{
	if (points == nullptr || count == 0)
	{
		return false; 
	}

	for (int i = 0; i < count; i++)
	{
		sys::Vector2 curPoint = points[i];

		if (curPoint == point)
		{
			continue;
		}

		if (curPoint.x > point.x)
		{
			return true;
		}
	}
	
	return false;
}

void Triangulation::addAuxiliaryEdge(const sys::Vector2& src, const sys::Vector2& dest)
{
	Edge newEdge(src, dest);
	m_setAuxiliaryEdges.push_back(newEdge);
}

void Triangulation::removeTemporaryEdge(int index)
{
	if (m_mapTemporaryEdge.size() < 0)
	{
		return;
	}
	if (m_mapTemporaryEdge.find(index) != m_mapTemporaryEdge.end())
	{
		m_mapTemporaryEdge.erase(index);
	}
}

void Triangulation::addTemporaryEdge(int index, const Edge& edge)
{
	if (m_mapTemporaryEdge.size() > 0)
	{
		if (m_mapTemporaryEdge.find(index) != m_mapTemporaryEdge.end())
		{
			m_mapTemporaryEdge.erase(index);
		}
	}
	
	m_mapTemporaryEdge.insert(std::pair<int, Edge>(index, edge));
}

bool Triangulation::indicesOfPolygon(const sys::Vector2* points, int count)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}
	
	m_setAuxiliaryEdges.clear();
	m_mapTemporaryEdge.clear();

	SAFE_DELETE_ARRAY(m_pIndices[3]);

	sys::Vector2* pSortPoints = Convex::sortByAxisY(points, count);

	VertexInfo* pVertexInfo = new VertexInfo[count]; // 顶点信息
	Edge* pVertexEdge = new Edge[count]; // 顶点与边关联信息
	int* pHelpInfo = new int[count]; // 边，顶点辅助
	memset(pHelpInfo, -1, sizeof(int)* count);

	for (int k = 0; k < count; k++)
	{
		int i = -1;
		for (int j = 0; j < count; j++)
		{
			if (pSortPoints[k] == points[j])
			{
				i = j;
			}
		}
		int lastIndex = (i - 1 + count) % count;
		int nextIndex = (i + 1 + count) % count;

		const sys::Vector2& point = points[i];
		const sys::Vector2& lastPoint = points[lastIndex];
		const sys::Vector2& nextPoint = points[nextIndex];

		Edge edge(points[i], nextPoint);
		pVertexEdge[i] = edge;

		VertexInfo info = typeOfVertex(i, points, count);
		pVertexInfo[i] = info;

		printf("%d\t%d\t", i, info.type);
		printf("%f,%f\r\n", point.x, point.y);

		if (info.type == VertexType::eStart)
		{
			addTemporaryEdge(i, edge);
			pHelpInfo[i] = i;
		}
		else if (info.type == VertexType::eEnd)
		{
			int nLastVertexIndex = pHelpInfo[lastIndex];
			if (nLastVertexIndex != -1)
			{
				const sys::Vector2& lastVertex = points[nLastVertexIndex];
				VertexInfo& pLastVertexInfo = pVertexInfo[nLastVertexIndex];
				if (pLastVertexInfo.type == VertexType::eMerge)
				{
					addAuxiliaryEdge(point, lastVertex);
				}
			}

			removeTemporaryEdge(lastIndex);
		}
		else if (info.type == VertexType::eRegular)
		{
			if (!hasRightVertex(point, points, count))
			{
				continue;
			}
			int nLastVertexIndex = pHelpInfo[lastIndex];
			if (nLastVertexIndex != -1)
			{
				VertexInfo& pLastVertexInfo = pVertexInfo[nLastVertexIndex];
				if (pLastVertexInfo.type == VertexType::eMerge)
				{
					addAuxiliaryEdge(point, points[nLastVertexIndex]);
					removeTemporaryEdge(lastIndex);
					addTemporaryEdge(i, edge);
					pHelpInfo[i] = i;
				}
				else
				{
					int nNearEdgeIndex = getNearEdge(point);
					if (nNearEdgeIndex != -1)
					{
						int nearVertexIndex = pHelpInfo[nNearEdgeIndex];
						if (nearVertexIndex != -1)
						{
							VertexInfo& pNearVertexInfo = pVertexInfo[nearVertexIndex];
							if (pNearVertexInfo.type == VertexType::eMerge)
							{
								addAuxiliaryEdge(point, points[nearVertexIndex]);
							}
						}
						pHelpInfo[nNearEdgeIndex] = i;
					}
				}
			}
		}
		else if (info.type == VertexType::eSplit)
		{
			int nNearEdgeIndex = getNearEdge(point);
			if (nNearEdgeIndex != -1)
			{
				int nearVertexIndex = pHelpInfo[nNearEdgeIndex];
				if (nearVertexIndex != -1)
				{
					addAuxiliaryEdge(point, points[nearVertexIndex]);

					pHelpInfo[nNearEdgeIndex] = i;

					addTemporaryEdge(i, edge);
					pHelpInfo[i] = i;
				}
			}
		}
		else if (info.type == VertexType::eMerge)
		{
			int nLastVertexIndex = pHelpInfo[lastIndex];
			if (nLastVertexIndex != -1)
			{
				const sys::Vector2& lastVertex = points[nLastVertexIndex];
				VertexInfo& pLastVertexInfo = pVertexInfo[nLastVertexIndex];
				if (pLastVertexInfo.type == VertexType::eMerge)
				{
					addAuxiliaryEdge(point, lastVertex);
				}
			}

			removeTemporaryEdge(lastIndex);

			int nNearEdgeIndex = getNearEdge(point);
			if (nNearEdgeIndex != -1)
			{
				int nearVertexIndex = pHelpInfo[nNearEdgeIndex];
				VertexInfo& pNearVertexInfo = pVertexInfo[nearVertexIndex];
				if (pNearVertexInfo.type == VertexType::eMerge)
				{
					addAuxiliaryEdge(point, points[nearVertexIndex]);
				}
				pHelpInfo[nNearEdgeIndex] = i;
			}
		}
	}

	printf("Auxiliary Edge\r\n");
	for (int i = 0; i < m_setAuxiliaryEdges.size(); i++)
	{
		printf("%d.(%f, %f)-(%f, %f)\r\n", i,
			m_setAuxiliaryEdges[i].start.x, m_setAuxiliaryEdges[i].start.y,
			m_setAuxiliaryEdges[i].end.x, m_setAuxiliaryEdges[i].end.y);
	}


	return false;
}
