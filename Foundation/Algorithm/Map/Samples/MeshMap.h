#pragma once

#include "PointMap.h"

namespace alg
{
	namespace map
	{
		/**
		*	网格关系
		*	多个点组成的网格
		*
		*	形状:
		*	 ___
		*	/	\
		*	\___/
		*/
		class MeshMapRelation : public MapRelation
		{
		public:
			MeshMapRelation();
			virtual ~MeshMapRelation();
		public:
			/**
			*	查找相邻节点
			*/
			bool findNeighbor(uint32_t srcIndex, std::vector<uint32_t>& neighbors) const;
			/**
			*	查找一个从起点到终点的路径
			*/
			bool findWay(uint32_t fromIndex, uint32_t toIndex, std::vector<uint32_t>& indices) const;
		private:
		};
		class MeshMapRelationCreate : public IMapObjectCreate
		{
		public:
			virtual ~MeshMapRelationCreate();
		public:
			virtual MapObject* create();
		};
		/**
		*	网格地图
		*/
		class MeshMap : public PointMap
		{
		public:
			MeshMap();
			virtual ~MeshMap();
		public:
			void addMeshRelation(int length, uint32_t start, ...);
			/**
			*	查找相邻节点
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
		};
	}
}