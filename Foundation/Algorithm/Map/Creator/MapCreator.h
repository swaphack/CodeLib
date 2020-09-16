#pragma once

#include "Map/Base/MapObject.h"
#include "Map/Base/MapObjects.h"

#include "MapSlotRule.h"
#include "MapModule.h"
#include "MapSlot.h"

namespace alg
{
	/**
	*	��ͼ������
	*	
	*	�����module) : ���������Ϣ�� {��ʶ�� ��۱��}
	*	��۹���rule����ÿ����ۿ���ƥ������в����Ϣ
	*/
	class MapCreator : public MapObject
	{
	public:
		MapCreator();
		virtual ~MapCreator();
	public:
		/**
		*	�������
		*/
		MapModule* createModule(const std::map<uint32_t, uint32_t>& slots);
		/**
		*	�Ƴ��������
		*/
		void removeAllModules();
		/**
		*	��ȡ�������
		*/
		virtual uint32_t getModuleCount() const;
		/**
		*	��ȡ���
		*/
		const MapModule* getModule(uint32_t nIndex) const;
	public:
		/**
		*	��Ӳ�۹���
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, ...);
		/**
		*	��Ӳ�۹���
		*/
		template<uint32_t Length>
		int32_t addSlotRule(uint32_t key, uint32_t start, va_list ap);
		/**
		*	�Ƴ����в�۹���
		*/
		void removeAllSlotRules();
		/**
		*	��ȡ��۹�������
		*/
		uint32_t getSlotRuleCount() const;
		/**
		*	��ȡ��۹���
		*/
		bool getSlotRule(uint32_t nSlotIndex, std::vector<uint32_t>& slots) const;
	public:
		/**
		*	����ƥ��ۣ���ȡ��������
		*/
		bool findModule(const MapSlot& conditionSlots, std::vector<uint32_t>& modules);
	protected:
		/**
		*	����ƥ��ۣ���ȡ��������
		*/
		bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules);
	protected:
		// ���
		MapObjects<MapModule> _mapModule;
		// ������ǵ����
		std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
		// ��۹�����ƥ����� {��۱�ţ�ƥ�������}
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