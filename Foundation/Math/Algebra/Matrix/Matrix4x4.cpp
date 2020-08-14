#include "Matrix4x4.h"
#include "Basic/base.h"
#include "Matrix1x4.h"
#include "Matrix3x3.h"
#include <cassert>

using namespace math;


Matrix4x4::Matrix4x4()
{
	this->loadIdentity();
}

Matrix4x4::Matrix4x4(const Matrix4x4& mat)
{
	*this = mat;
}

Matrix4x4::Matrix4x4(const Matrix3x3& mat)
{
	*this = mat;
}

Matrix4x4::Matrix4x4(const float* value)
{
	this->set(value);
}

void Matrix4x4::loadIdentity()
{
	(*this)[0] = 1;  (*this)[1] = 0;  (*this)[2] = 0;  (*this)[3] = 0; // x
	(*this)[4] = 0;  (*this)[5] = 1;  (*this)[6] = 0;  (*this)[7] = 0; // y
	(*this)[8] = 0;  (*this)[9] = 0;  (*this)[10] = 1; (*this)[11] = 0; // z
	(*this)[12] = 0; (*this)[13] = 0; (*this)[14] = 0; (*this)[15] = 1; // translate
}

void Matrix4x4::setTranslate(const Vector3& vector)
{
	(*this)[12] = vector.getX(); 
	(*this)[13] = vector.getY(); 
	(*this)[14] = vector.getZ();
}

void Matrix4x4::setScale(const Vector3& vector)
{
	(*this)[0] = vector.getX();
	(*this)[5] = vector.getY();
	(*this)[10] = vector.getZ();
}

void Matrix4x4::setRotate(const Vector3& radian)
{
	float cosX = cos(radian.getX());
	float cosY = cos(radian.getY());
	float cosZ = cos(radian.getZ());
	float sinX = sin(radian.getX());
	float sinY = sin(radian.getY());
	float sinZ = sin(radian.getZ());

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

void Matrix4x4::setRotateX(float x)
{
	(*this)[5] = cos(x); (*this)[6] = -sin(x);
	(*this)[9] = sin(x); (*this)[10] = cos(x);
}

void Matrix4x4::setRotateY(float y)
{
	(*this)[0] = cos(y); (*this)[2] = sin(y);
	(*this)[8] = -sin(y); (*this)[10] = cos(y);
}

void Matrix4x4::setRotateZ(float z)
{
	Matrix4x4 mat;
	(*this)[0] = cos(z); (*this)[1] = -sin(z);
	(*this)[4] = sin(z); (*this)[5] = cos(z);
}

void Matrix4x4::setRotationByAxis(const Vector3& axis, float radian)
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

void Matrix4x4::setRotationByLine(const Vector3& src, const Vector3& dest, float radian)
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

Matrix4x1 Matrix4x4::operator*(const Matrix4x1& mat)
{
	Matrix<float, 4, 4> mat0(*this);
	Matrix<float, 4, 4> mat1;
	mat1.setColumn(0, mat.getValue());
	Matrix4x4 mat2 = mat0 * mat1;
	return Matrix4x1(mat1[0], mat1[4], mat1[8], mat1[12]);
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat)
{
	Matrix<float, 4, 4> mat0(*this);
	Matrix<float, 4, 4> mat1(mat.getValue());
	return Matrix4x4(mat0 * mat1);
}

Vector3 Matrix4x4::getEularAngle() const
{
	float r11 = getValue(0, 0);
	float r12 = getValue(0, 1);
	float r13 = getValue(0, 2);
	float r21 = getValue(1, 0);
	float r22 = getValue(1, 1);
	float r23 = getValue(1, 2);
	float r31 = getValue(2, 0);
	float r33 = getValue(2, 2);
	float r34 = getValue(2, 3);

	float x = 0;
	float y = 0;
	float z = 0;

	if (r11 == 1.0f)
	{
		x = atan2(r13, r34);
	}
	else if (r11 == -1.0f)
	{
		x = atan2(r13, r34);
	}
	else
	{
		x = atan2(- r31, r11);
		y = asin(r21);
		z = atan2(-r23, r22);
	}

	return Vector3(x, y, z);
}

math::Matrix4x4::Matrix4x4(const Matrix<float, 4, 4>& mat)
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

math::Matrix4x4::Matrix4x4(const float value[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->setValue(i, j, value[i][j]);
		}
	}
}

math::Matrix4x4::Matrix4x4(const Matrix4x1& mat)
{
	*this = mat;
}

math::Matrix4x4::~Matrix4x4()
{

}

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix4x4& mat)
{
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			this->setValue(i, j, mat.getValue(i, j));
		}
	}

	return *this;
}

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix<float, 4, 4>& mat)
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

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix3x3& mat)
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

math::Matrix4x4& math::Matrix4x4::operator=(const Matrix4x1& mat)
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

math::Matrix4x4 math::Matrix4x4::ortho(float left, float right, float bottom, float top,
	float znear, float zfar)
{
	math::Matrix4x4 mat;

	mat[0] = 2 / (right - left);
	mat[12] = -(right + left) / (right - left);

	mat[5] = 2 / (top - bottom);
	mat[13] = -(top + bottom) / (top - bottom);

	mat[10] = -2 / (zfar - znear);
	mat[14] = -(zfar + znear) / (zfar - znear);

	mat[15] = 1;

	return mat;
}

