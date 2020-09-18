#pragma once

#include "MapObject.h"
#include "MapObjects.h"
#include "MapModule.h"
#include "ModuleSlots.h"

#include "SlotRule.h"

namespace alg
{
	/**
	*	��ͼ��Դ
	*	
	*	�����module) : ���������Ϣ�� {��ʶ�� ��۱��}
	*	��۹���rule����ÿ����ۿ���ƥ������в����Ϣ
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
		*	����ģ��
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
		*	�Ƴ�����ģ��
		*/
		void removeAllModules()
		{
			_mapModule.removeAllObjects();
		}
		/**
		*	��ȡģ������
		*/
		virtual uint32_t getModuleCount() const
		{
			return _mapModule.getObjectCount();
		}
		/**
		*	��ȡģ��
		*/
		const M* getModule(uint32_t nIndex) const
		{
			return _mapModule.getObject(nIndex);
		}
		/**
		*	��ȡ���в�ģ��
		*/
		const std::map <uint32_t, M*>& getAllModules() const
		{
			return _mapModule.getAllObjects();
		}
	public:
		/**
		*	��Ӳ�۹���
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
		*	��Ӳ�۹���
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
		*	�Ƴ����в�۹���
		*/
		void removeAllSlotRules()
		{
			_mapSlotRule.clear();
		}
		/**
		*	��ȡ��۹�������
		*/
		uint32_t getSlotRuleCount() const
		{
			return _mapSlotRule.size();
		}
		/**
		*	��ȡ��۹���
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
		*	��ȡ���в�۹���
		*/
		const std::map <uint32_t, SlotRule>& getAllSlotRules() const
		{
			return _mapSlotRule;
		}
	public:
		/**
		*	����ƥ��ۣ���ȡ�����ģ��
		*/
		bool findModule(const ModuleSlots& conditionSlots, std::vector<uint32_t>& modules)
		{
			return findModule(conditionSlots.getAllSlots(), modules);
		}
	protected:
		/**
		*	����ƥ��ۣ���ȡ�����ģ��
		*/
		bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules)
		{
			uint32_t target = 0;
			uint32_t count = 0;

			// ��ѯ��������С����
			for (auto item : conditionSlots)
			{
				auto it = _mapModuleTag.find(item.first);
				if (it == _mapModuleTag.end() || it->second.size() == 0)
				{// �����ƥ�����
					return false;
				}

				if (target == 0 || count > it->second.size())
				{
					target = item.first;
					count = it->second.size();
				}
			}

			// ��ѯƥ���ģ��
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
		// ģ��
		MapObjects<M> _mapModule;
		// ������ǵ�ģ��
		std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
		// ��۹�����ƥ����� {��۱�ţ�ƥ�������}
		std::map <uint32_t, SlotRule> _mapSlotRule;
	};

}