#pragma once

#include "Map/Base/MapModule.h"
#include "Map/Base/MapAssets.h"
#include "Array3DMap.h"

namespace alg
{
	// 二维方位
	enum class MapDirection3D
	{
		LEFT,
		RIGHT,
		Top,
		Bottom,
		FRONT,
		BACK,
	};
	// 二维模块
	class MapModule3D : public MapModule
	{
	public:
		MapModule3D();
		virtual ~MapModule3D();
	public:
		/**
		*	设置方位插槽
		*/
		void setDirectionSlot(MapDirection3D eDirection, uint32_t slotIndex);
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
		void setTopSlot(uint32_t slotIndex);
		/**
		*	设置下方位插槽
		*/
		void setBottomSlot(uint32_t slotIndex);
		/**
		*	设置前位插槽
		*/
		void setFrontSlot(uint32_t slotIndex);
		/**
		*	设置后方位插槽
		*/
		void setBackSlot(uint32_t slotIndex);
	};

	//////////////////////////////////////////////////////////////////////////

	// 三维地图创建
	template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Depth, const uint32_t Count = Width * Height * Depth>
	class MapCreator3D : public WFCAlgorithm
	{
	public:
		MapCreator3D() {}
		virtual ~MapCreator3D() {}
	public:
		/**
		*	生成地图
		*/
		bool create()
		{
			return false;
		}
	};
}