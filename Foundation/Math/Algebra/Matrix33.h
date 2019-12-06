#pragma once

#include "Matrix.h"
#include "Vector2.h"

namespace math
{
	/**
	*	三阶方阵
	*/
	struct Matrix33 : Matrix
	{
	public:
		Matrix33();
	public:
		/**
		*	标准化,单位矩阵
		*/
		void normalize();
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