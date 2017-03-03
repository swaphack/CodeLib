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
		*	��������
		*/
		void add(const Vector3& vector);
		/**
		*	��������
		*/
		void sub(const Vector3& vector);
		/**
		*	����
		*/
		void mult(const Vector3& vector);
		/**
		*	����
		*/
		void div(const float ratio);
		/**
		*	����
		*/
		void mult(const float ratio);
		/**
		*	�Ƿ�Ϊ0����
		*/
		bool isZero();
		/**
		*	����
		*/
		float getLength() const;
		/**
		*	����=
		*/
		Vector3& operator=(const Vector2& vector);
		/**
		*	����=
		*/
		Vector3& operator=(const Vector3& vector);
		/**
		*	����+
		*/
		Vector3 operator+(const Vector3& vector);
		/**
		*	����-
		*/
		Vector3 operator-(const Vector3& vector);
		/**
		*	����*
		*/
		Vector3 operator*(const float k);
		/**
		*	����/
		*/
		Vector3 operator/(const float k);

		/**
		*	����+
		*/
		Vector3 operator+(const Vector3& vector) const;
		/**
		*	����-
		*/
		Vector3 operator-(const Vector3& vector) const;
		/**
		*	����*
		*/
		Vector3 operator*(const float k) const;
		/**
		*	����/
		*/
		Vector3 operator/(const float k) const;

		/**
		*	����+=
		*/
		Vector3& operator+=(const Vector3& vector);
		/**
		*	����-=
		*/
		Vector3& operator-=(const Vector3& vector);
		/**
		*	����*=
		*/
		Vector3& operator*=(const float k);
		/**
		*	����/=
		*/
		Vector3& operator/=(const float k);

		/**
		*	����*
		*/
		float operator*(const Vector3& vector);
		/**
		*	����*
		*/
		float operator*(const Vector3& vector) const;
		/**
		*	�ж��������Ƿ����
		*/
		bool operator==(const Vector3& vector);
		/**
		*	�ж��������Ƿ񲻵�
		*/
		bool operator!=(const Vector3& vector);		
	public:
		/**
		*	�������
		*/
		static float dot(const Vector3& vector0, const Vector3& vector1);
		/**
		*	�������
		*/
		static Vector3 cross(const Vector3& vector0, const Vector3& vector1);
		/**
		*	�����ľ���
		*/
		static float distance(const Vector3& point0, const Vector3& point1);
		/**
		*	�ж�vector1��vector0��λ�÷���
		*	0 ����
		*	1 �����
		*	2 �ұ�
		*/
		static int direction(const Vector3& vector0, const Vector3& vector1);
		/**
		*	vector1��vector0�ļн�����ֵ
		*/
		static float cosAngle(const Vector3& vector0, const Vector3& vector1);
		/**
		*	���vector1��vector0��ͶӰ����
		*/
		static float project(const Vector3& vector0, const Vector3& vector1);
	public:
		static Vector3 Zero;
		static Vector3 One;
	};

	__declspec(selectany) Vector3 Vector3::Zero;
	__declspec(selectany) Vector3 Vector3::One = Vector3(1,1,1);
}