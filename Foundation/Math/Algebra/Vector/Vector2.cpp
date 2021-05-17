#include "Vector2.h"
#include <cmath>
#include <cassert>
//#include "Size.h"
#include "Basic/base.h"
#include "../Matrix/Matrix3x3.h"
#include "../Determinant/Determinant.h"

using namespace math;

Vector2::Vector2() 
{

}

Vector2::Vector2(float x, float y) 
{
	this->setX(x);
	this->setY(y);
}

Vector2::Vector2(const Vector2& point)
{
	this->setX(point.getX());
	this->setY(point.getY());

}

Vector2::Vector2(const Vector<float, 2>& vector)
{
	this->setX(vector[0]);
	this->setY(vector[1]);
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	this->setX(vec.getX());
	this->setY(vec.getY());

	return *this;
}

Vector2 Vector2::operator+(const Vector2& vec) const
{
	return Vector2(getX() + vec.getX(), getY() + vec.getY());
}

Vector2 Vector2::operator-(const Vector2& vec) const
{
	return Vector2(getX() - vec.getX(), getY() - vec.getY());
}

Vector2 Vector2::operator*(float k) const
{
	return Vector2(getX() * k, getY() * k);
}

Vector2 Vector2::operator/(float k) const
{
	assert(k != 0);

	return Vector2(getX() / k, getY() / k);
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	setX(getX() + vec.getX());
	setY(getY() + vec.getY());

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	setX(getX() - vec.getX());
	setY(getY() - vec.getY());

	return *this;
}

Vector2& Vector2::operator*=(float k)
{
	setX(getX() * k);
	setY(getY() * k);

	return *this;
}

Vector2& Vector2::operator/=(float k)
{
	assert(k != 0);

	setX(getX() / k);
	setY(getY() / k);

	return *this;
}

bool Vector2::operator==(const Vector2& vec)
{
	return getX() == vec.getX() && getY() == vec.getY();
}

Vector2& Vector2::operator=(const Vector3& vec)
{
	this->setX(vec.getX());
	this->setY(vec.getY());

	return *this;
}

bool Vector2::operator!=(const Vector2& vec)
{
	return getX() != vec.getX() || getY() != vec.getY();
}

void Vector2::set(float x, float y)
{
	this->setX(x);
	this->setY(y);
}

float Vector2::dot(const Vector2& vector0, const Vector2& vector1)
{
	return vector0.getX() * vector1.getX() + vector0.getY() * vector1.getY();
}
/*
Vector2 Vector2::cross(const Vector2& vector0, const Vector2& vector1)
{
	float x = vector0.getX() * vector1.getY();
	float y = -vector0.getY() * vector1.getX();

	return Vector2(x, y);
}
*/
float Vector2::cross(const Vector2& vector0, const Vector2& vector1)
{
	return vector0.getX() * vector1.getY() - vector0.getY() * vector1.getX();
}

float Vector2::distance(const Vector2& point0, const Vector2& point1)
{
	return (point1 - point0).getMagnitude();
}

float Vector2::cosAngle(const Vector2& vector0, const Vector2& vector1)
{
	float a = vector0.getMagnitude();
	float b = vector1.getMagnitude();

	assert(a != 0 && b != 0);

	return Vector3::dot(vector0, vector1) / (a * b);
}

float Vector2::sinAngle(const Vector2& vector0, const Vector2& vector1)
{
	float a = vector0.getMagnitude();
	float b = vector1.getMagnitude();

	assert(a != 0 && b != 0);

	Determinant2 det;
	det.setRow(0, vector0);
	det.setRow(1, vector1);

	return getDetMagnitude(det) / (a * b);
}

float Vector2::project(const Vector2& vector0, const Vector2& vector1)
{
	float l0 = vector0.getMagnitude();
	if (l0 == 0)
	{
		return 0;
	}
	return Vector2::dot(vector0, vector1) / l0;
}

float Vector2::getRotateAngle(const Vector2& vector0, const Vector2& vector1)
{
	float dotVal, degreeVal, angleVal;

	float l0 = vector0.getMagnitude();
	float l1 = vector1.getMagnitude();

	float x1 = vector0.getX() / l0;
	float y1 = vector0.getY() / l0;

	float x2 = vector1.getX() / l1;
	float y2 = vector1.getY() / l1;

	dotVal = x1 * x2 + y1 * y2;
	if (APPROXIMATELY(dotVal - 1.0f, 0))
	{
		angleVal = 0;
	}
	else if (APPROXIMATELY(dotVal + 1.0f, 0))
	{
		angleVal = PI;
	}
	else
	{
		float crossVal;
		angleVal = acos(dotVal);
		crossVal = x1 * y2 - x2 * y1;
		if (crossVal < 0)
		{
			angleVal = 2 * PI - angleVal;
		}
	}

	degreeVal = RADIAN_TO_ANGLE(angleVal);

	return degreeVal;
}

bool Vector2::isThreePointsOnSameLine(const Vector2& point0, const Vector2& point1, const Vector2& point2)
{
	Vector2 v0 = point2 - point0;
	Vector2 v1 = point2 - point1;

	Determinant2 det;
	det.setRow(0, v0);
	det.setRow(1, v1);

	return getDetMagnitude(det) == 0;
}

int math::Vector2::getPointPosition(const math::Vector2& point, const math::Vector2& src, const math::Vector2& dest)
{
	math::Vector2 p0 = dest - src;
	math::Vector2 p1 = point - src;

	int ret = math::Vector2::cross(p0, p1);
	if (ret == 0) return 0;
	else if (ret > 0) return -1;
	else return 1;
}

math::Vector2::~Vector2()
{

}

void math::Vector2::normalize()
{
	float magn = this->getMagnitude();
	if (magn == 0)
	{
		return;
	}

	for (int i = 0; i < getLength(); i++)
	{
		setValue(i, getValue(i) / magn);
	}
}
