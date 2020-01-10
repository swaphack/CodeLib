#include "TruthTable.h"
#include "CompoundProposition.h"
#include "PrimaryProposition.h"
#include <cassert>

using namespace math;


bool TruthTable::getResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue)
{
	assert(proposition != nullptr);

	auto selfIdentify = proposition->getAllUniqueIdentifyChildren();
	for (auto item : selfIdentify)
	{
		auto pp = item->get<PrimaryProposition>();
		auto it = idValue.find(pp->getIdentify());
		assert(it != idValue.end());
		pp->setResult(it->second ? PropositionResult::TRUE : PropositionResult::FALSE);
	}

	return proposition->isTrue();
}

bool TruthTable::isTowPropositionEqual(CompoundProposition* a, CompoundProposition* b)
{
	auto selfIdentify = a->getAllUniqueIdentifyChildren();
	auto otherIdentify = b->getAllUniqueIdentifyChildren();

	if (selfIdentify.size() != otherIdentify.size())
	{
		return false;
	}

	for (auto item : selfIdentify)
	{
		if (otherIdentify.find(item) == otherIdentify.end())
		{
			return false;
		}
	}

	// 真值比较
	std::map<uint64_t, bool> mapTest;
	std::vector<uint64_t> vecId;
	for (auto item : selfIdentify)
	{
		uint64_t id = item->get<Proposition>()->getIdentify();
		vecId.push_back(id);
		mapTest[id] = false;
	}
	for (int i = 0; i < selfIdentify.size(); i++)
	{
		if (getResult(a, mapTest) != getResult(b, mapTest))
		{
			return false;
		}
		mapTest[vecId[i]] = true;
		if (getResult(a, mapTest) != getResult(b, mapTest))
		{
			return false;
		}
	}

	return true;
}
