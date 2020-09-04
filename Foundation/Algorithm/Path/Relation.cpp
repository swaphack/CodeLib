#include "Relation.h"

using namespace alg;

Relation::Relation()
{

}

Relation::~Relation()
{
	this->clearAllRelations();
}

void Relation::setTag(int tag)
{
	_tag = tag;
}

int Relation::getTag() const
{
	return _tag;
}

void Relation::addSingleRelation(Relation* node)
{
	if (node == nullptr)
	{
		return;
	}

	SAFE_RETAIN(node);

	_adjacents.insert(node);
}

void Relation::clearAllRelations()
{
	for (auto item : _adjacents)
	{
		item->removeSingleRelation(this);
		SAFE_RELEASE(item);
	}

	_adjacents.clear();
}

Relation* Relation::findRelationByTag(int tag)
{
	for (auto item : _adjacents)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
	}

	return nullptr;
}

Relation* Relation::findRelationByTagWithRecurse(int tag)
{
	for (auto item : _adjacents)
	{
		if (item->getTag() == tag)
		{
			return item;
		}
		else
		{
			auto ret = item->findRelationByTagWithRecurse(tag);
			if (ret)
			{
				return ret;
			}
		}
	}

	return nullptr;
}

void alg::Relation::setName(const std::string& name)
{
	_name = name;
}

const std::string& alg::Relation::getName() const
{
	return _name;
}

void alg::Relation::removeSingleRelation(Relation* node)
{
	if (node == nullptr)
	{
		return;
	}

	auto it = _adjacents.find(node);
	if (it == _adjacents.end())
	{
		return;
	}

	SAFE_RELEASE(node);
	_adjacents.erase(it);
}

void alg::Relation::addDoubleRelation(Relation* node)
{
	if (node == nullptr)
	{
		return;
	}

	this->addSingleRelation(node);
	node->addSingleRelation(this);
}

void alg::Relation::removeDoubleRelation(Relation* node)
{
	if (node == nullptr)
	{
		return;
	}

	this->removeSingleRelation(node);
	node->removeSingleRelation(this);
}

alg::Relation* alg::Relation::findRelationByName(const std::string& name)
{
	for (auto item : _adjacents)
	{
		if (item->getName() == name)
		{
			return item;
		}
	}

	return nullptr;
}

alg::Relation* alg::Relation::findRelationByNameWithRecurse(const std::string& name)
{
	for (auto item : _adjacents)
	{
		if (item->getName() == name)
		{
			return item;
		}
		else
		{
			auto ret = item->findRelationByNameWithRecurse(name);
			if (ret)
			{
				return ret;
			}
		}
	}

	return nullptr;
}
