#include "Matrix33.h"

using namespace sys;


Matrix33::Matrix33() 
:Matrix(3, 3)
{
	this->unit();
}

void Matrix33::unit()
{
	values[0] = 1; values[1] = 0; values[2] = 0; // x
	values[3] = 0; values[4] = 1; values[5] = 0; // y
	values[6] = 0; values[7] = 0; values[8] = 1; // translate
}

void Matrix33::translate(const Vector2& vector)
{
	Matrix33 mat;
	mat[6] = vector.x; mat[7] = vector.y;

	*this *= mat;
}

void Matrix33::scale(const Vector2& vector)
{
	Matrix33 mat;
	mat[0] = vector.x;
	mat[4] = vector.y;

	*this *= mat;
}

void Matrix33::rotate(float rotation)
{
	Matrix33 mat;
	mat[0] = cos(rotation); mat[1] = sin(rotation);
	mat[3] = -sin(rotation); mat[4] = cos(rotation);

	*this *= mat;
}
