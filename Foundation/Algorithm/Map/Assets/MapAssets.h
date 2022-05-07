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
		*	��ͼ��Դ
		*
		*	�����module) : ���������Ϣ�� {��ʶ�� ��۱��}
		*	��۹���rule����ÿ����ۿ���ƥ������в����Ϣ
		*/
		class MapAssets : public MapObject
		{
		public:
			MapAssets(int nSlotCount, IMapObjectCreate* moduleCreate);
			virtual ~MapAssets();
		public:
			/**
			*	����ģ��
			*/
			Module* createModule(uint32_t resID, const std::map<uint32_t, uint32_t>& slots);
			/**
			*	�Ƴ�����ģ��
			*/
			void removeAllModules();
			/**
			*	��ȡģ������
			*/
			virtual uint32_t getModuleCount() const;
			/**
			*	��ȡģ��
			*/
			const Module* getModule(uint32_t nIndex) const;
			/**
			*	��ȡ���в�ģ��
			*/
			std::map<uint32_t, Module*> getAllModules() const;
		public:
			/**
			*	��Ӳ�۹���
			*/
			void addMatchRule(uint32_t key, int length, uint32_t start, ...);
			/**
			*	��ӹ���
			*/
			void addMatchRule(uint32_t key, uint32_t nLength, uint32_t startIndex, va_list ap);
			/**
			*	��Ӳ�۹���
			*/
			void addMatchRule(uint32_t key, const std::vector<uint32_t>& targets);
			/**
			*	�Ƴ����в�۹���
			*/
			void removeAllMatchRules();

			/**
			*	��ȡ��۹���
			*/
			bool getMatchSlots(uint32_t slotIndex, std::vector<uint32_t>& relativeSlots) const;
			/**
			*	��ȡ���в�۹���
			*/
			const SlotRule& getSlotRule() const;

			/**
			*	�ж������Ƿ��й���
			*/
			bool hasRelation(uint32_t src, uint32_t dest, int value = 1);
		public:
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const Slots& conditionSlots, std::vector<uint32_t>& modules);
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const CombineSlots& conditionSlots, std::vector<uint32_t>& modules);
		protected:
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const std::map<uint32_t, uint32_t>& conditionSlots, std::vector<uint32_t>& modules);
			/**
			*	����ƥ��ۣ���ȡ�����ģ��
			*/
			bool findModule(const std::map<uint32_t, std::set<uint32_t>>& conditionSlots, std::vector<uint32_t>& modules);
		protected:
			// ģ��
			MapObjects _mapModule;
			// ������ǵ�ģ��
			std::map<uint32_t, std::set<uint32_t>> _mapModuleTag;
			// ��۹�����ƥ����� {��۱�ţ�ƥ�������};0-�޹�ϵ��1-�й�ϵ
			SlotRule _mapSlotRule;
		};

	}
}