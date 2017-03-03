#pragma once

#include <cmath>

namespace sys
{
	struct Vector2;

	// 3d
	struct Vector3
	{
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float x, float y, float z = 0);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
		/**
		*	两向量和
		*/
		void add(const Vector3& vector);
		/**
		*	两向量差
		*/
		void sub(const Vector3& vector);
		/**
		*	乘以
		*/
		void mult(const Vector3& vector);
		/**
		*	除以
		*/
		void div(const float ratio);
		/**
		*	乘以
		*/
		void mult(const float ratio);
		/**
		*	是否为0向量
		*/
		bool isZero();
		/**
		*	长度
		*/
		float getLength() const;
		/**
		*	重载=
		*/
		Vector3& operator=(const Vector2& vector);
		/**
		*	重载=
		*/
		Vector3& operator=(const Vector3& vector);
		/**
		*	重载+
		*/
		Vector3 operator+(const Vector3& vector);
		/**
		*	重载-
		*/
		Vector3 operator-(const Vector3& vector);
		/**
		*	重载*
		*/
		Vector3 operator*(const float k);
		/**
		*	重载/
		*/
		Vector3 operator/(const float k);

		/**
		*	重载+
		*/
		Vector3 operator+(const Vector3& vector) const;
		/**
		*	重载-
		*/
		Vector3 operator-(const Vector3& vector) const;
		/**
		*	重载*
		*/
		Vector3 operator*(const float k) const;
		/**
		*	重载/
		*/
		Vector3 operator/(const float k) const;

		/**
		*	重载+=
		*/
		Vector3& operator+=(const Vector3& vector);
		/**
		*	重载-=
		*/
		Vector3& operator-=(const Vector3& vector);
		/**
		*	重载*=
		*/
		Vector3& operator*=(const float k);
		/**
		*	重载/=
		*/
		Vector3& operator/=(const float k);

		/**
		*	重载*
		*/
		float operator*(const Vector3& vector);
		/**
		*	重载*
		*/
		float operator*(const Vector3& vector) const;
		/**
		*	判断两向量是否相等
		*/
		bool operator==(const Vector3& vector);
		/**
		*	判断两向量是否不等
		*/
		bool operator!=(const Vector3& vector);		
	public:
		/**
		*	向量点积
		*/
		static float dot(const Vector3& vector0, const Vector3& vector1);
		/**
		*	向量叉积
		*/
		static Vector3 cross(const Vector3& vector0, const Vector3& vector1);
		/**
		*	两点间的距离
		*/
		static float distance(const Vector3& point0, const Vector3& point1);
		/**
		*	判断vector1在vector0的位置方向
		*	0 共线
		*	1 在左边
		*	2 右边
		*/
		static int direction(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1和vector0的夹角余弦值
		*/
		static float cosAngle(const Vector3& vector0, const Vector3& vector1);
		/**
		*	获得vector1在vector0的投影长度
		*/
		static float project(const Vector3& vector0, const Vector3& vector1);
	public:
		static Vector3 Zero;
		static Vector3 One;
	};

	__declspec(selectany) Vector3 Vector3::Zero;
	__declspec(selectany) Vector3 Vector3::One = Vector3(1,1,1);
}