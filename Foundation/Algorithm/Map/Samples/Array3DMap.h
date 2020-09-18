#pragma once


#include "RayMap.h"

namespace alg
{
	/**
	*	二维地图
	*
	*			 y
	*			|
	*			|
	*			------->x
	*		   /
	*		z /
	*/
	template<const uint32_t Width, const uint32_t Height, const uint32_t Depth>
	class Array3DMap : public RayMap
	{
	public:
		Array3DMap()
		{
			this->init3DMap();
		}
		virtual ~Array3DMap()
		{

		}
	public:
		/**
		*	获取点坐标
		*/
		const math::Vector3* getPosition(uint32_t i, uint32_t j, uint32_t k) const
		{
			assert(i < Width&& j < Height);

			uint32_t nIndex = k * Height * Width + i * Width + j;

			return getPoint(nIndex);
		}
	protected:
		/**
		*	初始化地图
		*/
		void init3DMap()
		{
			for (int k = 0; k < Depth; k++)
			{
				for (int i = 0; i < Height; i++)
				{
					for (int j = 0; j < Width; j++)
					{
						auto pCell = this->createCell();
						pCell->setPosition(math::Vector3(i, j, k));

						uint32_t nIndex = pCell->getObjectIndex();
						int32_t left = nIndex - 1;
						int32_t right = nIndex + 1;
						int32_t top = nIndex - Depth * Width;
						int32_t bottom = nIndex + Depth * Width;
						int32_t front = nIndex + Height * Width;
						int32_t back = nIndex - Height * Width;

						std::vector<uint32_t> relation;

						if (j > 0) relation.push_back(left);
						if (j <= Width - 1) relation.push_back(right);
						if (i > 0) relation.push_back(bottom);
						if (i <= Height - 1) relation.push_back(top);
						if (k > 0) relation.push_back(back);
						if (k <= Height - 1) relation.push_back(front);

						this->addRayRelation<nIndex>(relation);
					}
				}
			}
		}
	};

}