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

std::vector<Proposition*> EquivalenceRule::getEquivalenceProposition(CompoundProposition* proposition)
{
	std::vector<Proposition*> vecProposition;

	if (proposition == nullptr)
	{
		return vecProposition;
	}

	for (auto item : _equivalenceSamples)
	{
		auto result = item->GetEquivalenceProposition(proposition);
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
	this->addEquivalenceSample<EquivalenceRule0>();
	this->addEquivalenceSample<EquivalenceRule1>();
	this->addEquivalenceSample<EquivalenceRule2>();
	this->addEquivalenceSample<EquivalenceRule3>();
	this->addEquivalenceSample<EquivalenceRule4>();
	this->addEquivalenceSample<EquivalenceRule5>();
	this->addEquivalenceSample<EquivalenceRule6>();
	this->addEquivalenceSample<EquivalenceRule7>();
	this->addEquivalenceSample<EquivalenceRule8>();
	this->addEquivalenceSample<EquivalenceRule9>();
	this->addEquivalenceSample<EquivalenceRule10>();
	this->addEquivalenceSample<EquivalenceRule11>();
	this->addEquivalenceSample<EquivalenceRule12>();
	this->addEquivalenceSample<EquivalenceRule13>();
	this->addEquivalenceSample<EquivalenceRule14>();
	this->addEquivalenceSample<EquivalenceRule15>();
	this->addEquivalenceSample<EquivalenceRule16>();
	this->addEquivalenceSample<EquivalenceRule17>();
	this->addEquivalenceSample<EquivalenceRule18>();
	this->addEquivalenceSample<EquivalenceRule19>();
	this->addEquivalenceSample<EquivalenceRule20>();
	this->addEquivalenceSample<EquivalenceRule21>();
	this->addEquivalenceSample<EquivalenceRule22>();
	this->addEquivalenceSample<EquivalenceRule23>();
	this->addEquivalenceSample<EquivalenceRule24>();
	this->addEquivalenceSample<EquivalenceRule25>();
	this->addEquivalenceSample<EquivalenceRule26>();
	this->addEquivalenceSample<EquivalenceRule27>();
	this->addEquivalenceSample<EquivalenceRule28>();
	this->addEquivalenceSample<EquivalenceRule29>();
	this->addEquivalenceSample<EquivalenceRule30>();
	this->addEquivalenceSample<EquivalenceRule31>();
	this->addEquivalenceSample<EquivalenceRule32>();
	this->addEquivalenceSample<EquivalenceRule33>();
	this->addEquivalenceSample<EquivalenceRule34>();

}
