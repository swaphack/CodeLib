#pragma once

#include "RayMap.h"

namespace alg
{
	/** 
	*	二维地图
	* 
	*   ^ y
	*	|
	*	|
	*	------->x
	*/
	template<const uint32_t Width, const uint32_t Height>
	class Array2DMap : public RayMap
	{
	public:
		Array2DMap()
		{
			this->init2DMap();
		}
		virtual ~Array2DMap()
		{

		}
	public:
		/**
		*	获取点坐标
		*/
		const math::Vector3* getPosition(uint32_t i, uint32_t j) const
		{
			assert(i < Width&& j < Height);

			uint32_t nIndex = i * Width + j;

			return getPoint(nIndex);
		}
	protected:
		/**
		*	初始化地图
		*/
		void init2DMap()
		{
			for (int i = 0; i < Height; i++)
			{
				for (int j = 0; j < Width; j++)
				{

					auto pCell = this->createCell();
					pCell->setPosition(math::Vector2(i, j));

					uint32_t nIndex = pCell->getObjectIndex();
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
	};

}
