#include "Matrix44.h"
#include <cassert>

using namespace math;


Matrix44::Matrix44()
:Matrix(4, 4)
{
	this->normalize();
}

Matrix44::Matrix44(const Matrix44& mat)
	: Matrix44()
{
	for (size_t i = 0; i < getSize(); i++)
	{
		setValue(i, mat.getValue(i));
	}
}

Matrix44::Matrix44(const Matrix& mat)
	: Matrix44()
{
	assert(mat.getSize() != 0);

	for (size_t i = 0; i < getSize(); i++)
	{
		setValue(i, mat.getValue(i));
	}
}

Matrix44::Matrix44(float* value)
	: Matrix44()
{
	this->set(value, 4, 4);
}

void Matrix44::normalize()
{
	_values[0] = 1;  _values[1] = 0;  _values[2] = 0;  _values[3] = 0; // x
	_values[4] = 0;  _values[5] = 1;  _values[6] = 0;  _values[7] = 0; // y
	_values[8] = 0;  _values[9] = 0;  _values[10] = 1; _values[11] = 0; // z
	_values[12] = 0; _values[13] = 0; _values[14] = 0; _values[15] = 1; // translate
}

void Matrix44::setTranslate(const Vector3& vector)
{
	_values[3] = vector.getX(); 
	_values[7] = vector.getY(); 
	_values[11] = vector.getZ();
}

void Matrix44::setScale(const Vector3& vector)
{
	_values[0] = vector.getX();
	_values[5] = vector.getY();
	_values[10] = vector.getZ();
}

void Matrix44::setRotate(const Vector3& rotation)
{
	float cosX = cos(rotation.getX());
	float cosY = cos(rotation.getY());
	float cosZ = cos(rotation.getZ());
	float sinX = sin(rotation.getX());
	float sinY = sin(rotation.getY());
	float sinZ = sin(rotation.getZ());

	_values[0] = cosY * cosZ;
	_values[1] = -cosX * sinZ + sinX * sinY* cosZ;
	_values[2] = sinX * sinZ + cosX * sinY * cosZ;
	_values[3] = 0;

	_values[4] = cosY * sinZ;
	_values[5] = cosX * cosZ + sinX * sinY * sinZ;
	_values[6] = -sinX * cosZ + cosX * sinY * sinZ;
	_values[7] = 0;

	_values[8] = - sinY;
	_values[9] = sinX * cosY;
	_values[10] = cosX * cosY;
	_values[11] = 0;

	_values[12] = 0;
	_values[13] = 0;
	_values[14] = 0;
	_values[15] = 1;
}

void Matrix44::setRotateX(float x)
{
	_values[5] = cos(x); _values[6] = -sin(x);
	_values[9] = sin(x); _values[10] = cos(x);
}

void Matrix44::setRotateY(float y)
{
	_values[0] = cos(y); _values[2] = sin(y);
	_values[8] = -sin(y); _values[10] = cos(y);
}

void Matrix44::setRotateZ(float z)
{
	Matrix44 mat;
	_values[0] = cos(z); _values[1] = -sin(z);
	_values[4] = sin(z); _values[5] = cos(z);
}

void Matrix44::setRotationByAxis(const Vector3& axis, float radian)
{
	float cosR = cos(radian);
	float sinR = sin(radian);

	float u = axis.getX();
	float v = axis.getY();
	float w = axis.getZ();

	_values[0] = cosR + (u * u) * (1 - cosR);
	_values[1] = u * v * (1 - cosR) + w * sinR;
	_values[2] = u * w * (1 - cosR) - v * sinR;
	_values[3] = 0;

	_values[4] = u * v * (1 - cosR) - w * sinR;
	_values[5] = cosR + v * v * (1 - cosR);
	_values[6] = w * v * (1 - cosR) + u * sinR;
	_values[7] = 0;

	_values[8] = u * w * (1 - cosR) + v * sinR;
	_values[9] = v * w * (1 - cosR) - u * sinR;
	_values[10] = cosR + w * w * (1 - cosR);
	_values[11] = 0;

	_values[12] = 0;
	_values[13] = 0;
	_values[14] = 0;
	_values[15] = 1;
}

void Matrix44::setRotationByLine(const Vector3& src, const Vector3& dest, float radian)
{
	float a = src.getX();
	float b = src.getY();
	float c = src.getZ();

	Vector3 p0 = dest - src;
	Vector3 p = p0.normalize();

	float u = p.getX();
	float v = p.getY();
	float w = p.getZ();

	float uu = u * u;
	float uv = u * v;
	float uw = u * w;
	float vv = v * v;
	float vw = v * w;
	float ww = w * w;
	float au = a * u;
	float av = a * v;
	float aw = a * w;
	float bu = b * u;
	float bv = b * v;
	float bw = b * w;
	float cu = c * u;
	float cv = c * v;
	float cw = c * w;

	float costheta = cos(radian);
	float sintheta = sin(radian);

	_values[0] = uu + (vv + ww) * costheta;
	_values[1] = uv * (1 - costheta) + w * sintheta;
	_values[2] = uw * (1 - costheta) - v * sintheta;
	_values[3] = 0;

	_values[4] = uv * (1 - costheta) - w * sintheta;
	_values[5] = vv + (uu + ww) * costheta;
	_values[6] = vw * (1 - costheta) + u * sintheta;
	_values[7] = 0;

	_values[8] = uw * (1 - costheta) + v * sintheta;
	_values[9] = vw * (1 - costheta) - u * sintheta;
	_values[10] = ww + (uu + vv) * costheta;
	_values[11] = 0;

	_values[12] = (a * (vv + ww) - u * (bv + cw)) * (1 - costheta) + (bw - cv) * sintheta;
	_values[13] = (b * (uu + ww) - v * (au + cw)) * (1 - costheta) + (cu - aw) * sintheta;
	_values[14] = (c * (uu + vv) - w * (au + bv)) * (1 - costheta) + (av - bu) * sintheta;
	_values[15] = 1;
}

Matrix41 Matrix44::operator*(const Matrix41& mat)
{
	Matrix mat0 = *this;
	Matrix mat1 = mat0 * mat;
	return Matrix41(mat1[0], mat1[1], mat1[2], mat1[3]);
}

Matrix44 Matrix44::operator*(const Matrix44& mat)
{
	Matrix mat0 = *this;
	Matrix mat1 = mat0 * mat;
	return Matrix44(mat1);
}

Vector3 Matrix44::getEularAngle()
{
	float r32 = getValue(1, 2);
	float r33 = getValue(2, 2);
	float r31 = getValue(0, 2);
	float r21 = getValue(0, 1);
	float r11 = getValue(0, 0);

	float x = atan2(r32, r33);
	float y = atan2(-r31, sqrt(pow(r32, 2)+ pow(r33, 2)));
	float z = atan2(r21, r11);

	return Vector3(x, y, z);
}


