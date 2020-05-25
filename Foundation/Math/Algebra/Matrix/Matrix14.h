#pragma once

#include "Matrix.h"
#include "../Vector/Vector3.h"
#include "Matrix44.h"

namespace math
{
	// 用于向量转换的矩阵
	struct Matrix14 : public Matrix
	{
	public:
		Matrix14();
		Matrix14(float x, float y, float z);
		Matrix14(float x, float y, float z, float w);
		Matrix14(const Vector3& vector);
		Matrix14(const Vector3& vector, float w);
		virtual ~Matrix14();
	public:
		operator Vector3();

		Matrix14 operator*(const Matrix44& mat);
	};
}