#pragma once

#include "mathlib.h"

namespace alg
{
	class TerrianHelper
	{
	public:
		/**
		*	��ȡ��ʼ��Ŀ��֮�����С�����ֵ
		*/
		static void getRange(const math::Vector3& start, const math::Vector3& end, math::Vector3& min, math::Vector3& max);
		/**
		*	��ȡ��ʼ��Ŀ��֮����������
		*/
		static math::Vector3 getRandomPosition(math::Vector3 start, math::Vector3 end);

	};
}