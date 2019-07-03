#include "ConditionSheet.h"

#include "Condition.h"
#include "DataTable.h"

using namespace game;

ConditionSheet::ConditionSheet()
{

}

ConditionSheet::~ConditionSheet()
{
}



bool ConditionSheet::match(const DataTable* pSearchSheet, std::vector<ICondition*>& pNotMatchSheet)
{
	if (pSearchSheet == nullptr)
	{
		return false;
	}

	pNotMatchSheet.clear();
	bool bRet = true;

	this->foreach([&bRet, &pNotMatchSheet, &pSearchSheet](uint64_t key, ICondition* value){
		DataRecord** pCondition = ((DataTable*)pSearchSheet)->find(key);
		if (pCondition && (*pCondition))
		{
			if (!value->match((*pCondition)->getValue()))
			{
				bRet = false;
				pNotMatchSheet.push_back((ICondition*)value);
			}
		}
	});
	return bRet;
}

void ConditionSheet::destoryValue(ICondition* value)
{
	if (value)
	{
		delete value;
	}
}

