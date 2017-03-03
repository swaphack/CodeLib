#pragma once

#include "Matrix.h"
#include "Vector2.h"

namespace sys
{
	/**
	*	���׷���
	*/
	struct Matrix33 : Matrix
	{
		Matrix33();
		/**
		*	��׼��,��λ����
		*/
		void unit();
		/**
		*	ƽ��
		*/
		void translate(const Vector2& vector);

		/**
		*	����
		*/
		void scale(const Vector2& vector);

		/**
		*	��ת
		*/
		void rotate(float rotation);
	};
}