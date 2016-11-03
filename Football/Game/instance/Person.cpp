#include "Person.h"

using namespace game;

Person::Person()
{
}

Person::~Person()
{
}

bool Person::runAction(IAction* pAction)
{
	if (pAction == nullptr)
	{
		return false;
	}

	return true;
}