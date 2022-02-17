#include "MassHelper.h"

/*
*	计算质量和重心
*/

float phy::MassHelper::calMassAndCentroid(std::vector<PointMass>& masses, math::Vector3& centroid)
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
