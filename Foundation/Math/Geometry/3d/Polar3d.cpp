#include "Polar3d.h"
#include <cmath>
#include <cassert>

using namespace math;


Polar3d::Polar3d()
{

}

Polar3d::Polar3d(float r, float radianX, float radianZ)
{
	this->setRadius(r);
	this->setRadianX(radianX);
	this->setRadianZ(radianZ);
}

Polar3d::Polar3d(const Vector3& vector)
{
	float r = vector.getMagnitude();
	float randianX = atan2(vector.getY(), vector.getX());
	float randianZ = atan2(vector.getZ(), r);

	this->set(r, randianX, randianZ);
}

Polar3d::Polar3d(const Polar3d& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadianX(polar.getRadianX());
	this->setRadianZ(polar.getRadianZ());
}

Polar3d::~Polar3d()
{

}

void Polar3d::set(float r, float radianX, float radianZ)
{
	this->setRadius(r);
	this->setRadianX(radianX);
	this->setRadianZ(radianZ);
}

Polar3d& Polar3d::operator=(const Polar3d& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadianX(polar.getRadianX());
	this->setRadianZ(polar.getRadianZ());

	return *this;
}

Polar3d& Polar3d::operator=(const Vector3& vector)
{
	float r = vector.getMagnitude();
	float randianX = atan2(vector.getY(), vector.getX());
	float randianZ = atan2(vector.getZ(), r);

	this->set(r, randianX, randianZ);

	return *this;
}

Polar3d& Polar3d::operator*=(float ratio)
{
	this->setRadius(ratio * this->getRadius());
	return *this;
}

Polar3d& Polar3d::operator/=(float ratio)
{
	assert(ratio != 0);

	this->setRadius(this->getRadius() / ratio);
	return *this;
}

Polar3d Polar3d::operator*(float ratio) const
{
	return Polar3d(ratio * this->getRadius(), this->getRadianX(), this->getRadianZ());
}

Polar3d Polar3d::operator/(float ratio) const
{
	assert(ratio != 0);

	return Polar3d(this->getRadius() / ratio, this->getRadianX(), this->getRadianZ());
}

bool Polar3d::operator==(const Polar3d& polar) const
{
	return polar.getRadianX() == getRadianX() && polar.getRadianZ() == getRadianZ() && polar.getRadius() == getRadius();
}

bool Polar3d::operator!=(const Polar3d& polar) const
{
	return polar.getRadianX() != getRadianX() || polar.getRadianZ() != getRadianZ() || polar.getRadius() != getRadius();
}

Polar3d::operator Vector3() const
{
	float x = getRadius() * sin(getRadianX()) * cos(getRadianZ());
	float y = getRadius() * sin(getRadianX()) * sin(getRadianZ());
	float z = getRadius() * cos(getRadianX());

	return Vector3(x, y, z);
}
