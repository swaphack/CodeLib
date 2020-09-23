#pragma once

#include <cstdint>

#include "MapObject.h"
#include "MapObjects.h"
#include "Module.h"
#include "Slots.h"
#include "CombineSlots.h"

#include "SlotRule.h"

namespace alg
{
	namespace map
	{
		/**
		*	地图资源
		*
		*	组件（module) : 包含插槽信息， {标识， 插槽编号}
		*	插槽规则（rule）：每个插槽可以匹配的所有插槽信息
		*/
		template<typename M, const uint32_t SlotCount, const uint32_t RelationValue>
		class MapAssets : public MapObject
		{
			static_assert(std::is_base_of<Module, M>::value, "M must inherit from Module");
		public:
			MapAssets()
			{
				_mapModule.increaseID();
			}
			virtual ~MapAssets()
			{

			}
		public:
			/**
			*	生成模块
			*/
			M* createModule(uint32_t resID, const std::map<uint32_t, uint32_t>& slots)
			{
				auto ptr = _mapModule.create();
				if (ptr)
				{
					ptr->setResourceID(resID);
					ptr->getModuleSlot()->setSlots(slots);

					for (auto item : slots)
					{
						_mapModuleTag[item.first].insert(ptr->getMapObjectID());
					}
				}

				return ptr;
			}
			/**
			*	移除所有模块
			*/
			void removeAllModules()
			{
				_mapModule.removeAllObjects();
			}
			/**
			*	获取模块数量
			*/
			virtual uint32_t getModuleCount() const
			{
				return _mapModule.getObjectCount();
			}
			/**
			*	获取模块
			*/
			const M* getModule(uint32_t nIndex) const
			{
				return _mapModule.getObject(nIndex);
			}
			/**
			*	获取所有插模块
			*/
			const std::map<uint32_t, M*>& getAllModules() const
			{
				return _mapModule.getAllObjects();
			}
		public:
			/**
			*	添加插槽规则
			*/
			template<uint32_t Length>
			void addMatchSlot(uint32_t key, uint32_t start, ...)
			{
				va_list ap;
				va_start(ap, start);
				_mapSlotRule.addRelation<Length>(key, start, ap);
				va_end(ap);
			}
			/**
			*	添加插槽规则
			*/
			template<uint32_t Length>
			void addMatchSlot(uint32_t key, uint32_t start, va_list ap)
			{
				_mapSlotRule.addRelation<key, Length>(start, ap);
			}
			/**
			*	移除所有插槽规则
			*/
			void removeAllSlotRules()
			{
				_mapSlotRule.initRelationTable();
			}

			/**
			*	获取插槽规则
			*/
			bool getMatchSlots(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const
			{
				return _mapSlotRule.getRelations(slotIndex, relativeSlots);
			}
			/**
			*	获取所有插槽规则
			*/
			const SlotRule<SlotCount, RelationValue>& getSlotRule() const
			{
				return _mapSlotRule;
			}

			/**
			*	判断两者是否有关联
			*/
			bool hasRelation(uint32_t src, uint32_t dest)
			{
				return _mapSlotRule.hasRelation(src, dest);
			}
		public:
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const Slots& conditionSlots, std::vector<uint32_t>& modules)
			{
				return findModule(conditionSlots.getAllSlots(), modules);
			}
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const CombineSlots& conditionSlots, std::vector<uint32_t>& modules)
			{
				return findModule(conditionSlots.getAllSlots(), modules);
			}
		protected:
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules)
			{
				uint32_t target = 0;
				uint32_t count = 0;

				// 查询数据量最小的组
				for (const auto& item : conditionSlots)
				{
					auto it = _mapModuleTag.find(item.first);
					if (it == _mapModuleTag.end() || it->second.size() == 0)
					{// 无相关匹配对象
						return false;
					}

					if (target == 0 || count > it->second.size())
					{
						target = item.first;
						count = it->second.size();
					}
				}

				// 查询匹配的模块
				auto setData = _mapModuleTag[target];
				for (const auto& item : setData)
				{
					auto pModule = getModule(item);
					if (pModule->getModuleSlot()->matchSlots(conditionSlots))
					{
						modules.push_back(item);
					}
				}

				return modules.size() > 0;
			}
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const std::map<uint32_t, std::set<uint32_t>>& conditionSlots, std::vector<uint32_t>& modules)
			{
				int32_t target = -1;
				int32_t count = -1;

				// 查询数据量最小的组
				for (const auto& item : conditionSlots)
				{
					auto it = _mapModuleTag.find(item.first);
					if (it == _mapModuleTag.end() || it->second.size() == 0)
					{// 无相关匹配对象
						return false;
					}

					if (target == -1 || count > it->second.size())
					{
						target = item.first;
						count = it->second.size();
					}
				}

				if (target == -1)
				{
					return false;
				}

				// 查询匹配的模块
				auto setData = _mapModuleTag[target];
				for (const auto& item : setData)
				{
					auto pModule = getModule(item);
					if (pModule->getModuleSlot()->matchSlots(conditionSlots))
					{
						modules.push_back(item);
					}
				}
				return modules.size() > 0;
			}
		protected:
			// 模块
			MapObjects<M> _mapModule;
			// 包含标记的模块
			std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
			// 插槽关联的匹配规则 {插槽编号，匹配规则编号}
			SlotRule<SlotCount, RelationValue> _mapSlotRule;
		};

	}
}