#include "OneToOneRelationship.h"

alg::OneToOneRelationship::OneToOneRelationship()
{

}

alg::OneToOneRelationship::~OneToOneRelationship()
{
	this->removeAllRelations();
}

void alg::OneToOneRelationship::addRelation(const sys::Object* src, const sys::Object* dest)
{
	if (src == nullptr || dest == nullptr)
	{
		return;
	}

	sys::Object* pSrc = (sys::Object*)src;
	sys::Object* pDest = (sys::Object*)dest;

	auto it = _relations.find(pSrc);
	if (it != _relations.end())
	{
		SAFE_RELEASE(it->second);
	}
	else
	{
		SAFE_RETAIN(pSrc);
	}

	SAFE_RETAIN(pDest);
	_relations[pSrc] = pDest;
}

void alg::OneToOneRelationship::removeRelation(const sys::Object* src)
{
	if (src == nullptr)
	{
		return;
	}

	sys::Object* pSrc = (sys::Object*)src;

	auto it = _relations.find(pSrc);
	if (it != _relations.end())
	{
		SAFE_RELEASE(it->first);
		SAFE_RELEASE(it->second);
		_relations.erase(it);
	}
}

void alg::OneToOneRelationship::removeAllRelations()
{
	for (auto& item : _relations)
	{
		SAFE_RELEASE(item.first);
		SAFE_RELEASE(item.second);
	}

	_relations.clear();
}

const sys::Object* alg::OneToOneRelationship::getRelation(const sys::Object* src)
{
	if (src == nullptr)
	{
		return nullptr;
	}

	sys::Object* pSrc = (sys::Object*)src;

	auto it = _relations.find(pSrc);
	if (it != _relations.end())
	{
		return it->second;
	}
	else
	{
		return nullptr;
	}
}

