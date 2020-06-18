#pragma once

#include "mathlib.h"
#include <cstdint>

namespace render
{
	struct ParticleData
	{
		math::Vector3 pos;
		math::Vector3 vel;

		static uint32_t totalSize()
		{
			return 6 * sizeof(float);
		}

		static uint32_t offsetVel()
		{
			return 3 * sizeof(float);
		}
	};
}