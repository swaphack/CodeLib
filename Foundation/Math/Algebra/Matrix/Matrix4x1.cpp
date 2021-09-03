#include "Matrix4x1.h"
#include <cassert>
using namespace math;

Matrix4x1::Matrix4x1()
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
	(*this)[3] = 1;
}

Matrix4x1::Matrix4x1(const Vector3& vector)
	: Matrix4x1(vector, 1)
{

}

Matrix4x1::Matrix4x1(const Vector3& vector, float w)
{
	(*this)[0] = vector.getX();
	(*this)[1] = vector.getY();
	(*this)[2] = vector.getZ();
	(*this)[3] = w;
}

Matrix4x1::Matrix4x1(float x, float y, float z)
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = 1;
}

Matrix4x1::Matrix4x1(float x, float y, float z, float w)
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = w;
}

Matrix4x1::operator Vector3() const
{
	float w = (*this)[3];

	assert(w != 0);

	float x = (*this)[0] / w;
	float y = (*this)[1] / w;
	float z = (*this)[2] / w;
	return Vector3(x, y, z);
}

math::Matrix4x1::Matrix4x1(const float* value)
	: Matrix4x1()
{
	this->assign(value);
}

math::Matrix4x1::~Matrix4x1()
{

}
