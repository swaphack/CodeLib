#pragma once

#include "PointMap.h"

namespace alg
{
	namespace map
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
		class RayMapRelation : public MapRelation
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

		class RayMapRelationCreate : public IMapObjectCreate
		{
		public:
			virtual ~RayMapRelationCreate();
		public:
			virtual MapObject* create();
		};

		//////////////////////////////////////////////////////////////////////////
		class RayMap : public PointMap
		{
		public:
			RayMap();
			virtual ~RayMap();
		public:
			/**
			*	������߹�ϵ
			*/
			void addRayRelation(uint32_t center, int length, uint32_t start, ...);

			/**
			*	������߹�ϵ
			*/
			void addRayRelation(uint32_t Center, const std::vector<uint32_t>& relation);
			/**
			*	�������ڽڵ�
			*/
			virtual bool findNeighborCells(uint32_t srcIndex, std::vector<uint32_t>& neighboors) const;
		protected:
			/**
			*	���������ڽڵ�{��ǰ�㣬�뵱ǰ������Ĺ�ϵ���}
			*/
			std::map<uint32_t, uint32_t> _centerRayRelation;
		};
	}
}