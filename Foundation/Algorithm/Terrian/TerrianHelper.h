#pragma once

#include "mathlib.h"

namespace alg
{
	class TerrianHelper
	{
	public:
		/**
		*	获取起始与目标之间的最小和最大值
		*/
		static void getRange(const math::Vector3& start, const math::Vector3& end, math::Vector3& min, math::Vector3& max);
		/**
		*	获取起始与目标之间的随机坐标
		*/
		static math::Vector3 getRandomPosition(math::Vector3 start, math::Vector3 end);

	};
}