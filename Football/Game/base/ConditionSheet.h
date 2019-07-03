#pragma once

#include <map>
#include <vector>
#include "../base/Dictionary.h"

namespace game
{
	class DataTable;
	class ICondition;
	/**
	*	������
	*/
	class ConditionSheet : public Dictionary<uint64_t, ICondition*>
	{
	public:
		ConditionSheet();
		virtual ~ConditionSheet();
	public:
		/**
		*	�Ƿ���������
		*	@param pSearchSheet ����������
		*	@param pNotMatchSheet ��ƥ���
		*/
		bool match(const DataTable* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet);
	protected:
		/**
		*	���ֵ
		*/
		virtual void destoryValue(ICondition* value);
	};
}