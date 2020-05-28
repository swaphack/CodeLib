#include "Matrix41.h"
#include <cassert>
using namespace math;

Matrix41::Matrix41()
	:Matrix(4, 1)
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
	(*this)[3] = 1;
}

Matrix41::Matrix41(const Vector3& vector)
	: Matrix41(vector, 1)
{

}

Matrix41::Matrix41(const Vector3& vector, float w)
	: Matrix41()
{
	(*this)[0] = vector.getX();
	(*this)[1] = vector.getY();
	(*this)[2] = vector.getZ();
	(*this)[3] = w;
}

Matrix41::Matrix41(float x, float y, float z)
	: Matrix41()
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = 1;
}

Matrix41::Matrix41(float x, float y, float z, float w)
	: Matrix41()
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = w;
}

Matrix41::operator Vector3()
{
	float w = (*this)[3];

	assert(w != 0);

	float x = (*this)[0] / w;
	float y = (*this)[1] / w;
	float z = (*this)[2] / w;
	return Vector3(x, y, z);
}

math::Matrix41::Matrix41(const float* value)
	: Matrix41()
{
	this->set(value, 4, 1);
}

math::Matrix41::~Matrix41()
{

}
