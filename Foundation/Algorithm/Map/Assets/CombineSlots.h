#pragma once

#include <cstdint>
#include <vector>
#include <map>
#include <set>

namespace alg
{
	namespace map
	{
		/**
		*	组合插槽
		*/
		class CombineSlots
		{
		public:
			CombineSlots();
			virtual ~CombineSlots();
		public:
			/**
			*	设置插槽
			*/
			void addSlot(uint32_t side, uint32_t slotIndex);
			/**
			*	设置插槽
			*/
			void addSlots(uint32_t side, const std::vector<uint32_t>& slotIndices);
			/**
			*	移除插槽
			*/
			void removeSlot(uint32_t side);
			/**
			*	移除插槽
			*/
			void removeSlot(uint32_t side, uint32_t slotIndex);
			/**
			*	移除所有插槽
			*/
			void removellAllSlots();
			/**
			*	获取插槽
			*/
			const std::set<uint32_t>* getSlots(uint32_t side) const;
			/**
			*	获取插槽
			*/
			const std::map<uint32_t, std::set<uint32_t>>& getAllSlots() const;
			/**
			*	是否为空
			*/
			bool empty() const;
		protected:
			// 插槽信息
			std::map<uint32_t, std::set<uint32_t>> _slots;

		};
	}
}