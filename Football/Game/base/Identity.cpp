#include "Identity.h"

using namespace game;


Identity::Identity()
:_id(0)
{

}

Identity::~Identity()
{

}

uint64_t Identity::getID()
{
	return _id;
}

void Identity::setID(uint64_t nID)
{
	_id = nID;
}
//////////////////////////////////////////////////////////////////////////
IdentityContainer::IdentityContainer()
{

}

IdentityContainer::~IdentityContainer()
{

}

void IdentityContainer::add(Identity* value)
{
	if (value == nullptr)
	{
		return;
	}

	Dictionary<uint64_t, Identity*>::add(value->getID(), value);
}

void IdentityContainer::remove(Identity* value)
{
	if (value == nullptr)
	{
		return;
	}

	Dictionary<uint64_t, Identity*>::remove(value->getID());
}

void IdentityContainer::destoryValue(Identity* value)
{
	if (value)
	{
		delete value;
	}
}
