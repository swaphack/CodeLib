#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"

namespace math
{
	// 用于向量转换的矩阵
	struct Matrix4x1 : public Matrix<float, 4, 1>
	{
	public:
		Matrix4x1();
		Matrix4x1(float x, float y, float z);
		Matrix4x1(float x, float y, float z, float w);
		Matrix4x1(const Vector3& vector);
		Matrix4x1(const Vector3& vector, float w);
		Matrix4x1(const float* value);
		virtual ~Matrix4x1();
	public:
		operator Vector3() const;
	};
}