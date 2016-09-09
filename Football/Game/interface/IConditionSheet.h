#pragma once

#include <vector>

namespace game
{
	class ICondition;

	/**
	*	条件栏
	*/
	class IConditionSheet
	{
	public:
		virtual ~IConditionSheet() {}
	public:
		/**
		*	添加条件
		*/
		virtual void addCondition(ICondition* pCondtion) = 0;
		/**
		*	移除条件
		*/
		virtual void removeCondition(int nConditionID) = 0;
		/**
		*	获取条件
		*/
		virtual const ICondition* getCondition(int nConditionID) const = 0;
		/**
		*	清空判断条件
		*/
		virtual void removeAllConditions() = 0;
		/**
		*	是否满足条件
		*	@param vNotMatchConditions 不匹配的条件
		*/
		virtual bool match(float value, std::vector<ICondition*>& vNotMatchConditions) const = 0;
	};
}