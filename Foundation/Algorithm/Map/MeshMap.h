#pragma once

#include "Map.h"

namespace alg
{
	/**
	*	�����ϵ
	*	�������ɵ�����
	* 
	*	��״:
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
		*	�������ڽڵ�
		*/
		bool findNeighbor(uint32_t srcIndex, std::vector<uint32_t>& neighbors) const;
		/**
		*	����һ������㵽�յ��·��
		*/
		bool findWay(uint32_t fromIndex, uint32_t toIndex, std::vector<uint32_t>& indices) const;
	private:
	};
	/**
	*	�����ͼ
	*/
	class MeshMap : public Map
	{
	public:
		MeshMap();
		virtual ~MeshMap();
	public:
		/**
		*	�������ڽڵ�
		*/
		bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	};
}
