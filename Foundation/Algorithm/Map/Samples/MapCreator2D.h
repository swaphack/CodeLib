#pragma once

#include "Map/Creator/MapModule.h"
#include "Map/Creator/MapCreator.h"

namespace alg
{
	// 二维方位
	enum class Map2DDirection
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
	};
	// 二维配件
	class MapModule2D : public MapModule
	{
	public:
		MapModule2D();
		virtual ~MapModule2D();
	public:
		/**
		*	设置方位插槽
		*/
		void setDirectionSlot(Map2DDirection eDirection, uint32_t slotIndex);
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

	// 二维地图创建
	class MapCreator2D : public MapCreator
	{
	public:
		MapCreator2D();
		virtual ~MapCreator2D();
	public:
		/**
		*	设置地图大小
		*/
		void setMapSize(uint32_t width, uint32_t height);
		/**
		*	设置地图宽度
		*/
		uint32_t getWidth() const;
		/**
		*	设置地图高度
		*/
		uint32_t getHeight() const;
	public:
		/**
		*	生成地图
		*/
		//void create(Map& map);
	private:
		// 地图宽度
		uint32_t _mapWidth = 0;
		// 地图高度
		uint32_t _mapHeight = 0;
	};
}