#include "Matrix33.h"

using namespace math;


Matrix33::Matrix33() 
:Matrix(3, 3)
{
	this->normalize();
}

void Matrix33::normalize()
{
	_values[0] = 1; _values[1] = 0; _values[2] = 0; // x
	_values[3] = 0; _values[4] = 1; _values[5] = 0; // y
	_values[6] = 0; _values[7] = 0; _values[8] = 1; // translate
}

void Matrix33::setTranslate(const Vector2& vector)
{
	_values[2] = vector.x; _values[5] = vector.y;
}

void Matrix33::setScale(const Vector2& vector)
{
	_values[0] = vector.x;
	_values[4] = vector.y;
}

void Matrix33::setRotate(float rotation)
{
	_values[0] = cos(rotation); _values[1] = -sin(rotation);
	_values[3] = sin(rotation); _values[4] = cos(rotation);
}
