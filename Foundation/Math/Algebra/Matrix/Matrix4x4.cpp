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
	this->assign(value);
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

void math::Matrix4x4::setShear(float radianX, float radianY, float radianZ)
{
	this->setShearX(radianX);
	this->setShearY(radianY);
	this->setShearZ(radianZ);
}

void Matrix4x4::setRotateX(float x)
{
	(*this)[5] = cos(x); (*this)[6] = sin(x);
	(*this)[9] = -sin(x); (*this)[10] = cos(x);
}

void Matrix4x4::setRotateY(float y)
{
	(*this)[0] = cos(y); (*this)[2] = -sin(y);
	(*this)[8] = sin(y); (*this)[10] = cos(y);
}

void Matrix4x4::setRotateZ(float z)
{
	Matrix4x4 mat;
	(*this)[0] = cos(z); (*this)[1] = sin(z);
	(*this)[4] = -sin(z); (*this)[5] = cos(z);
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
	float value[4] = { 0 };
	value[0] = getValue(0) * mat.getValue(0) + getValue(1) * mat.getValue(1) + getValue(2) * mat.getValue(2) + getValue(3) * mat.getValue(3);
	value[1] = getValue(4) * mat.getValue(0) + getValue(5) * mat.getValue(1) + getValue(6) * mat.getValue(2) + getValue(7) * mat.getValue(3);
	value[2] = getValue(8) * mat.getValue(0) + getValue(9) * mat.getValue(1) + getValue(10) * mat.getValue(2) + getValue(11) * mat.getValue(3);
	value[3] = getValue(12) * mat.getValue(0) + getValue(13) * mat.getValue(1) + getValue(14) * mat.getValue(2) + getValue(15) * mat.getValue(3);

	return Matrix4x1(value);
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat)
{
	float value[16] = { 0 };
	value[0] = getValue(0) * mat.getValue(0) + getValue(1) * mat.getValue(4) + getValue(2) * mat.getValue(8) + getValue(3) * mat.getValue(12);
	value[1] = getValue(0) * mat.getValue(1) + getValue(1) * mat.getValue(5) + getValue(2) * mat.getValue(9) + getValue(3) * mat.getValue(13);
	value[2] = getValue(0) * mat.getValue(2) + getValue(1) * mat.getValue(6) + getValue(2) * mat.getValue(10) + getValue(3) * mat.getValue(14);
	value[3] = getValue(0) * mat.getValue(3) + getValue(1) * mat.getValue(7) + getValue(2) * mat.getValue(11) + getValue(3) * mat.getValue(15);

	value[4] = getValue(4) * mat.getValue(0) + getValue(5) * mat.getValue(4) + getValue(6) * mat.getValue(8) + getValue(7) * mat.getValue(12);
	value[5] = getValue(4) * mat.getValue(1) + getValue(5) * mat.getValue(5) + getValue(6) * mat.getValue(9) + getValue(7) * mat.getValue(13);
	value[6] = getValue(4) * mat.getValue(2) + getValue(5) * mat.getValue(6) + getValue(6) * mat.getValue(10) + getValue(7) * mat.getValue(14);
	value[7] = getValue(4) * mat.getValue(3) + getValue(5) * mat.getValue(7) + getValue(6) * mat.getValue(11) + getValue(7) * mat.getValue(15);

	value[8] = getValue(8) * mat.getValue(0) + getValue(9) * mat.getValue(4) + getValue(10) * mat.getValue(8) + getValue(11) * mat.getValue(12);
	value[9] = getValue(8) * mat.getValue(1) + getValue(9) * mat.getValue(5) + getValue(10) * mat.getValue(9) + getValue(11) * mat.getValue(13);
	value[10] = getValue(8) * mat.getValue(2) + getValue(9) * mat.getValue(6) + getValue(10) * mat.getValue(10) + getValue(11) * mat.getValue(14);
	value[11] = getValue(8) * mat.getValue(3) + getValue(9) * mat.getValue(7) + getValue(10) * mat.getValue(11) + getValue(11) * mat.getValue(15);

	value[12] = getValue(12) * mat.getValue(0) + getValue(13) * mat.getValue(4) + getValue(14) * mat.getValue(8) + getValue(15) * mat.getValue(12);
	value[13] = getValue(12) * mat.getValue(1) + getValue(13) * mat.getValue(5) + getValue(14) * mat.getValue(9) + getValue(15) * mat.getValue(13);
	value[14] = getValue(12) * mat.getValue(2) + getValue(13) * mat.getValue(6) + getValue(14) * mat.getValue(10) + getValue(15) * mat.getValue(14);
	value[15] = getValue(12) * mat.getValue(3) + getValue(13) * mat.getValue(7) + getValue(14) * mat.getValue(11) + getValue(15) * mat.getValue(15);


	
	return Matrix4x4(value);
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

math::Matrix4x4::Matrix4x4(const SquareMatrix4& mat)
{
	this->assign(mat.getValue());
}

math::Matrix4x4::Matrix4x4(const SquareMatrix<float, 4>& mat)
{
	this->assign(mat.getValue());
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

math::Matrix4x4::operator SquareMatrix4()
{
	return SquareMatrix4(*this);
}

Matrix4x4 math::Matrix4x4::getInverse()
{
	float inv[16], invOut[16], det;
    int i;
	
	

    inv[0] = (*this)[5]  * (*this)[10] * (*this)[15] - 
             (*this)[5]  * (*this)[11] * (*this)[14] - 
             (*this)[9]  * (*this)[6]  * (*this)[15] + 
             (*this)[9]  * (*this)[7]  * (*this)[14] +
             (*this)[13] * (*this)[6]  * (*this)[11] - 
             (*this)[13] * (*this)[7]  * (*this)[10];

    inv[4] = -(*this)[4]  * (*this)[10] * (*this)[15] + 
              (*this)[4]  * (*this)[11] * (*this)[14] + 
              (*this)[8]  * (*this)[6]  * (*this)[15] - 
              (*this)[8]  * (*this)[7]  * (*this)[14] - 
              (*this)[12] * (*this)[6]  * (*this)[11] + 
              (*this)[12] * (*this)[7]  * (*this)[10];

    inv[8] = (*this)[4]  * (*this)[9] * (*this)[15] - 
             (*this)[4]  * (*this)[11] * (*this)[13] - 
             (*this)[8]  * (*this)[5] * (*this)[15] + 
             (*this)[8]  * (*this)[7] * (*this)[13] + 
             (*this)[12] * (*this)[5] * (*this)[11] - 
             (*this)[12] * (*this)[7] * (*this)[9];

    inv[12] = -(*this)[4]  * (*this)[9] * (*this)[14] + 
               (*this)[4]  * (*this)[10] * (*this)[13] +
               (*this)[8]  * (*this)[5] * (*this)[14] - 
               (*this)[8]  * (*this)[6] * (*this)[13] - 
               (*this)[12] * (*this)[5] * (*this)[10] + 
               (*this)[12] * (*this)[6] * (*this)[9];

    inv[1] = -(*this)[1]  * (*this)[10] * (*this)[15] + 
              (*this)[1]  * (*this)[11] * (*this)[14] + 
              (*this)[9]  * (*this)[2] * (*this)[15] - 
              (*this)[9]  * (*this)[3] * (*this)[14] - 
              (*this)[13] * (*this)[2] * (*this)[11] + 
              (*this)[13] * (*this)[3] * (*this)[10];

    inv[5] = (*this)[0]  * (*this)[10] * (*this)[15] - 
             (*this)[0]  * (*this)[11] * (*this)[14] - 
             (*this)[8]  * (*this)[2] * (*this)[15] + 
             (*this)[8]  * (*this)[3] * (*this)[14] + 
             (*this)[12] * (*this)[2] * (*this)[11] - 
             (*this)[12] * (*this)[3] * (*this)[10];

    inv[9] = -(*this)[0]  * (*this)[9] * (*this)[15] + 
              (*this)[0]  * (*this)[11] * (*this)[13] + 
              (*this)[8]  * (*this)[1] * (*this)[15] - 
              (*this)[8]  * (*this)[3] * (*this)[13] - 
              (*this)[12] * (*this)[1] * (*this)[11] + 
              (*this)[12] * (*this)[3] * (*this)[9];

    inv[13] = (*this)[0]  * (*this)[9] * (*this)[14] - 
              (*this)[0]  * (*this)[10] * (*this)[13] - 
              (*this)[8]  * (*this)[1] * (*this)[14] + 
              (*this)[8]  * (*this)[2] * (*this)[13] + 
              (*this)[12] * (*this)[1] * (*this)[10] - 
              (*this)[12] * (*this)[2] * (*this)[9];

    inv[2] = (*this)[1]  * (*this)[6] * (*this)[15] - 
             (*this)[1]  * (*this)[7] * (*this)[14] - 
             (*this)[5]  * (*this)[2] * (*this)[15] + 
             (*this)[5]  * (*this)[3] * (*this)[14] + 
             (*this)[13] * (*this)[2] * (*this)[7] - 
             (*this)[13] * (*this)[3] * (*this)[6];

    inv[6] = -(*this)[0]  * (*this)[6] * (*this)[15] + 
              (*this)[0]  * (*this)[7] * (*this)[14] + 
              (*this)[4]  * (*this)[2] * (*this)[15] - 
              (*this)[4]  * (*this)[3] * (*this)[14] - 
              (*this)[12] * (*this)[2] * (*this)[7] + 
              (*this)[12] * (*this)[3] * (*this)[6];

    inv[10] = (*this)[0]  * (*this)[5] * (*this)[15] - 
              (*this)[0]  * (*this)[7] * (*this)[13] - 
              (*this)[4]  * (*this)[1] * (*this)[15] + 
              (*this)[4]  * (*this)[3] * (*this)[13] + 
              (*this)[12] * (*this)[1] * (*this)[7] - 
              (*this)[12] * (*this)[3] * (*this)[5];

    inv[14] = -(*this)[0]  * (*this)[5] * (*this)[14] + 
               (*this)[0]  * (*this)[6] * (*this)[13] + 
               (*this)[4]  * (*this)[1] * (*this)[14] - 
               (*this)[4]  * (*this)[2] * (*this)[13] - 
               (*this)[12] * (*this)[1] * (*this)[6] + 
               (*this)[12] * (*this)[2] * (*this)[5];

    inv[3] = -(*this)[1] * (*this)[6] * (*this)[11] + 
              (*this)[1] * (*this)[7] * (*this)[10] + 
              (*this)[5] * (*this)[2] * (*this)[11] - 
              (*this)[5] * (*this)[3] * (*this)[10] - 
              (*this)[9] * (*this)[2] * (*this)[7] + 
              (*this)[9] * (*this)[3] * (*this)[6];

    inv[7] = (*this)[0] * (*this)[6] * (*this)[11] - 
             (*this)[0] * (*this)[7] * (*this)[10] - 
             (*this)[4] * (*this)[2] * (*this)[11] + 
             (*this)[4] * (*this)[3] * (*this)[10] + 
             (*this)[8] * (*this)[2] * (*this)[7] - 
             (*this)[8] * (*this)[3] * (*this)[6];

    inv[11] = -(*this)[0] * (*this)[5] * (*this)[11] + 
               (*this)[0] * (*this)[7] * (*this)[9] + 
               (*this)[4] * (*this)[1] * (*this)[11] - 
               (*this)[4] * (*this)[3] * (*this)[9] - 
               (*this)[8] * (*this)[1] * (*this)[7] + 
               (*this)[8] * (*this)[3] * (*this)[5];

    inv[15] = (*this)[0] * (*this)[5] * (*this)[10] - 
              (*this)[0] * (*this)[6] * (*this)[9] - 
              (*this)[4] * (*this)[1] * (*this)[10] + 
              (*this)[4] * (*this)[2] * (*this)[9] + 
              (*this)[8] * (*this)[1] * (*this)[6] - 
              (*this)[8] * (*this)[2] * (*this)[5];

    det = (*this)[0] * inv[0] + (*this)[1] * inv[4] + (*this)[2] * inv[8] + (*this)[3] * inv[12];

    if (det == 0)
        return Matrix4x4();

    det = 1.0 / det;

    for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;
	
	return Matrix4x4(invOut);
}


math::Matrix4x4 math::Matrix4x4::ortho(float left, float right, float bottom, float top,
	float znear, float zfar)
{
	math::Matrix4x4 mat;

	mat[0] = 2 / (right - left);
	mat[5] = 2 / (top - bottom);
	mat[10] = -2 / (zfar - znear);

	mat[12] = -(right + left) / (right - left);
	mat[13] = -(top + bottom) / (top - bottom);
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
	Matrix1x4 srcMatrix(src);
	Matrix1x4 result = srcMatrix * mat;
	Vector3 pos = (Vector3)result;
	return pos;
}

math::Matrix4x4 math::Matrix4x4::getFrontViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[0] = 1;
	mat[5] = 1;
	mat[10] = 1;
	mat[15] = 1;
	return mat;
}

math::Matrix4x4 math::Matrix4x4::getBackViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[2] = 1;
	mat[5] = 1;
	mat[8] = -1;
	mat[15] = 1;
	return mat;
}

