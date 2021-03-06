#pragma once

#include <cstdint>

#include "Vector.h"
#include "Vector3.h"

namespace math
{
	// 2d
	struct Vector2 : public Vector<float, 2>
	{
	public:
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector<float, 2>& vector);
		Vector2(const Vector2& point);
		virtual ~Vector2();
	public:
		CREATE_INDEX_VALUE(X, 0, float);
		CREATE_INDEX_VALUE(Y, 1, float);

		void set(float x, float y);
	public:
		/**
		*	单位化
		*/
		void normalize();
		/**
		*	复制元素
		*/
		Vector2& operator=(const Vector2& vec);
		/**
		*	复制元素
		*/
		Vector2& operator=(const Vector3& vec);
	public:
		/**
		*	相加
		*/
		Vector2 operator+(const Vector2& vec) const;
		/**
		*	相减
		*/
		Vector2 operator-(const Vector2& vec) const;
		/**
		*	相乘
		*/
		Vector2 operator*(float k) const;
		/**
		*	相除
		*/
		Vector2 operator/(float k) const;
		/**
		*	相加
		*/
		Vector2& operator+=(const Vector2& vec);
		/**
		*	相减
		*/
		Vector2& operator-=(const Vector2& vec);
		/**
		*	相乘
		*/
		Vector2& operator*=(float k);
		/**
		*	相除
		*/
		Vector2& operator/=(float k);
	public:
		/**
		*	相等
		*/
		virtual bool operator==(const Vector2& vec);
		/**
		*	不相等
		*/
		virtual bool operator!=(const Vector2& vec);
	public:
		/**
		*	点积
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector2& vector0, const Vector2& vector1);
		/**
		*	向量叉积
		*	a x b = n |a||b|sin<a, b>
		*	长度等于围成平行四边形的面积
		*/
		//static Vector2 cross(const Vector2& vector0, const Vector2& vector1);
		/**
		*	叉积
		*/
		static float cross(const Vector2& vector0, const Vector2& vector1);
		/**
		*	距离
		*/
		static float distance(const Vector2& point0, const Vector2& point1);
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
		/**
		*	三点共线
		*/
		static bool isThreePointsOnSameLine(const Vector2& point0, const Vector2& point1, const Vector2& point2);
		/**
		*	在平面上，获取点与线的位置关系 返回结果：-1左边，0线上，1右边
		*/
		static int getPointPosition(const math::Vector2& point, const math::Vector2& src, const math::Vector2& dest);
	};

	static inline Vector2 operator*(float k, const Vector2& value)
	{
		return value * k;
	}
}