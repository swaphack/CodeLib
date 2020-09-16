#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	// 组件插槽
	class MapSlot : public MapObject
	{
	public:
		MapSlot();
		virtual ~MapSlot();
	public:
		/**
		*	设置插槽
		*/
		void set(const std::map<uint32_t, uint32_t>& slots);
		/**
		*	设置插槽
		*/
		void set(uint32_t tag, uint32_t slotIndex);
		/**
		*	移除插槽
		*/
		void remove(uint32_t tag);
		/**
		*	移除所有插槽
		*/
		void removellAllSlots();
		/**
		*	获取插槽
		*/
		uint32_t get(uint32_t tag) const;
		/**
		*	获取插槽
		*/
		const std::map<uint32_t, uint32_t>& getSlots() const;
	public:
		/**
		*	检查插槽是否匹配
		*/
		bool match(const MapSlot& slot) const;
		/**
		*	检查插槽是否匹配
		*/
		bool match(const std::map<uint32_t, uint32_t>& slots) const;
	protected:
		// 插槽信息
		std::map<uint32_t, uint32_t> _slots;
	};

}
