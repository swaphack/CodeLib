#include "Person.h"

using namespace game;

Person::Person()
{
	addComponent(new Body());
	addComponent(new Mind());
}

Person::~Person()
{
}