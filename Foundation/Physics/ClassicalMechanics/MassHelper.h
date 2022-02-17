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
		static float calMassAndCentroid(std::vector<PointMass>& masses, math::Vector3& centroid);
	};
}
