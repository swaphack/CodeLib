#pragma once

#include <map>
#include <cstdint>
#include <vector>
#include "SaleItem.h"
#include "../base/Dictionary.h"

namespace game
{
	class DataTable;

	/**
	*	转会市场
	*/
	class TransferMarket : public Dictionary<uint64_t, SaleItem*>
	{
	public:
		TransferMarket();
		virtual ~TransferMarket();
	public:
		/**
		*	超找符合条件的人员
		*	@param pCondition 搜索条件
		*	@param targets 搜索结果
		*/
		bool findSaleItem(const DataTable* pCondition, std::vector<uint64_t>& targets);
	};
}