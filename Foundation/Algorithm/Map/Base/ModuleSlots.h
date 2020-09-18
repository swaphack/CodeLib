#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	/* 
	*	组件插槽
	*	每个组件包含多个插槽
	*	每个插槽都是一个指定的形状，只有跟这个插槽匹配的插槽，才能连结在一起
	*/ 
	class ModuleSlots : public MapObject
	{
	public:
		ModuleSlots();
		virtual ~ModuleSlots();
	public:
		/**
		*	设置插槽
		*/
		void setSlots(const std::map<uint32_t, uint32_t>& slots);
		/**
		*	设置插槽
		*/
		void addSlot(uint32_t side, uint32_t slotIndex);
		/**
		*	移除插槽
		*/
		void removeSlot(uint32_t side);
		/**
		*	移除所有插槽
		*/
		void removellAllSlots();
		/**
		*	获取插槽
		*/
		uint32_t getSlot(uint32_t tag) const;
		/**
		*	获取插槽
		*/
		const std::map<uint32_t, uint32_t>& getAllSlots() const;
	public:
		/**
		*	检查插槽是否匹配
		*/
		bool matchModuleSlots(const ModuleSlots& slot) const;
		/**
		*	检查插槽是否匹配
		*/
		bool matchSlots(const std::map<uint32_t, uint32_t>& slots) const;
	protected:
		// 插槽信息
		std::map<uint32_t, uint32_t> _slots;
	};

}
