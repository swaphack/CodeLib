#pragma once

namespace sys
{
	// 2d
	struct Vector2
	{
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& point);
		/**
		*	长度
		*/
		float getLength() const;
		/**
		*	两向量和
		*/
		void add(const Vector2& point);
		/**
		*	两向量差
		*/
		void sub(const Vector2& point);
		/**
		*	乘以
		*/
		void mult(const Vector2& point);
		/**
		*	除以
		*/
		void div(const Vector2& point);

		/**
		*	乘以
		*/
		void mult(const float ratio);
		/**
		*	除以
		*/
		void div(const float ratio);
		/**
		*	重载=
		*/
		Vector2& operator = (const Vector2& point);
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
		*	重载+
		*/
		Vector2 operator+(const Vector2& vector) const;
		/**
		*	重载-
		*/
		Vector2 operator-(const Vector2& vector) const;
		/**
		*	重载*
		*/
		Vector2 operator*(const float k) const;
		/**
		*	重载/
		*/
		Vector2 operator/(const float k) const;
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
		static float distance(const Vector2& point0, const Vector2& point1);
		/**
		*	判断vector1在vector0的位置方向
		*	0 共线
		*	1 在左边
		*	2 在右边
		*/
		static int direction(const Vector2& vector0, const Vector2& vector1);
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