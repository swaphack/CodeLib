#include "CompoundProposition.h"
#include "PrimaryProposition.h"

using namespace math;

CompoundProposition::CompoundProposition()
{
	this->_children.resize(2);
	this->setType(PropositionType::Compound);
}

CompoundProposition::CompoundProposition(const CompoundProposition& value)
	:CompoundProposition()
{
	*this = value;
}

CompoundProposition::~CompoundProposition()
{

}

bool CompoundProposition::hasSameLogic(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}

	if (!proposition->is<CompoundProposition>())
	{
		return false;
	}

	if (!Proposition::hasSameLogic(proposition))
	{
		return false;
	}

	return matchChildren(proposition->getAllChildren());
}

std::set<TreeNode*> CompoundProposition::getAllUniqueIdentifyChildren()
{
	std::set<TreeNode*> result;

	std::vector<TreeNode*> vecLeaf = this->getAllLeafChildren();
	if (vecLeaf.size() == 0)
	{
		return result;
	}

	for (auto item : vecLeaf)
	{
		auto proposition = item->as<Proposition>();
		if (proposition && proposition->getLogicID() != 0)
		{
			result.insert(item);
		}
	}

	return result;
}

bool CompoundProposition::matchChildren(const std::vector<TreeNode*>& children)
{
	if (getChildrenCount() != children.size())
	{
		return false;
	}
	for (auto i = 0; i < children.size(); i++)
	{
		Proposition* p0 = getChildAt(i)->as<Proposition>();
		Proposition* p1 = children[i]->as<Proposition>();
		if (p0 == nullptr || p1 == nullptr)
		{
			return false;
		}
		if (!p0->hasSameLogic(p1))
		{
			return false;
		}
	}
	return true;
}

CompoundProposition& CompoundProposition::operator=(const CompoundProposition& value)
{
	Proposition::operator=(value);
	this->setLogicID(value.getLogicID());
	this->removeAllChildren();
	for (auto item : value.getAllChildren())
	{
		this->addChild(item);
	}
	return *this;
}

bool CompoundProposition::isPrimaryPropositionOfAllChildren()
{
	for (auto item : _children)
	{
		if (!item->is<PrimaryProposition>())
		{
			return false;
		}
	}
	return true;
}

Proposition* CompoundProposition::clone()
{
	return create<CompoundProposition>();
}

Proposition* CompoundProposition::deepClone()
{
	CompoundProposition* proposition = create<CompoundProposition>();
	proposition->setChildren(this->deepCloneChildren());
	return proposition;
}

std::vector<TreeNode*> math::CompoundProposition::deepCloneChildren()
{
	std::vector<TreeNode*> vecNode;
	for (auto item : _children)
	{
		vecNode.push_back(item->as<Proposition>()->deepClone());
	}

	return vecNode;
}


