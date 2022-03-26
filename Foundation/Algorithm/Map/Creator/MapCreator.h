#pragma once

#include <cstdint>

#include "Map/Base/Module.h"
#include "Map/Base/MapAssets.h"
#include "WFCAlgorithm.h"

namespace alg
{
	namespace map
	{
		class MapProtocol;

		/**
		*	生成地图接口
		*/
		class CreateMapProtocol
		{
		public:
			virtual ~CreateMapProtocol() {}
		public:
			/**
			*	取出可填充位置的模块
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const = 0;
			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const = 0;
			/**
			*	获取模型数据
			*/
			virtual const Module* getModule(uint32_t moduleID) const = 0;
		};

		/**
		*	地图生成
		*/
		class MapCreator : public CreateMapProtocol
		{
		public:
			MapCreator(uint32_t slotCount, IMapObjectCreate* moduleCreate);
			virtual ~MapCreator();
		public:
			/**
			*	设置随机种子
			*/
			void setSeed(uint32_t seed);
			/**
			*	随机种子
			*/
			uint32_t getSeed() const;
			/**
			*	地图资源
			*/
			MapAssets* getMapAssets() const;
		public:
			/**
			*	查找适应位置的槽
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const;
			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const;
			/**
			*	获取模型数据
			*/
			virtual const Module* getModule(uint32_t moduleID) const;
		public:			
			/**
			*	设置地图资源
			*/
			void setMapAssets(const MapAssets* assets);
			
			/**
			*	创建地图
			*/
			bool create(MapProtocol* map, WFCAlgorithm* alg);

			/**
			*	取出可填充位置的模块
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const;
		protected:
			// 地图资源
			MapAssets* _mapAssets = nullptr;
			// 随机种子
			uint32_t _seed = 0;
		};
	}
}