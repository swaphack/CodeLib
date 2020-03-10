#include "Vector.h"
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace math;

Vector::Vector(int32_t len)
	:Array(len)
{

}

Vector::Vector()
{

}

float Vector::getMagnitude() const
{
	float len = 0;
	for (int i = 0; i < _length; i++)
	{
		len += pow(_values[i], 2);
	}

	return sqrt(len);
}

float Vector::getMagnitudeSqr() const
{
	float len = 0;
	for (int i = 0; i < _length; i++)
	{
		len += pow(_values[i], 2);
	}

	return len;
}

Vector Vector::operator+(const Vector& vec) const
{
	assert(_length != vec.getSize());

	Vector target = *this;
	for (int i = 0; i < target.getSize(); i++)
	{
		target[i] += vec[i];
	}
	return target;
}

Vector Vector::operator-(const Vector& vec) const
{
	assert(_length != vec.getSize());

	Vector target = *this;
	for (int i = 0; i < target.getSize(); i++)
	{
		target[i] -= vec[i];
	}
	return target;
}

Vector Vector::operator*(float k) const
{
	Vector target = *this;
	for (int i = 0; i < target.getSize(); i++)
	{
		target[i] *= k;
	}
	return target;
}

Vector Vector::operator/(float k) const
{
	assert(k != 0);

	Vector target = *this;
	for (int i = 0; i < target.getSize(); i++)
	{
		target[i] /= k;
	}
	return target;
}

Vector& Vector::operator+=(const Vector& vec)
{
	assert(_length != vec.getSize());

	for (int i = 0; i < vec.getSize(); i++)
	{
		_values[i] += vec[i];
	}
	return *this;
}

Vector& Vector::operator-=(const Vector& vec)
{
	assert(_length != vec.getSize());

	for (int i = 0; i < vec.getSize(); i++)
	{
		_values[i] -= vec[i];
	}
	return *this;
}

Vector& Vector::operator*=(float k)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		_values[i] *= k;
	}
	return *this;
}

Vector& Vector::operator/=(float k)
{
	assert(k != 0);

	for (int i = 0; i < this->getSize(); i++)
	{
		_values[i] /= k;
	}
	return *this;
}

bool Vector::operator==(const Vector& vec)
{
	assert(_length == vec._length);

	for (int i = 0; i < _length; i++)
	{
		if (_values[i] != vec.getValue(i))
		{
			return false;
		}
	}

	return true;
}

bool Vector::operator!=(const Vector& vec)
{
	assert(_length == vec._length);

	for (int i = 0; i < _length; i++)
	{
		if (_values[i] != vec.getValue(i))
		{
			return true;
		}
	}

	return false;
}

Vector Vector::normalize() const
{
	float magn = this->getMagnitude();
	assert(magn > 0);

	Vector vec;
	vec.reset(_length);
	for (int i = 0; i < _length; i++)
	{
		vec.setValue(i, _values[i] / magn);
	}

	return vec;
}

float Vector::dot(const Vector& vector0, const Vector& vector1)
{
	assert(vector0.getSize() == vector1.getSize());

	float value = 0;
	for (int32_t i = 0; i < vector0.getSize(); i++)
	{
		value += vector0.getValue(i) * vector1.getValue(i);
	}

	return value;
}

float Vector::cosAngle(const Vector& vector0, const Vector& vector1)
{
	float a = vector0.getMagnitude();
	float b = vector1.getMagnitude();

	assert(a != 0 && b != 0);

	return Vector::dot(vector0, vector1) / (a * b);
}

