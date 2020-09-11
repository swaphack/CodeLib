#pragma once

#include "Map.h"

namespace alg
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
	struct MeshRelation : public MapRelation
	{
	public:
		MeshRelation();
		virtual ~MeshRelation();
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
	/**
	*	网格地图
	*/
	class MeshMap : public Map
	{
	public:
		MeshMap();
		virtual ~MeshMap();
	public:
		/**
		*	查找相邻节点
		*/
		bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	};
}
