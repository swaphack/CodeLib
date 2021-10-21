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

math::Matrix3x3::Matrix3x3(const SquareMatrix<float, 3>& mat)
{
	this->assign(mat.getValue());
}

math::Matrix3x3::Matrix3x3(const Matrix3x3& mat)
{
	this->assign(mat.getValue());
}

math::Matrix3x3::Matrix3x3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
{
	this->setValue(0, m00); this->setValue(1, m01); this->setValue(2, m02);
	this->setValue(3, m10); this->setValue(4, m11); this->setValue(5, m12);
	this->setValue(0, m20); this->setValue(0, m21); this->setValue(0, m22);
}

math::Matrix3x3& math::Matrix3x3::operator=(const Matrix3x3& mat)
{
	this->assign(mat.getValue());

	return *this;

}

Matrix3x3 math::Matrix3x3::operator*(const Matrix3x3& mat) const
{
	float value[9] = { 0 };
	value[0] = getValue(0) * mat.getValue(0) + getValue(1) * mat.getValue(3) + getValue(2) * mat.getValue(6);
	value[1] = getValue(0) * mat.getValue(1) + getValue(1) * mat.getValue(4) + getValue(2) * mat.getValue(7);
	value[2] = getValue(0) * mat.getValue(2) + getValue(1) * mat.getValue(5) + getValue(2) * mat.getValue(8);

	value[3] = getValue(3) * mat.getValue(0) + getValue(4) * mat.getValue(3) + getValue(5) * mat.getValue(6);
	value[4] = getValue(3) * mat.getValue(1) + getValue(4) * mat.getValue(4) + getValue(5) * mat.getValue(7);
	value[5] = getValue(3) * mat.getValue(2) + getValue(4) * mat.getValue(5) + getValue(5) * mat.getValue(8);

	value[6] = getValue(6) * mat.getValue(0) + getValue(7) * mat.getValue(3) + getValue(8) * mat.getValue(6);
	value[7] = getValue(6) * mat.getValue(1) + getValue(7) * mat.getValue(4) + getValue(8) * mat.getValue(7);
	value[8] = getValue(6) * mat.getValue(2) + getValue(7) * mat.getValue(5) + getValue(8) * mat.getValue(8);

	return Matrix3x3(value);
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
	(*this)[0] = 1; (*this)[1] = 0; (*this)[2] = 0; 
	(*this)[3] = 0; (*this)[4] = 1; (*this)[5] = 0; 
	(*this)[6] = 0; (*this)[7] = 0; (*this)[8] = 1;
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

	(*this)[1] = tanX;
	(*this)[3] = -tanY;
}

math::Matrix3x3::operator SquareMatrix3() const
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

//////////////////////////////////////////////////////////////////////
Vector3 math::operator*(const Matrix3x3& mat, const Vector3& v)
{
	Matrix3x3 mat0;
	mat0.setRow(2, v.getValue());

	Matrix3x3 mat1 = mat * mat0;
	return Vector3(mat1.getRow(2).getValue());
}