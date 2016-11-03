#pragma once

#include <vector>

namespace game
{
	class ICondition;
	class PropertySheet;

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
		*	@param nConditionID ������������
		*	@param pCondtion ��������
		*/
		virtual void addCondition(int nConditionID, ICondition* pCondtion) = 0;
		/**
		*	�Ƴ�����
		*	@param nConditionID ������������
		*/
		virtual void removeCondition(int nConditionID) = 0;
		/**
		*	��ȡ����
		*	@param nConditionID ������������
		*/
		virtual const ICondition* getCondition(int nConditionID) const = 0;
		/**
		*	����ж�����
		*/
		virtual void removeAllConditions() = 0;
		/**
		*	�Ƿ���������
		*	@param pSearchSheet ����������
		*	@param pNotMatchSheet ��ƥ���
		*/
		virtual bool match(const PropertySheet* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet) const = 0;
	};
}