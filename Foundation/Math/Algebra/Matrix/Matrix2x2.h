#pragma once

#include "Matrix.h"
#include "SquareMatrix.h"

namespace math
{
	/**
	*	用于计算二元一次方程
	*/
	struct Matrix2x2 : public SquareMatrix2
	{
	public:
		Matrix2x2();
		Matrix2x2(const float* value);
		Matrix2x2(const Matrix2x2& mat);
		Matrix2x2(const SquareMatrix2& mat);
		Matrix2x2(const SquareMatrix<float, 2>& mat);
		Matrix2x2(float a00, float a01, float a10, float a11);
		virtual ~Matrix2x2();
	public:
		Matrix2x2& operator=(const Matrix2x2& mat);

		Matrix2x2 operator*(const Matrix2x2& mat);
		
	};
}