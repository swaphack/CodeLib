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
		//////////////////////////////////////////////////////////////////////////

		/**
		*	矩形地图创建
		*/
		template<const uint32_t SlotCount, const uint32_t Width, const uint32_t Height, const uint32_t PonitCount = Width * Height>
		class RectMapCreator : public MapCreator<SlotCount, PonitCount, 1, RectModule>
		{
			typedef MapCreator<SlotCount, PonitCount, 1, RectModule> base;
		public:
			RectMapCreator() {}
			virtual ~RectMapCreator() {}
		protected:
			/**
			*	获取指定方向的插槽信息
			*/
			bool getSlots(const MapCell* cell, RectModuleDirection dir, CombineSlots& slots) const
			{
				if (cell == nullptr)
				{
					return false;
				}

				uint32_t nModuleID = cell->getModuldeID();
				if (nModuleID == 0)
				{
					return false;
				}

				auto pModule = base::getModule(nModuleID);
				if (pModule == nullptr)
				{
					return false;
				}

				RectModuleDirection reverseDir = RectModuleDirection::LEFT;
				switch (dir)
				{
				case alg::map::RectModuleDirection::LEFT:
					reverseDir = RectModuleDirection::RIGHT;
					break;
				case alg::map::RectModuleDirection::RIGHT:
					reverseDir = RectModuleDirection::LEFT;
					break;
				case alg::map::RectModuleDirection::UP:
					reverseDir = RectModuleDirection::DOWN;
					break;
				case alg::map::RectModuleDirection::DOWN:
					reverseDir = RectModuleDirection::UP;
					break;
				default:
					break;
				}

				uint32_t nTargetSlot = pModule->getModuleSlot()->getSlot((uint32_t)reverseDir);
				std::vector<uint32_t> relations;
				if (base::getMapAssets()->getMatchSlots(nTargetSlot, relations))
				{
					slots.addSlots((uint32_t)dir, relations);
					return true;
				}

				return false;
			}
		public:
			/**
			*	查找适应位置的槽
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const
			{
				auto pCell = map->getCell(nIndex);
				if (pCell == nullptr)
				{
					return false;
				}
				/*
				if (pCell->getModuldeID() > 0)
				{
					return false;
				}
				*/

				uint32_t i = nIndex / Width;
				uint32_t j = nIndex % Width;

				RectModule module;
				if (j > 0)
				{
					auto pLeftCell = map->getCell(nIndex - 1);
					
					if (pLeftCell != nullptr && pLeftCell->getModuldeID() > 0)
					{// 左边
						getSlots(pLeftCell, RectModuleDirection::LEFT, slots);
						
					}
				}
				if (j < Width - 1)
				{
					auto pRightCell = map->getCell(nIndex + 1);
					if (pRightCell != nullptr && pRightCell->getModuldeID() > 0)
					{// 右边
						getSlots(pRightCell, RectModuleDirection::RIGHT, slots);
					}
				}
				if (i > 0)
				{
					auto pDownCell = map->getCell(nIndex - Width);
					if (pDownCell != nullptr && pDownCell->getModuldeID() > 0)
					{// 右边
						getSlots(pDownCell, RectModuleDirection::DOWN, slots);
					}
				}

				if (i < Height - 1)
				{
					auto pUpCell = map->getCell(nIndex + Width);
					if (pUpCell != nullptr && pUpCell->getModuldeID() > 0)
					{// 右边
						getSlots(pUpCell, RectModuleDirection::UP, slots);
					}
				}
				return true;
			}

			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const
			{
				
				RectModule* pSrcModule = (RectModule*)base::getModule(srcModuleID);
				RectModule* pDestModule = (RectModule*)base::getModule(destModuleID);
				if (pSrcModule == nullptr || pDestModule == nullptr)
				{
					return true;
				}

				std::map<uint32_t, RectModule*> mapModule;
				mapModule[srcIndex] = pSrcModule;
				mapModule[destIndex] = pDestModule;

				uint32_t minIndex = MIN(srcIndex, destIndex);
				uint32_t maxIndex = MAX(srcIndex, destIndex);

				uint32_t minI = minIndex / Width;
				uint32_t minJ = minIndex % Width;

				uint32_t maxI = maxIndex / Width;
				uint32_t maxJ = maxIndex % Width;

				// 左右关系
				if (minI == maxI && minJ + 1 == maxJ)
				{
					auto pLeftModule = mapModule[minIndex];
					auto pRightModule = mapModule[maxIndex];

					if (base::getMapAssets()->hasRelation(pLeftModule->getSlot(RectModuleDirection::RIGHT),
						pRightModule->getSlot(RectModuleDirection::LEFT)))
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				// 上下关系
				if (minJ == maxJ && minI + 1 == maxI)
				{
					auto pBottomModule = mapModule[minIndex];
					auto pTopModule = mapModule[maxIndex];

					if (base::getMapAssets()->hasRelation(pBottomModule->getSlot(RectModuleDirection::UP),
						pTopModule->getSlot(RectModuleDirection::DOWN)))
					{
						return true;
					}
					else
					{
						return false;
					}
				}

				return true;
			}
		};
	}
}