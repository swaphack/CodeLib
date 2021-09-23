#include "Matrix2x2.h"

using namespace math;


Matrix2x2::Matrix2x2()
{

}

Matrix2x2::Matrix2x2(float m00, float m01, float m10, float m11)
{
	this->setValue(0, m00); this->setValue(1, m01); 
	this->setValue(2, m10); this->setValue(3, m11);
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
