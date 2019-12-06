#pragma once

#include <cmath>
#include <cstdint>

namespace math
{
	struct Vector2;

	// 3d
	struct Vector3
	{
	public:
		float x = 0;
		float y = 0;
		float z = 0;
	public:
		Vector3();
		Vector3(float x, float y, float z = 0);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
		/**
		*	是否为0向量
		*/
		bool isZero();
		/**
		*	长度
		*/
		float getLength();
		/**
		*	单位化
		*/
		Vector3 normalize();
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
		*	判断两向量是否相等
		*/
		bool operator==(const Vector3& vector);
		/**
		*	判断两向量是否不等
		*/
		bool operator!=(const Vector3& vector);	
	public:
		/**
		*	平移
		*/
		Vector3 tranlate(const Vector3& vector);
		/**
		*	缩放
		*/
		Vector3 scale(const Vector3& vector);
		/**
		*	绕轴旋转
		*/
		Vector3 rotationByAxis(const Vector3& vector, float radian);
		/**
		*	绕轴线段旋转度数
		*/
		Vector3 rotationByLine(const Vector3& src, const Vector3& dest, float radian);
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
		static float distance(const Vector3& point320, const Vector3& point321);
		/**
		*	判断vector1在vector0的位置方向
		*	0 共线
		*	1 在左边
		*	2 右边
		*/
		static int32_t direction(const Vector3& vector0, const Vector3& vector1);
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