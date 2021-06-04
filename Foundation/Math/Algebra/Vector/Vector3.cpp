#include "Vector3.h"
#include "Vector2.h"
#include <cassert>
#include "../Matrix/Matrix4x4.h"
#include "../Determinant/Determinant.h"

using namespace math;


Vector3::Vector3() 
{

}

Vector3::Vector3(float x, float y, float z /*= 0*/) 
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
}

Vector3::Vector3(const Vector2& vector)
{
	this->setX(vector.getX());
	this->setY(vector.getY());
}

Vector3::Vector3(const Vector3& vector) 
{
	this->setX(vector.getX());
	this->setY(vector.getY());
	this->setZ(vector.getZ());
}

Vector3::Vector3(const Vector& vector)
{
	assert(vector.getLength() == getLength());

	this->setX(vector[0]);
	this->setY(vector[1]);
	this->setZ(vector[2]);
}

Vector3::Vector3(const Array<float, 3>& vector)
{
	this->setX(vector[0]);
	this->setY(vector[1]);
	this->setZ(vector[2]);
}

Vector3& Vector3::operator=(const Vector3& vec)
{
	this->setX(vec.getX());
	this->setY(vec.getY());
	this->setZ(vec.getZ());

	return *this;
}

Vector3 Vector3::operator+(const Vector3& vec) const
{
	return Vector3(getX() + vec.getX(), getY() + vec.getY(), getZ() + vec.getZ());
}

Vector3 Vector3::operator-(const Vector3& vec) const
{
	return Vector3(getX() - vec.getX(), getY() - vec.getY(), getZ() - vec.getZ());
}

Vector3 Vector3::operator*(const Vector3& vec) const
{
	return Vector3(getX() * vec.getX(), getY() * vec.getY(), getZ() * vec.getZ());
}

Vector3 Vector3::operator/(const Vector3& vec) const
{
	if (vec.getX() == 0 || vec.getY() == 0 || vec.getZ() == 0)
	{
		return *this;
	}

	return Vector3(getX() / vec.getX(), getY() / vec.getY(), getZ() / vec.getZ());
}

Vector3 Vector3::operator*(float k) const
{
	return Vector3(getX() * k, getY() * k, getZ() * k);
}

Vector3 Vector3::operator/(float k) const
{
	assert(k != 0);

	return Vector3(getX() / k, getY() / k,  getZ() / k);
}

Vector3& Vector3::operator+=(const Vector3& vec)
{
	setX(getX() + vec.getX());
	setY(getY() + vec.getY());
	setZ(getZ() + vec.getZ());

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& vec)
{
	setX(getX() - vec.getX());
	setY(getY() - vec.getY());
	setZ(getZ() - vec.getZ());

	return *this;
}

Vector3& Vector3::operator*=(float k)
{
	setX(getX() * k);
	setY(getY() * k);
	setZ(getZ() * k);

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& vec)
{
	setX(getX() * vec.getX());
	setY(getY() * vec.getY());
	setZ(getZ() * vec.getZ());

	return *this;
}

Vector3& Vector3::operator/=(const Vector3& vec)
{
	if (vec.getX() == 0 || vec.getY() == 0 || vec.getZ() == 0)
	{
		return *this;
	}

	setX(getX() / vec.getX());
	setY(getY() / vec.getY());
	setZ(getZ() / vec.getZ());

	return *this;
}

Vector3& Vector3::operator/=(float k)
{
	assert(k != 0);

	setX(getX() / k);
	setY(getY() / k);
	setZ(getZ() / k);

	return *this;
}

bool Vector3::operator==(const Vector3& vec) const
{
	return getX() == vec.getX() && getY() == vec.getY() && getZ() == vec.getZ();
}

Vector3& Vector3::operator=(const Vector2& vec)
{
	setX(vec.getX());
	setY(vec.getY());

	return *this;
}

bool Vector3::operator!=(const Vector3& vec) const
{
	return getX() != vec.getX() || getY() != vec.getY() || getZ() != vec.getZ();
}

void Vector3::set(float x, float y, float z)
{
	setX(x);
	setY(y);
	setZ(z);
}

void Vector3::set(float x, float y)
{
	setX(x);
	setY(y);
}

float Vector3::dot(const Vector3& vector0, const Vector3& vector1)
{
	return vector0.getX() * vector1.getX() + vector0.getY() * vector1.getY() + vector0.getZ() * vector1.getZ();
}

