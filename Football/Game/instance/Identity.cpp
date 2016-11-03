#include "Identity.h"

using namespace game;


Identity::Identity()
:_id(0)
{

}

Identity::~Identity()
{

}

int Identity::getID()
{
	return _id;
}

void Identity::setID(int nID)
{
	_id = nID;
}

const char* Identity::getName()
{
	return _name.c_str();
}

void Identity::setName(const char* name)
{
	if (name)
	{
		_name = name;
	}
}
