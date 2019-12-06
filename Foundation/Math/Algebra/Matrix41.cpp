#include "Matrix41.h"
#include <cassert>
using namespace math;

Matrix41::Matrix41()
	:Matrix(1, 4)
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
	: Matrix(1, 4)
{
	_values[0] = vector.x;
	_values[1] = vector.y;
	_values[2] = vector.z;
	_values[3] = w;
}

Matrix41::Matrix41(float x, float y, float z)
	: Matrix(1, 4)
{
	_values[0] = x;
	_values[1] = y;
	_values[2] = z;
	_values[3] = 1;
}

Matrix41::Matrix41(float x, float y, float z, float w)
	: Matrix(1, 4)
{
	_values[0] = x;
	_values[1] = y;
	_values[2] = z;
	_values[3] = w;
}

Vector3 Matrix41::operator()()
{
	float w = _values[3];

	assert(w != 0);

	Vector3 vector;
	vector.x = _values[0] / w;
	vector.y = _values[1] / w;
	vector.z = _values[2] / w;
	return vector;
}
