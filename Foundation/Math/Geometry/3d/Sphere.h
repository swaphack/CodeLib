#pragma once

#include "Geometry/base/Vector3.h"

namespace math
{
	// ��
	struct Sphere
	{
		// ���ĵ�
		Vector3 center;
		// �뾶
		float radius;

		Sphere(Vector3 center, float radius)
			:center(center), radius(radius)
		{
		}
	};
}