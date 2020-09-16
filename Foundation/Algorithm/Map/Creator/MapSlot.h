#pragma once

#include "Map/Base/MapObject.h"

namespace alg
{
	// ������
	class MapSlot : public MapObject
	{
	public:
		MapSlot();
		virtual ~MapSlot();
	public:
		/**
		*	���ò��
		*/
		void set(const std::map<uint32_t, uint32_t>& slots);
		/**
		*	���ò��
		*/
		void set(uint32_t tag, uint32_t slotIndex);
		/**
		*	�Ƴ����
		*/
		void remove(uint32_t tag);
		/**
		*	�Ƴ����в��
		*/
		void removellAllSlots();
		/**
		*	��ȡ���
		*/
		uint32_t get(uint32_t tag) const;
		/**
		*	��ȡ���
		*/
		const std::map<uint32_t, uint32_t>& getSlots() const;
	public:
		/**
		*	������Ƿ�ƥ��
		*/
		bool match(const MapSlot& slot) const;
		/**
		*	������Ƿ�ƥ��
		*/
		bool match(const std::map<uint32_t, uint32_t>& slots) const;
	protected:
		// �����Ϣ
		std::map<uint32_t, uint32_t> _slots;
	};

}
