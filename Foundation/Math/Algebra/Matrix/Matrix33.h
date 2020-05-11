#pragma once

#include "Matrix.h"
#include "../Vector/Vector2.h"

namespace math
{
	/**
	*	三阶方阵
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
		*	标准化,单位矩阵
		*/
		void loadIdentity();
		/**
		*	平移
		*/
		void setTranslate(const Vector2& vector);

		/**
		*	缩放
		*/
		void setScale(const Vector2& vector);

		/**
		*	旋转
		*/
		void setRotate(float rotation);
	};
}