#pragma once

#include "Map.h"

namespace alg
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
	struct RayRelation : public MapRelation
	{
	public:
		RayRelation();
		virtual ~RayRelation();
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
	//////////////////////////////////////////////////////////////////////////
	class RayMap : public Map
	{
	public:
		RayMap();
		virtual ~RayMap();
	public:
		/**
		*	添加射线关系
		*/
		void addRayRelation(uint32_t centerIndex, uint32_t nLength, uint32_t start, ...);
		/**
		*	查找相邻节点
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		/**
		*	与中心相邻节点
		*/
		std::map<uint32_t, uint32_t> _centerRayRelation;
	};
}
