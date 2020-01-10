#include "Polar2.h"
#include "Basic/base.h"

#include <cmath>
#include <cassert>

using namespace math;

Polar2::Polar2()
	:Vector(2)
{

}

Polar2::Polar2(float r, float radian)
	: Polar2()
{
	this->setRadius(r);
	this->setRadian(radian);
}

Polar2::Polar2(const Vector2& vector)
	: Polar2()
{
	float r = vector.getMagnitude();
	float radian = atan2(vector.getY(), vector.getX());

	this->setRadius(r);
	this->setRadian(radian);
}

Polar2::Polar2(const Polar2& polar)
	: Polar2()
{
	this->setRadius(polar.getRadius());
	this->setRadian(polar.getRadian());
}

Polar2::~Polar2()
{

}

void Polar2::set(float r, float radian)
{
	this->setRadius(r);
	this->setRadian(radian);
}

Polar2& Polar2::operator=(const Polar2& polar)
{
	this->setRadius(polar.getRadius());
	this->setRadian(polar.getRadian());

	return *this;
}

Polar2& Polar2::operator=(const Vector2& vector)
{
	float r = vector.getMagnitude();
	float radian = atan2(vector.getY(), vector.getX());

	this->setRadius(r);
	this->setRadian(radian);

	return *this;
}

Polar2& Polar2::operator+=(float radian)
{
	radian = this->getRadian() + radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	this->setRadian(radian);

	return *this;
}

Polar2& Polar2::operator-=(float radian)
{
	radian = this->getRadian() - radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	this->setRadian(radian);

	return *this;
}

Polar2& Polar2::operator*=(float ratio)
{
	this->setRadius(ratio * this->getRadius());
	return *this;
}

Polar2& Polar2::operator/=(float ratio)
{
	assert(ratio != 0);

	this->setRadius(this->getRadius() / ratio);
	return *this;
}

Polar2 Polar2::operator+(float radian)
{
	radian = this->getRadian() + radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	return Polar2(this->getRadius(), radian);
}

Polar2 Polar2::operator-(float radian)
{
	radian = this->getRadian() - radian;

	ADJUST_DURATION_VALUE_RANGE(radian, 0, 2 * PI, 2 * PI);

	return Polar2(this->getRadius(), radian);
}

Polar2 Polar2::operator*(float ratio)
{
	return Polar2(ratio * this->getRadius(), this->getRadian());
}

Polar2 Polar2::operator/(float ratio)
{
	assert(ratio != 0);

	return Polar2(this->getRadius() / ratio, this->getRadian());
}

bool Polar2::operator==(const Polar2& polar)
{
	return polar.getRadian() == getRadian() && polar.getRadius() == getRadius();
}

bool Polar2::operator!=(const Polar2& polar)
{
	return polar.getRadian() != getRadian() || polar.getRadius() != getRadius();
}

Polar2::operator Vector2()
{
	return Vector2(getRadius() * cos(getRadian()), getRadian()* sin(getRadian()));
}

