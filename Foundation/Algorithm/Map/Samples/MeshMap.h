#pragma once

#include "PointMap.h"

namespace alg
{
	namespace map
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
		class MeshMapRelation : public MapRelation
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
		class MeshMapRelationCreate : public IMapObjectCreate
		{
		public:
			virtual ~MeshMapRelationCreate();
		public:
			virtual MapObject* create();
		};
		/**
		*	�����ͼ
		*/
		class MeshMap : public PointMap
		{
		public:
			MeshMap();
			virtual ~MeshMap();
		public:
			void addMeshRelation(int length, uint32_t start, ...);
			/**
			*	�������ڽڵ�
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
		};
	}
}