#include "Convex.h"
#include "VertexSet.h"
#include <vector>
#include <algorithm>

using namespace acg;


bool Convex::isConvex(const sys::Vector2* points, int count)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	int lastDirection = -1;

	for (int i = 0; i < count; i++)
	{
		sys::Vector2 p0 = points[(i + count) % count];
		sys::Vector2 p1 = points[(i + 1 + count) % count];
		sys::Vector2 p2 = points[(i + 2 + count) % count];

		sys::Vector2 v0 = p1 - p0;
		sys::Vector2 v1 = p2 - p1;

		int vd = sys::Vector2::direction(v0, v1);
		if (vd == 0)
		{
			return false;
		}

		if (lastDirection == -1)
		{
			lastDirection = vd;
		}
		else if (lastDirection != vd)
		{
			return false;
		}
	}

	return true;

}

bool Convex::makeSlowConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	std::vector<std::pair<sys::Vector2, sys::Vector2>> edges;

	bool bValid = true;

	for (int i = 0; i < count; i++)
	{
		sys::Vector2 p0 = points[(i + count) % count];
		sys::Vector2 p1 = points[(i + 1 + count) % count];

		bValid = true;

		for (int j = 0; j < count - 2;j++)
		{
			sys::Vector2 p2 = points[(i + 2 + j + count) % count];
			sys::Vector2 v0 = p1 - p0;
			sys::Vector2 v1 = p2 - p1;

			int vd = sys::Vector2::direction(v0, v1);
			if (vd == 1)
			{
				edges.push_back(std::make_pair(p0, p1));
			}
		}
	}

	if (edges.size() == 0)
	{
		return false;
	}

	vertexes.clear();

	// 先读取一条记录
	vertexes.add(edges[0].first);
	vertexes.add(edges[0].second);
	edges.erase(edges.begin());

	do 
	{
		if (edges.empty())
		{
			break;
		}

		bool bExist = false;
		sys::Vector2 last = *vertexes.tail();
		
		for (int i = 0; i < edges.size(); i++)
		{
			if (edges[i].first == last)
			{ // 首尾相连
				vertexes.add(edges[i].second);
				edges.erase(edges.begin() + i);
				bExist = true;
				break;
			}
		}
		if (!bExist)
		{
			return false;
		}
	} while (0);

	return true;
}

bool Convex::makeConvexHull(const sys::Vector2* points, int count, VertexSet& vertexes)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	sys::Vector2* pNewPoints = sortByAxisX(points, count);

	// 上包
	VertexSet& upper = vertexes;
	// 下包
	VertexSet lower;

	upper.add(pNewPoints[0]);
	upper.add(pNewPoints[1]);
	for (int i = 2; i < count; i++)
	{
		upper.add(pNewPoints[i]);
		int len = upper.count();
		while (len >= 3)
		{
			sys::Vector2& p0 = upper[len - 3];
			sys::Vector2& p1 = upper[len - 2];
			sys::Vector2& p2 = upper[len - 1];
			
			int result = sys::Vector2::direction(p1 - p0, p2 - p1);
			if (result == 2)
			{
				break;
			}

			upper.remove(len - 2);
			len = upper.count();
		}
	}

	lower.add(pNewPoints[count - 1]);
	lower.add(pNewPoints[count - 2]);

	for (int i = count - 3; i >= 0; i--)
	{
		lower.add(pNewPoints[i]);
		int len = lower.count();

		while (len >= 3)
		{
			sys::Vector2& p0 = lower[len - 3];
			sys::Vector2& p1 = lower[len - 2];
			sys::Vector2& p2 = lower[len - 1];

			int result = sys::Vector2::direction(p1 - p0, p2 - p1);
			if (result == 2)
			{
				break;
			}

			lower.remove(len - 2);
			len = lower.count();
		}
	}

	lower.remove(0);
	lower.remove(lower.count() - 1);

	upper.append(lower);

	return true;
}

sys::Vector2* Convex::sortByAxisX(const sys::Vector2* points, int count)
{
	if (points == nullptr || count <= 0)
	{
		return nullptr;
	}

	std::vector<sys::Vector2> vecPoints;

	for (int i = 0; i < count; i++)
	{
		vecPoints.push_back(points[i]);
	}

	std::sort(vecPoints.begin(), vecPoints.end(), [](const sys::Vector2 & m1, const sys::Vector2 & m2) {
		if (m1.x < m2.x) {
			return true;
		}
		else if (m1.x == m2.x)
		{
			return m1.y < m2.y;
		}
		else
		{
			return false;
		}
	});

	sys::Vector2* pNewPoints = new sys::Vector2[count];

	for (int i = 0; i < count; i++)
	{
		pNewPoints[i] = vecPoints[i];
	}

	return pNewPoints;
}

sys::Vector2* Convex::sortByAxisY(const sys::Vector2* points, int count)
{
	if (points == nullptr || count <= 0)
	{
		return nullptr;
	}

	std::vector<sys::Vector2> vecPoints;

	for (int i = 0; i < count; i++)
	{
		vecPoints.push_back(points[i]);
	}

	std::sort(vecPoints.begin(), vecPoints.end(), [](const sys::Vector2 & m1, const sys::Vector2 & m2) {
		if (m1.y > m2.y) {
			return true;
		}
		else if (m1.y == m2.y)
		{
			return m1.x < m2.x;
		}
		else
		{
			return false;
		}
	});

	sys::Vector2* pNewPoints = new sys::Vector2[count];

	for (int i = 0; i < count; i++)
	{
		pNewPoints[i] = vecPoints[i];
	}

	return pNewPoints;
}


