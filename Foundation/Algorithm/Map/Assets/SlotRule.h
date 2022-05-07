#pragma once

#include "Map/Base/RelationTable.h"

namespace alg
{
	namespace map
	{
		/**
		*	��۹��� ��ά����
		*/
		class SlotRule
		{
		public:
			SlotRule();
			SlotRule(int count);
			virtual ~SlotRule();
		public:
			/**
			*	��ʼ��
			*/
			void init(int count);
			/**
			*	��Ӳ�۹���
			*/
			void addRelation(uint32_t key, const std::vector<uint32_t>& targets, uint8_t value);
			/**
			*	��ȡ����
			*/
			bool getRelations(uint32_t key, uint8_t value, std::vector<uint32_t>& relations) const;

			/**
			*	�ж������Ƿ��й���
			*/
			bool hasRelation(uint32_t src, uint32_t dest, uint8_t value) const;
			/**
			*	�������й�ϵ
			*/
			void resetAllRelations(uint8_t value);
		private:
			// ��ϵ��
			RelationTable _table;
		};
	}
}