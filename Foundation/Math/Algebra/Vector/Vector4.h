#pragma once

#include <cmath>
#include <cstdint>

#include "Vector.h"

namespace math
{
	struct Vector2;
	struct Vector3;
	// �������
	struct Vector4 : public Vector<float, 4>
	{
	public:
		Vector4();
		Vector4(float x, float y, float z, float w = 1);
		Vector4(const Vector& vector);
		Vector4(const Vector2& vector);
		Vector4(const Vector3& vector);
		Vector4(const Vector4& vector);
		virtual ~Vector4();
	public:
		CREATE_INDEX_VALUE(X, 0, float);
		CREATE_INDEX_VALUE(Y, 1, float);
		CREATE_INDEX_VALUE(Z, 2, float);
		CREATE_INDEX_VALUE(W, 3, float);

		void set(float x, float y, float z, float w);
		void set(float x, float y, float z);
		void set(float x, float y);
	public:
		/**
		*	����Ԫ��
		*/
		Vector4& operator=(const Vector4& vec);
		/**
		*	����Ԫ��
		*/
		Vector4& operator=(const Vector3& vec);
	public:
		/**
		*	���
		*/
		Vector4 operator+(const Vector4& vec) const;
		/**
		*	���
		*/
		Vector4 operator-(const Vector4& vec) const;
		/**
		*	���
		*/
		Vector4 operator*(const Vector4& vec) const;

		/**
		*	���
		*/
		Vector4 operator*(float k) const;
	};

	static inline Vector4 operator*(float k, const Vector4& value)
	{
		return value * k;
	}
}