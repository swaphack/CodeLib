#pragma once

#include "mathlib.h"

#include <vector>

namespace phy
{
	// 点质量
	struct PointMass
	{
		// 质量
		float mass = 0;
		// 设计位置
		math::Vector3 designPosition;
		// 与重心的相对位置
		math::Vector3 correctedPosition;
	};


	struct MassHelper
	{
	public:
		/*
		*	计算质量和重心
		*/
		static float calMassAndCentroid(std::vector<PointMass>& masses, math::Vector3& centroid)
		{
			float total = 0;
			math::Vector3 center;

			for (const auto& item : masses)
			{
				total += item.mass;
				center += item.designPosition * item.mass;
			}


			centroid = center / total;
			for (auto& item : masses)
			{
				item.correctedPosition = item.designPosition - centroid;
			}
			return total;
		}
	};
}
