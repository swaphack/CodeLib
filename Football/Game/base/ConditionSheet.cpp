#include "ConditionSheet.h"

#include "Condition.h"
#include "PropertySheet.h"

using namespace game;

ConditionSheet::ConditionSheet()
{

}

ConditionSheet::~ConditionSheet()
{
	this->removeAllConditions();
}

void ConditionSheet::addCondition(int nConditionID, ICondition* pCondtion)
{
	if (pCondtion == nullptr)
	{
		return;
	}

	if (getCondition(nConditionID))
	{
		return;
	}

	m_mConditions[nConditionID] = pCondtion;
}

void ConditionSheet::removeCondition(int nConditionID)
{
	if (!getCondition(nConditionID))
	{
		return;
	}

	m_mConditions.erase(nConditionID);
}

const ICondition* ConditionSheet::getCondition(int nConditionID) const
{
	std::map<int, ICondition*>::const_iterator iter = m_mConditions.find(nConditionID);
	if (iter == m_mConditions.end())
	{
		return nullptr;
	}

	return iter->second;
}

void ConditionSheet::removeAllConditions()
{
	std::map<int, ICondition*>::const_iterator iter = m_mConditions.begin();
	while (iter != m_mConditions.end())
	{
		delete iter->second;
		iter++;
	}

	m_mConditions.clear();
}

bool ConditionSheet::match(const PropertySheet* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet) const
{
	if (pSearchSheet == nullptr)
	{
		return false;
	}

	pNotMatchSheet.clear();

	Property* pCondition;
	bool bRet = true;
	std::map<int, ICondition*>::const_iterator iter = m_mConditions.begin();
	while (iter != m_mConditions.end())
	{
		pCondition = ((PropertySheet*)pSearchSheet)->getProperty(iter->first);
		if (pCondition)
		{
			if (!iter->second->match(pCondition->getValue()))
			{
				bRet = false;
				pNotMatchSheet.push_back(iter->second);
			}
		}
		iter++;
	}

	return bRet;
}

