#include "Line2.h"
#include <cassert>
#include "Basic/base.h"

using namespace math;

Line2::Line2(const Vector2& src, const Vector2& dest)
{
	float a = dest.getY() - src.getY();
	float b = src.getX() - dest.getX();
	float c = -(_paramA * src.getX() + _paramB * src.getY());

	assert(a != 0 || b != 0);

	_paramA = a;
	_paramB = b;
	_paramC = c;

	_normal = Vector2(_paramA, _paramB);
	_direction = dest - src;
}

Line2::Line2(float a, float b, float c)
{
	assert(a != 0 || b != 0);

	_paramA = a;
	_paramB = b;
	_paramC = c;

	_normal = Vector2(_paramA, _paramB);
	_direction = Vector2(_paramA, -_paramB);
}

Line2::Line2(const Line2& line)
{
	_paramA = line.getParamA();
	_paramB = line.getParamB();
	_paramC = line.getParamC();

	_normal = line.getNormal();
	_direction = line.getDirection();
}

const Vector2& Line2::getNormal() const
{
	return _normal;
}

const Vector2& Line2::getDirection() const
{
	return _direction;
}

float Line2::getParamA() const
{
	return _paramA;
}

float Line2::getParamC() const
{
	return _paramC;
}

float Line2::getParamB() const
{
	return _paramB;
}

float Line2::getDistanceWithPoint(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;
	float b = sqrt(pow(_paramA, 2) + pow(_paramB, 2));

	return a / b;
}

bool Line2::contains(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;

	return a == 0;
}

bool Line2::isParallel(const Line2& line)
{
	Vector2 v0 = getDirection();
	Vector2 n1 = line.getNormal();

	return Vector2::dot(v0, n1) == 0;
}

bool Line2::isIntersect(const Line2& line)
{
	Vector2 v0 = getDirection();
	Vector2 n1 = line.getNormal();

	return Vector2::dot(v0, n1) != 0;
}

PointAndLinePositionType math::Line2::getPointPositionType(const Vector2& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC;

	if (a == 0)
	{
		return PointAndLinePositionType::INCLUDE;
	}
	if (a < 0)
	{
		return PointAndLinePositionType::EXLUDE_LEFT;
	}

	return PointAndLinePositionType::EXLUDE_RIGHT;
}
