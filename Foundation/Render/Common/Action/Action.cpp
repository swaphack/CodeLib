#include "Action.h"

using namespace render;

Action::Action()
:_target(nullptr)
{
	
}

Action::~Action()
{
	SAFE_RELEASE(_target);
}

void Action::setTarget(sys::Object* target)
{
	SAFE_RELEASE(_target);
	SAFE_RETAIN(target);
	_target = target;
}

bool Action::isEqualsTarget(const sys::Object* target)
{
	return _target == target;
}

void Action::reset()
{
	this->start();
}



