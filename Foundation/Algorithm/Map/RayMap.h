#pragma once

#include "Map.h"

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
	struct RayRelation : public MapRelation
	{
	public:
		RayRelation();
		virtual ~RayRelation();
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
	class RayMap : public Map
	{
	public:
		RayMap();
		virtual ~RayMap();
	public:
		/**
		*	������߹�ϵ
		*/
		void addRayRelation(uint32_t centerIndex, uint32_t nLength, uint32_t start, ...);
		/**
		*	�������ڽڵ�
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	protected:
		/**
		*	���������ڽڵ�
		*/
		std::map<uint32_t, uint32_t> _centerRayRelation;
	};
}
