#include "Inference.h"
#include "Proposition.h"

using namespace math;

Inference::Inference()
{

}

Inference::~Inference()
{

}

void Inference::addCondition(Proposition* condition)
{
	if (condition == nullptr)
	{
		return;
	}

	_condtions.insert(condition);
}

void Inference::removeCondtion(Proposition* condition)
{
	if (condition == nullptr)
	{
		return;
	}

	_condtions.erase(condition);
}

void Inference::removeAllCondtions()
{
	_condtions.clear();
}

std::set<Proposition*> Inference::getResult()
{
	std::set<Proposition*> result;
	std::set<Proposition*> condtions = _condtions;
	for (auto item : _condtions)
	{
		if (item->getType() == PropositionType::Primary)
		{
			result.insert(item);
		}
		else
		{
			condtions.insert(item);
		}
	}

	do 
	{
		
	} while (true);
}
