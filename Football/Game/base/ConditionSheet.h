#pragma once

#include "PropertySheet.h"
#include "Condition.h"
#include <map>
#include <vector>

namespace game
{
	/**
	*	条件栏
	*/
	class ConditionSheet
	{
	public:
		ConditionSheet();
		virtual ~ConditionSheet();
	public:
		/**
		*	添加条件
		*	@param nConditionID 限制条件类型
		*	@param pCondtion 限制条件
		*/
		void addCondition(int nConditionID, ICondition* pCondtion);
		/**
		*	移除条件
		*	@param nConditionID 限制条件类型
		*/
		void removeCondition(int nConditionID);
		/**
		*	获取条件
		*	@param nConditionID 限制条件类型
		*/
		const ICondition* getCondition(int nConditionID) const;
		/**
		*	清空判断条件
		*/
		void removeAllConditions();
		/**
		*	是否满足条件
		*	@param pSearchSheet 查找条件表
		*	@param pNotMatchSheet 不匹配表
		*/
		bool match(const PropertySheet* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet) const;
	private:
		std::map<int, ICondition*> m_mConditions;
	};
}