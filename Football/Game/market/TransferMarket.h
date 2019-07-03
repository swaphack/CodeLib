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
	*	ת���г�
	*/
	class TransferMarket : public Dictionary<uint64_t, SaleItem*>
	{
	public:
		TransferMarket();
		virtual ~TransferMarket();
	public:
		/**
		*	���ҷ�����������Ա
		*	@param pCondition ��������
		*	@param targets �������
		*/
		bool findSaleItem(const DataTable* pCondition, std::vector<uint64_t>& targets);
	};
}