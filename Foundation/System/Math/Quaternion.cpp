#include "Quaternion.h"
#include "Vector3.h"
#include "Matrix44.h"

using namespace sys;

Quaternion::Quaternion()
:w(0)
, x(0)
, y(0)
, z(0)
{

}

Quaternion::Quaternion(const Quaternion& quaternion)
:w(quaternion.w)
, x(quaternion.x)
, y(quaternion.y)
, z(quaternion.z)
{

}

Quaternion::Quaternion(float w, float x, float y, float z)
:w(w)
, x(x)
, y(y)
, z(z)
{

}

Quaternion::Quaternion(float w, const Vector3& vector)
:w(w)
, x(vector.x)
, y(vector.y)
, z(vector.z)
{

}

void Quaternion::unit()
{
	w = 1;
	x = 0;
	y = 0;
	z = 0;
}

Quaternion Quaternion::negative()
{
	return Quaternion(-w, -x, -y, -z);
}

Quaternion Quaternion::conjugate()
{
	return Quaternion(w, -x, -y, -z);
}

Quaternion Quaternion::inverse()
{
	return Quaternion(w, -x, -y, -z);
}

float Quaternion::getLength()
{
	return pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2);
}

void Quaternion::normalize()
{
	float len = getLength();
	if (len == 0)
	{
		return;
	}

	*this /= len;
}

Quaternion Quaternion::negative() const
{
	return Quaternion(-w, -x, -y, -z);
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(w, -x, -y, -z);
}

Quaternion Quaternion::inverse() const
{
	return Quaternion(w, -x, -y, -z);
	
}

float Quaternion::getLength() const
{
	return pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2);
	
}

Quaternion Quaternion::operator*(float k)
{
	return Quaternion(w * k, x * k, y * k, z * k);
}

float Quaternion::operator*(const Quaternion& quaternion)
{
	return w * quaternion.w + x * quaternion.x + y * quaternion.y + z * quaternion.z;
}

Quaternion& Quaternion::operator*=(float k)
{
	w *= k;
	x *= k;
	y *= k;
	z *= k;

	return *this;
}

Quaternion Quaternion::operator/(float k)
{
	if (k == 0)
	{
		return *this;
	}

	return Quaternion(w / k, x / k, y / k, z / k);
}

Quaternion& Quaternion::operator/=(float k)
{
	if (k == 0)
	{
		return *this;
	}

	w /= k;
	x /= k;
	y /= k;
	z /= k;

	return *this;
}

Quaternion& Quaternion::operator=(const Quaternion& quaternion)
{
	w = quaternion.w;
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;

	return *this;
}

Quaternion Quaternion::rotate(const Vector3& vector, float angle)
{
	float radian = ANGLE_TO_RADIAN(angle) * 0.5f;

	float w = cos(radian);
	float x = sin(radian) * vector.x;
	float y = sin(radian) * vector.y;
	float z = sin(radian) * vector.z;

	return Quaternion(w, x, y, z);
}

Quaternion Quaternion::rotate(const Vector3& rotation)
{
	return rotate(rotation.x, rotation.y, rotation.z);
}

Quaternion Quaternion::rotate(float roll, float pitch, float yaw)
{
	float ax = ANGLE_TO_RADIAN(roll) * 0.5f;
	float ay = ANGLE_TO_RADIAN(pitch) * 0.5f;
	float az = ANGLE_TO_RADIAN(yaw) * 0.5f;

	float w = cos(ax) * cos(ay) * cos(az) + sin(ax)* sin(ay) * sin(az);
	float x = sin(ax) * cos(ay) * cos(az) - cos(ax)* sin(ay) * sin(az);
	float y = cos(ax) * sin(ay) * cos(az) + sin(ax)* cos(ay) * sin(az);
	float z = cos(ax) * cos(ay) * sin(az) - sin(ax)* sin(ay) * cos(az);

	return Quaternion(w, x, y, z);
}

Vector3 Quaternion::rotate(const Vector3& vector, const Quaternion& quaternion)
{
	Quaternion q0(0, vector);

	Quaternion q = rotateBy(quaternion, q0);
	q = rotateBy(q, quaternion.inverse());

	return Vector3(q.x, q.y, q.z);
}

Quaternion Quaternion::rotateBy(const Quaternion& q0, const Quaternion& q1)
{
	float nw = q0.w * q1.w - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z;
	float nx = q0.w * q1.x + q0.x * q1.w + q0.y * q1.z - q0.z * q1.y;
	float ny = q0.w * q1.y - q0.x * q1.z + q0.y * q1.w + q0.z * q1.x;
	float nz = q0.w * q1.z + q0.x * q1.y - q0.y * q1.x + q0.z * q1.w;

	return Quaternion(nw, nx, ny, nz);
}

Vector3 Quaternion::euler(const Quaternion& quaternion)
{
	Vector3 rotation;
	float x;
	float y;
	float z;

	// 万向锁, 南北极±90°
	double test = quaternion.x * quaternion.y + quaternion.z * quaternion.w;
	if (test > 0.499f) { // singularity at north pole
		x = 2 * atan2(quaternion.x, quaternion.w);
		y = PI * 0.5f;
		z = 0;
	}
	else if (test < -0.499f) { // singularity at south pole
		x = -2 * atan2(quaternion.x, quaternion.w);
		y = -PI * 0.5f;
		z = 0;
	}
	else
	{
		x = atan2(2 * (quaternion.w * quaternion.x + quaternion.y * quaternion.z), (1 - 2 * (pow(quaternion.x, 2) + pow(quaternion.y, 2))));
		y = asin(2 * (quaternion.w * quaternion.y - quaternion.x * quaternion.z));
		z = atan2(2 * (quaternion.w * quaternion.z + quaternion.x * quaternion.y), (1 - 2 * (pow(quaternion.y, 2) + pow(quaternion.z, 2))));
	}
	return Vector3(RADIAN_TO_ANGLE(x), RADIAN_TO_ANGLE(y), RADIAN_TO_ANGLE(z));
}

Matrix44 Quaternion::mat(const Quaternion& quaternion)
{
	Matrix44 mat44;

	float x = quaternion.x;
	float y = quaternion.y;
	float z = quaternion.z;
	float w = quaternion.w;

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


