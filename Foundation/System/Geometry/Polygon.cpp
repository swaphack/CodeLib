#include "Polygon.h"
#include "Line2.h"
#include "../Collider/import.h"

using namespace sys;

Polygon::Polygon(Vector2* points, int count) 
{
	if (points == nullptr || count < 3)
	{
		return;
	}

	this->points = new Vector2[count];
	this->count = count;
	for (int i = 0; i < count; i++)
	{
		this->points[i] = points[i];
	}
}

Polygon::~Polygon()
{
	if (points != nullptr)
	{
		delete points;
	}
}

AABB Polygon::getBounds()
{
	Vector2 minPoint = points[0];
	Vector2 maxPoint = points[0];

	for (int i = 0; i < count; i++)
	{
		if (minPoint.x > points[i].x) minPoint.x = points[i].x;
		if (minPoint.y > points[i].y) minPoint.y = points[i].y;
		if (maxPoint.x < points[i].x) maxPoint.x = points[i].x;
		if (maxPoint.y < points[i].x) maxPoint.y = points[i].x;
	}

	Vector2 center = (minPoint + maxPoint) * 0.5f;
	Vector2 size = (maxPoint - minPoint);

	return AABB(center, size);
}

AABB Polygon::getBounds() const
{
	Vector2 minPoint = points[0];
	Vector2 maxPoint = points[0];

	for (int i = 0; i < count; i++)
	{
		if (minPoint.x > points[i].x) minPoint.x = points[i].x;
		if (minPoint.y > points[i].y) minPoint.y = points[i].y;
		if (maxPoint.x < points[i].x) maxPoint.x = points[i].x;
		if (maxPoint.y < points[i].x) maxPoint.y = points[i].x;
	}

	Vector2 center = (minPoint + maxPoint) * 0.5f;
	Vector2 size = (maxPoint - minPoint);

	return AABB(center, size);
}

bool Polygon::contains(const Vector2& point)
{
	int sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int i = 0; i < count; i++)
	{		
		p0 = points[i];
		p1 = points[(i + 1) % count];

		// 水平
		if (p0.y == p1.y) continue;

		// 在其延长线上
		if (point.y < MIN(p0.y, p1.y)) continue;
		if (point.y >= MAX(p0.y, p1.y)) continue;

		// 求解 y=point.y 与 p0p1 的交点
		float x = (point.y - p0.y) * (p1.x - p0.x) / (p1.y - p0.y) + p0.x;
		if (x > point.x) sum++;
	}

	return sum % 2 == 1;
}

bool Polygon::contains(const Line2& line)
{
	if (!contains(line.src) || !contains(line.dest))
	{
		return false;
	}
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int i = 0; i < count; i++)
	{
		segment.src = points[i];
		segment.dest = points[(i + 1) % count];

		if (segment.intersects(line))
		{
			return false;
		}
	}

	return true;
}

bool Polygon::intersects(const Line2& line)
{
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int i = 0; i < count; i++)
	{
		segment.src = points[i];
		segment.dest = points[(i + 1) % count];

		if (segment.intersects(line))
		{
			return true;
		}
	}

	return false;
}

bool Polygon::isStandard(const Polygon& polygon)
{
	if (polygon.points == nullptr || polygon.count < 3)
	{
		return false;
	}

	int lineCount = polygon.count;
	int lastDirection = -1;
	for (int i = 0; i < lineCount; i++)
	{
		Vector2 l0 = polygon.points[(i + 1) % lineCount] - polygon.points[i % lineCount];
		Vector2 l1 = polygon.points[(i + 2) % lineCount] - polygon.points[(i + 1) % lineCount];

		int direction = Vector2::direction(l1, l0);
		if (direction == 0)
		{
			return false;
		}
	}

	return true;
}

bool Polygon::isConvex(const Polygon& polygon)
{
	if (!isStandard(polygon))
	{
		return false;
	}

	int lineCount = polygon.count;
	int lastDirection = -1;
	for (int i = 0; i < lineCount; i++)
	{
		Vector2 l0 = polygon.points[(i + 1) % lineCount] - polygon.points[i % lineCount];
		Vector2 l1 = polygon.points[(i + 2) % lineCount] - polygon.points[(i + 1) % lineCount];

		int direction = Vector2::direction(l1, l0);
		if (lastDirection == -1)
		{
			lastDirection = direction;
		}
		else 
		{
			if (direction != lastDirection)
			{
				return false;
			}
		}
	}

	return true;
}