#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix4x4.h"

namespace math
{
	// 用于向量转换的矩阵
	struct Matrix1x4 : public Matrix<float, 1, 4>
	{
	public:
		Matrix1x4();
		Matrix1x4(float x, float y, float z);
		Matrix1x4(float x, float y, float z, float w);
		Matrix1x4(const Vector3& vector);
		Matrix1x4(const Vector3& vector, float w);
		virtual ~Matrix1x4();
	public:
		operator Vector3();

		Matrix1x4 operator*(const Matrix4x4& mat);
	};
}