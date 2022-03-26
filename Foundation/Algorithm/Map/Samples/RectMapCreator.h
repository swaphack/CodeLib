#pragma once

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "Map/Creator/MapCreator.h"
#include "RectMap.h"

namespace alg
{
	namespace map
	{
		// 二维方位
		enum class RectModuleDirection
		{
			LEFT,
			RIGHT,
			UP,
			DOWN,
		};
		// 矩形模块
		class RectModule : public Module
		{
		public:
			RectModule();
			virtual ~RectModule();
		public:
			/**
			*	设置方位插槽
			*/
			void setSlot(RectModuleDirection eDirection, uint32_t slotIndex);
			/**
			*	获取方位插槽
			*/
			uint32_t getSlot(RectModuleDirection eDirection);
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
		class RectModuleCreate : public IMapObjectCreate
		{
		public:
			RectModuleCreate();
			virtual ~RectModuleCreate();
		public:
			virtual MapObject* create();
		};
		//////////////////////////////////////////////////////////////////////////
		class RectMapCreator : public MapCreator
		{
		public:
			RectMapCreator(int slotCount, uint32_t width, uint32_t height);
			virtual ~RectMapCreator();
		protected:
			/**
			*	获取指定方向的插槽信息
			*/
			bool getSlots(const MapCell* cell, RectModuleDirection dir, CombineSlots& slots) const;
		public:
			/**
			*	查找适应位置的槽
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const;

			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const;
		private:
			int _width = 0;
			int _height = 0;
		};
	}
}