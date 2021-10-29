#include "Polar2d.h"
#include "Basic/base.h"

#include <cmath>
#include <cassert>

using namespace math;

Polar2d::Polar2d()
{

}

Polar2d::Polar2d(float r, float radian)
{
	this->setRadius(r);
	this->setRadian(radian);
}

Polar2d::Polar2d(const Vector2& vector)
{
	float r = vector.getMagnitude();
	float radian = atan2(vector.getY(), vector.getX());

	this->setRadius(r);
	this->setRadian(radian);
}

Polar2d::Polar2d(const Polar2d& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadian(polar.getRadian());
}

Polar2d::~Polar2d()
{

}

void Polar2d::set(float r, float radian)
{
	this->setRadius(r);
	this->setRadian(radian);
}

Polar2d& Polar2d::operator=(const Polar2d& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadian(polar.getRadian());

	return *this;
}

Polar2d& Polar2d::operator=(const Vector2& vector)
{
	float r = vector.getMagnitude();
	float radian = atan2(vector.getY(), vector.getX());

	this->setRadius(r);
	this->setRadian(radian);

	return *this;
}

Polar2d& Polar2d::operator+=(float radian)
{
	radian = this->getRadian() + radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	this->setRadian(radian);

	return *this;
}

Polar2d& Polar2d::operator-=(float radian)
{
	radian = this->getRadian() - radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	this->setRadian(radian);

	return *this;
}

Polar2d& Polar2d::operator*=(float ratio)
{
	this->setRadius(ratio * this->getRadius());
	return *this;
}

Polar2d& Polar2d::operator/=(float ratio)
{
	assert(ratio != 0);

	this->setRadius(this->getRadius() / ratio);
	return *this;
}

Polar2d Polar2d::operator+(float radian) const
{
	radian = this->getRadian() + radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	return Polar2d(this->getRadius(), radian);
}

Polar2d Polar2d::operator-(float radian) const
{
	radian = this->getRadian() - radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	return Polar2d(this->getRadius(), radian);
}

Polar2d Polar2d::operator*(float ratio) const
{
	return Polar2d(ratio * this->getRadius(), this->getRadian());
}

Polar2d Polar2d::operator/(float ratio) const
{
	assert(ratio != 0);

	return Polar2d(this->getRadius() / ratio, this->getRadian());
}

bool Polar2d::operator==(const Polar2d& polar)
{
	return polar.getRadian() == getRadian() && polar.getRadius() == getRadius();
}

bool Polar2d::operator!=(const Polar2d& polar)
{
	return polar.getRadian() != getRadian() || polar.getRadius() != getRadius();
}

Polar2d::operator Vector2() const
{
	return Vector2(getRadius() * cos(getRadian()), getRadian()* sin(getRadian()));
}

