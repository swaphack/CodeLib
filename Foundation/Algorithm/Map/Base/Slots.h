#pragma once

#include "Map/Base/MapObject.h"
#include <set>


namespace alg
{
	namespace map
	{
		/*
		*	������
		*	ÿ���������������
		*	ÿ����۶���һ��ָ������״��ֻ�и�������ƥ��Ĳ�ۣ�����������һ��
		*	��۱��Ĭ�ϴ�1��ʼ��1��ʶ��
		*/
		class Slots : public MapObject
		{
		public:
			Slots();
			virtual ~Slots();
		public:
			/**
			*	���ò��
			*/
			void setSlots(const std::map<uint32_t, uint32_t>& slots);
			/**
			*	���ò��
			*/
			void addSlot(uint32_t side, uint32_t slotIndex);
			/**
			*	�Ƴ����
			*/
			void removeSlot(uint32_t side);
			/**
			*	�Ƴ����в��
			*/
			void removellAllSlots();
			/**
			*	��ȡ���
			*/
			uint32_t getSlot(uint32_t tag) const;
			/**
			*	��ȡ���
			*/
			const std::map<uint32_t, uint32_t>& getAllSlots() const;
		public:
			/**
			*	������Ƿ�ƥ��
			*/
			bool matchModuleSlots(const Slots& slot) const;
			/**
			*	������Ƿ�ƥ��
			*/
			bool matchSlots(const std::map<uint32_t, uint32_t>& slots) const;
			/**
			*	������Ƿ�ƥ��
			*/
			bool matchSlots(const std::map<uint32_t, std::set<uint32_t>>& slots) const;
		protected:
			// �����Ϣ
			std::map<uint32_t, uint32_t> _slots;
		};

	}
}