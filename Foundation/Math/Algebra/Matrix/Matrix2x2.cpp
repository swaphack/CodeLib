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
	this->assign(mat.getValue());
}

math::Matrix2x2::Matrix2x2(const SquareMatrix2& mat)
{
	this->assign(mat.getValue());
}

math::Matrix2x2::Matrix2x2(const SquareMatrix<float, 2>& mat)
{
	this->assign(mat.getValue());
}

math::Matrix2x2& math::Matrix2x2::operator=(const Matrix2x2& mat)
{
	this->assign(mat.getValue());
	return *this;
}

Matrix2x2 math::Matrix2x2::operator*(const Matrix2x2& mat)
{
	float value[4] = { 0 };
	value[0] = getValue(0) * mat.getValue(0) + getValue(1) * mat.getValue(2);
	value[1] = getValue(0) * mat.getValue(1) + getValue(1) * mat.getValue(3);
	value[2] = getValue(2) * mat.getValue(0) + getValue(3) * mat.getValue(2);
	value[3] = getValue(2) * mat.getValue(1) + getValue(3) * mat.getValue(3);

	return Matrix2x2(value);
}

math::Matrix2x2::Matrix2x2(const float* value)
{
	this->assign(value);
}

Matrix2x2::~Matrix2x2()
{

}
