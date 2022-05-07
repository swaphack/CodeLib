#pragma once

#include <cstdint>

#include "Map/Base/MapObject.h"
#include "Map/Base/MapObjects.h"
#include "Module.h"
#include "Slots.h"
#include "CombineSlots.h"

#include "SlotRule.h"

namespace alg
{
	namespace map
	{
		class MapModuleCreate : public IMapObjectCreate
		{
		public:
			virtual~MapModuleCreate();
		public:
			virtual MapObject* create();
		};

		/**
		*	地图资源
		*
		*	组件（module) : 包含插槽信息， {标识， 插槽编号}
		*	插槽规则（rule）：每个插槽可以匹配的所有插槽信息
		*/
		class MapAssets : public MapObject
		{
		public:
			MapAssets(int nSlotCount, IMapObjectCreate* moduleCreate);
			virtual ~MapAssets();
		public:
			/**
			*	生成模块
			*/
			Module* createModule(uint32_t resID, const std::map<uint32_t, uint32_t>& slots);
			/**
			*	移除所有模块
			*/
			void removeAllModules();
			/**
			*	获取模块数量
			*/
			virtual uint32_t getModuleCount() const;
			/**
			*	获取模块
			*/
			const Module* getModule(uint32_t nIndex) const;
			/**
			*	获取所有插模块
			*/
			std::map<uint32_t, Module*> getAllModules() const;
		public:
			/**
			*	添加插槽规则
			*/
			void addMatchRule(uint32_t key, int length, uint32_t start, ...);
			/**
			*	添加关联
			*/
			void addMatchRule(uint32_t key, uint32_t nLength, uint32_t startIndex, va_list ap);
			/**
			*	添加插槽规则
			*/
			void addMatchRule(uint32_t key, const std::vector<uint32_t>& targets);
			/**
			*	移除所有插槽规则
			*/
			void removeAllMatchRules();

			/**
			*	获取插槽规则
			*/
			bool getMatchSlots(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const;
			/**
			*	获取所有插槽规则
			*/
			const SlotRule& getSlotRule() const;

			/**
			*	判断两者是否有关联
			*/
			bool hasRelation(uint32_t src, uint32_t dest, int value = 1);
		public:
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const Slots& conditionSlots, std::vector<uint32_t>& modules);
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const CombineSlots& conditionSlots, std::vector<uint32_t>& modules);
		protected:
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules);
			/**
			*	根据匹配槽，获取满足的模块
			*/
			bool findModule(const std::map<uint32_t, std::set<uint32_t>>& conditionSlots, std::vector<uint32_t>& modules);
		protected:
			// 模块
			MapObjects _mapModule;
			// 包含标记的模块
			std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
			// 插槽关联的匹配规则 {插槽编号，匹配规则编号};0-无关系，1-有关系
			SlotRule _mapSlotRule;
		};

	}
}