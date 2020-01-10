#pragma once

#include "Plane.h"

using namespace math;

Plane::Plane(const Vector3& point0, const Vector3& point1, const Vector3& point2)
{
	Vector3 v1 = point1 - point0;
	Vector3 v2 = point2 - point0;

	_paramA = v1.getY() * v2.getZ() - v1.getZ() * v2.getY();
	_paramB = -(v1.getX() * v2.getZ() - v1.getZ() * v2.getX());
	_paramC = v1.getX() * v2.getY() - v1.getY() * v2.getX();

	_paramD = -point0.getX() * _paramA + point0.getY() * _paramB - point0.getZ() * _paramC;

	_normal = Vector3(_paramA, _paramB, _paramC);
}

Plane::Plane(const Vector3& point, const Vector3& normal)
{
	_paramA = normal.getX();
	_paramB = normal.getY();
	_paramC = normal.getZ();

	_paramD = -(_paramA * point.getX() + _paramB * point.getY() + _paramC * point.getZ());

	_normal = normal;
}

Plane::Plane(float a, float b, float c, float d)
{
	_paramA = a;
	_paramB = b;
	_paramC = c;
	_paramD = d;

	_normal = Vector3(a, b, c);
}

Plane::Plane(const Plane& plane)
{

}

Plane::~Plane()
{

}

float Plane::getParamA() const
{
	return _paramA;
}

float Plane::getParamB() const
{
	return _paramB;
}

float Plane::getParamC() const
{
	return _paramC;
}

const Vector3& Plane::normal() const
{
	return _normal;
}

float Plane::getParamD() const
{
	return _paramD;
}

float Plane::getDistanceWithPoint(const Vector3& point)
{
	float a = _paramA * point.getX() + _paramB * point.getY() + _paramC * point.getZ() + _paramD;
	float b = sqrt(pow(_paramA, 2) + pow(_paramB, 2) + pow(_paramC, 2));

	return a / b;
}
