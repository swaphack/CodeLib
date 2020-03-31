#pragma once

#include <cmath>
#include <cstdint>

#include "Vector.h"

namespace math
{
	struct Vector2;
	struct Vector3;
	// 齐次坐标
	struct Vector4 : public Vector
	{
	public:
		Vector4();
		Vector4(float x, float y, float z, float w = 1);
		Vector4(const Vector& vector);
		Vector4(const Vector2& vector);
		Vector4(const Vector3& vector);
		Vector4(const Vector4& vector);
	public:
		CREATE_AXIS(X, 0);
		CREATE_AXIS(Y, 1);
		CREATE_AXIS(Z, 2);
		CREATE_AXIS(W, 3);

		void set(float x, float y, float z, float w);
		void set(float x, float y, float z);
		void set(float x, float y);
	public:
		/**
		*	复制元素
		*/
		virtual Vector4& operator=(const Vector4& vec);
		/**
		*	复制元素
		*/
		virtual Vector4& operator=(const Vector3& vec);
	public:
		/**
		*	相加
		*/
		virtual Vector4 operator+(const Vector4& vec) const;
		/**
		*	相减
		*/
		virtual Vector4 operator-(const Vector4& vec) const;
		/**
		*	相乘
		*/
		virtual Vector4 operator*(const Vector4& vec) const;
	};
}