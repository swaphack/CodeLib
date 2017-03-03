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

void Matrix44::rotate(const Vector3& vector)
{
// 	Matrix44 matZ;
// 	matZ[0] = cos(vector.z); matZ[1] = sin(vector.z);
// 	matZ[4] = -sin(vector.z); matZ[5] = cos(vector.z);
// 
// 	Matrix44 matY;
// 	matY[0] = cos(vector.y); matY[2] = -sin(vector.y);
// 	matY[8] = sin(vector.y); matY[10] = cos(vector.y);
// 
// 	Matrix44 matX;
// 	matX[5] = cos(vector.x); matX[6] = sin(vector.x);
// 	matX[9] = -sin(vector.x); matX[10] = cos(vector.x);

	Matrix44 mat;

	values[0] = cos(vector.y) * cos(vector.z);  
	values[1] = cos(vector.y) * sin(vector.z);  
	values[2] = -sin(vector.y);

	values[4] = -cos(vector.x) * sin(vector.z) + sin(vector.x) * sin(vector.y) * cos(vector.z);
	values[5] = cos(vector.x) * cos(vector.z) + sin(vector.x) * sin(vector.y) * cos(vector.z);
	values[6] = sin(vector.x) * cos(vector.y);

	values[8] = sin(vector.x) * sin(vector.z) + cos(vector.x) * sin(vector.y) * cos(vector.z);
	values[9] = -sin(vector.x) * cos(vector.z) + cos(vector.x) * sin(vector.y) * sin(vector.z);
	values[10] = cos(vector.x) * cos(vector.y);
	
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
