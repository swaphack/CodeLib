#pragma once

#include "Algebra/import.h"

namespace math
{
	// ��
	struct Sphere
	{
		// ���ĵ�
		Vector3 center;
		// �뾶
		float radius = 0;

		Sphere(Vector3 center, float radius)
			:center(center), radius(radius)
		{
		}
	};
}