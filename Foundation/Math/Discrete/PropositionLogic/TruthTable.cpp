#include "TruthTable.h"
#include "CompoundProposition.h"
#include "PrimaryProposition.h"
#include <cassert>
#include <functional>

using namespace math;


bool TruthTable::testResult(CompoundProposition* proposition, const std::map<uint64_t, bool>& idValue)
{
	assert(proposition != nullptr);

	auto selfIdentify = proposition->getAllUniqueIdentifyChildren();
	for (auto item : selfIdentify)
	{
		auto pp = item->as<PrimaryProposition>();
		auto it = idValue.find(pp->getLogicID());
		if (it != idValue.end())
		{
			pp->setResult(it->second ? PropositionResult::EPR_TRUE : PropositionResult::EPR_FALSE);
		}
		else
		{
			return false;
		}
	}

	return proposition->isTrue();
}

bool TruthTable::isTwoPropositionsEqual(CompoundProposition* a, CompoundProposition* b)
{
	assert(a != nullptr && b != nullptr);

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

	for (auto item : otherIdentify)
	{
		if (selfIdentify.find(item) == selfIdentify.end())
		{
			return false;
		}
	}

	// 真值比较
	std::map<uint64_t, bool> mapTest;
	std::vector<uint64_t> vecId;
	for (auto item : selfIdentify)
	{
		uint64_t id = item->as<Proposition>()->getLogicID();
		vecId.push_back(id);
		mapTest[id] = false;
	}

	int32_t count = selfIdentify.size();
	int32_t index = 0;
	bool ret = true;
	std::function<void(int32_t)> func;
	func = [&](int32_t j){
		if (!ret)
		{
			return;
		}
		if (j == count - 1)
		{
			// 假值
			if (testResult(a, mapTest) != testResult(b, mapTest))
			{
				ret = false;
				return;
			}
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			mapTest[vecId[j]] = i == 0 ? false : true;
			func(j++);
		}
	};

	func(0);

	return ret;
}

bool TruthTable::isTautologyProposition(CompoundProposition* a)
{
	assert(a != nullptr);

	auto selfIdentify = a->getAllUniqueIdentifyChildren();

	// 真值比较
	std::map<uint64_t, bool> mapTest;
	std::vector<uint64_t> vecId;
	for (auto item : selfIdentify)
	{
		uint64_t id = item->as<Proposition>()->getLogicID();
		vecId.push_back(id);
		mapTest[id] = false;
	}
	int32_t count = selfIdentify.size();
	int32_t index = 0;
	bool ret = true;
	std::function<void(int32_t)> func;
	func = [&](int32_t j){
		if (!ret)
		{
			return;
		}
		if (j == count - 1)
		{
			// 假值
			if (!testResult(a, mapTest))
			{
				ret = false;
				return;
			}
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			mapTest[vecId[j]] = i == 0 ? false : true;
			func(j++);
		}
	};

	func(0);

	return ret;
}

bool TruthTable::isContradictoryProposition(CompoundProposition* a)
{
	assert(a != nullptr);

	auto selfIdentify = a->getAllUniqueIdentifyChildren();

	// 真值比较
	std::map<uint64_t, bool> mapTest;
	std::vector<uint64_t> vecId;
	for (auto item : selfIdentify)
	{
		uint64_t id = item->as<Proposition>()->getLogicID();
		vecId.push_back(id);
		mapTest[id] = false;
	}
	int32_t count = selfIdentify.size();
	int32_t index = 0;
	bool ret = true;
	std::function<void(int32_t)> func;
	func = [&](int32_t j){
		if (!ret)
		{
			return;
		}
		if (j == count - 1)
		{
			// 真值
			if (testResult(a, mapTest))
			{
				ret = false;
				return;
			}
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			mapTest[vecId[j]] = i == 0 ? false : true;
			func(j++);
		}
	};

	func(0);
	return ret;
}
