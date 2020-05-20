#include "Matrix22.h"

using namespace math;


Matrix22::Matrix22()
	:Matrix(2,2)
{

}

Matrix22::Matrix22(float a00, float a01, float a10, float a11)
	: Matrix22()
{
	(*this)[0] = a00;
	(*this)[1] = a01;
	(*this)[2] = a10;
	(*this)[3] = a11;
}

math::Matrix22::Matrix22(const Matrix22& mat)
	: Matrix22()
{
	this->set(mat.getValue(), mat.getHeight(), mat.getWidth());
}

Matrix22::~Matrix22()
{

}
