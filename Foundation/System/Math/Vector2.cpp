#include "Vector2.h"
#include <cmath>
using namespace sys;

Vector2::Vector2() 
:x(0)
, y(0)
{

}

Vector2::Vector2(float x, float y) 
: x(x)
, y(y)
{

}

Vector2::Vector2(const Vector2& point32) 
: x(point32.x)
, y(point32.y)
{

}

float Vector2::getLength() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

void Vector2::add(const Vector2& point32)
{
	x += point32.x;
	y += point32.y;
}

void Vector2::sub(const Vector2& point32)
{
	x -= point32.x;
	y -= point32.y;
}

void Vector2::mult(const Vector2& point32)
{
	x *= point32.x;
	y *= point32.y;
}

void Vector2::mult(const float ratio)
{
	x *= ratio;
	y *= ratio;
}

void Vector2::div(const Vector2& point32)
{
	x /= point32.x;
	y /= point32.y;
}

void Vector2::div(const float ratio)
{
	if (ratio == 0)
	{
		return;
	}

	x /= ratio;
	y /= ratio;
}

Vector2& Vector2::operator=(const Vector2& point32)
{
	x = point32.x;
	y = point32.y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2& vector)
{
	Vector2 newVector;
	newVector.add(*this);
	newVector.add(vector);
	return newVector;
}

Vector2 Vector2::operator-(const Vector2& vector)
{
	Vector2 newVector;
	newVector.add(*this);
	newVector.sub(vector);
	return newVector;
}

Vector2 Vector2::operator/(const float k)
{
	if (k == 0)
	{
		return *this;
	}

	Vector2 newVector = *this;
	newVector.div(k);
	return newVector;
}

Vector2 Vector2::operator*(const float k)
{
	Vector2 newVector = *this;
	newVector *= k;

	return newVector;
}

Vector2 Vector2::operator+(const Vector2& vector) const
{
	Vector2 newVector;
	newVector.add(*this);
	newVector.add(vector);
	return newVector;
}

Vector2 Vector2::operator-(const Vector2& vector) const
{
	Vector2 newVector;
	newVector.add(*this);
	newVector.sub(vector);
	return newVector;
}

Vector2 Vector2::operator/(const float k) const
{
	if (k == 0)
	{
		return *this;
	}

	Vector2 newVector = *this;
	newVector.div(k);
	return newVector;
}

Vector2 Vector2::operator*(const float k) const
{
	Vector2 newVector = *this;
	newVector *= k;

	return newVector;
}

Vector2& Vector2::operator+=(const Vector2& vector)
{
	x += vector.x;
	y += vector.y;

	return *this;
}

Vector2& Vector2::operator-=(const Vector2& vector)
{
	x -= vector.x;
	y -= vector.y;

	return *this;
}

Vector2& Vector2::operator*=(const float k)
{
	x *= k;
	y *= k;

	return *this;
}

Vector2& Vector2::operator/=(const float k)
{
	if (k == 0)
	{
		return *this;
	}
	x /= k;
	y /= k;

	return *this;
}

bool Vector2::operator==(const Vector2& vector)
{
	return x == vector.x && y == vector.y;
}

bool Vector2::operator!=(const Vector2& vector)
{
	return x != vector.x || y == vector.y;
}

float Vector2::dot(const Vector2& vector0, const Vector2& vector1)
{
	return vector0.x * vector1.x + vector0.y * vector1.y;
}

Vector2 Vector2::cross(const Vector2& vector0, const Vector2& vector1)
{
	Vector2 newVector;
	newVector.x = vector0.x * vector1.y;
	newVector.y = -vector0.y * vector1.x;

	return newVector;
}

float Vector2::distance(const Vector2& point320, const Vector2& point321)
{
	return sqrt(pow(point320.x - point321.x, 2) + pow(point320.y - point321.y, 2));
}

int32 Vector2::direction(const Vector2& vector0, const Vector2& vector1)
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

float Vector2::cosAngle(const Vector2& vector0, const Vector2& vector1)
{
	float l0 = vector0.getLength();
	float l1 = vector1.getLength();

	if (l0 == 0 || l1 == 0)
	{
		return 0;
	}

	return Vector2::dot(vector0, vector1) / (l0 * l1);
}

float Vector2::sinAngle(const Vector2& vector0, const Vector2& vector1)
{
	float l0 = vector0.getLength();
	float l1 = vector1.getLength();

	if (l0 == 0 || l1 == 0)
	{
		return 0;
	}

	float l2 = Vector2::cross(vector0, vector1).getLength();

	return l2 / (l0 * l1);
}

float Vector2::project(const Vector2& vector0, const Vector2& vector1)
{
	float l0 = vector0.getLength();
	if (l0 == 0)
	{
		return 0;
	}
	return Vector2::dot(vector0, vector1) / l0;
}

float Vector2::getRotateAngle(const Vector2& vector0, const Vector2& vector1)
{
	const float epsilon = 1.0e-6;
	const float nyPI = acos(-1.0f);

	float distVal, dotVal, degreeVal, angleVal;

	float l0 = vector0.getLength();
	float l1 = vector1.getLength();

	float x1 = vector0.x / l0;
	float y1 = vector0.y / l0;

	float x2 = vector1.x / l1;
	float y2 = vector1.y / l1;

	dotVal = x1 * x2 + y1 * y2;
	if (fabs(dotVal - 1.0f) <= epsilon)
	{
		angleVal = 0;
	}
	else if (fabs(dotVal + 1.0f) <= epsilon)
	{
		angleVal = nyPI;
	}
	else
	{
		float crossVal;
		angleVal = acos(dotVal);
		crossVal = x1 * y2 - x2 * y1;
		if (crossVal < 0)
		{
			angleVal = 2 * nyPI - angleVal;
		}
	}

	degreeVal = angleVal* 180.0 / nyPI;

	return degreeVal;
}
