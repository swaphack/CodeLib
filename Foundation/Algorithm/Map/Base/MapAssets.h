#pragma once

#include "MapObject.h"
#include "MapObjects.h"
#include "MapModule.h"
#include "ModuleSlots.h"

#include "SlotRule.h"

namespace alg
{
	/**
	*	地图资源
	*	
	*	组件（module) : 包含插槽信息， {标识， 插槽编号}
	*	插槽规则（rule）：每个插槽可以匹配的所有插槽信息
	*/
	template<typename M, typename = std::enable_if<std::is_base_of<MapModule, M>::value, M>::type>
	class MapAssets : public MapObject
	{
	public:
		MapAssets()
		{

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
				ptr->getSlot()->setSlots(slots);

				for (auto item : slots)
				{
					_mapModuleTag[item.first].insert(ptr->getObjectIndex());
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
		const std::map <uint32_t, M*>& getAllModules() const
		{
			return _mapModule.getAllObjects();
		}
	public:
		/**
		*	添加插槽规则
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, ...)
		{
			SlotRule* mr = &_mapSlotRule[key];
			if (mr)
			{
				va_list ap;
				va_start(ap, start);
				mr->addRelation(Length, start, ap);
				va_end(ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	添加插槽规则
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, va_list ap)
		{
			SlotRule* mr = &_mapSlotRule[key];
			if (mr)
			{
				mr->addRelation(Length, start, ap);
				return mr->getObjectIndex();
			}
			return -1;
		}
		/**
		*	移除所有插槽规则
		*/
		void removeAllSlotRules()
		{
			_mapSlotRule.clear();
		}
		/**
		*	获取插槽规则数量
		*/
		uint32_t getSlotRuleCount() const
		{
			return _mapSlotRule.size();
		}
		/**
		*	获取插槽规则
		*/
		bool getSlotRule(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const
		{
			auto it = _mapSlotRule.find(slotIndex);
			if (it == _mapSlotRule.end())
			{
				return false;
			}

			relativeSlots = it->second.getAllRelations();

			return relativeSlots.size() > 0;
		}
		/**
		*	获取所有插槽规则
		*/
		const std::map <uint32_t, SlotRule>& getAllSlotRules() const
		{
			return _mapSlotRule;
		}
	public:
		/**
		*	根据匹配槽，获取满足的模块
		*/
		bool findModule(const ModuleSlots& conditionSlots, std::vector<uint32_t>& modules)
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
			for (auto item : conditionSlots)
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
			for (auto item : setData)
			{
				auto pModule = getModule(item);
				if (pModule->getSlot()->matchSlots(conditionSlots))
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
		std::map <uint32_t, SlotRule> _mapSlotRule;
	};

}