#pragma once

#include "PropertySheet.h"
#include "Condition.h"
#include <map>
#include <vector>

namespace game
{
	/**
	*	������
	*/
	class ConditionSheet
	{
	public:
		ConditionSheet();
		virtual ~ConditionSheet();
	public:
		/**
		*	�������
		*	@param nConditionID ������������
		*	@param pCondtion ��������
		*/
		virtual void addCondition(int nConditionID, ICondition* pCondtion);
		/**
		*	�Ƴ�����
		*	@param nConditionID ������������
		*/
		virtual void removeCondition(int nConditionID);
		/**
		*	��ȡ����
		*	@param nConditionID ������������
		*/
		virtual const ICondition* getCondition(int nConditionID) const;
		/**
		*	����ж�����
		*/
		virtual void removeAllConditions();
		/**
		*	�Ƿ���������
		*	@param pSearchSheet ����������
		*	@param pNotMatchSheet ��ƥ���
		*/
		virtual bool match(const PropertySheet* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet) const;
	private:
		std::map<int, ICondition*> m_mConditions;
	};
}