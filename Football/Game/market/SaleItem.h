#pragma once

#include "../base/Component.h"

#include <vector>

namespace game
{
	class DataTable;
	class ICondition;
	/**
	*	������Ʒ
	*/
	class SaleItem : public Component
	{
	public:
		SaleItem();
		virtual ~SaleItem();
	public:
		CREATE_COMPONENT_TYPE();
		CREATE_COMPONENT_CLONE(SaleItem);
	public:
		// ��ʼʱ��
		CREATE_COMPONENT_PROPERTY(uint64_t, StartTime);
		// ����ʱ��
		CREATE_COMPONENT_PROPERTY(uint64_t, EndTime);
		// �����ۼ�
		CREATE_COMPONENT_PROPERTY(float, BasePrice);
		// ����ۼ�
		CREATE_COMPONENT_PROPERTY(float, MaxPrice);

		// ƥ��
		virtual bool match(const DataTable* pCondition, std::vector<ICondition*>& pNotMatchSheet)
		{
			return false;
		}
	};
}