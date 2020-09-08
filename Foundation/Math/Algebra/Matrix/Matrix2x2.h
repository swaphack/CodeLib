#pragma once

#include "Matrix.h"
#include "SquareMatrix.h"

namespace math
{
	/**
	*	用于计算二元一次方程
	*/
	struct Matrix2x2 : public SquareMatrix<2>
	{
	public:
		Matrix2x2();
		Matrix2x2(const float* value);
		Matrix2x2(const Matrix2x2& mat);
		Matrix2x2(float a00, float a01, float a10, float a11);
		virtual ~Matrix2x2();
	public:
		math::Matrix2x2& operator=(const Matrix2x2& mat);

		operator SquareMatrix<2>();
	};
}