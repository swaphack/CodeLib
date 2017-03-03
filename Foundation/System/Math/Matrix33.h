#pragma once

#include "Matrix.h"
#include "Vector2.h"

namespace sys
{
	/**
	*	三阶方阵
	*/
	struct Matrix33 : Matrix
	{
		Matrix33();
		/**
		*	标准化,单位矩阵
		*/
		void unit();
		/**
		*	平移
		*/
		void translate(const Vector2& vector);

		/**
		*	缩放
		*/
		void scale(const Vector2& vector);

		/**
		*	旋转
		*/
		void rotate(float rotation);
	};
}