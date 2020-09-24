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
		template<const uint32_t SlotCount, const uint32_t PonitCount, 
			const uint32_t RelationValue, typename M>
			class MapCreator : public CreateMapProtocol
		{
			static_assert(std::is_base_of<Module, M>::value, "M must inherit from Module");
		public:
			MapCreator() {}
			virtual ~MapCreator() {}
		public:
			/**
			*	设置随机种子
			*/
			void setSeed(uint32_t seed)
			{
				_seed = seed;
			}
			/**
			*	随机种子
			*/
			uint32_t getSeed() const
			{
				return _seed;
			}

			MapAssets<M, SlotCount, RelationValue>* getMapAssets() const
			{
				return _mapAssets;
			}
		public:
			/**
			*	查找适应位置的槽
			*/
			virtual bool getMatchPointSlots(MapProtocol* map, uint32_t nIndex, CombineSlots& slots) const
			{
				return false;
			}
			/**
			*	判断两个位置的插槽是否匹配
			*/
			virtual bool isTwoPointMatch(MapProtocol* map, uint32_t srcIndex, uint32_t srcModuleID, uint32_t destIndex, uint32_t destModuleID) const
			{
				return false;
			}
			/**
			*	获取模型数据
			*/
			virtual const Module* getModule(uint32_t moduleID) const
			{
				if (_mapAssets == nullptr)
				{
					return nullptr;
				}

				return _mapAssets->getModule(moduleID);
			}
		public:
			/**
			*	获取模型数据
			*/
			M* getModule(uint32_t moduleID)
			{
				if (_mapAssets == nullptr)
				{
					return nullptr;
				}

				return (M*)_mapAssets->getModule(moduleID);
			}
			
			/**
			*	加载地图资源
			*/
			void setMapAssets(const MapAssets<M, SlotCount, RelationValue>* assets)
			{
				_mapAssets = (MapAssets<M, SlotCount, RelationValue>*)assets;
			}
			
			/**
			*	创建地图
			*/
			bool create(MapProtocol* map, WFCAlgorithm* alg)
			{
				if (map == nullptr || alg == nullptr)
				{
					return false;
				}

				sys::Random::setSeed(_seed);

				MultiState states;
				for (const auto& item : _mapAssets->getAllModules())
				{
					states.add(item.first);
				}
				alg->initMap(map->getCellCount(), states);
				return alg->autoFillMap(map, this);
			}

			/**
			*	取出可填充位置的模块
			*/
			virtual bool getFillPointModules(MapProtocol* map, uint32_t nIndex, std::vector<uint32_t>& modules) const
			{
				if (map == nullptr)
				{
					return false;
				}
				if (nIndex >= map->getCellCount())
				{
					return false;
				}
				CombineSlots slots;
				if (!getMatchPointSlots(map, nIndex, slots))
				{
					return false;
				}

				if (!slots.empty())
				{
					return _mapAssets->findModule(slots, modules);
				}
				else
				{
					return true;
				}
			}
		protected:
			// 地图资源
			MapAssets<M, SlotCount, RelationValue>* _mapAssets = nullptr;
			// 随机种子
			uint32_t _seed = 0;
		};
	}
}