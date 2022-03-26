#pragma once

#include "PointMap.h"

namespace alg
{
	namespace map
	{
		/**
		*	射线地图
		*	一个点，与周围点的链接
		*	形状:
		*
		*
		*  __/
		*	/\
		*
		*/
		class RayMapRelation : public MapRelation
		{
		public:
			RayMapRelation();
			virtual ~RayMapRelation();
		public:
			/**
			*	查找相邻节点
			*/
			bool findNeighbor(std::vector<uint32_t>& neighbors) const;
			/**
			*	查找一个从起点到终点的路径
			*/
			bool findWay(uint32_t toIndex) const;
		};

		class RayMapRelationCreate : public IMapObjectCreate
		{
		public:
			virtual ~RayMapRelationCreate();
		public:
			virtual MapObject* create();
		};

		//////////////////////////////////////////////////////////////////////////
		class RayMap : public PointMap
		{
		public:
			RayMap();
			virtual ~RayMap();
		public:
			/**
			*	添加射线关系
			*/
			void addRayRelation(uint32_t center, int length, uint32_t start, ...);

			/**
			*	添加射线关系
			*/
			void addRayRelation(uint32_t Center, const std::vector<uint32_t>& relation);
			/**
			*	查找相邻节点
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
		protected:
			/**
			*	与中心相邻节点{当前点，与当前点关联的关系编号}
			*/
			std::map<uint32_t, uint32_t> _centerRayRelation;
		};
	}
}