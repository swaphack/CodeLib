#include "Matrix44.h"
#include "Basic/base.h"
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
	return Matrix41(mat1[0], mat1[1], mat1[2], mat1[3]);
}

Matrix44 Matrix44::operator*(const Matrix44& mat)
{
	Matrix mat0 = *this;
	Matrix mat1 = mat0 * mat;
	return Matrix44(mat1);
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

math::Matrix44::~Matrix44()
{

}

math::Matrix44 math::Matrix44::ortho(float l, float r, float b, float t, float n, float f)
{
	math::Matrix44 mat;

	mat[0] = 2 / (r - l);
	mat[5] = 2 / (t - b);
	mat[10] = -2 / (f - n);
	
	mat[12] = -(r + l) / (r - l);
	mat[13] = -(t + b) / (t - b);
	mat[14] = -(f + n) / (f - n);

	return mat;
}

math::Matrix44 math::Matrix44::perspective(float l, float r, float b, float t, float n, float f)
{
	math::Matrix44 mat;

	mat[0] = 2.0f * n / (r - l);
	mat[2] = (r + l) / (r - l);
	mat[5] = 2.0f * n / (t - b);
	mat[6] = (t + b) / (t - b);
	mat[10] = -(f + n) / (f - n);
	mat[11] = -(2.0f * f * n) / (f - n);
	mat[14] = -1.0f;
	mat[15] = 0.0f;

	return mat;
}

math::Matrix44 math::Matrix44::verticalPerspective(float fov, float aspect, float front, float back)
{
	fov = ANGLE_TO_RADIAN(fov);                      // transform fov from degrees to radians

	float tangent = tanf(fov / 2.0f);               // tangent of half vertical fov
	float height = front * tangent;                 // half height of near plane
	float width = height * aspect;                  // half width of near plane

	return perspective(-width, width, -height, height, front, back);
}

math::Matrix44 math::Matrix44::horizontalPerspective(float fov, float aspect, float front, float back)
{
	fov = ANGLE_TO_RADIAN(fov);                      // transform fov from degrees to radians
	fov = 2.0f * atanf(tanf(fov * 0.5f) / aspect);  // transform from horizontal fov to vertical fov

	float tangent = tanf(fov / 2.0f);               // tangent of half vertical fov
	float height = front * tangent;                 // half height of near plane
	float width = height * aspect;                  // half width of near plane

	return perspective(-width, width, -height, height, front, back);
}

math::Matrix44 math::Matrix44::lookAt(const Vector3& target, const Vector3& eye, const Vector3& up)
{
	Vector3 dir = target - eye;
	Vector3 z(dir);
	z = z.normalize();
	Vector3 x(up * z); // x = up cross z 
	z = x.normalize();
	Vector3 y(z * x); // y = z cross x 

	Vector cx(4, x);
	Vector cy(4, y);
	Vector cz(4, z);

	Matrix44 m;
	m.setColumn(0, cx);
	m.setColumn(1, cz);
	m.setColumn(2, cz);

	return m;
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

	Matrix44 srcMatrix;
	srcMatrix.setTranslate(src);
	Matrix44 result = (Matrix44)mat * srcMatrix;
	Vector3 pos = result.getPosition();
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

