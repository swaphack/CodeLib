#pragma once

#include "Map/Base/Map.h"

namespace alg
{
	namespace map
	{
		/**
		*	���־��Ԫ
		*/
		class PointMapCell : public MapCell
		{
		public:
		protected:
		private:
		};

		class PointMapCellCreate : public IMapObjectCreate
		{
		public:
			virtual ~PointMapCellCreate();
		public:
			virtual MapObject* create();
		};

		/**
		*	���־��ͼ
		*/
		class PointMap : public Map
		{
		public:
			PointMap();
			virtual ~PointMap();
		public:
			/**
			*	�������ڵ�ľ���
			*/
			virtual float getDistance(uint32_t srcIndex, uint32_t toIndex) const;
			/**
			*	��������
			*/
			int32_t addPoint(const math::Vector3& point);
			/**
			*	��ȡ������
			*/
			const math::Vector3* getPoint(uint32_t nIndex) const;
		};
	}

}