#include "Matrix2x2.h"

using namespace math;


Matrix2x2::Matrix2x2()
{

}

Matrix2x2::Matrix2x2(float a00, float a01, float a10, float a11)
{
	(*this)[0] = a00;
	(*this)[1] = a01;
	(*this)[2] = a10;
	(*this)[3] = a11;
}

math::Matrix2x2::Matrix2x2(const Matrix2x2& mat)
{
	this->set(mat.getValue());
}

math::Matrix2x2& math::Matrix2x2::operator=(const Matrix2x2& mat)
{
	this->set(mat.getValue());
	return *this;
}

math::Matrix2x2::Matrix2x2(const float* value)
{
	this->set(value);
}

Matrix2x2::~Matrix2x2()
{

}
