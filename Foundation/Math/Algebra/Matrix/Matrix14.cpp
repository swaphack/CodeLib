#include "Matrix14.h"
#include <cassert>
using namespace math;

Matrix14::Matrix14()
{
	(*this)[0] = 0;
	(*this)[1] = 0;
	(*this)[2] = 0;
	(*this)[3] = 1;
}

Matrix14::Matrix14(const Vector3& vector)
	: Matrix14(vector, 1)
{

}

Matrix14::Matrix14(const Vector3& vector, float w)
{
	(*this)[0] = vector.getX();
	(*this)[1] = vector.getY();
	(*this)[2] = vector.getZ();
	(*this)[3] = w;
}

Matrix14::Matrix14(float x, float y, float z)
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = 1;
}

Matrix14::Matrix14(float x, float y, float z, float w)
{
	(*this)[0] = x;
	(*this)[1] = y;
	(*this)[2] = z;
	(*this)[3] = w;
}

Matrix14::operator Vector3()
{
	float w = (*this)[3];

	assert(w != 0);

	float x = (*this)[0] / w;
	float y = (*this)[1] / w;
	float z = (*this)[2] / w;
	return Vector3(x, y, z);
}

math::Matrix14::~Matrix14()
{

}

math::Matrix14 math::Matrix14::operator*(const math::Matrix44& mat)
{
	Matrix<float, 4, 4> mat0;
	mat0.setRow(0, this->getValue());
	Matrix<float, 4, 4> mat1(mat);

	Matrix44 mat2 = mat0 * mat1;
	return Matrix14(mat2[0], mat2[4], mat2[8], mat2[12]);
}
