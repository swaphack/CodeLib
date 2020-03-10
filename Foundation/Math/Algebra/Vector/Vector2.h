#pragma once

#include <cstdint>

#include "Vector.h"
#include "Vector3.h"

namespace math
{
	// 2d
	struct Vector2 : public Vector
	{
	public:
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector& vector);
		Vector2(const Vector2& point);
	public:
		CREATE_AXIS(X, 0);
		CREATE_AXIS(Y, 1);

		void set(float x, float y);
	public:
		/**
		*	����Ԫ��
		*/
		virtual Vector2& operator=(const Vector2& vec);
		/**
		*	����Ԫ��
		*/
		virtual Vector2& operator=(const Vector3& vec);
	public:
		/**
		*	���
		*/
		virtual Vector2 operator+(const Vector2& vec) const;
		/**
		*	���
		*/
		virtual Vector2 operator-(const Vector2& vec) const;
		/**
		*	���
		*/
		Vector2 operator*(float k) const;
		/**
		*	���
		*/
		Vector2 operator/(float k) const;
		/**
		*	���
		*/
		virtual Vector2& operator+=(const Vector2& vec);
		/**
		*	���
		*/
		virtual Vector2& operator-=(const Vector2& vec);
		/**
		*	���
		*/
		Vector2& operator*=(float k);
		/**
		*	���
		*/
		Vector2& operator/=(float k);
	public:
		/**
		*	���
		*/
		virtual bool operator==(const Vector2& vec);
		/**
		*	�����
		*/
		virtual bool operator!=(const Vector2& vec);
	public:
		/**
		*	���
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector2& vector0, const Vector2& vector1);
		/**
		*	�������
		*	a x b = n |a||b|sin<a, b>
		*	���ȵ���Χ��ƽ���ı��ε����
		*/
		static Vector2 cross(const Vector2& vector0, const Vector2& vector1);
		/**
		*	����
		*/
		static float distance(const Vector2& point0, const Vector2& point1);
		/**
		*	vector1��vector0�ļн�����ֵ
		*/
		static float cosAngle(const Vector2& vector0, const Vector2& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ(0,PI)
		*/
		static float sinAngle(const Vector2& vector0, const Vector2& vector1);
		/**
		*	���vector1��vector0��ͶӰ����
		*/
		static float project(const Vector2& vector0, const Vector2& vector1);
		/**
		*	vector1���vector0����ת�Ƕ�(0,360)
		*/
		static float getRotateAngle(const Vector2& vector0, const Vector2& vector1);
		/**
		*	���㹲��
		*/
		static bool isThreePointsOnSameLine(const Vector2& point0, const Vector2& point1, const Vector2& point2);
	};
}