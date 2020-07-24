#include "Matrix22.h"

using namespace math;


Matrix22::Matrix22()
{

}

Matrix22::Matrix22(float a00, float a01, float a10, float a11)
{
	(*this)[0] = a00;
	(*this)[1] = a01;
	(*this)[2] = a10;
	(*this)[3] = a11;
}

math::Matrix22::Matrix22(const Matrix22& mat)
{
	this->set(mat.getValue());
}

math::Matrix22& math::Matrix22::operator=(const Matrix22& mat)
{
	this->set(mat.getValue());
	return *this;
}

math::Matrix22::Matrix22(const float* value)
{
	this->set(value);
}

Matrix22::~Matrix22()
{

}
