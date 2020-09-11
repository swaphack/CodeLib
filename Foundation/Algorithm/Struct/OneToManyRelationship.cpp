#include "OneToManyRelationship.h"

alg::OneToManyRelationship::OneToManyRelationship()
{

}

alg::OneToManyRelationship::~OneToManyRelationship()
{
	SAFE_RELEASE(_src);
	this->removeAllRelations();
}

void alg::OneToManyRelationship::setObject(const sys::Object* src)
{
	sys::Object* pSrc = (sys::Object*)src;

	SAFE_RETAIN(pSrc);
	SAFE_RELEASE(_src);
	_src = pSrc;
}

const sys::Object* alg::OneToManyRelationship::getObject()
{
	return _src;
}

void alg::OneToManyRelationship::addRelation(const sys::Object* dest)
{
	if (dest == nullptr)
	{
		return;
	}

	sys::Object* pDest = (sys::Object*)dest;

	auto it = _relations.find(pDest);
	if (it != _relations.end())
	{
		return;
	}

	SAFE_RETAIN(pDest);
	_relations.insert(pDest);
}

void alg::OneToManyRelationship::removeRelation(const sys::Object* dest)
{
	if (dest == nullptr)
	{
		return;
	}

	sys::Object* pDest = (sys::Object*)dest;

	auto it = _relations.find(pDest);
	if (it == _relations.end())
	{
		return;
	}

	SAFE_RELEASE(pDest);
	_relations.erase(it);
}

void alg::OneToManyRelationship::removeAllRelations()
{
	for (auto& item : _relations)
	{
		SAFE_RELEASE(item);
	}

	_relations.clear();
}

bool alg::OneToManyRelationship::contains(const sys::Object* dest)
{
	if (dest == nullptr)
	{
		return false;
	}

	sys::Object* pDest = (sys::Object*)dest;

	auto it = _relations.find(pDest);
	return it != _relations.end();
}

