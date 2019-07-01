#include "TransferMarket.h"

#include "../base/DataTable.h"
#include "../base/ConditionSheet.h"

using namespace game;

TransferMarket::SaleItem::SaleItem()
{

}

TransferMarket::SaleItem::~SaleItem()
{
	if (Condition)
	{
		delete Condition;
	}
}
//////////////////////////////////////////////////////////////////////////
TransferMarket::TransferMarket()
{

}

TransferMarket::~TransferMarket()
{
	this->clear();
}

bool TransferMarket::onSale(uint64_t nPersonID, ConditionSheet* pCondition, uint64_t nClubID)
{
	if (pCondition == nullptr)
	{
		return false;
	}

	if (m_mOnSalePerson.find(nPersonID) != m_mOnSalePerson.end())
	{
		return false;
	}

	SaleItem* pSale = new SaleItem();
	pSale->PersonID = nPersonID;
	pSale->Condition = pCondition;
	pSale->ClubID = nClubID;

	m_mOnSalePerson.insert(std::make_pair(nPersonID, pSale));

	return true;
}

bool TransferMarket::offShelf(uint64_t nPersonID)
{
	if (m_mOnSalePerson.find(nPersonID) == m_mOnSalePerson.end())
	{
		return false;
	}

	SaleItem* pSale = m_mOnSalePerson[nPersonID];
	delete pSale;
	m_mOnSalePerson.erase(nPersonID);

	return true;
}

bool TransferMarket::findPerson(const DataTable* pCondition, std::vector<uint64_t>& targets) const
{
	if (pCondition == nullptr)
	{
		return false;
	}

	auto iter = m_mOnSalePerson.begin();
	std::vector<ICondition*> pNotMatchSheet;
	while (iter != m_mOnSalePerson.end())
	{
		if (iter->second->Condition->match(pCondition, pNotMatchSheet))
		{
			targets.push_back(iter->first);
		}
		iter++;
	}

	return !targets.empty();
}

void TransferMarket::clear()
{
	auto iter = m_mOnSalePerson.begin();

	while (iter != m_mOnSalePerson.end())
	{
		delete iter->second;
		iter++;
	}

	m_mOnSalePerson.clear();
}
