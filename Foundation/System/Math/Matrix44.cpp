#include "Matrix44.h"

using namespace sys;


Matrix44::Matrix44()
:Matrix(4, 4)
{
	this->unit();
}

void Matrix44::unit()
{
	values[0] = 1;  values[1] = 0;  values[2] = 0;  values[3] = 0; // x
	values[4] = 0;  values[5] = 1;  values[6] = 0;  values[7] = 0; // y
	values[8] = 0;  values[9] = 0;  values[10] = 1; values[11] = 0; // z
	values[12] = 0; values[13] = 0; values[14] = 0; values[15] = 1; // translate
}

void Matrix44::translate(const Vector3& vector)
{
	Matrix44 mat;
	values[12] = vector.x; values[13] = vector.y; values[14] = vector.z;

	*this *= mat;
}

void Matrix44::scale(const Vector3& vector)
{
	Matrix44 mat;
	mat[0] = vector.x;
	mat[5] = vector.y;
	mat[10] = vector.z;

	*this *= mat;
}

void Matrix44::rotate(const Vector3& rotation)
{
	Matrix44 mat = Matrix44::createWithRotation(rotation);
	*this *= mat;
}

void Matrix44::rotateX(float x)
{
	Matrix44 mat;
	mat[5] = cos(x); mat[6] = sin(x);
	mat[9] = -sin(x); mat[10] = cos(x);
	*this *= mat;
}

void Matrix44::rotateY(float y)
{
	Matrix44 mat;
	mat[0] = cos(y); mat[2] = -sin(y);
	mat[8] = sin(y); mat[10] = cos(y);
	*this *= mat;
}

void Matrix44::rotateZ(float z)
{
	Matrix44 mat;
	mat[0] = cos(z); mat[1] = sin(z);
	mat[4] = -sin(z); mat[5] = cos(z);
	*this *= mat;
}


Matrix44 Matrix44::createWithRotation(const Vector3& rotation)
{
	float cosA = cos(rotation.x);
	float cosB = cos(rotation.y);
	float cosR = cos(rotation.z);
	float sinA = sin(rotation.x);
	float sinB = sin(rotation.y);
	float sinR = sin(rotation.z);

	Matrix44 mat;
	mat.values[0] = cosA * cosR - cosB * sinA * sinR;
	mat.values[1] = -cosB * cosR * sinA - cosA * sinR;
	mat.values[2] = sinA * sinB;

	mat.values[4] = cosR * sinA + cosA * cosB * sinR;
	mat.values[5] = cosA * cosB * cosR - sinA * sinR;
	mat.values[6] = -cosA * sinB;

	mat.values[8] = sinB * sinR;
	mat.values[9] = cosR * sinB;
	mat.values[10] = cosB;

	return mat;
}

Matrix44 Matrix44::createWithRotationByAxis(const Vector3& axis, float radian)
{
	float cosR = cos(radian);
	float sinR = sin(radian);
	Matrix44 mat;

	mat.values[0] = cosR + (1 - cosR) * axis.x * axis.x;
	mat.values[1] = (1 - cosR) * axis.x * axis.y - sinR * axis.z;
	mat.values[2] = (1 - cosR) * axis.x * axis.z + sinR * axis.y;

	mat.values[4] = (1 - cosR) * axis.x * axis.y + sinR * axis.z;
	mat.values[5] = cosR + (1 - cosR) * axis.y * axis.y;
	mat.values[6] = (1 - cosR) * axis.y * axis.z - sinR * axis.x;

	mat.values[8] = (1 - cosR) * axis.x * axis.z - sinR * axis.y;
	mat.values[9] = (1 - cosR) * axis.y * axis.z + sinR * axis.x;
	mat.values[10] = cosR + (1 - cosR) * axis.z * axis.z;

	return mat;
}