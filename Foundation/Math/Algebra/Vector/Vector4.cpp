#include "Vector4.h"
#include "Vector3.h"
#include "Vector2.h"

using namespace math;

Vector4::Vector4()
	:Vector(4)
{

}

Vector4::Vector4(const Vector4& vector)
	: Vector4()
{
	this->set(vector.getX(), vector.getY(), vector.getZ(), vector.getW());
}

Vector4::Vector4(const Vector3& vector)
	: Vector4()
{
	this->set(vector.getX(), vector.getY(), vector.getZ());
}

Vector4::Vector4(const Vector2& vector)
	: Vector4()
{
	this->set(vector.getX(), vector.getY());
}

Vector4::Vector4(const Vector& vector)
	: Vector4()
{
	assert(vector.getSize() == getSize());

	this->setX(vector[0]);
	this->setY(vector[1]);
	this->setZ(vector[2]);
	this->setW(vector[3]);
}

Vector4::Vector4(float x, float y, float z, float w /*= 1*/)
	: Vector4()
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setW(w);
}

Vector4 Vector4::operator+(const Vector4& vec) const
{
	assert(this->getW() != vec.getW());

	return Vector4(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ(), getW());
}

Vector4 Vector4::operator-(const Vector4& vec) const
{
	assert(this->getW() != vec.getW());

	return Vector4(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ(), getW());
}

Vector4 Vector4::operator*(const Vector4& vec) const
{
	assert(this->getW() != vec.getW());

	return Vector4(getX() * vec.getX(), getY() * vec.getY(), getZ() * vec.getZ(), getW());
}

Vector4& Vector4::operator=(const Vector3& vec)
{
	this->setX(vec.getX());
	this->setY(vec.getY());
	this->setZ(vec.getZ());

	return *this;
}

Vector4& Vector4::operator=(const Vector4& vec)
{
	this->setX(vec.getX());
	this->setY(vec.getY());
	this->setZ(vec.getZ());
	this->setW(vec.getW());

	return *this;
}

void Vector4::set(float x, float y, float z, float w)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setW(w);
}

void Vector4::set(float x, float y)
{
	this->setX(x);
	this->setY(y);
}

void Vector4::set(float x, float y, float z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}