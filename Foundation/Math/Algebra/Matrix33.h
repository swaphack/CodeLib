#pragma once

#include "Matrix.h"
#include "Vector2.h"

namespace math
{
	/**
	*	���׷���
	*/
	struct Matrix33 : Matrix
	{
	public:
		Matrix33();
	public:
		/**
		*	��׼��,��λ����
		*/
		void normalize();
		/**
		*	ƽ��
		*/
		void setTranslate(const Vector2& vector);

		/**
		*	����
		*/
		void setScale(const Vector2& vector);

		/**
		*	��ת
		*/
		void setRotate(float rotation);
	};
}