#include "Quaternion.h"
#include "../Vector/Vector3.h"
#include "../Matrix/Matrix4x4.h"
#include "Basic/base.h"
#include <cassert>

using namespace math;

Quaternion::Quaternion()
{

}

Quaternion::Quaternion(const Quaternion& quaternion)
{
	*this = quaternion;
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
	this->setX(x);
	this->setY(y);
	this->setZ(z);
	this->setW(w);
}

Quaternion::Quaternion(float w, const Vector3& vector)
{
	this->setX(vector.getX());
	this->setY(vector.getY());
	this->setZ(vector.getZ());
	this->setW(w);
}

Quaternion Quaternion::identity()
{
	return Quaternion(1, 0, 0, 0);
}

Quaternion Quaternion::negative() const
{
	return Quaternion(-getW(), -getX(), -getY(), -getZ());
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(getW(), -getX(), -getY(), -getZ());
}

Quaternion Quaternion::inverse() const
{
	return conjugate() / getSqrMagnitude();
}

float Quaternion::getMagnitude() const
{
	return sqrtf(powf(getX(), 2) + powf(getY(), 2) + powf(getZ(), 2));
}

float math::Quaternion::getSqrMagnitude() const
{
	return powf(getX(), 2) + powf(getY(), 2) + powf(getZ(), 2);
}

void Quaternion::normalize()
{
	float len = getMagnitude();
	assert(len > 0);

	setX(getX() / len);
	setY(getY() / len);
	setZ(getZ() / len);
}

Quaternion Quaternion::operator*(const Quaternion& quaternion) const
{
	float qw = getW()*quaternion.getW() - getX()*quaternion.getX() - getY()*quaternion.getY() - getZ()*quaternion.getZ();
	float qx = getW()*quaternion.getX() + getX()*quaternion.getW() + getY()*quaternion.getZ() - getZ()*quaternion.getY();
	float qy = getW()*quaternion.getY() + getY()*quaternion.getW() + getZ()*quaternion.getX() - getX()*quaternion.getZ();
	float qz = getW()*quaternion.getZ() + getZ()*quaternion.getW() + getX()*quaternion.getY() - getY()*quaternion.getX();

	return Quaternion(qw, qx, qy, qz);
}

Quaternion Quaternion::operator-(const Quaternion& quaternion) const
{
	math::Quaternion inverse = this->inverse();
	math::Quaternion qd = inverse * quaternion;

	return qd;
}

Quaternion Quaternion::operator*(float k) const
{
	Quaternion q(k * getW(), k * getX(), k * getY(), k * getZ());
	return q;
}

Quaternion::operator Matrix4x4()
{
	/*
	float a = (*this)[0];
	float b = (*this)[1];
	float c = (*this)[2];
	float d = (*this)[3];

	Matrix44 mat;
	mat.setValue(0, a); mat.setValue(1, -b); mat.setValue(2, d); mat.setValue(3, -c);
	mat.setValue(4, b); mat.setValue(5, a); mat.setValue(6, -c); mat.setValue(7, -d);
	mat.setValue(8, -d); mat.setValue(9, c); mat.setValue(10, a); mat.setValue(11, -b);
	mat.setValue(12, c); mat.setValue(13, d); mat.setValue(14, b); mat.setValue(15, a);
	*/

	Matrix4x4 mat;

	float x = (*this)[0];
	float y = (*this)[1];
	float z = (*this)[2];
	float w = (*this)[3];

	float xx = x * x;
	float yy = y * y;
	float zz = z * z;
	float ww = w * w;

	float xy = x * y;
	float xz = x * z;
	float xw = x * w;
	float yz = y * z;
	float yw = y * w;
	float zw = z * w;

	mat.setValue(0, 0, 1 - 2 * (yy + zz));
	mat.setValue(0, 1, 2 * (xy - zw));
	mat.setValue(0, 2, 2 * (xz + yw));

	mat.setValue(1, 0, 2 * (xy + zw));
	mat.setValue(1, 1, 1 - 2 * (xx + zz));
	mat.setValue(1, 2, 2 * (yz - xw));

	mat.setValue(2, 0, 2 * (xz - yw));
	mat.setValue(2, 1, 2 * (yz + xw));
	mat.setValue(2, 2, 1 - 2 * (xx + yy));

	return mat;
}

Quaternion Quaternion::rotate(const Vector3& vector, float angle)
{
	float radian = ANGLE_TO_RADIAN(angle) * 0.5f;

	float len = vector.getMagnitude();

	assert(len != 0);

	float cosR = cos(radian);
	float sinR = sin(radian);

	float w = cosR;
	float x = sinR * vector.getX() / len;
	float y = sinR * vector.getY() / len;
	float z = sinR * vector.getZ() / len;

	return Quaternion(w, x, y, z);
}

Quaternion Quaternion::rotate(const Vector3& rotation)
{
	return rotate(rotation.getX(), rotation.getY(), rotation.getZ());
}

