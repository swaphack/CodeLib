#pragma once

#include "Matrix.h"

namespace math
{
	/**
	*	用于计算二元一次方程
	*/
	struct Matrix22 : public Matrix<float, 2,2>
	{
	public:
		Matrix22();
		Matrix22(const float* value);
		Matrix22(const Matrix22& mat);
		Matrix22(float a00, float a01, float a10, float a11);
		virtual ~Matrix22();
	public:
		math::Matrix22& operator=(const Matrix22& mat);
	};
}