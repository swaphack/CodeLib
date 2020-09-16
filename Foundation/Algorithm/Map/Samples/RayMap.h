#pragma once

#include "PointMap.h"

namespace alg
{
	/**
	*	���ߵ�ͼ
	*	һ���㣬����Χ�������
	*	��״:
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
		*	�������ڽڵ�
		*/
		bool findNeighbor(std::vector<uint32_t>& neighbors) const;
		/**
		*	����һ������㵽�յ��·��
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
		*	������߹�ϵ
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
		*	������߹�ϵ
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
		*	�������ڽڵ�
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		/**
		*	���������ڽڵ�{��ǰ�㣬�뵱ǰ������Ĺ�ϵ���}
		*/
		std::map<uint32_t, uint32_t> _centerRayRelation;
	};
}
