#include "system.h"
#include "Action.h"
#include "ActionProxy.h"
#include "ActionManager.h"
#include "../Node/Node.h"
using namespace render;

ActionProxy::ActionProxy()
{
}

ActionProxy::~ActionProxy()
{
	this->stopAllActions();
}

void render::ActionProxy::setTarget(Node* target)
{
	_target = target;
}

Node* render::ActionProxy::getTarget()
{
	return nullptr;
}

Action* ActionProxy::runAction(Action* handler)
{
	if (handler)
	{
		handler->setTarget(_target);
		G_ACTIONMANAGER->addAction(handler);
		handler->start();
	}

	return handler;
}

void ActionProxy::stopAction(Action* handler)
{
	if (handler)
	{
		handler->stop();
		G_ACTIONMANAGER->removeAction(handler);
	}
}

void ActionProxy::pauseAction(Action* handler)
{
	if (handler)
	{
		handler->pause();
	}
}

void ActionProxy::reusmeAction(Action* handler)
{
	if (handler)
	{
		handler->resume();
	}
}

void ActionProxy::pauseAllActions()
{
	if (_target)
	{
		G_ACTIONMANAGER->pauseAllActionsByTargets(_target);
	}
}

void ActionProxy::resumeAllActions()
{
	if (_target)
	{
		G_ACTIONMANAGER->resumeAllActionsByTargets(_target);
	}
}

void ActionProxy::stopAllActions()
{
	if (_target)
	{
		G_ACTIONMANAGER->removeAllActionsByTargets(_target);
	}
}
