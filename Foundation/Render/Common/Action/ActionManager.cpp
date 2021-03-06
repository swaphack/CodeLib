#include "ActionManager.h"
#include "Action.h"
#include "../Node/Node.h"
#include <vector>

using namespace render;

ActionManager::ActionManager()
{

}

ActionManager::~ActionManager()
{
	this->removeAllActions();
}

void ActionManager::update(float interval)
{
	std::vector<Action*> removeActions;
	std::set<Action*>::iterator it = _actions.begin();
	while (it != _actions.end())
	{
		if ((*it)->isFinish())
		{
			removeActions.push_back((*it));
		}
		else
		{
			if ((*it)->isRunning())
			{
				(*it)->update(interval);
			}
		}
		it++;
	}

	std::vector<Action*>::iterator raIter = removeActions.begin();
	while (raIter != removeActions.end())
	{
		this->removeAction(*raIter);
		raIter++;
	}
}

void ActionManager::addAction(Action* action)
{
	if (action == nullptr)
	{
		return;
	}
	SAFE_RETAIN(action);
	_actions.insert(action);
}

void ActionManager::removeAction(Action* action)
{
	if (action == nullptr)
	{
		return;
	}
	SAFE_RELEASE(action);
	_actions.erase(action);
}

void ActionManager::removeAllActions()
{
	std::set<Action*>::iterator it = _actions.begin();
	while (it != _actions.end())
	{
		SAFE_RELEASE((*it));
		it =_actions.erase(it);
	}
}

void ActionManager::pauseAllActionsByTargets(Node* target)
{
	if (target == nullptr)
	{
		return;
	}
	std::set<Action*>::iterator it = _actions.begin();
	while (it != _actions.end())
	{
		if ((*it)->isEqualsTarget(target))
		{
			(*it)->pause();
		}
		it++;
	}
}

void ActionManager::resumeAllActionsByTargets(Node* target)
{
	if (target == nullptr)
	{
		return;
	}

	std::set<Action*>::iterator it = _actions.begin();
	while (it != _actions.end())
	{
		if ((*it)->isEqualsTarget(target))
		{
			(*it)->resume();
		}
		it++;
	}
}

void ActionManager::removeAllActionsByTargets(Node* target)
{
	if (target == nullptr)
	{
		return;
	}

	std::vector<Action*> removeActions;
	std::set<Action*>::iterator it = _actions.begin();
	while (it != _actions.end())
	{
		if ((*it)->isEqualsTarget(target))
		{
			removeActions.push_back((*it));
		}
		it++;
	}

	std::vector<Action*>::iterator raIter = removeActions.begin();
	while (raIter != removeActions.end())
	{
		this->removeAction(*raIter);
		raIter++;
	}
}
