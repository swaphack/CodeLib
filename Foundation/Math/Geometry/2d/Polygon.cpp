#include "Polygon.h"
#include "Geometry/base/Line2.h"
#include "Basic/base.h"

using namespace math;

Polygon::Polygon(int32_t vcount, const Vector2* vpoints)
:Polygon()
{
	this->init(vcount, vpoints);
}

Polygon::Polygon()
	:points(nullptr)
	, count(0)
{

}

Polygon::Polygon(const Polygon & polygon)
	:Polygon(polygon.count, polygon.points)
{

}

Polygon::~Polygon()
{
	if (points != nullptr)
	{
		delete[] points;
	}
}

bool Polygon::contains(const Vector2& point)
{
	int32_t sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int32_t i = 0; i < count; i++)
	{		
		p0 = points[i];
		p1 = points[(i + 1) % count];

		// 水平
		if (p0.getY() == p1.getY()) continue;

		// 在其延长线上
		if (point.getY() < MIN(p0.getY(), p1.getY())) continue;
		if (point.getY() >= MAX(p0.getY(), p1.getY())) continue;

		// 求解 y=point.getY() 与 p0p1 的交点
		float x = (point.getY() - p0.getY()) * (p1.getX() - p0.getX()) / (p1.getY() - p0.getY()) + p0.getX();
		if (x > point.getX()) sum++;
	}

	return sum % 2 == 1;
}

bool Polygon::contains(const Line2& line)
{
	/*
	if (!contains(line.src) || !contains(line.dest))
	{
		return false;
	}
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int32_t i = 0; i < count; i++)
	{
		segment.src = points[i];
		segment.dest = points[(i + 1) % count];

		if (segment.intersects(line))
		{
			return false;
		}
	}

	return true;
	*/

	return false;
}

bool Polygon::intersects(const Line2& line)
{
	/*
	Vector2 p0;
	Vector2 p1;
	Line2 segment;
	for (int32_t i = 0; i < count; i++)
	{
		segment.src = points[i];
		segment.dest = points[(i + 1) % count];

		if (segment.intersects(line))
		{
			return true;
		}
	}
	*/
	return false;
}

bool Polygon::intersects(const Polygon& polygon)
{
	for (int32_t i = 0; i < polygon.count; i++)
	{
		Line2 line(polygon.points[i], polygon.points[(i + 1) % polygon.count]);
		if (this->intersects(line) || this->contains(line))
		{
			return true;
		}
	}

	return false;
}

Polygon& Polygon::operator=(const Polygon& polygon)
{
	if (polygon.points == nullptr || polygon.count < 3)
	{
		return *this;
	}

	if (this->points != nullptr)
	{
		delete[] this->points;
	}

	this->points = new Vector2[count];
	this->count = count;
	for (int32_t i = 0; i < count; i++)
	{
		this->points[i] = points[i];
	}

	return *this;
}

bool Polygon::isStandard(const Polygon& polygon)
{
	if (polygon.points == nullptr || polygon.count < 3)
	{
		return false;
	}

	int32_t lineCount = polygon.count;
	PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon.points[i % lineCount];
		Vector2 v1 = polygon.points[(i + 1) % lineCount];
		Vector2 v2 = polygon.points[(i + 1) % lineCount];
		Line2 line(v0, v1);
		PointAndLinePositionType eType = line.getPointPositionType(v2);
		if (eType == PointAndLinePositionType::INCLUDE)
		{
			return false;
		}

		if (lastDirection != PointAndLinePositionType::NONE)
		{
			if (lastDirection != eType)
			{
				return false;
			}
		}
		else
		{
			lastDirection = eType;
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

	int32_t lineCount = polygon.count;
	PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon.points[i % lineCount];
		Vector2 v1 = polygon.points[(i + 1) % lineCount];
		Vector2 v2 = polygon.points[(i + 1) % lineCount];
		Line2 line(v0, v1);
		PointAndLinePositionType eType = line.getPointPositionType(v2);
		if (eType == PointAndLinePositionType::INCLUDE)
		{
			return false;
		}

		if (lastDirection != PointAndLinePositionType::NONE)
		{
			if (lastDirection != eType)
			{
				return false;
			}
		}
		else
		{
			lastDirection = eType;
		}
	}

	return true;
}

void Polygon::init(int32_t vcount, const Vector2* vpoints)
{
	if (vpoints == nullptr || vcount < 3)
	{
		return;
	}

	if (this->points != nullptr)
	{
		delete[] this->points;
	}

	this->points = new Vector2[vcount];
	this->count = vcount;
	for (int32_t i = 0; i < vcount; i++)
	{
		this->points[i] = vpoints[i];
	}
}
