#include "Matrix33.h"

using namespace math;


Matrix33::Matrix33() 
:Matrix(3, 3)
{
	this->normalize();
}

Matrix33::Matrix33(const Vector3& row0, const Vector3& row1, const Vector3& row2)
	: Matrix33()
{
	this->setRow(0, row0);
	this->setRow(1, row1);
	this->setRow(2, row2);
}

Matrix33::~Matrix33()
{

}

void Matrix33::normalize()
{
	(*this)[0] = 1; (*this)[1] = 0; (*this)[2] = 0; // x
	(*this)[3] = 0; (*this)[4] = 1; (*this)[5] = 0; // y
	(*this)[6] = 0; (*this)[7] = 0; (*this)[8] = 1; // translate
}

void Matrix33::setTranslate(const Vector2& vector)
{
	(*this)[2] = vector.getX(); (*this)[5] = vector.getY();
}

void Matrix33::setScale(const Vector2& vector)
{
	(*this)[0] = vector.getX();
	(*this)[4] = vector.getY();
}

void Matrix33::setRotate(float rotation)
{
	(*this)[0] = cos(rotation); (*this)[1] = -sin(rotation);
	(*this)[3] = sin(rotation); (*this)[4] = cos(rotation);
}
