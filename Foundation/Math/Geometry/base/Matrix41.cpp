#include "Matrix41.h"
#include <cassert>
using namespace math;

Matrix41::Matrix41()
	:Matrix(4, 1)
{
	_values[0] = 0;
	_values[1] = 0;
	_values[2] = 0;
	_values[3] = 1;
}

Matrix41::Matrix41(const Vector3& vector)
	: Matrix41(vector, 1)
{

}

Matrix41::Matrix41(const Vector3& vector, float w)
	: Matrix41()
{
	_values[0] = vector.getX();
	_values[1] = vector.getY();
	_values[2] = vector.getZ();
	_values[3] = w;
}

Matrix41::Matrix41(float x, float y, float z)
	: Matrix41()
{
	_values[0] = x;
	_values[1] = y;
	_values[2] = z;
	_values[3] = 1;
}

Matrix41::Matrix41(float x, float y, float z, float w)
	: Matrix41()
{
	_values[0] = x;
	_values[1] = y;
	_values[2] = z;
	_values[3] = w;
}

Matrix41::operator Vector3()
{
	float w = _values[3];

	assert(w != 0);

	float x = _values[0] / w;
	float y = _values[1] / w;
	float z = _values[2] / w;
	return Vector3(x, y, z);
}
