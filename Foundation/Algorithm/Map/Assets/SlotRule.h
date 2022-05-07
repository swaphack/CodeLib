#pragma once

#include "Map/Base/RelationTable.h"

namespace alg
{
	namespace map
	{
		/**
		*	插槽规则 二维方阵
		*/
		class SlotRule
		{
		public:
			SlotRule();
			SlotRule(int count);
			virtual ~SlotRule();
		public:
			/**
			*	初始化
			*/
			void init(int count);
			/**
			*	添加插槽规则
			*/
			void addRelation(uint32_t key, const std::vector<uint32_t>& targets, uint8_t value);
			/**
			*	获取关联
			*/
			bool getRelations(uint32_t key, uint8_t value, std::vector<uint32_t>& relations) const;

			/**
			*	判断两者是否有关联
			*/
			bool hasRelation(uint32_t src, uint32_t dest, uint8_t value) const;
			/**
			*	重置所有关系
			*/
			void resetAllRelations(uint8_t value);
		private:
			// 关系表
			RelationTable _table;
		};
	}
}