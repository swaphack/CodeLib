#pragma once

#include "Map/Base/MapObject.h"
#include "Map/Base/MapObjects.h"

#include "MapSlotRule.h"
#include "MapModule.h"
#include "MapSlot.h"

namespace alg
{
	/**
	*	地图生成器
	*	
	*	组件（module) : 包含插槽信息， {标识， 插槽编号}
	*	插槽规则（rule）：每个插槽可以匹配的所有插槽信息
	*/
	class MapCreator : public MapObject
	{
	public:
		MapCreator();
		virtual ~MapCreator();
	public:
		/**
		*	生成配件
		*/
		MapModule* createModule(const std::map<uint32_t, uint32_t>& slots);
		/**
		*	移除所有配件
		*/
		void removeAllModules();
		/**
		*	获取配件数量
		*/
		virtual uint32_t getModuleCount() const;
		/**
		*	获取配件
		*/
		const MapModule* getModule(uint32_t nIndex) const;
	public:
		/**
		*	添加插槽规则
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, ...);
		/**
		*	添加插槽规则
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, va_list ap);
		/**
		*	移除所有插槽规则
		*/
		void removeAllSlotRules();
		/**
		*	获取插槽规则数量
		*/
		uint32_t getSlotRuleCount() const;
		/**
		*	获取插槽规则
		*/
		bool getSlotRule(uint32_t nSlotIndex, std::vector<uint32_t>& slots) const;
	public:
		/**
		*	根据匹配槽，获取满足的配件
		*/
		bool findModule(const MapSlot& conditionSlots, std::vector<uint32_t>& modules);
	protected:
		/**
		*	根据匹配槽，获取满足的配件
		*/
		bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules);
	protected:
		// 配件
		MapObjects<MapModule> _mapModule;
		// 包含标记的配件
		std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
		// 插槽关联的匹配规则 {插槽编号，匹配规则编号}
		std::map <uint32_t, MapObjects<MapSlotRule>> _mapSlotRule;
	};

	template<uint32_t Length>
	int32_t alg::MapCreator::addSlotRule(uint32_t key, uint32_t start, ...)
	{
		MapSlotRule* mr = _mapSlotRule[key].create();
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

	template<uint32_t Length>
	int32_t alg::MapCreator::addSlotRule(uint32_t key, uint32_t start, va_list ap)
	{
		MapSlotRule* mr = _mapSlotRule[key].create();
		if (mr)
		{
			mr->addRelation(Length, start, ap);
			return mr->getObjectIndex();
		}
		return -1;
	}

}