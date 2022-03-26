#pragma once

#include "RayMap.h"

namespace alg
{
	namespace map
	{
		/**
		*	��ά��ͼ
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
			*	��ȡ������
			*/
			const math::Vector3* getPosition(uint32_t i, uint32_t j) const;
		protected:
			/**
			*	��ʼ����ͼ
			*/
			void init2DMap(int width, int height);
		private:
			int _width = 0;
			int _height = 0;
		};

	}
}