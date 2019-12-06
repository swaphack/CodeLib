#pragma once

#include <cstdint>

namespace math
{
	// 2d
	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& point32);
		/**
		*	长度
		*/
		float getLength();
		/**
		*	重载=
		*/
		Vector2& operator = (const Vector2& point32);
		/**
		*	重载+
		*/
		Vector2 operator+(const Vector2& vector);
		/**
		*	重载-
		*/
		Vector2 operator-(const Vector2& vector);
		/**
		*	重载*
		*/
		Vector2 operator*(const float k);
		/**
		*	重载/
		*/
		Vector2 operator/(const float k);
		/**
		*	重载+=
		*/
		Vector2& operator+=(const Vector2& vector);
		/**
		*	重载-=
		*/
		Vector2& operator-=(const Vector2& vector);
		/**
		*	重载*=
		*/
		Vector2& operator*=(const float k);
		/**
		*	重载/=
		*/
		Vector2& operator/=(const float k);
		/**
		*	判断两向量是否相等
		*/
		bool operator==(const Vector2& vector);
		/**
		*	判断两向量是否不等
		*/
		bool operator!=(const Vector2& vector);
	public:
		static Vector2 Zero;
	public:
		/**
		*	点积
		*/
		static float dot(const Vector2& vector0, const Vector2& vector1);
		/**
		*	向量叉积
		*/
		static Vector2 cross(const Vector2& vector0, const Vector2& vector1);
		/**
		*	距离
		*/
		static float distance(const Vector2& point320, const Vector2& point321);
		/**
		*	判断vector1在vector0的位置方向
		*	0 共线
		*	1 在左边
		*	2 在右边
		*/
		static int32_t direction(const Vector2& vector0, const Vector2& vector1);
		/**
		*	vector1和vector0的夹角余弦值
		*/
		static float cosAngle(const Vector2& vector0, const Vector2& vector1);
		/**
		*	vector1和vector0的夹角正弦值(0,PI)
		*/
		static float sinAngle(const Vector2& vector0, const Vector2& vector1);
		/**
		*	获得vector1在vector0的投影长度
		*/
		static float project(const Vector2& vector0, const Vector2& vector1);
		/**
		*	vector1相对vector0的旋转角度(0,360)
		*/
		static float getRotateAngle(const Vector2& vector0, const Vector2& vector1);
	};

	__declspec(selectany) Vector2 Vector2::Zero;
}