#pragma once

#include <cmath>
#include <cstdint>

#include "Algebra/Vector.h"

namespace math
{
	struct Vector2;
	struct Volume;
	// 3d
	struct Vector3 : public Vector
	{
	public:
		Vector3();
		Vector3(float x, float y, float z = 0);
		Vector3(const Vector& vector);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
	public:
		CREATE_AXIS(X, 0);
		CREATE_AXIS(Y, 1);
		CREATE_AXIS(Z, 2);

		void set(float x, float y, float z);
		void set(float x, float y);
	public:
		/**
		*	ƽ��
		*/
		Vector3 tranlate(const Vector3& vector);
		/**
		*	����
		*/
		Vector3 scale(const Vector3& vector);
		/**
		*	������ת
		*/
		Vector3 rotationByAxis(const Vector3& vector, float radian);
		/**
		*	�����߶���ת����
		*/
		Vector3 rotationByLine(const Vector3& src, const Vector3& dest, float radian);
	public:
		/**
		*	����Ԫ��
		*/
		virtual Vector3& operator=(const Vector3& vec);
		/**
		*	����Ԫ��
		*/
		virtual Vector3& operator=(const Vector2& vec);
	public:
		/**
		*	���
		*/
		virtual Vector3 operator+(const Vector3& vec) const;
		/**
		*	���
		*/
		virtual Vector3 operator-(const Vector3& vec) const;
		/**
		*	���
		*/
		virtual Vector3 operator*(const Vector3& vec) const;
		/**
		*	���
		*/
		Vector3 operator*(float k) const;
		/**
		*	���
		*/
		Vector3 operator/(float k) const;
		/**
		*	���
		*/
		virtual Vector3& operator+=(const Vector3& vec);
		/**
		*	���
		*/
		virtual Vector3& operator-=(const Vector3& vec);
		/**
		*	���
		*/
		virtual Vector3& operator*=(const Vector3& vec);
		/**
		*	���
		*/
		Vector3& operator*=(float k);
		/**
		*	���
		*/
		Vector3& operator/=(float k);
	public:
		/**
		*	���
		*/
		virtual bool operator==(const Vector3& vec);
		/**
		*	�����
		*/
		virtual bool operator!=(const Vector3& vec);
	public:
		/**
		*	ת�������
		*/
		operator Volume();
	public:
		/**
		*	�������
		*	a * b = |a||b|cos<a, b>
		*/
		static float dot(const Vector3& vector0, const Vector3& vector1);
		/**
		*	�������
		*	a x b = n |a||b|sin<a, b>
		*	���ȵ���Χ��ƽ���ı��ε����
		*/
		static Vector3 cross(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ
		*/
		static float cosAngle(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ(0,PI)
		*/
		static float sinAngle(const Vector3& vector0, const Vector3& vector1);
		/**
		*	�����ľ���
		*/
		static float distance(const Vector3& point0, const Vector3& point1);
		/**
		*	���vector1��vector0��ͶӰ����
		*/
		static float project(const Vector3& vector0, const Vector3& vector1);
		/**
		*	���㹲��
		*/
		static bool isThreePointsOnSameLine(const Vector3& point0, const Vector3& point1, const Vector3& point2);
		/**
		*	����������
		*/
		static bool isThreeVectorInSamePlane(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);

		/**
		*	�������
		*	a x b x r = (a * r) b - (b * r��a
		*/
		static Vector3 calDoubleCross(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);

		/**
		*	���ػ�
		*	a x b * c = b x c * a = c x a * b
		*	a x b * c = a * b x c
		*	��a,b,c����ƽ�����������
		*/
		static float calTripleProduct(const Vector3& vector0, const Vector3& vector1, const Vector3& vector2);
	};
}