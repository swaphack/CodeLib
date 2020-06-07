#include "Action.h"
#include "../Node/Node.h"
using namespace render;

Action::Action()
:_target(nullptr)
{
	
}

Action::~Action()
{
	SAFE_RELEASE(_target);
}

void Action::setTarget(Node* target)
{
	SAFE_RELEASE(_target);
	SAFE_RETAIN(target);
	_target = target;
}

bool Action::isEqualsTarget(const Node* target)
{
	return _target == target;
}

void Action::reset()
{
	this->start();
}



