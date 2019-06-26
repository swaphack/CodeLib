#include "Vector3.h"
#include "Vector2.h"

using namespace sys;


Vector3::Vector3() 
:x(0)
, y(0)
, z(0)
{

}

Vector3::Vector3(float x, float y, float z /*= 0*/) 
: x(x)
, y(y)
, z(z)
{

}

Vector3::Vector3(const Vector2& vector)
: x(vector.x)
, y(vector.y)
, z(0)
{

}

Vector3::Vector3(const Vector3& vector) : x(vector.x), y(vector.y), z(vector.z)
{

}



void Vector3::add(const Vector3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
}

void Vector3::sub(const Vector3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
}

void Vector3::mult(const float ratio)
{
	x *= ratio;
	y *= ratio;
	z *= ratio;
}

void Vector3::mult(const Vector3& vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
}

void Vector3::div(const float ratio)
{
	if (ratio == 0)
	{
		return;
	}
	x /= ratio;
	y /= ratio;
	z /= ratio;
}

bool Vector3::isZero()
{
	return x == 0.0f && y == 0.0f && z == 0.0f;
}

float Vector3::getLength() const
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3& Vector3::operator=(const Vector2& vector)
{
	x = vector.x;
	y = vector.y;
	
	return *this;
}

Vector3& Vector3::operator=(const Vector3& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

Vector3 Vector3::operator+(const Vector3& vector)
{
	Vector3 newVector;
	newVector.add(*this);
	newVector.add(vector);
	return newVector;
}

Vector3 Vector3::operator-(const Vector3& vector)
{
	Vector3 newVector;
	newVector.add(*this);
	newVector.sub(vector);
	return newVector;
}

Vector3 Vector3::operator/(const float k)
{
	if (k == 0)
	{
		return *this;
	}

	Vector3 newVector = *this;
	newVector.div(k);
	return newVector;
}

Vector3 Vector3::operator*(const float k)
{
	Vector3 newVector = *this;
	newVector *= k;

	return newVector;
}

Vector3 Vector3::operator+(const Vector3& vector) const
{
	Vector3 newVector;
	newVector.add(*this);
	newVector.add(vector);
	return newVector;
}

Vector3 Vector3::operator-(const Vector3& vector) const
{
	Vector3 newVector;
	newVector.add(*this);
	newVector.sub(vector);
	return newVector;
}

Vector3 Vector3::operator/(const float k) const
{
	if (k == 0)
	{
		return *this;
	}

	Vector3 newVector = *this;
	newVector.div(k);
	return newVector;
}

Vector3 Vector3::operator*(const float k) const
{
	Vector3 newVector = *this;
	newVector *= k;

	return newVector;
}

Vector3& Vector3::operator+=(const Vector3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;

	return *this;
}

Vector3& Vector3::operator*=(const float k)
{
	x *= k;
	y *= k;
	z *= k;

	return *this;
}

Vector3& Vector3::operator/=(const float k)
{
	if (k == 0)
	{
		return *this;
	}
	x /= k;
	y /= k;
	z /= k;

	return *this;
}

bool Vector3::operator==(const Vector3& vector)
{
	return x == vector.x && y == vector.y && z == vector.z;
}

bool Vector3::operator!=(const Vector3& vector)
{
	return x != vector.x || y == vector.y || z == vector.z;
}

float Vector3::dot(const Vector3& vector0, const Vector3& vector1)
{
	return vector0.x * vector1.x + vector0.y * vector1.y + vector0.z * vector1.z;
}

Vector3 Vector3::cross(const Vector3& vector0, const Vector3& vector1)
{
	Vector3 newVector;
	newVector.x = vector0.y * vector1.z - vector0.z * vector1.y;
	newVector.y = vector0.z * vector1.x - vector0.x * vector1.z;
	newVector.z = vector0.x * vector1.y - vector0.y * vector1.x;

	return newVector;
}

float Vector3::distance(const Vector3& point320, const Vector3& point321)
{
	return sqrt(pow(point320.x - point321.x, 2) + pow(point320.y - point321.y, 2) + pow(point320.z - point321.z, 2));
}

int32 Vector3::direction(const Vector3& vector0, const Vector3& vector1)
{
	float value = dot(vector0, vector1);
	if (value > 0)
	{
		return 1;
	}
	else if (value == 0)
	{
		return 0;
	}
	else if (value < 0)
	{
		return 2;
	}

	return -1;
}

float Vector3::cosAngle(const Vector3& vector0, const Vector3& vector1)
{
	float l0 = vector0.getLength();
	float l1 = vector1.getLength();

	if (l0 == 0 || l1 == 0)
	{
		return 0;
	}
	
	return Vector3::dot(vector0, vector1) / (l0 * l1);
}

float Vector3::project(const Vector3& vector0, const Vector3& vector1)
{
	float l0 = vector0.getLength();
	if (l0 == 0)
	{
		return 0;
	}
	return Vector3::dot(vector1, vector0) / l0;
}


