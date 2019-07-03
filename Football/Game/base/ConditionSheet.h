#pragma once

#include <map>
#include <vector>
#include "../base/Dictionary.h"

namespace game
{
	class DataTable;
	class ICondition;
	/**
	*	条件栏
	*/
	class ConditionSheet : public Dictionary<uint64_t, ICondition*>
	{
	public:
		ConditionSheet();
		virtual ~ConditionSheet();
	public:
		/**
		*	是否满足条件
		*	@param pSearchSheet 查找条件表
		*	@param pNotMatchSheet 不匹配表
		*/
		bool match(const DataTable* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet);
	protected:
		/**
		*	清除值
		*/
		virtual void destoryValue(ICondition* value);
	};
}