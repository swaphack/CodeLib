#include "Polygon.h"
#include "Geometry/base/Line2.h"
#include "Basic/base.h"

using namespace math;

Polygon::Polygon(Vector2* _points, int32_t _count) 
:Polygon()
{
	if (_points == nullptr || _count < 3)
	{
		return;
	}

	this->_points = new Vector2[_count];
	this->_count = _count;
	for (int32_t i = 0; i < _count; i++)
	{
		this->_points[i] = _points[i];
	}
}

Polygon::Polygon()
	:_points(nullptr)
	, _count(0)
{

}

Polygon::Polygon(const Polygon & polygon)
	:Polygon(polygon._points, polygon._count)
{

}

Polygon::~Polygon()
{
	if (_points != nullptr)
	{
		delete[] _points;
	}
}

bool Polygon::contains(const Vector2& point)
{
	int32_t sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int32_t i = 0; i < _count; i++)
	{		
		p0 = _points[i];
		p1 = _points[(i + 1) % _count];

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
	for (int32_t i = 0; i < _count; i++)
	{
		segment.src = _points[i];
		segment.dest = _points[(i + 1) % _count];

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
	for (int32_t i = 0; i < _count; i++)
	{
		segment.src = _points[i];
		segment.dest = _points[(i + 1) % _count];

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
	for (int32_t i = 0; i < polygon._count; i++)
	{
		Line2 line(polygon._points[i], polygon._points[(i + 1) % polygon._count]);
		if (this->intersects(line) || this->contains(line))
		{
			return true;
		}
	}

	return false;
}

Polygon& Polygon::operator=(const Polygon& polygon)
{
	if (polygon._points == nullptr || polygon._count < 3)
	{
		return *this;
	}

	if (this->_points != nullptr)
	{
		delete[] this->_points;
	}

	this->_points = new Vector2[_count];
	this->_count = _count;
	for (int32_t i = 0; i < _count; i++)
	{
		this->_points[i] = _points[i];
	}

	return *this;
}

bool Polygon::isStandard(const Polygon& polygon)
{
	if (polygon._points == nullptr || polygon._count < 3)
	{
		return false;
	}

	int32_t lineCount = polygon._count;
	PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon._points[i % lineCount];
		Vector2 v1 = polygon._points[(i + 1) % lineCount];
		Vector2 v2 = polygon._points[(i + 1) % lineCount];
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

	int32_t lineCount = polygon._count;
	PointAndLinePositionType lastDirection = PointAndLinePositionType::NONE;
	for (int32_t i = 0; i < lineCount; i++)
	{
		Vector2 v0 = polygon._points[i % lineCount];
		Vector2 v1 = polygon._points[(i + 1) % lineCount];
		Vector2 v2 = polygon._points[(i + 1) % lineCount];
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