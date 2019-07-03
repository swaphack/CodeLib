#include "TransferMarket.h"

#include "../base/DataTable.h"
#include "../base/ConditionSheet.h"

using namespace game;

TransferMarket::TransferMarket()
{

}

TransferMarket::~TransferMarket()
{
	this->clear();
}

bool TransferMarket::findSaleItem(const DataTable* pCondition, std::vector<uint64_t>& targets)
{
	if (pCondition == nullptr)
	{
		return false;
	}

	this->foreach([&targets, &pCondition](uint64_t key, SaleItem* value){
		std::vector<ICondition*> pNotMatchSheet;
		if (value->match(pCondition, pNotMatchSheet))
		{
			targets.push_back(key);
		}
	});

	return !targets.empty();
}