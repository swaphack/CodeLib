#pragma once

#include "macros.h"

namespace sys
{
	// Çò
	struct Sphere
	{
		// ÖÐÐÄµã
		Vector3 center;
		// °ë¾¶
		float radius;

		Sphere(Vector3 center, float radius)
			:center(center), radius(radius)
		{
		}


	};
}