#pragma once

#include "mathlib.h"
#include "Struct/ObjectDetail.h"

namespace alg
{
	namespace map
	{
		/**
		*	地图上对象
		*/
		class MapObject : public ObjectDetail
		{
		public:
			MapObject();
			virtual ~MapObject();
		public:
			/**
			*	节点编号
			*/
			void setMapObjectID(uint32_t nIndex);
			/**
			*	节点编号
			*/
			uint32_t getMapObjectID() const;
		private:
			/**
			*	节点索引
			*/
			uint32_t _mapObjectID = 0;
		};
	}
}