Vector3 Vector3::cross(const Vector3& vector0, const Vector3& vector1)
{
	float x = vector0.getY() * vector1.getZ() - vector0.getZ() * vector1.getY();
	float y = vector0.getZ() * vector1.getX() - vector0.getX() * vector1.getZ();
	float z = vector0.getX() * vector1.getY() - vector0.getY() * vector1.getX();

	return Vector3(x,y,z);
}

float math::Vector3::getRadian(const Vector3& vector0, const Vector3& vector1)
{
	float radian = acosf(cosValue(vector0, vector1));

	return radian;
}

float Vector3::distance(const Vector3& point0, const Vector3& point1)
{
	return (point1 - point0).getMagnitude();
}

float Vector3::cosValue(const Vector3& vector0, const Vector3& vector1)
{
	float a = vector0.getMagnitude();
	float b = vector1.getMagnitude();

	assert(a != 0 && b != 0);
	
	return Vector3::dot(vector0, vector1) / (a * b);
}

float Vector3::project(const Vector3& vector0, const Vector3& vector1)
{
	float l0 = vector0.getMagnitude();
	if (l0 == 0)
	{
		return 0;
	}
	return Vector3::dot(vector1, vector0) / l0;
}

Vector3 Vector3::tranlate(const Vector3& vector)
{
	Matrix4x4 mat;
	mat.setTranslate(vector);

	Matrix4x1 mat41(*this);

	Matrix4x1 ret = mat * mat41; 
	float w = ret[3];
	return Vector3(ret[0] / w, ret[1] / w, ret[2] / w);
}

Vector3 Vector3::scale(const Vector3& vector)
{
	Matrix4x4 mat;
	mat.setScale(vector);

	Matrix4x1 mat41(*this);
	Matrix4x1 ret = mat * mat41;
	float w = ret[3];
	return Vector3(ret[0] / w, ret[1] / w, ret[2] / w);
}

Vector3 Vector3::rotationByAxis(const Vector3& vector, float radian)
{
	Matrix4x4 mat;
	mat.setRotationByAxis(vector, radian);

	Matrix4x1 mat41(*this);
	Matrix4x1 ret = mat * mat41;
	float w = ret[3];
	return Vector3(ret[0] / w, ret[1] / w, ret[2] / w);
}

Vector3 Vector3::rotationByLine(const Vector3& src, const Vector3& dest, float radian)
{
	Matrix4x4 mat;
	mat.setRotationByLine(src, dest, radian);

	Matrix4x1 mat41(*this);
	Matrix4x1 ret = mat * mat41;
	float w = ret[3];
	return Vector3(ret[0] / w, ret[1] / w, ret[2] / w);
}

float Vector3::sinValue(const Vector3& vector0, const Vector3& vector1)
{
	float a = vector0.getMagnitude();
	float b = vector1.getMagnitude();

	assert(a != 0 && b != 0);

	Determinant3 det;
	det.setRow(0, Vector3(1,1,1));
	det.setRow(1, vector0);
	det.setRow(2, vector1);

	return getDetMagnitude(det) / (a * b);
}

bool Vector3::isThreePointsOnSameLine(const Vector3& point0, const Vector3& point1, const Vector3& point2)
{
	Vector3 v0 = point2 - point0;
	Vector3 v1 = point2 - point1;

	Determinant3 det;
	det.setRow(0, Vector3(1, 1, 1));
	det.setRow(1, v0);
	det.setRow(2, v1);

	return getDetMagnitude(det) == 0;
}

bool Vector3::isThreeVectorInSamePlane(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2)
{
	Determinant3 det;
	det.setRow(0, vector0);
	det.setRow(1, vector1);
	det.setRow(2, vector2);

	return getDetMagnitude(det) == 0;
}

Vector3 Vector3::calDoubleCross(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2)
{
	float a = Vector3::dot(vector0, vector2);
	float b = Vector3::dot(vector1, vector2);

	return vector1 * a - vector0 * b;
}

float Vector3::calTripleProduct(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2)
{
	Vector3 v0 = Vector3::cross(vector0, vector1);

	return Vector3::dot(v0, vector2);
}

math::Vector3::~Vector3()
{

}

void math::Vector3::normalize()
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

math::Vector3 math::Vector3::normalize(const Vector3& vector)
{
	math::Vector3 ret;
	float magn = vector.getMagnitude();
	if (magn == 0)
	{
		return vector;
	}

	for (int i = 0; i < vector.getLength(); i++)
	{
		ret.setValue(i, vector.getValue(i) / magn);
	}

	return ret;
}
