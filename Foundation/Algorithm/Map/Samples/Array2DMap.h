#pragma once

#include "RayMap.h"

namespace alg
{
	// ¶þÎ¬µØÍ¼
	template<const uint32_t Width, const uint32_t Height>
	class Array2DMap : public RayMap
	{
	public:
		Array2DMap()
		{

		}
		virtual ~Array2DMap()
		{

		}
	public:
		void initRelations()
		{
			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{
					int count = 4;
					uint32_t nIndex = i * Width + j;

					int32_t left = nIndex - 1;
					int32_t right = nIndex + 1;
					int32_t top = nIndex - Width;
					int32_t bottom = nIndex + Width;

					std::vector<uint32_t> relation;

					if (j > 0) relation.push_back(left);
					if (j <= Width - 1) relation.push_back(right);
					if (i > 0) relation.push_back(bottom);
					if (i <= Height - 1) relation.push_back(top);

					this->addRayRelation<nIndex>(relation);
				}
			}
		}
	private:
	};

}
