#pragma once

#include "Map/Base/MapModule.h"
#include "Map/Base/MapAssets.h"
#include "Array2DMap.h"

namespace alg
{
	// 二维方位
	enum class MapDirection2D
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
	// 二维模块
	class MapModule2D : public MapModule
	{
	public:
		MapModule2D();
		virtual ~MapModule2D();
	public:
		/**
		*	设置方位插槽
		*/
		void setDirectionSlot(MapDirection2D eDirection, uint32_t slotIndex);
		/**
		*	设置左方位插槽
		*/
		void setLeftSlot(uint32_t slotIndex);
		/**
		*	设置右方位插槽
		*/
		void setRightSlot(uint32_t slotIndex);
		/**
		*	设置上方位插槽
		*/
		void setUpSlot(uint32_t slotIndex);
		/**
		*	设置下方位插槽
		*/
		void setDownSlot(uint32_t slotIndex);
	};

	//////////////////////////////////////////////////////////////////////////

	/**
	*	二维地图创建
	*/
	template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Count = Width * Height>
	class MapCreator2D : public WFCAlgorithm
	{
	public:
		MapCreator2D() {}
		virtual ~MapCreator2D() {}
	public:
	};
}