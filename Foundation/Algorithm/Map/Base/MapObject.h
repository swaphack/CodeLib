#pragma once

#include "mathlib.h"
#include "Struct/ObjectDetail.h"

namespace alg
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
		*	节点索引
		*/
		void setObjectIndex(uint32_t nIndex);
		/**
		*	节点索引
		*/
		uint32_t getObjectIndex() const;
	private:
		/**
		*	节点索引
		*/
		uint32_t _objectIndex = 0;
	};
}