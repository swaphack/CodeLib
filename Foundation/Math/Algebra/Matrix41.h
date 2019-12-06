#pragma once

#include "Matrix.h"
#include "Vector3.h"

namespace math
{
	// 用于向量转换的矩阵
	struct Matrix41 : public Matrix
	{
	public:
		Matrix41();
		Matrix41(float x, float y, float z);
		Matrix41(float x, float y, float z, float w);
		Matrix41(const Vector3& vector);
		Matrix41(const Vector3& vector, float w);
	public:
		Vector3 operator()();
	};
}