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
	return getEquivalenceProposition(proposition, std::vector<Proposition*>());
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

	// ��������
	if (proposition->is<PrimaryProposition>())
	{
		result.push_back(proposition);
		return result;
	}

	// �Ǹ�������
	if (!proposition->is<CompoundProposition>())
	{
		return result;
	}

	CompoundProposition* compound = proposition->as<CompoundProposition>();
	// ����ӽڵ㶼�ǻ������� 
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

	// �����ӽڵ�Ŀ�����
	std::vector<std::vector<Proposition*> > eachChildProposition;
	// ���ȵݹ��ӽڵ�
	for (auto i = 0; i < vecChildren.size(); i++)
	{
		auto child = vecChildren[i];
		std::vector<Proposition*> branch;
		if (child->is<CompoundProposition>())
		{
			auto coumpoundProposition = child->as<CompoundProposition>();
			branch.push_back(coumpoundProposition);

			auto temp = getEquivalenceProposition(coumpoundProposition, branch);
			if (temp.size() != 0)
			{
				branch.insert(branch.end(), temp.begin(), temp.end());
			}
		}
		else if (child->is<PrimaryProposition>())
		{
			branch.push_back(child->as<PrimaryProposition>());
		}
		eachChildProposition.push_back(branch);
	}

	std::function<void(int32_t)> func;
	int nCount = eachChildProposition.size();
	std::vector<int> vecIndex;
	vecIndex.resize(nCount);

	func = [&](int index){
		if (index = eachChildProposition.size())
		{
			std::vector<TreeNode*> vecChildren;
			int i = 0;
			for (auto item : vecIndex)
			{
				vecChildren.push_back(eachChildProposition[i][item]);
				i++;
			}
			CompoundProposition* temp = compound->clone()->as<CompoundProposition>();
			temp->addChildren(vecChildren);	
			result.push_back(temp);
			return;
		}
		for (int i = 0; i < eachChildProposition[index].size(); i++)
		{
			if (index == 0)
			{
				vecIndex.clear();				
			}
			vecIndex.push_back(i);
			func(index++);
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