math::Matrix4x4 math::Matrix4x4::frustum(float left, float right, float bottom, float top,
	float znear, float zfar)
{
	math::Matrix4x4 mat;

	float temp, temp1, temp2, temp3, temp4, temp5, temp6;
	temp = 2.0f * znear;
	temp1 = left + right;
	temp2 = right - left;
	temp3 = top + bottom;
	temp4 = top - bottom;
	temp5 = zfar + znear;
	temp6 = zfar - znear;

	mat[0] = temp / temp2;
	mat[1] = 0.0f;
	mat[2] = 0.0f;
	mat[3] = 0.0f;

	mat[4] = 0.0f;
	mat[5] = temp / temp4;
	mat[6] = 0.0f;
	mat[7] = 0.0f;

	mat[8] = temp1 / temp2;
	mat[9] = temp3 / temp4;
	mat[10] = -temp5 / temp6;
	mat[11] = -1.0f;

	mat[12] = 0.0f;
	mat[13] = 0.0f;
	mat[14] = -2.0f * zfar * znear / temp6;
	mat[15] = 0.0f;

	return mat;
}

math::Matrix4x4 math::Matrix4x4::perspective(float fovyInDegrees, float aspectRatio, float znear, float zfar)
{
	float ymax, xmax;
	//float temp, temp2, temp3, temp4;
	ymax = znear * tanf(fovyInDegrees * M_PI / 360.0);
	// ymin = -ymax;
	// xmin = -ymax * aspectRatio;
	xmax = ymax * aspectRatio;

	return frustum(-xmax, xmax, -ymax, ymax, znear, zfar);
}

math::Matrix4x4 math::Matrix4x4::lookAt(const Vector3& eye, const Vector3& center, const Vector3& up)
{
	math::Vector3 f = math::Vector3::normalize(center - eye);
	math::Vector3 u = math::Vector3::normalize(up);
	math::Vector3 s = math::Vector3::normalize(math::Vector3::cross(f, u));
	u = math::Vector3::cross(s, f);

	math::Matrix4x4 Result;
	Result.setValue(0, 0, s.getX());
	Result.setValue(1, 0, s.getY());
	Result.setValue(2, 0, s.getZ());
	Result.setValue(0, 1, u.getX());
	Result.setValue(1, 1, u.getY());
	Result.setValue(2, 1, u.getZ());
	Result.setValue(0, 2, -f.getX());
	Result.setValue(1, 2, -f.getY());
	Result.setValue(2, 2, -f.getZ());
	return Result;
}

void math::Matrix4x4::getRST(const Vector3& rotate, const Vector3& scale, const Vector3& translate, Matrix4x4& outValue)
{
	math::Matrix4x4 matScale;
	matScale.setScale(scale);
	math::Matrix4x4 matRotate;
	matRotate.setRotate(rotate);
	math::Matrix4x4 matTranslate;
	matTranslate.setTranslate(translate);

	outValue = matRotate * matScale * matTranslate;
}

math::Matrix4x4 math::Matrix4x4::getTSR(const Vector3& translate, const Vector3& scale, const Vector3& rotate)
{
	math::Matrix4x4 matScale;
	matScale.setScale(scale);
	math::Matrix4x4 matRotate;
	matRotate.setRotate(rotate);
	math::Matrix4x4 matTranslate;
	matTranslate.setTranslate(translate);

	return matTranslate * matScale * matRotate;
}

Vector3 math::Matrix4x4::transpose(const Vector3& src, const Matrix4x4& mat)
{
	//printf("%s\n", mat.toString().c_str());

	Matrix1x4 srcMatrix(src);
	Matrix1x4 result = srcMatrix * mat;
	//printf("%s\n", result.toString().c_str());
	Vector3 pos = (Vector3)result;
	return pos;
}

math::Vector3 math::Matrix4x4::getPosition() const
{
	return Vector3((*this)[12], (*this)[13], (*this)[14]);
}

math::Vector3 math::Matrix4x4::getScale() const
{
	return Vector3((*this)[0], (*this)[5], (*this)[10]);
}

Vector4 math::Matrix4x4::getRow(int column) const
{
	return Vector4(
		getValue(column, 0),
		getValue(column, 1),
		getValue(column, 2),
		getValue(column, 3));
}

void math::Matrix4x4::setRow(int column, const Vector4& value)
{
	this->setValue(column, 0, value[0]);
	this->setValue(column, 1, value[1]);
	this->setValue(column, 2, value[2]);
	this->setValue(column, 3, value[3]);
}

math::Vector4 math::Matrix4x4::getColumn(int column) const
{
	return Vector4(
		getValue(column, 0),
		getValue(column, 1),
		getValue(column, 2),
		getValue(column, 3));
}

void math::Matrix4x4::setColumn(int column, const Vector4& value)
{
	this->setValue(column, 0, value[0]);
	this->setValue(column, 1, value[1]);
	this->setValue(column, 2, value[2]);
	this->setValue(column, 3, value[3]);
}

