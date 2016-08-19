#include "Vector3.h"

using namespace math;

Vector3 Vector3::cross(const Vector3& dest) const
{
	Vector3 vec;
	vec.setX(Y * dest.getZ() - Z * dest.getY());
	vec.setX(Z * dest.getX() - X * dest.getZ());
	vec.setX(X * dest.getY() - Y * dest.getX());

	return vec;
}


Vector3 Vector3::project(const Vector3& dest) const
{
	Vector3 vec;
	float destLen = dest.getLength();
	if (destLen == 0)
	{
		return vec;
	}

	vec = dest * (this->dot(dest) / (destLen * destLen));

	return vec;
}


float Vector3::angle(const Vector3& dest) const
{
	float len = getLength();
	float destLen = dest.getLength();
	if (len == 0 || destLen == 0)
	{
		return PI / 2;
	}
	return acosf(dot(dest) / getLength() * dest.getLength());
}


float Vector3::dot(const Vector3& dest) const
{
	return X * dest.getX() + X * dest.getY() + X * dest.getZ();
}


Vector3 Vector3::operator-(const Vector3& dest) const
{
	Vector3 vec;
	vec.setX(X - dest.getX());
	vec.setY(Y - dest.getY());
	vec.setZ(Z - dest.getZ());
	return vec;
}


Vector3 Vector3::operator+(const Vector3& dest) const
{
	Vector3 vec;
	vec.setX(X + dest.getX());
	vec.setY(Y + dest.getY());
	vec.setZ(Z + dest.getZ());
	return vec;
}


Vector3 Vector3::operator*(float factor) const
{
	Vector3 vec;
	vec.setX(X * factor);
	vec.setY(Y * factor);
	vec.setZ(Z * factor);
	return vec;
}


Vector3& Vector3::operator-=(const Vector3& dest)
{
	setX(X - dest.getX());
	setY(Y - dest.getY());
	setZ(Z - dest.getZ());
	return *this;
}


Vector3& Vector3::operator+=(const Vector3& dest)
{
	setX(X + dest.getX());
	setY(Y + dest.getY());
	setZ(Z + dest.getZ());
	return *this;
}


Vector3& Vector3::operator*=(float factor)
{
	setX(X * factor);
	setY(Y * factor);
	setZ(Z * factor);
	return *this;
}


Vector3& Vector3::operator=(const Vector3& dest)
{
	X = dest.getX();
	Y = dest.getY();
	Z = dest.getZ();

	return *this;
}

/*

float Vector3::getRotationZ()
{

}


float Vector3::getRotationY()
{

}


float Vector3::getRotationX()
{

}
*/


Vector3& Vector3::zero() const
{
	X = 0;
	Y = 0;
	Z = 0;
}


Vector3 Vector3::norm() const
{
	float len = getLength();

	Vector3 vec;
	if (len != 0)
	{
		vec.setX(X / len);
		vec.setY(Y / len);
		vec.setZ(Z / len);
	}
	return vec;
}


float Vector3::getLength() const
{
	return sqrtf(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}


void Vector3::setZ(float t)
{
	Z = t;
}


float Vector3::getZ() const
{
	return Z;
}


void Vector3::setY(float t)
{
	Y = t;
}


float Vector3::getY() const
{
	return Y;
}


void Vector3::setX(float t)
{
	X = t;
}


float Vector3::getX() const
{
	return X;
}


Vector3::~Vector3()
{

}


Vector3::Vector3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}


Vector3::Vector3(const Vector3& dest)
{
	X = dest.getX();
	Y = dest.getY();
	Z = dest.getZ();
}


Vector3::Vector3()
{
	X = 0;
	Y = 0;
	Z = 0;
}