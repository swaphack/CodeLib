#include "OneToOneDoubleRelationship.h"
#include "OneToOneRelationship.h"

alg::OneToOneDoubleRelationship::OneToOneDoubleRelationship()
{
	_srcRelations = new OneToOneRelationship();
	_destRelations = new OneToOneRelationship();
}

alg::OneToOneDoubleRelationship::~OneToOneDoubleRelationship()
{
	SAFE_DELETE(_srcRelations);
	SAFE_DELETE(_destRelations);
}

void alg::OneToOneDoubleRelationship::addRelation(const sys::Object* src, const sys::Object* dest)
{
	if (src == nullptr || dest == nullptr)
	{
		return;
	}

	_srcRelations->addRelation(src, dest);
	_destRelations->addRelation(dest, src);
}

void alg::OneToOneDoubleRelationship::removeRelation(const sys::Object* src)
{
	if (src == nullptr)
	{
		return;
	}
	_srcRelations->removeRelation(src);
	_destRelations->removeRelation(src);

}

void alg::OneToOneDoubleRelationship::removeAllRelations()
{
	_srcRelations->removeAllRelations();
	_destRelations->removeAllRelations();
}

const sys::Object* alg::OneToOneDoubleRelationship::getRelation(const sys::Object* src)
{
	if (src == nullptr)
	{
		return nullptr;
	}

	auto it = _srcRelations->getRelation(src);
	if (it != nullptr)
	{
		return it;
	}

	it = _destRelations->getRelation(src);
	if (it != nullptr)
	{
		return it;
	}

	return nullptr;
}

