#pragma once

#include "Matrix.h"
#include "Vector3.h"

namespace math
{
	// ��������ת���ľ���
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