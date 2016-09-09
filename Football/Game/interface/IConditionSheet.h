#pragma once

#include <vector>

namespace game
{
	class ICondition;

	/**
	*	������
	*/
	class IConditionSheet
	{
	public:
		virtual ~IConditionSheet() {}
	public:
		/**
		*	�������
		*/
		virtual void addCondition(ICondition* pCondtion) = 0;
		/**
		*	�Ƴ�����
		*/
		virtual void removeCondition(int nConditionID) = 0;
		/**
		*	��ȡ����
		*/
		virtual const ICondition* getCondition(int nConditionID) const = 0;
		/**
		*	����ж�����
		*/
		virtual void removeAllConditions() = 0;
		/**
		*	�Ƿ���������
		*	@param vNotMatchConditions ��ƥ�������
		*/
		virtual bool match(float value, std::vector<ICondition*>& vNotMatchConditions) const = 0;
	};
}