Quaternion Quaternion::rotate(float roll, float pitch, float yaw)
{
	float ax = ANGLE_TO_RADIAN(roll) * 0.5f;
	float ay = ANGLE_TO_RADIAN(pitch) * 0.5f;
	float az = ANGLE_TO_RADIAN(yaw) * 0.5f;

	float cosAx = cos(ax);
	float sinAx = cos(ax);

	float cosAy = cos(ay);
	float sinAy = cos(ay);

	float cosAz = cos(az);
	float sinAz = cos(az);

	float w = cosAx * cosAy * cosAz + sinAx* sinAy * sinAz;
	float x = sinAx * cosAy * cosAz - cosAx* sinAy * sinAz;
	float y = cosAx * sinAy * cosAz + sinAx* cosAy * sinAz;
	float z = cosAx * cosAy * sinAz - sinAx* sinAy * cosAz;

	return Quaternion(w, x, y, z);
}

Vector3 Quaternion::rotate(const Vector3& vector, const Quaternion& quaternion)
{
	Quaternion q0(0, vector);

	Quaternion q = rotateBy(quaternion, q0);
	Quaternion i = ((Quaternion)quaternion).inverse();
	q = rotateBy(q, i);

	return Vector3(q.getX(), q.getY(), q.getZ());
}

Quaternion Quaternion::rotateBy(const Quaternion& q0, const Quaternion& q1)
{
	float nw = q0.getW() * q1.getW() - q0.getX() * q1.getX() - q0.getY() * q1.getY() - q0.getZ() * q1.getZ();
	float nx = q0.getW() * q1.getX() + q0.getX() * q1.getW() + q0.getY() * q1.getZ() - q0.getZ() * q1.getY();
	float ny = q0.getW() * q1.getY() - q0.getX() * q1.getZ() + q0.getY() * q1.getW() + q0.getZ() * q1.getX();
	float nz = q0.getW() * q1.getZ() + q0.getX() * q1.getY() - q0.getY() * q1.getX() + q0.getZ() * q1.getW();

	return Quaternion(nw, nx, ny, nz);
}

Vector3 Quaternion::euler(const Quaternion& quaternion)
{
	Vector3 rotation;
	float x;
	float y;
	float z;

	// 万向锁, 南北极±90°
	float test = quaternion.getX() * quaternion.getY() + quaternion.getZ() * quaternion.getW();
	if (test > 0.499f) { // singularity at north pole
		x = 2 * atan2(quaternion.getX(), quaternion.getW());
		y = M_PI * 0.5f;
		z = 0;
	}
	else if (test < -0.499f) { // singularity at south pole
		x = -2 * atan2(quaternion.getX(), quaternion.getW());
		y = -M_PI * 0.5f;
		z = 0;
	}
	else
	{
		x = atan2f(2 * (quaternion.getW() * quaternion.getX() + quaternion.getY() * quaternion.getZ()), (1 - 2 * (pow(quaternion.getX(), 2) + pow(quaternion.getY(), 2))));
		y = asinf(2 * (quaternion.getW() * quaternion.getY() - quaternion.getX() * quaternion.getZ()));
		z = atan2f(2 * (quaternion.getW() * quaternion.getZ() + quaternion.getX() * quaternion.getY()), (1 - 2 * (pow(quaternion.getY(), 2) + pow(quaternion.getZ(), 2))));
	}
	return Vector3(RADIAN_TO_ANGLE(x), RADIAN_TO_ANGLE(y), RADIAN_TO_ANGLE(z));
}

Matrix4x4 Quaternion::mat(const Quaternion& quaternion)
{
	Matrix4x4 mat44;

	float x = quaternion.getX();
	float y = quaternion.getY();
	float z = quaternion.getZ();
	float w = quaternion.getW();

	mat44[0] = 1.0f - 2.0f * y * y - 2.0f * z * z;
	mat44[1] = 2.0f * x * y - 2.0f * z * w;
	mat44[2] = 2.0f * x * z + 2.0f * y * w;
	mat44[3] = 0.0f;
	mat44[4] = 2.0f * x * y + 2.0f * z * w;
	mat44[5] = 1.0f - 2.0f * x * x - 2.0f * z * z;
	mat44[6] = 2.0f * y * z - 2.0f * x * w;
	mat44[7] = 0.0f;
	mat44[8] = 2.0f * x * z - 2.0f * y * w;
	mat44[9] = 2.0f * y * z + 2.0f * x * w;
	mat44[10] = 1.0f - 2.0f * x * x - 2.0f * y * y;
	mat44[11] = 0.0f;
	mat44[12] = 0.0f;
	mat44[13] = 0.0f;
	mat44[14] = 0.0f;
	mat44[15] = 1.0f;

	return mat44;

}

math::Quaternion::~Quaternion()
{

}

math::Quaternion math::Quaternion::normalize(const Quaternion& quaternion)
{
	float len = quaternion.getMagnitude();
	assert(len > 0);

	return Quaternion(quaternion.getW(), quaternion.getX() / len, quaternion.getY() / len, quaternion.getZ() / len);
}

float math::Quaternion::dot(const Quaternion& src, const Quaternion& dest)
{
	return src.getW() * dest.getW() + src.getX() * dest.getX() + src.getY() * dest.getY() + src.getZ() * dest.getZ();
}

math::Vector3 math::Quaternion::eulerAngle() const
{
	return euler(*this);
}

math::Vector3 math::Quaternion::vector() const
{
	return math::Vector3(getX(), getY(), getZ());
}

float math::Quaternion::radian() const
{
	return 2 * atan2f(vector().getMagnitude(), getW());
}
