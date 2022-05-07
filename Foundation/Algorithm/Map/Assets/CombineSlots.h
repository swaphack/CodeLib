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
		*	��ϲ��
		*/
		class CombineSlots
		{
		public:
			CombineSlots();
			virtual ~CombineSlots();
		public:
			/**
			*	���ò��
			*/
			void addSlot(uint32_t side, uint32_t slotIndex);
			/**
			*	���ò��
			*/
			void addSlots(uint32_t side, const std::vector<uint32_t>& slotIndices);
			/**
			*	�Ƴ����
			*/
			void removeSlot(uint32_t side);
			/**
			*	�Ƴ����
			*/
			void removeSlot(uint32_t side, uint32_t slotIndex);
			/**
			*	�Ƴ����в��
			*/
			void removellAllSlots();
			/**
			*	��ȡ���
			*/
			const std::set<uint32_t>* getSlots(uint32_t side) const;
			/**
			*	��ȡ���
			*/
			const std::map<uint32_t, std::set<uint32_t>>& getAllSlots() const;
			/**
			*	�Ƿ�Ϊ��
			*/
			bool empty() const;
		protected:
			// �����Ϣ
			std::map<uint32_t, std::set<uint32_t>> _slots;

		};
	}
}