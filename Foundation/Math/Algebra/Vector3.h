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
		*	�Ƿ�Ϊ0����
		*/
		bool isZero();
		/**
		*	����
		*/
		float getLength();
		/**
		*	��λ��
		*/
		Vector3 normalize();
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
		*	�ж��������Ƿ����
		*/
		bool operator==(const Vector3& vector);
		/**
		*	�ж��������Ƿ񲻵�
		*/
		bool operator!=(const Vector3& vector);	
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
		static float distance(const Vector3& point320, const Vector3& point321);
		/**
		*	�ж�vector1��vector0��λ�÷���
		*	0 ����
		*	1 �����
		*	2 �ұ�
		*/
		static int32_t direction(const Vector3& vector0, const Vector3& vector1);
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