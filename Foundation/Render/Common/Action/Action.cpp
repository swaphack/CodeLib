#include "Action.h"

using namespace render;

Action::Action()
:_target(nullptr)
{
	
}

Action::~Action()
{
	
}

void Action::setTarget(sys::Object* target)
{
	_target = target;
}

bool Action::isEqualsTarget(const sys::Object* target)
{
	return _target == target;
}



