#include "Matrix3x3.h"
#include "Matrix4x4.h"
using namespace math;


Matrix3x3::Matrix3x3() 
{
	this->loadIdentity();
}

Matrix3x3::Matrix3x3(const Vector3& row0, const Vector3& row1, const Vector3& row2)
{
	this->setRow(0, row0);
	this->setRow(1, row1);
	this->setRow(2, row2);
}

math::Matrix3x3::Matrix3x3(const Matrix4x4& mat)
{
	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}
}

math::Matrix3x3::Matrix3x3(const SquareMatrix3& mat)
{
	this->assign(mat.getValue());
}

math::Matrix3x3::Matrix3x3(const Matrix3x3& mat)
{
	this->assign(mat.getValue());
}

math::Matrix3x3& math::Matrix3x3::operator=(const Matrix3x3& mat)
{
	this->assign(mat.getValue());

	return *this;

}

math::Matrix3x3::Matrix3x3(const float* value)
{
	this->assign(value);
}

Matrix3x3::~Matrix3x3()
{

}

void Matrix3x3::loadIdentity()
{
	(*this)[0] = 1; (*this)[1] = 0; (*this)[2] = 0; // x
	(*this)[3] = 0; (*this)[4] = 1; (*this)[5] = 0; // y
	(*this)[6] = 0; (*this)[7] = 0; (*this)[8] = 1; // translate
}

void Matrix3x3::setTranslate(const Vector2& vector)
{
	(*this)[6] = vector.getX(); (*this)[7] = vector.getY();
}

void Matrix3x3::setScale(const Vector2& vector)
{
	(*this)[0] = vector.getX();
	(*this)[4] = vector.getY();
}

void Matrix3x3::setRotate(float rotation)
{
	(*this)[0] = cos(rotation); (*this)[1] = sin(rotation);
	(*this)[3] = -sin(rotation); (*this)[4] = cos(rotation);
}

void math::Matrix3x3::setShear(float radianX, float radianY)
{
	float tanX = tanf(radianX);
	float tanY = tanf(radianY);

	(*this)[1] = tanY;
	(*this)[3] = tanX;
}

math::Matrix3x3::operator SquareMatrix3()
{
	return SquareMatrix3(*this);
}

Matrix3x3& math::Matrix3x3::operator=(const Matrix4x4& mat)
{
	for (int i = 0; i < this->getHeight(); i++)
	{
		for (int j = 0; j < this->getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}

	return *this;
}
