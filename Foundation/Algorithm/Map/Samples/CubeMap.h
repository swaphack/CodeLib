#pragma once


#include "RayMap.h"

namespace alg
{
	namespace map
	{
		/**
		*	��ά��ͼ
		*
		*			 y
		*			|
		*			|
		*			------->x
		*		   /
		*		z /
		*/
		class CubeMap : public RayMap
		{
		public:
			CubeMap();
			virtual ~CubeMap();
		public:
			uint32_t getWidth() const;
			uint32_t getHeight() const;
			uint32_t getDepth() const;
		public:
			/**
			*	��ȡ������
			*/
			const math::Vector3* getPosition(uint32_t i, uint32_t j, uint32_t k) const;
			/**
			*	��ʼ����ͼ
			*/
			void init3DMap(uint32_t width, uint32_t height, uint32_t depth);
		private:
			int _width = 0;
			int _height = 0;
			int _depth = 0;
		};

	}
}