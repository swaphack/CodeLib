#pragma once

#include "Map/Base/Map.h"

namespace alg
{
	namespace map
	{
		/**
		*	点标志单元
		*/
		class PointMapCell : public MapCell
		{
		public:
		protected:
		private:
		};

		class PointMapCellCreate : public IMapObjectCreate
		{
		public:
			virtual ~PointMapCellCreate();
		public:
			virtual MapObject* create();
		};

		/**
		*	点标志地图
		*/
		class PointMap : public Map
		{
		public:
			PointMap();
			virtual ~PointMap();
		public:
			/**
			*	计算两节点的距离
			*/
			virtual float getDistance(uint32_t srcIndex, uint32_t toIndex) const;
			/**
			*	添加坐标点
			*/
			int32_t addPoint(const math::Vector3& point);
			/**
			*	获取点坐标
			*/
			const math::Vector3* getPoint(uint32_t nIndex) const;
		};
	}

}