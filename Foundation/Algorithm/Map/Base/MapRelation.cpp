#include "MapRelation.h"

alg::map::MapRelation::MapRelation()
{

}

alg::map::MapRelation::~MapRelation()
{
	this->removeAllRelations();
}

void alg::map::MapRelation::addRelation(uint32_t relationIndex)
{
	_relations.push_back(relationIndex);
}

void alg::map::MapRelation::addRelation(const std::vector<uint32_t>& relationIndex)
{
	_relations = relationIndex;
}

void alg::map::MapRelation::addRelation(uint32_t nLength, uint32_t relationIndex[])
{
	if (relationIndex == nullptr)
	{
		return;
	}

	for (int i = 0; i < nLength; i++)
	{
		_relations.push_back(relationIndex[i]);
	}
}

void alg::map::MapRelation::addRelation(uint32_t relationIndex0, uint32_t relationIndex1, uint32_t relationIndex2)
{
	_relations.push_back(relationIndex0);
	_relations.push_back(relationIndex1);
	_relations.push_back(relationIndex2);
}

void alg::map::MapRelation::addRelation(uint32_t relationIndex0, uint32_t relationIndex1)
{
	_relations.push_back(relationIndex0);
	_relations.push_back(relationIndex1);
}

void alg::map::MapRelation::addRelation(uint32_t nLength, uint32_t startIndex, va_list ap)
{
	uint32_t* value = math::GET_PARAMETERS(nLength, startIndex, ap);

	_relations.resize(nLength);
	memcpy(&_relations[0], value, nLength * sizeof(uint32_t));
	free(value);
}

void alg::map::MapRelation::addRelation(uint32_t nLength, uint32_t startIndex, ...)
{
	uint32_t* value = math::GET_PARAMETERS(nLength, startIndex);
	_relations.resize(nLength);
	memcpy(&_relations[0], value, nLength * sizeof(uint32_t));
	free(value);
}

void alg::map::MapRelation::removeRelation(uint32_t relationIndex)
{
	auto it = std::find(_relations.begin(), _relations.end(), relationIndex);
	if (it != _relations.end())
	{
		_relations.erase(it);
	}
}

void alg::map::MapRelation::removeAllRelations()
{
	_relations.clear();
}

bool alg::map::MapRelation::containRelation(uint32_t relationIndex) const
{
	auto it = std::find(_relations.begin(), _relations.end(), relationIndex);
	return it != _relations.end();
}

const std::vector<uint32_t>& alg::map::MapRelation::getAllRelations() const
{
	return _relations;
}

uint32_t alg::map::MapRelation::getRelationCount() const
{
	return _relations.size();
}

uint32_t alg::map::MapRelation::getRelation(uint32_t index) const
{
	assert(index < _relations.size());

	return _relations[index];
}

int32_t alg::map::MapRelation::getRelationIndex(uint32_t relationIndex) const
{
	int count = getRelationCount();
	for (int i = 0; i < count; i++)
	{
		if (_relations[i] == relationIndex)
		{
			return i;
		}
	}
	return -1;
}