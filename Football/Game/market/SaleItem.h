#pragma once

#include "../base/Component.h"

#include <vector>

namespace game
{
	class DataTable;
	class ICondition;
	/**
	*	出售物品
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
		// 开始时间
		CREATE_COMPONENT_PROPERTY(uint64_t, StartTime);
		// 结束时间
		CREATE_COMPONENT_PROPERTY(uint64_t, EndTime);
		// 基础售价
		CREATE_COMPONENT_PROPERTY(float, BasePrice);
		// 最大售价
		CREATE_COMPONENT_PROPERTY(float, MaxPrice);

		// 匹配
		virtual bool match(const DataTable* pCondition, std::vector<ICondition*>& pNotMatchSheet)
		{
			return false;
		}
	};
}