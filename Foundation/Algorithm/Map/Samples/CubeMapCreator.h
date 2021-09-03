#pragma once

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "Map/Creator/MapCreator.h"
#include "CubeMap.h"

namespace alg
{
	namespace map
	{
		// 三维方位
		enum class CubeModuleDirection
		{
			LEFT,
			RIGHT,
			Top,
			Bottom,
			FRONT,
			BACK,
		};
		// 立方体模块
		class CubeMapModule : public Module
		{
		public:
			CubeMapModule();
			virtual ~CubeMapModule();
		public:
			/**
			*	设置方位插槽
			*/
			void setSlot(CubeModuleDirection eDirection, uint32_t slotIndex);
			/**
			*	获取方位插槽
			*/
			uint32_t getSlot(CubeModuleDirection eDirection);
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

		// 立方体地图创建
		template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t Depth, const uint32_t PonitCount = Width * Height* Depth>
		class CubeMapCreator : public MapCreator<SlotCount, PonitCount, 1, CubeMapModule>
		{
		public:
			CubeMapCreator() {}
			virtual ~CubeMapCreator() {}
		public:
			/**
			*	查找适应位置的模块
			*/
			virtual bool getMatchModules(uint32_t nIndex, std::vector<uint32_t>& modules)
			{
				return false;
			}
			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID)
			{
				return false;
			}
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
}