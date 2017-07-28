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
		*	����
		*/
		float getLength() const;
		/**
		*	��������
		*/
		void add(const Vector2& point);
		/**
		*	��������
		*/
		void sub(const Vector2& point);
		/**
		*	����
		*/
		void mult(const Vector2& point);
		/**
		*	����
		*/
		void div(const Vector2& point);

		/**
		*	����
		*/
		void mult(const float ratio);
		/**
		*	����
		*/
		void div(const float ratio);
		/**
		*	����=
		*/
		Vector2& operator = (const Vector2& point);
		/**
		*	����+
		*/
		Vector2 operator+(const Vector2& vector);
		/**
		*	����-
		*/
		Vector2 operator-(const Vector2& vector);
		/**
		*	����*
		*/
		Vector2 operator*(const float k);
		/**
		*	����/
		*/
		Vector2 operator/(const float k);
		/**
		*	����+
		*/
		Vector2 operator+(const Vector2& vector) const;
		/**
		*	����-
		*/
		Vector2 operator-(const Vector2& vector) const;
		/**
		*	����*
		*/
		Vector2 operator*(const float k) const;
		/**
		*	����/
		*/
		Vector2 operator/(const float k) const;
		/**
		*	����+=
		*/
		Vector2& operator+=(const Vector2& vector);
		/**
		*	����-=
		*/
		Vector2& operator-=(const Vector2& vector);
		/**
		*	����*=
		*/
		Vector2& operator*=(const float k);
		/**
		*	����/=
		*/
		Vector2& operator/=(const float k);
		/**
		*	�ж��������Ƿ����
		*/
		bool operator==(const Vector2& vector);
		/**
		*	�ж��������Ƿ񲻵�
		*/
		bool operator!=(const Vector2& vector);
	public:
		static Vector2 Zero;
	public:
		/**
		*	���
		*/
		static float dot(const Vector2& vector0, const Vector2& vector1);
		/**
		*	�������
		*/
		static Vector2 cross(const Vector2& vector0, const Vector2& vector1);
		/**
		*	����
		*/
		static float distance(const Vector2& point0, const Vector2& point1);
		/**
		*	�ж�vector1��vector0��λ�÷���
		*	0 ����
		*	1 �����
		*	2 ���ұ�
		*/
		static int direction(const Vector2& vector0, const Vector2& vector1);
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
	};

	__declspec(selectany) Vector2 Vector2::Zero;
}