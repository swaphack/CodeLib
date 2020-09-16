#pragma once

#include "PointMap.h"

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
	struct MeshMapRelation : public MapRelation
	{
	public:
		MeshMapRelation();
		virtual ~MeshMapRelation();
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
		*	�������ڽڵ�
		*/
		virtual bool findNeighborPoint(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
	};
}
