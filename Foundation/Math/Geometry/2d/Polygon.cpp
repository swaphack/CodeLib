#include "Polygon.h"

math::Polygon::Polygon() 
{}

math::Polygon::Polygon(const std::vector<math::Vector3>& points)
{
	this->setPoints(points);
}

math::Polygon::Polygon(const std::vector<math::Vector2>& points)
{
	std::vector<math::Vector3> values;
	for (auto item : points)
	{
		values.push_back(item);
	}
	this->setPoints(values);
}

math::Polygon::Polygon(const Polygon& polygon)
{
	this->setPoints(polygon.getPoints());
}

math::Polygon::~Polygon() 
{}

const std::vector<math::Vector3>& math::Polygon::getPoints() const
{
	return _points;
}

int math::Polygon::getPointCount() const
{
	return _points.size();
}

void math::Polygon::setPoints(const std::vector<math::Vector3>& points)
{
	_points = points;
}

bool math::Polygon::contains(const Vector2& point)
{
	int32_t sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int32_t i = 0; i < getPointCount(); i++)
	{
		p0 = _points[i];
		p1 = _points[(i + 1) % getPointCount()];

		// 在其延长线上
		if (point.getY() <= MIN(p0.getY(), p1.getY())) continue;
		if (point.getY() >= MAX(p0.getY(), p1.getY())) continue;

		// 求解 y=point.getY() 与 p0p1 的交点
		float x = (point.getY() - p0.getY()) * (p1.getX() - p0.getX()) / (p1.getY() - p0.getY()) + p0.getX();
		if (x >= point.getX()) sum++;
	}

	return sum % 2 == 1;
}

bool math::Polygon::includes(const Vector2& point)
{
	int32_t sum = 0;
	Vector2 p0;
	Vector2 p1;

	for (int32_t i = 0; i < getPointCount(); i++)
	{
		p0 = _points[i];
		p1 = _points[(i + 1) % getPointCount()];

		if (p0.getY() == p1.getY()) continue;

		// 在其延长线上
		if (point.getY() < MIN(p0.getY(), p1.getY())) continue;
		if (point.getY() > MAX(p0.getY(), p1.getY())) continue;

		// 求解 y=point.getY() 与 p0p1 的交点
		float x = (point.getY() - p0.getY()) * (p1.getX() - p0.getX()) / (p1.getY() - p0.getY()) + p0.getX();
		if (x > point.getX()) sum++;
	}

	return sum % 2 == 1;
}

bool math::Polygon::contains(const LineSegment2d& line)
{
	bool one = contains(line.getSrc());
	bool two = contains(line.getDest());
	return one && two;
}

bool math::Polygon::intersects(const LineSegment2d& line)
{
	bool one = contains(line.getSrc());
	bool two = contains(line.getDest());
	return (one && !two) || (!one && two);
}

bool math::Polygon::intersects(const Polygon& polygon)
{
	for (int32_t i = 0; i < _points.size(); i++)
	{
		LineSegment2d line(polygon[i], polygon[(i + 1) % polygon.getPointCount()]);
		if (this->intersects(line))
		{
			return true;
		}
	}

	return false;
}

math::Polygon& math::Polygon::operator=(const Polygon& polygon)
{
	this->setPoints(polygon.getPoints());
	return *this;
}

math::Vector3& math::Polygon::operator[](int index)
{
	assert(index >= 0 && index < getPointCount());

	return _points[index];
}

const math::Vector3& math::Polygon::operator[](int index) const
{
	assert(index >= 0 && index < getPointCount());

	return _points[index];
}
