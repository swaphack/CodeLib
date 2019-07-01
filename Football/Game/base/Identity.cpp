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
