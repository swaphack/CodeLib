#include "EquivalenceRule.h"
#include "Proposition.h"
#include "CompoundProposition.h"
#include "EquivalenceSample.h"

#include <cassert>

using namespace math;


EquivalenceRule::EquivalenceRule()
{

}

EquivalenceRule::~EquivalenceRule()
{
	this->removeAllEquivalenceSamples();
}

Proposition* EquivalenceRule::getEquivalenceProposition(CompoundProposition* proposition)
{
	if (proposition == nullptr)
	{
		return nullptr;
	}

	auto vecChildren = proposition->getAllChildren();
	if (vecChildren.size() == 0)
	{
		return proposition;
	}

	// 优先递归子节点
	for (auto i = 0; i < vecChildren.size(); i++)
	{
		auto child = vecChildren[i];
		if (child->is<CompoundProposition>())
		{
			Proposition* ret = getEquivalenceProposition(child->as<CompoundProposition>());
			if (ret != nullptr)
			{
				vecChildren[i] = ret;
			}
		}
	}

	// 计算等价式
	std::vector<Proposition*> vecResult = getEquivalence(proposition);
	if (vecResult.size() == 0)
	{
		return proposition;
	}

	// 取第一个，如果可以转换的话，继续转换，否者返回第一个值
	auto firstResult = vecResult[0];
	if (firstResult->is<CompoundProposition>())
	{
		return getEquivalenceProposition(firstResult->as<CompoundProposition>());
	}

	return firstResult->as<Proposition>();
}

std::vector<Proposition*> EquivalenceRule::getEquivalence(CompoundProposition* proposition)
{
	std::vector<Proposition*> vecProposition;

	if (proposition == nullptr)
	{
		return vecProposition;
	}

	for (auto item : _equivalenceSamples)
	{
		auto result = item->getEquivalenceProposition(proposition);
		if (result != nullptr)
		{
			vecProposition.push_back(result);
		}
	}

	return vecProposition;
}

void EquivalenceRule::addEquivalenceSample(EquivalenceSample* sample)
{
	if (sample == nullptr)
	{
		return;
	}

	auto it = _equivalenceSamples.find(sample);

	assert(it == _equivalenceSamples.end());

	_equivalenceSamples.insert(sample);
}

void EquivalenceRule::removeEquivalenceSample(EquivalenceSample* sample)
{
	if (sample == nullptr)
	{
		return;
	}

	auto it = _equivalenceSamples.find(sample);
	if (it == _equivalenceSamples.end())
	{
		return;
	}

	delete (*it);

	_equivalenceSamples.erase(it);
}

void EquivalenceRule::removeAllEquivalenceSamples()
{
	for (auto item : _equivalenceSamples)
	{
		delete item;
	}

	_equivalenceSamples.clear();
}

void EquivalenceRule::init()
{
	this->addEquivalenceSample<EquivalenceSample0>();
	this->addEquivalenceSample<EquivalenceSample1>();
	this->addEquivalenceSample<EquivalenceSample2>();
	this->addEquivalenceSample<EquivalenceSample3>();
	this->addEquivalenceSample<EquivalenceSample4>();
	this->addEquivalenceSample<EquivalenceSample5>();
	this->addEquivalenceSample<EquivalenceSample6>();
	this->addEquivalenceSample<EquivalenceSample7>();
	this->addEquivalenceSample<EquivalenceSample8>();
	this->addEquivalenceSample<EquivalenceSample9>();
	this->addEquivalenceSample<EquivalenceSample10>();
	this->addEquivalenceSample<EquivalenceSample11>();
	this->addEquivalenceSample<EquivalenceSample12>();
	this->addEquivalenceSample<EquivalenceSample13>();
	this->addEquivalenceSample<EquivalenceSample14>();
	this->addEquivalenceSample<EquivalenceSample15>();
	this->addEquivalenceSample<EquivalenceSample16>();
	this->addEquivalenceSample<EquivalenceSample17>();
	this->addEquivalenceSample<EquivalenceSample18>();
	this->addEquivalenceSample<EquivalenceSample19>();
	this->addEquivalenceSample<EquivalenceSample20>();
	this->addEquivalenceSample<EquivalenceSample21>();
	this->addEquivalenceSample<EquivalenceSample22>();
	this->addEquivalenceSample<EquivalenceSample23>();
	this->addEquivalenceSample<EquivalenceSample24>();
	this->addEquivalenceSample<EquivalenceSample25>();
	this->addEquivalenceSample<EquivalenceSample26>();
	this->addEquivalenceSample<EquivalenceSample27>();
	this->addEquivalenceSample<EquivalenceSample28>();
	this->addEquivalenceSample<EquivalenceSample29>();
	this->addEquivalenceSample<EquivalenceSample30>();
	this->addEquivalenceSample<EquivalenceSample31>();
	this->addEquivalenceSample<EquivalenceSample32>();
	this->addEquivalenceSample<EquivalenceSample33>();
	this->addEquivalenceSample<EquivalenceSample34>();

}
