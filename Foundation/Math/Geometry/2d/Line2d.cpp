#include "Line2d.h"
#include <cassert>
#include "Basic/base.h"

using namespace math;

Line2d::Line2d(const Vector2& src, const Vector2& dest)
{
	float a = dest.getY() - src.getY();
	float b = src.getX() - dest.getX();
	float c = sqrt(_paramA * src.getX() + _paramB * src.getY());

	if (c > 0)
	{
		a /= c; c /= c; c = -a * src.getX() - b * src.getY();
	}
	else
	{
		a = 0; b = 1; c = -src.getX();
	}

	_paramA = a;
	_paramB = b;
	_paramC = c;

	_normal = Vector2(_paramA, _paramB);
	_direction = dest - src;
}

Line2d::Line2d(float a, float b, float c)
{
	assert(a != 0 || b != 0);

	_paramA = a;
	_paramB = b;
	_paramC = c;

	_normal = Vector2(_paramA, _paramB);
	_direction = Vector2(_paramA, -_paramB);
}

Line2d::Line2d(const Line2d& line)
{
	_paramA = line.getParamA();
	_paramB = line.getParamB();
	_paramC = line.getParamC();

	_normal = line.getNormal();
	_direction = line.getDirection();
}

const Vector2& Line2d::getNormal() const
{
	return _normal;
}

const Vector2& Line2d::getDirection() const
{
	return _direction;
}

float Line2d::getParamA() const
{
	return _paramA;
}

float Line2d::getParamC() const
{
	return _paramC;
}

float Line2d::getParamB() const
{
	return _paramB;
}

float Line2d::getDistanceWithPoint(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;
	float b = sqrt(pow(_paramA, 2) + pow(_paramB, 2));
	assert(b != 0);
	return a / b;
}

bool Line2d::contains(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;

	return a == 0;
}

bool Line2d::isParallel(const Line2d& line)
{
	Vector2 v0 = getDirection();
	Vector2 n1 = line.getNormal();

	return Vector2::dot(v0, n1) == 0;
}

bool Line2d::isIntersect(const Line2d& line)
{
	Vector2 v0 = getDirection();
	Vector2 n1 = line.getNormal();

	return Vector2::dot(v0, n1) != 0;
}

PointAndLinePosition2DType math::Line2d::getPointPositionType(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;

	if (a == 0)
	{
		return PointAndLinePosition2DType::INCLUDE;
	}
	if (a < 0)
	{
		return PointAndLinePosition2DType::EXLUDE_LEFT;
	}

	return PointAndLinePosition2DType::EXLUDE_RIGHT;
}
