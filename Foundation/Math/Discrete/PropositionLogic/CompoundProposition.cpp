#include "CompoundProposition.h"

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

bool CompoundProposition::isSameTo(Proposition* proposition)
{
	if (proposition == nullptr)
	{
		return false;
	}
	if (proposition->getType() != PropositionType::Compound)
	{
		return false;
	}

	if (proposition->get<CompoundProposition>()->getCompoundType() != this->getCompoundType())
	{
		return false;
	}

	if (!Proposition::isSameTo(proposition))
	{
		return false;
	}

	return matchChildren(proposition->getChildren());
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
		auto proposition = item->get<Proposition>();
		if (proposition && proposition->getIdentify() != 0)
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
		Proposition* p0 = getChildAt(i)->get<Proposition>();
		Proposition* p1 = children[i]->get<Proposition>();
		if (p0 == nullptr || p1 == nullptr)
		{
			return false;
		}
		if (!p0->isSameTo(p1))
		{
			return false;
		}
	}
	return true;
}

CompoundProposition& CompoundProposition::operator=(const CompoundProposition& value)
{
	Proposition::operator=(value);

	this->setCompoundType(value.getCompoundType());
	this->removeAllChildren();
	for (auto item : value.getChildren())
	{
		this->addChild(item);
	}
	return *this;
}







