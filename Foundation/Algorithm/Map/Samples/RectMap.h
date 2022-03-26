#pragma once

#include "RayMap.h"

namespace alg
{
	namespace map
	{
		/**
		*	二维地图
		*
		*   ^ y
		*	|
		*	|
		*	------->x
		*/
		class RectMap : public RayMap
		{
		public:
			RectMap(int width, int height);
			virtual ~RectMap();
		public:
			/**
			*	获取点坐标
			*/
			const math::Vector3* getPosition(uint32_t i, uint32_t j) const;
		protected:
			/**
			*	初始化地图
			*/
			void init2DMap(int width, int height);
		private:
			int _width = 0;
			int _height = 0;
		};

	}
}