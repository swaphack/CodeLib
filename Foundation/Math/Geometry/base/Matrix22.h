#pragma once

#include "Algebra/Matrix.h"

namespace math
{
	/**
	*	���ڼ����Ԫһ�η���
	*/
	struct Matrix22 : public Matrix
	{
	public:
		Matrix22();
		Matrix22(float a00, float a01, float a10, float a11);
		virtual ~Matrix22();
	public:
		float getValue();
	};
}