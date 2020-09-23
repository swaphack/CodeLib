#pragma once

#include <cstdint>

#include "MapObject.h"
#include "MapObjects.h"
#include "Module.h"
#include "Slots.h"
#include "CombineSlots.h"

#include "SlotRule.h"

namespace alg
{
	namespace map
	{
		/**
		*	��ͼ��Դ
		*
		*	�����module) : ���������Ϣ�� {��ʶ�� ��۱��}
		*	��۹���rule����ÿ����ۿ���ƥ������в����Ϣ
		*/
		template<typename M, const uint32_t SlotCount, const uint32_t RelationValue>
		class MapAssets : public MapObject
		{
			static_assert(std::is_base_of<Module, M>::value, "M must inherit from Module");
		public:
			MapAssets()
			{
				_mapModule.increaseID();
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
					ptr->getModuleSlot()->setSlots(slots);

					for (auto item : slots)
					{
						_mapModuleTag[item.first].insert(ptr->getMapObjectID());
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
			const std::map<uint32_t, M*>& getAllModules() const
			{
				return _mapModule.getAllObjects();
			}
		public:
			/**
			*	��Ӳ�۹���
			*/
			template<uint32_t Length>
			void addMatchSlot(uint32_t key, uint32_t start, ...)
			{
				va_list ap;
				va_start(ap, start);
				_mapSlotRule.addRelation<Length>(key, start, ap);
				va_end(ap);
			}
			/**
			*	��Ӳ�۹���
			*/
			template<uint32_t Length>
			void addMatchSlot(uint32_t key, uint32_t start, va_list ap)
			{
				_mapSlotRule.addRelation<key, Length>(start, ap);
			}
			/**
			*	�Ƴ����в�۹���
			*/
			void removeAllSlotRules()
			{
				_mapSlotRule.initRelationTable();
			}

			/**
			*	��ȡ��۹���
			*/
			bool getMatchSlots(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const
			{
				return _mapSlotRule.getRelations(slotIndex, relativeSlots);
			}
			/**
			*	��ȡ���в�۹���
			*/
			const SlotRule<SlotCount, RelationValue>& getSlotRule() const
			{
				return _mapSlotRule;
			}

			/**
			*	�ж������Ƿ��й���
			*/
			bool hasRelation(uint32_t src, uint32_t dest)
			{
				return _mapSlotRule.hasRelation(src, dest);
			}
		public:
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const Slots& conditionSlots, std::vector<uint32_t>& modules)
			{
				return findModule(conditionSlots.getAllSlots(), modules);
			}
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const CombineSlots& conditionSlots, std::vector<uint32_t>& modules)
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
				for (const auto& item : conditionSlots)
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
				for (const auto& item : setData)
				{
					auto pModule = getModule(item);
					if (pModule->getModuleSlot()->matchSlots(conditionSlots))
					{
						modules.push_back(item);
					}
				}

				return modules.size() > 0;
			}
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const std::map<uint32_t, std::set<uint32_t>>& conditionSlots, std::vector<uint32_t>& modules)
			{
				int32_t target = -1;
				int32_t count = -1;

				// ��ѯ��������С����
				for (const auto& item : conditionSlots)
				{
					auto it = _mapModuleTag.find(item.first);
					if (it == _mapModuleTag.end() || it->second.size() == 0)
					{// �����ƥ�����
						return false;
					}

					if (target == -1 || count > it->second.size())
					{
						target = item.first;
						count = it->second.size();
					}
				}

				if (target == -1)
				{
					return false;
				}

				// ��ѯƥ���ģ��
				auto setData = _mapModuleTag[target];
				for (const auto& item : setData)
				{
					auto pModule = getModule(item);
					if (pModule->getModuleSlot()->matchSlots(conditionSlots))
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
			SlotRule<SlotCount, RelationValue> _mapSlotRule;
		};

	}
}