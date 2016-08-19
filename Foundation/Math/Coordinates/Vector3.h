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

		// 模（长度）
		float getLength() const;
		// 标准化
		Vector3 norm() const;
		// 零化
		Vector3& zero() const;

		// 与x轴夹角
		//float getRotationX();
		// 与y轴夹角
		//float getRotationY();
		// 与z轴夹角
		//float getRotationZ();

		Vector3& operator=(const Vector3& dest);
		Vector3& operator*=(float factor);
		Vector3& operator+=(const Vector3& dest);
		Vector3& operator-=(const Vector3& dest);

		Vector3 operator*(float factor) const;
		Vector3 operator+(const Vector3& dest) const;
		Vector3 operator-(const Vector3& dest) const;

		// 点乘
		float dot(const Vector3& dest) const;
		// 夹角
		float angle(const Vector3& dest) const;
		// 投影
		Vector3 project(const Vector3& dest) const;
		// 叉乘
		Vector3 cross(const Vector3& dest) const;
	};
}