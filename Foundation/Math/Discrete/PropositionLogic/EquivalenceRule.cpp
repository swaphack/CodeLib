#include "EquivalenceRule.h"
#include "Proposition.h"
#include "CompoundProposition.h"
#include "EquivalenceSample.h"

#include <cassert>
#include <functional>

using namespace math;


EquivalenceRule::EquivalenceRule()
{

}

EquivalenceRule::~EquivalenceRule()
{
	this->removeAllEquivalenceSamples();
}

std::vector<Proposition*> EquivalenceRule::getEquivalenceProposition(Proposition* proposition)
{
	auto result = getEquivalenceProposition(proposition, std::vector<Proposition*>());

	return result;
}

std::vector<Proposition*> EquivalenceRule::getEquivalenceProposition(Proposition* proposition, const std::vector<Proposition*>& preEquivalencePropositions)
{
	std::vector<Proposition*> result;
	if (proposition == nullptr)
	{
		return result;
	}

	auto vecChildren = proposition->getAllChildren();
	if (vecChildren.size() == 0)
	{
		result.push_back(proposition);
		return result;
	}

	// 基础命题
	if (proposition->is<PrimaryProposition>())
	{
		result.push_back(proposition);
		return result;
	}

	// 非复合命题
	if (!proposition->is<CompoundProposition>())
	{
		return result;
	}

	CompoundProposition* compound = proposition->as<CompoundProposition>();
	// 如果子节点都是基础命题 
	if (compound->isPrimaryPropositionOfAllChildren())
	{
		result.push_back(compound);
		auto temp = getEquivalence(compound);
		if (temp.size() > 0)
		{
			for (auto item : temp)
			{
				bool exits = false;
				for (auto item2 : preEquivalencePropositions)
				{
					if (item2->hasSameLogic(item))
					{
						exits = true;
					}
				}
				if (!exits)
				{
					result.push_back(item);
				}
			}
		}
		return result;
	}

	// 所有子节点的可能性
	std::vector<std::vector<Proposition*> > eachChildProposition;
	// 优先递归子节点
	for (size_t i = 0; i < vecChildren.size(); i++)
	{
		auto child = vecChildren[i];
		std::vector<Proposition*> branch;
		if (child->is<CompoundProposition>())
		{
			auto coumpoundProposition = child->as<CompoundProposition>()->deepClone();
			branch.push_back(coumpoundProposition);

			auto temp = getEquivalenceProposition(coumpoundProposition, branch);
			if (temp.size() != 0)
			{
				for (auto item0 : temp)
				{
					bool bExist = false;
					for (auto item1 : branch)
					{
						if (item0->hasSameLogic(item1))
						{
							bExist = true;
						}
					}
					if (!bExist)
					{
						branch.push_back(item0);
					}
				}
			}
		}
		else if (child->is<PrimaryProposition>())
		{
			branch.push_back(child->as<PrimaryProposition>()->deepClone());
		}
		eachChildProposition.push_back(branch);
	}

	// 对所有结果进行组合
	std::function<void(int32_t)> func;
	int nCount = eachChildProposition.size();
	std::vector<int> vecIndex;

	func = [&](int index){
		if (index == eachChildProposition.size())
		{
			std::vector<TreeNode*> vecChildren;
			int i = 0;
			for (auto item : vecIndex)
			{
				vecChildren.push_back(eachChildProposition[i][item]->deepClone());
				i++;
			}
			CompoundProposition* temp = compound->clone()->as<CompoundProposition>();
			temp->addChildren(vecChildren);	
			result.push_back(temp);
			return;
		}
		for (size_t i = 0; i < eachChildProposition[index].size(); i++)
		{
			if (index == 0)
			{
				vecIndex.clear();				
			}
			vecIndex.push_back(i);
			int j = index + 1;
			func(j);
		}
	};

	func(0);

	return result;
}

std::vector<Proposition*> EquivalenceRule::getEquivalence(CompoundProposition* proposition)
{
	std::vector<Proposition*> vecProposition;

	if (proposition == nullptr)
	{
		return vecProposition;
	}

	vecProposition.push_back(proposition);

	for (auto item : _equivalenceSamples)
	{
		auto result = item->getEquivalenceProposition(proposition);
		if (result != nullptr)
		{
			printf("%s\n", item->toString().c_str());
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
