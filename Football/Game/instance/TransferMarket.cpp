#include "TransferMarket.h"

#include "PropertySheet.h"
#include "ConditionSheet.h"

using namespace game;

TransferMarket::TransferMarket()
{

}

TransferMarket::~TransferMarket()
{
	this->clear();
}

bool TransferMarket::onSale(int nPersonID, ConditionSheet* pCondition, int nClubID)
{
	if (pCondition == nullptr)
	{
		return false;
	}

	if (m_mOnSalePerson.find(nPersonID) != m_mOnSalePerson.end())
	{
		return false;
	}

	PersonSale* pSale = new PersonSale();
	pSale->PersonID = nPersonID;
	pSale->Condition = pCondition;
	pSale->ClubID = nClubID;

	m_mOnSalePerson.insert(std::make_pair(nPersonID, pSale));

	return true;
}

bool TransferMarket::offShelf(int nPersonID)
{
	if (m_mOnSalePerson.find(nPersonID) == m_mOnSalePerson.end())
	{
		return false;
	}

	PersonSale* pSale = m_mOnSalePerson[nPersonID];
	delete pSale;
	m_mOnSalePerson.erase(nPersonID);

	return true;
}

bool TransferMarket::findPerson(const PropertySheet* pCondition, std::vector<int>& targets) const
{
	if (pCondition == nullptr)
	{
		return false;
	}

	std::map<int, PersonSale*>::const_iterator iter = m_mOnSalePerson.begin();
	std::vector<ICondition*> pNotMatchSheet;
	while (iter != m_mOnSalePerson.end())
	{
		if (iter->second->Condition->match(pCondition, pNotMatchSheet))
		{
			targets.push_back(iter->first);
		}
		iter++;
	}

	return true;
}

void TransferMarket::clear()
{
	std::map<int, PersonSale*>::iterator iter = m_mOnSalePerson.begin();

	while (iter != m_mOnSalePerson.end())
	{
		delete iter->second;
		iter++;
	}

	m_mOnSalePerson.clear();
}
