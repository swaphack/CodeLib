#pragma once

#include "mathlib.h"

#include <vector>

namespace phy
{
	// ������
	struct PointMass
	{
		// ����
		float mass = 0;
		// ���λ��
		math::Vector3 designPosition;
		// �����ĵ����λ��
		math::Vector3 correctedPosition;
	};


	struct MassHelper
	{
	public:
		/*
		*	��������������
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
