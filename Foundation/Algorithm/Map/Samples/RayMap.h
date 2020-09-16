#pragma once

#include "PointMap.h"

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
	struct RayMapRelation : public MapRelation
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
	//////////////////////////////////////////////////////////////////////////
	class RayMap : public PointMap<RayMapRelation>
	{
	public:
		RayMap();
		virtual ~RayMap();
	public:
		/**
		*	添加射线关系
		*/
		template<uint32_t Center,  uint32_t Length>
		void addRayRelation(uint32_t start, ...)
		{
			va_list ap;
			va_start(ap, start);
			int32_t relationIndex = this->addRelation<Length>(start, ap);
			va_end(ap);
			if (relationIndex < 0)
			{
				return;
			}
			_centerRayRelation[Center] = relationIndex;
		}
		/**
		*	添加射线关系
		*/
		template<uint32_t Center>
		void addRayRelation(const std::vector<uint32_t>& relation)
		{
			int32_t relationIndex = this->addRelation(relation);
			if (relationIndex < 0)
			{
				return;
			}
			_centerRayRelation[Center] = relationIndex;
		}
		/**
		*	查找相邻节点
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		/**
		*	与中心相邻节点{当前点，与当前点关联的关系编号}
		*/
		std::map<uint32_t, uint32_t> _centerRayRelation;
	};
}