math::Matrix4x4 math::Matrix4x4::getTopViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[0] = 1;
	mat[6] = 1;
	mat[9] = -1;
	mat[15] = 1;
	return mat;
}

math::Matrix4x4 math::Matrix4x4::getBottomViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[0] = 1;
	mat[6] = -1;
	mat[9] = 1;
	mat[15] = 1;
	return mat;
}

math::Matrix4x4 math::Matrix4x4::getLeftViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[2] = -1;
	mat[5] = 1;
	mat[8] = 1;
	mat[15] = 1;
	return mat;
}

math::Matrix4x4 math::Matrix4x4::getRightViewMatrix()
{
	Matrix4x4 mat;
	mat.reset();
	mat[2] = 1;
	mat[5] = 1;
	mat[8] = -1;
	mat[15] = 1;
	return mat;
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

void math::Matrix4x4::setShearX(float radian)
{
	float offset = tanf(radian);

	(*this)[4] = offset;
	(*this)[8] = offset;
}

void math::Matrix4x4::setShearY(float radian)
{
	float offset = tanf(radian);

	(*this)[1] = offset;
	(*this)[9] = offset;
}

void math::Matrix4x4::setShearZ(float radian)
{
	float offset = tanf(radian);

	(*this)[2] = offset;
	(*this)[6] = offset;
}

