#include "Matrix44.h"
#include "Basic/base.h"
#include "Matrix14.h"
#include "Matrix33.h"
#include <cassert>

using namespace math;


Matrix44::Matrix44()
:Matrix(4, 4)
{
	this->loadIdentity();
}

Matrix44::Matrix44(const Matrix44& mat)
	: Matrix44()
{
	for (size_t i = 0; i < getSize(); i++)
	{
		setValue(i, mat.getValue(i));
	}
}

Matrix44::Matrix44(const Matrix33& mat)
	: Matrix44()
{
	for (int i = 0; i < mat.getHeight(); i++)
	{
		for (int j = 0; j < mat.getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}
}

Matrix44::Matrix44(const float* value)
	: Matrix44()
{
	this->set(value, 4, 4);
}

void Matrix44::loadIdentity()
{
	(*this)[0] = 1;  (*this)[1] = 0;  (*this)[2] = 0;  (*this)[3] = 0; // x
	(*this)[4] = 0;  (*this)[5] = 1;  (*this)[6] = 0;  (*this)[7] = 0; // y
	(*this)[8] = 0;  (*this)[9] = 0;  (*this)[10] = 1; (*this)[11] = 0; // z
	(*this)[12] = 0; (*this)[13] = 0; (*this)[14] = 0; (*this)[15] = 1; // translate
}

void Matrix44::setTranslate(const Vector3& vector)
{
	(*this)[12] = vector.getX(); 
	(*this)[13] = vector.getY(); 
	(*this)[14] = vector.getZ();
}

void Matrix44::setScale(const Vector3& vector)
{
	(*this)[0] = vector.getX();
	(*this)[5] = vector.getY();
	(*this)[10] = vector.getZ();
}

void Matrix44::setRotate(const Vector3& rotation)
{
	float cosX = cos(rotation.getX());
	float cosY = cos(rotation.getY());
	float cosZ = cos(rotation.getZ());
	float sinX = sin(rotation.getX());
	float sinY = sin(rotation.getY());
	float sinZ = sin(rotation.getZ());

	(*this)[0] = cosY * cosZ;
	(*this)[1] = -cosX * sinZ + sinX * sinY* cosZ;
	(*this)[2] = sinX * sinZ + cosX * sinY * cosZ;
	(*this)[3] = 0;

	(*this)[4] = cosY * sinZ;
	(*this)[5] = cosX * cosZ + sinX * sinY * sinZ;
	(*this)[6] = -sinX * cosZ + cosX * sinY * sinZ;
	(*this)[7] = 0;

	(*this)[8] = - sinY;
	(*this)[9] = sinX * cosY;
	(*this)[10] = cosX * cosY;
	(*this)[11] = 0;

	(*this)[12] = 0;
	(*this)[13] = 0;
	(*this)[14] = 0;
	(*this)[15] = 1;
}

void Matrix44::setRotateX(float x)
{
	(*this)[5] = cos(x); (*this)[6] = -sin(x);
	(*this)[9] = sin(x); (*this)[10] = cos(x);
}

void Matrix44::setRotateY(float y)
{
	(*this)[0] = cos(y); (*this)[2] = sin(y);
	(*this)[8] = -sin(y); (*this)[10] = cos(y);
}

void Matrix44::setRotateZ(float z)
{
	Matrix44 mat;
	(*this)[0] = cos(z); (*this)[1] = -sin(z);
	(*this)[4] = sin(z); (*this)[5] = cos(z);
}

void Matrix44::setRotationByAxis(const Vector3& axis, float radian)
{
	float cosR = cos(radian);
	float sinR = sin(radian);

	float u = axis.getX();
	float v = axis.getY();
	float w = axis.getZ();

	(*this)[0] = cosR + (u * u) * (1 - cosR);
	(*this)[1] = u * v * (1 - cosR) + w * sinR;
	(*this)[2] = u * w * (1 - cosR) - v * sinR;
	(*this)[3] = 0;

	(*this)[4] = u * v * (1 - cosR) - w * sinR;
	(*this)[5] = cosR + v * v * (1 - cosR);
	(*this)[6] = w * v * (1 - cosR) + u * sinR;
	(*this)[7] = 0;

	(*this)[8] = u * w * (1 - cosR) + v * sinR;
	(*this)[9] = v * w * (1 - cosR) - u * sinR;
	(*this)[10] = cosR + w * w * (1 - cosR);
	(*this)[11] = 0;

	(*this)[12] = 0;
	(*this)[13] = 0;
	(*this)[14] = 0;
	(*this)[15] = 1;
}

void Matrix44::setRotationByLine(const Vector3& src, const Vector3& dest, float radian)
{
	float a = src.getX();
	float b = src.getY();
	float c = src.getZ();

	Vector3 p = dest - src;
	p.normalize();

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

	(*this)[0] = uu + (vv + ww) * costheta;
	(*this)[1] = uv * (1 - costheta) + w * sintheta;
	(*this)[2] = uw * (1 - costheta) - v * sintheta;
	(*this)[3] = 0;

	(*this)[4] = uv * (1 - costheta) - w * sintheta;
	(*this)[5] = vv + (uu + ww) * costheta;
	(*this)[6] = vw * (1 - costheta) + u * sintheta;
	(*this)[7] = 0;

	(*this)[8] = uw * (1 - costheta) + v * sintheta;
	(*this)[9] = vw * (1 - costheta) - u * sintheta;
	(*this)[10] = ww + (uu + vv) * costheta;
	(*this)[11] = 0;

	(*this)[12] = (a * (vv + ww) - u * (bv + cw)) * (1 - costheta) + (bw - cv) * sintheta;
	(*this)[13] = (b * (uu + ww) - v * (au + cw)) * (1 - costheta) + (cu - aw) * sintheta;
	(*this)[14] = (c * (uu + vv) - w * (au + bv)) * (1 - costheta) + (av - bu) * sintheta;
	(*this)[15] = 1;
}

Matrix41 Matrix44::operator*(const Matrix41& mat)
{
	Matrix mat0 = *this;
	Matrix mat1 = mat0 * mat;
	return Matrix41(mat1.getValue());
}

Matrix44 Matrix44::operator*(const Matrix44& mat)
{
	Matrix mat0 = *this;
	Matrix mat1 = mat0 * mat;
	return Matrix44(mat1.getValue());
}

Vector3 Matrix44::getEularAngle() const
{
	float r32 = getValue((size_t)1, (size_t)2);
	float r33 = getValue((size_t)2, (size_t)2);
	float r31 = getValue((size_t)0, (size_t)2);
	float r21 = getValue((size_t)0, (size_t)1);
	float r11 = getValue((size_t)0, (size_t)0);

	float x = atan2(r32, r33);
	float y = atan2(-r31, sqrt(pow(r32, 2)+ pow(r33, 2)));
	float z = atan2(r21, r11);

	return Vector3(x, y, z);
}

math::Matrix44::Matrix44(const Matrix& mat)
	: Matrix44()
{
	assert(mat.getWidth() == this->getWidth() && mat.getHeight() == this->getHeight());

	for (int i = 0; i < mat.getHeight(); i++)
	{
		for (int j = 0; j < mat.getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}
}

math::Matrix44::~Matrix44()
{

}

math::Matrix44& math::Matrix44::operator=(const Matrix44& mat)
{
	for (size_t i = 0; i < getSize(); i++)
	{
		setValue(i, mat.getValue(i));
	}

	return *this;
}

math::Matrix44& math::Matrix44::operator=(const Matrix& mat)
{
	assert(mat.getWidth() == this->getWidth() && mat.getHeight() == this->getHeight());

	for (int i = 0; i < mat.getHeight(); i++)
	{
		for (int j = 0; j < mat.getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}

	return *this;
}

math::Matrix44& math::Matrix44::operator=(const Matrix33& mat)
{
	for (int i = 0; i < mat.getHeight(); i++)
	{
		for (int j = 0; j < mat.getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}

	return *this;
}

math::Matrix44 math::Matrix44::ortho(float left, float right, float bottom, float top,
	float znear, float zfar)
{
	math::Matrix44 mat;

	mat[0] = 2 / (right - left);
	mat[5] = 2 / (top - bottom);
	mat[10] = -2 / (zfar - znear);
	
	mat[12] = -(right + left) / (right - left);
	mat[13] = -(top + bottom) / (top - bottom);
	mat[14] = -(zfar + znear) / (zfar - znear);

	return mat;
}

math::Matrix44 math::Matrix44::frustum(float left, float right, float bottom, float top,
	float znear, float zfar)
{
	math::Matrix44 mat;

	float temp, temp2, temp3, temp4;
	temp = 2.0 * znear;
	temp2 = right - left;
	temp3 = top - bottom;
	temp4 = zfar - znear;
	mat[0] = temp / temp2;
	mat[1] = 0.0;
	mat[2] = 0.0;
	mat[3] = 0.0;
	mat[4] = 0.0;
	mat[5] = temp / temp3;
	mat[6] = 0.0;
	mat[7] = 0.0;
	mat[8] = (right + left) / temp2;
	mat[9] = (top + bottom) / temp3;
	mat[10] = (-zfar - znear) / temp4;
	mat[11] = -1.0;
	mat[12] = 0.0;
	mat[13] = 0.0;
	mat[14] = (-temp * zfar) / temp4;
	mat[15] = 0.0;

	return mat;
}

math::Matrix44 math::Matrix44::perspective(float fovyInDegrees, float aspectRatio, float znear, float zfar)
{
	float ymax, xmax;
	float temp, temp2, temp3, temp4;
	ymax = znear * tanf(fovyInDegrees * M_PI / 360.0);
	// ymin = -ymax;
	// xmin = -ymax * aspectRatio;
	xmax = ymax * aspectRatio;

	return frustum(-xmax, xmax, -ymax, ymax, znear, zfar);
}

math::Matrix44 math::Matrix44::lookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
{
	math::Vector3 f = math::Vector3::normalize(center - eye);
	math::Vector3 u = math::Vector3::normalize(up);
	math::Vector3 s = math::Vector3::normalize(math::Vector3::cross(f, u));
	u = math::Vector3::cross(s, f);

	math::Matrix44 Result;
	Result.setValue(0, 0, s.getX());
	Result.setValue(1, 0, s.getY());
	Result.setValue(2, 0, s.getZ());
	Result.setValue(0, 1, u.getX());
	Result.setValue(1, 1, u.getY());
	Result.setValue(2, 1, u.getZ());
	Result.setValue(0, 2, -f.getX());
	Result.setValue(1, 2, -f.getY());
	Result.setValue(2, 2, -f.getZ());
	Result.setValue(0, 3, math::Vector3::dot(s, eye));
	Result.setValue(1, 3, math::Vector3::dot(u, eye));
	Result.setValue(2, 3, math::Vector3::dot(f, eye));
	return Result;
}

math::Matrix44 math::Matrix44::getRST(const Vector3& rotate, const Vector3& scale, const Vector3& translate)
{
	math::Matrix44 matScale;
	matScale.setScale(scale);
	math::Matrix44 matRotate;
	matRotate.setRotate(rotate);
	math::Matrix44 matTranslate;
	matTranslate.setTranslate(translate);

	return matRotate * matScale * matTranslate;
}

math::Matrix44 math::Matrix44::getTSR(const Vector3& translate, const Vector3& scale, const Vector3& rotate)
{
	math::Matrix44 matScale;
	matScale.setScale(scale);
	math::Matrix44 matRotate;
	matRotate.setRotate(rotate);
	math::Matrix44 matTranslate;
	matTranslate.setTranslate(translate);

	return matTranslate * matScale * matRotate;
}

Vector3 math::Matrix44::transpose(const Vector3& src, const Matrix44& mat)
{
	//printf("%s\n", mat.toString().c_str());

	Matrix14 srcMatrix(src);
	Matrix14 result = srcMatrix * mat;
	//printf("%s\n", result.toString().c_str());
	Vector3 pos = (Vector3)result;
	return pos;
}

math::Vector3 math::Matrix44::getPosition() const
{
	return Vector3((*this)[12], (*this)[13], (*this)[14]);
}

math::Vector3 math::Matrix44::getScale() const
{
	return Vector3((*this)[0], (*this)[5], (*this)[10]);
}

