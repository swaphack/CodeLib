#pragma once

#include "macros.h"

namespace sys
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