#pragma once

#include "PointMap.h"

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
	struct MeshMapRelation : public MapRelation
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
	/**
	*	网格地图
	*/
	class MeshMap : public PointMap<MeshMapRelation>
	{
	public:
		MeshMap();
		virtual ~MeshMap();
	public:
		template<uint32_t Length>
		void addMeshRelation(uint32_t start, ...)
		{
			va_list ap;
			va_start(ap, start);
			int32_t relationIndex = this->addRelation<Length>(start, ap);
			va_end(ap);
		}
		/**
		*	查找相邻节点
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	};
}
