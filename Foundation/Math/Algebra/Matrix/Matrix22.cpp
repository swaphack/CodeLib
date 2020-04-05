#include "Matrix22.h"

using namespace math;


Matrix22::Matrix22()
	:Matrix(2,2)
{

}

Matrix22::Matrix22(float a00, float a01, float a10, float a11)
	: Matrix22()
{
	_values[0] = a00;
	_values[1] = a01;
	_values[2] = a10;
	_values[3] = a11;
}

Matrix22::~Matrix22()
{

}
