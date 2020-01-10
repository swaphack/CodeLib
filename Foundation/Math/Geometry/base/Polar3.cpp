#include "Polar3.h"
#include <cmath>
#include <cassert>

using namespace math;


Polar3::Polar3()
	:Vector(3)
{

}

Polar3::Polar3(float r, float radianX, float radianZ)
	: Polar3()
{
	this->setRadius(r);
	this->setRadianX(radianX);
	this->setRadianZ(radianZ);
}

Polar3::Polar3(const Vector3& vector)
	: Polar3()
{
	float r = vector.getMagnitude();
	float randianX = atan2(vector.getY(), vector.getX());
	float randianZ = atan2(vector.getZ(), r);

	this->set(r, randianX, randianZ);
}

Polar3::Polar3(const Polar3& polar)
	: Polar3()
{
	this->setRadius(polar.getRadius());
	this->setRadianX(polar.getRadianX());
	this->setRadianZ(polar.getRadianZ());
}

Polar3::~Polar3()
{

}

void Polar3::set(float r, float radianX, float radianZ)
{
	this->setRadius(r);
	this->setRadianX(radianX);
	this->setRadianZ(radianZ);
}

Polar3& Polar3::operator=(const Polar3& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadianX(polar.getRadianX());
	this->setRadianZ(polar.getRadianZ());

	return *this;
}

Polar3& Polar3::operator=(const Vector3& vector)
{
	float r = vector.getMagnitude();
	float randianX = atan2(vector.getY(), vector.getX());
	float randianZ = atan2(vector.getZ(), r);

	this->set(r, randianX, randianZ);

	return *this;
}

Polar3& Polar3::operator*=(float ratio)
{
	this->setRadius(ratio * this->getRadius());
	return *this;
}

Polar3& Polar3::operator/=(float ratio)
{
	assert(ratio != 0);

	this->setRadius(this->getRadius() / ratio);
	return *this;
}

Polar3 Polar3::operator*(float ratio)
{
	return Polar3(ratio * this->getRadius(), this->getRadianX(), this->getRadianZ());
}

Polar3 Polar3::operator/(float ratio)
{
	assert(ratio != 0);

	return Polar3(this->getRadius() / ratio, this->getRadianX(), this->getRadianZ());
}

bool Polar3::operator==(const Polar3& polar)
{
	return polar.getRadianX() == getRadianX() && polar.getRadianZ() == getRadianZ() && polar.getRadius() == getRadius();
}

bool Polar3::operator!=(const Polar3& polar)
{
	return polar.getRadianX() != getRadianX() || polar.getRadianZ() != getRadianZ() || polar.getRadius() != getRadius();
}

Polar3::operator Vector3()
{
	float x = getRadius() * sin(getRadianX()) * cos(getRadianZ());
	float y = getRadius() * sin(getRadianX()) * sin(getRadianZ());
	float z = getRadius() * cos(getRadianX());

	return Vector3(x, y, z);
}
