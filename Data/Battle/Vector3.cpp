#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
:x(0)
, y(0)
, z(0)
{

}

Vector3::Vector3(float x, float y) :x(x), y(y), z(0)
{

}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{

}

float Vector3::Distance(const Vector3& target)
{
	return sqrt(pow(x - target.x, 2) + pow(y - target.y, 2) + pow(z - target.z, 2));
}

float Vector3::Length()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::operator-(const Vector3& target)
{
	return Vector3(x - target.x, y - target.y, z - target.z);
}

Vector3 Vector3::operator+(const Vector3& target)
{
	return Vector3(x + target.x, y + target.y, z + target.z);
}

Vector3 Vector3::operator*(float k)
{
	return Vector3(x * k, y *k, z * k);
}

