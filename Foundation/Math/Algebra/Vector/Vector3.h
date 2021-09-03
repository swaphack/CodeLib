#pragma once

#include <cmath>
#include <cstdint>

#include "Vector.h"

namespace math
{
	struct Vector2;
	// 3d
	struct Vector3 : public Vector<float, 3>
	{
	public:
		Vector3();
		Vector3(float x, float y, float z = 0);
		Vector3(const Vector& vector);
		Vector3(const Vector2& vector);
		Vector3(const Vector3& vector);
		Vector3(const Array<float, 3>& vector);
		virtual ~Vector3();
	public:
		CREATE_INDEX_VALUE(X, 0, float);
		CREATE_INDEX_VALUE(Y, 1, float);
		CREATE_INDEX_VALUE(Z, 2, float);

		void set(float x, float y, float z);
		void set(float x, float y);
	public:
		/**
		*	ƽ��
		*/
		Vector3 tranlate(const Vector3& vector) const;
		/**
		*	����
		*/
		Vector3 scale(const Vector3& vector) const;
		/**
		*	������ת
		*/
		Vector3 rotationByAxis(const Vector3& vector, float radian) const;
		/**
		*	�����߶���ת����
		*/
		Vector3 rotationByLine(const Vector3& src, const Vector3& dest, float radian) const;
	public:
		/**
		*	��λ��
		*/
		void normalize();
		/**
		*	����Ԫ��
		*/
		Vector3& operator=(const Vector3& vec);
		/**
		*	����Ԫ��
		*/
		Vector3 operator=(const Vector3& vec) const;
	public:
		/**
		*	���
		*/
		Vector3 operator+(const Vector3& vec) const;
		/**
		*	���
		*/
		Vector3 operator-(const Vector3& vec) const;
		/**
		*	���
		*/
		Vector3 operator*(const Vector3& vec) const;
		/**
		*	���
		*/
		Vector3 operator/(const Vector3& vec) const;
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
		Vector3& operator+=(const Vector3& vec);
		/**
		*	���
		*/
		Vector3& operator-=(const Vector3& vec);
		/**
		*	���
		*/
		Vector3& operator*=(const Vector3& vec);
		/**
		*	���
		*/
		Vector3& operator/=(const Vector3& vec);
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
		bool operator==(const Vector3& vec) const;
		/**
		*	�����
		*/
		bool operator!=(const Vector3& vec) const;
		/**
		*	תΪ2ά
		*/
		operator Vector2() const;
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
		*	vector1��vector0�ļнǵĻ���
		*/
		static float getRadian(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ
		*/
		static float cosValue(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ(0,PI)
		*/
		static float sinValue(const Vector3& vector0, const Vector3& vector1);
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
		static bool isThreePointsCollinear(const Vector3& point0, const Vector3& point1, const Vector3& point2);
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
		/**
		*	��λ��
		*/
		static Vector3 normalize(const Vector3& vector);
	};

	static inline Vector3 operator*(float k, const Vector3& value)
	{
		return value * k;
	}
}