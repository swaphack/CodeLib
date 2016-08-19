#pragma once

#include <cmath>

namespace math
{
	class Vector3
	{
	public:
		float X;
		float Y;
		float Z;
	public:
		Vector3();
		Vector3(const Vector3& dest);
		Vector3(float x, float y, float z);
		~Vector3();
	public:
		float getX() const;
		void setX(float t);

		float getY() const;
		void setY(float t);

		float getZ() const;
		void setZ(float t);

		// ģ�����ȣ�
		float getLength() const;
		// ��׼��
		Vector3 norm() const;
		// �㻯
		Vector3& zero() const;

		// ��x��н�
		//float getRotationX();
		// ��y��н�
		//float getRotationY();
		// ��z��н�
		//float getRotationZ();

		Vector3& operator=(const Vector3& dest);
		Vector3& operator*=(float factor);
		Vector3& operator+=(const Vector3& dest);
		Vector3& operator-=(const Vector3& dest);

		Vector3 operator*(float factor) const;
		Vector3 operator+(const Vector3& dest) const;
		Vector3 operator-(const Vector3& dest) const;

		// ���
		float dot(const Vector3& dest) const;
		// �н�
		float angle(const Vector3& dest) const;
		// ͶӰ
		Vector3 project(const Vector3& dest) const;
		// ���
		Vector3 cross(const Vector3& dest) const;
	};
}