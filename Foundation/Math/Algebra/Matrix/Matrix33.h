#pragma once

#include "Matrix.h"
#include "../Vector/Vector2.h"

namespace math
{
	/**
	*	���׷���
	*/
	struct Matrix33 : public Matrix
	{
	public:
		Matrix33();
		Matrix33(const Vector3& row0, const Vector3& row1, const Vector3& row2);
		Matrix33(const Matrix33& mat);
		virtual ~Matrix33();
	public:
		/**
		*	��׼��,��λ����
		*/
		void loadIdentity();
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