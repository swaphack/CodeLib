#include "Convex.h"
#include "VertexSet.h"
#include <vector>
#include <algorithm>

using namespace sys;


bool Convex::isConvex(Vector2* points, int count)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	int lastDirection = -1;

	for (int i = 0; i < count; i++)
	{
		Vector2 p0 = points[(i + count) % count];
		Vector2 p1 = points[(i + 1 + count) % count];
		Vector2 p2 = points[(i + 2 + count) % count];

		Vector2 v0 = p1 - p0;
		Vector2 v1 = p2 - p1;

		int vd = Vector2::direction(v0, v1);
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

bool Convex::makeSlowConvexHull(Vector2* points, int count, VertexSet& vertexes)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	std::vector<std::pair<Vector2, Vector2>> edges;

	bool bValid = true;

	for (int i = 0; i < count; i++)
	{
		Vector2 p0 = points[(i + count) % count];
		Vector2 p1 = points[(i + 1 + count) % count];

		bValid = true;

		for (int j = 0; j < count - 2;j++)
		{
			Vector2 p2 = points[(i + 2 + j + count) % count];
			Vector2 v0 = p1 - p0;
			Vector2 v1 = p2 - p1;

			int vd = Vector2::direction(v0, v1);
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
		Vector2 last = *vertexes.tail();
		
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

bool Convex::makeConvexHull(Vector2* points, int count, VertexSet& vertexes)
{
	if (points == nullptr || count < 3)
	{
		return false;
	}

	points = sortByXAxis(points, count);

	// 上包
	VertexSet& upper = vertexes;
	// 下包
	VertexSet lower;

	upper.add(points[0]);
	upper.add(points[1]);
	for (int i = 2; i < count; i++)
	{
		upper.add(points[i]);
		int len = upper.count();
		while (len >= 3)
		{
			Vector2* p0 = upper[len - 3];
			Vector2* p1 = upper[len - 2];
			Vector2* p2 = upper[len - 1];
			
			int result = Vector2::direction(*p1 - *p0, *p2 - *p1);
			if (result == 2)
			{
				break;
			}

			upper.remove(len - 2);
		}
	}

	lower.add(points[count - 1]);
	lower.add(points[count - 2]);

	for (int i = count - 3; i >= 0; i--)
	{
		lower.add(points[i]);
		int len = lower.count();

		while (len >= 3)
		{
			Vector2* p0 = upper[len - 3];
			Vector2* p1 = upper[len - 2];
			Vector2* p2 = upper[len - 1];

			int result = Vector2::direction(*p1 - *p0, *p2 - *p1);
			if (result == 2)
			{
				break;
			}

			lower.remove(len - 2);
		}
	}

	lower.remove(0);
	lower.remove(lower.count() - 1);

	upper.append(lower);

	return true;
}

Vector2* Convex::sortByAxisX(Vector2* points, int count)
{
	if (points == nullptr || count <= 0)
	{
		return nullptr;
	}

	std::vector<Vector2> vecPoints;

	for (int i = 0; i < count; i++)
	{
		vecPoints.push_back(points[i]);
	}

	std::sort(vecPoints.begin(), vecPoints.end(), [](const Vector2 & m1, const Vector2 & m2) {
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

	for (int i = 0; i < count; i++)
	{
		points[i] = vecPoints[i];
	}

	return points;
}

Vector2* Convex::sortByAxisY(Vector2* points, int count)
{
	if (points == nullptr || count <= 0)
	{
		return nullptr;
	}

	std::vector<Vector2> vecPoints;

	for (int i = 0; i < count; i++)
	{
		vecPoints.push_back(points[i]);
	}

	std::sort(vecPoints.begin(), vecPoints.end(), [](const Vector2 & m1, const Vector2 & m2) {
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

	for (int i = 0; i < count; i++)
	{
		points[i] = vecPoints[i];
	}

	return points;
}


