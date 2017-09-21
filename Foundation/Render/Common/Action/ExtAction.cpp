#include "ExtAction.h"
#include "IntervalAction.h"
using namespace render;

//////////////////////////////////////////////////////////////////////////
RepeateAction::RepeateAction()
	:_count(0)
	, _action(nullptr)
{

}

RepeateAction::~RepeateAction()
{
	SAFE_RELEASE(_action);
}

int RepeateAction::getCount()
{
	return _count;
}

void RepeateAction::setCount(int count)
{
	_totalCount = count;
}

void RepeateAction::setAction(IntervalAction* action)
{
	SAFE_RELEASE(_action);
	SAFE_RETAIN(action);
	_action = action;
}

void RepeateAction::update(float duration)
{
	if (!_action)
	{
		return;
	}

	_action->update(duration);
	if (_action->isFinish())
	{
		_count++;
		if (_count == _totalCount)
		{
			this->stop();
		}
		else
		{
			_action->reset();
		}
	}
}

//////////////////////////////////////////////////////////////////////////
RepeateForeverAction::RepeateForeverAction()
{

}

RepeateForeverAction::~RepeateForeverAction()
{
	SAFE_RELEASE(_action);
}

void RepeateForeverAction::setAction(IntervalAction* action)
{
	SAFE_RELEASE(_action);
	SAFE_RETAIN(action);
	_action = action;
}

void RepeateForeverAction::update(float duration)
{
	if (!_action)
	{
		return;
	}

	_action->update(duration);
	if (_action->isFinish())
	{
		_action->reset();
	}
}

//////////////////////////////////////////////////////////////////////////


SequenceAction::SequenceAction()
{

}

SequenceAction::~SequenceAction()
{
	this->removeAllActions();
}

void SequenceAction::addAction(Action* action)
{
	if (action)
	{
		SAFE_RETAIN(action);
		_actions.push_back(action);
	}
}

void SequenceAction::removeAction(Action* action)
{
	if (!action)
	{
		return;
	}

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		if ((*it) == action)
		{
			SAFE_RELEASE((*it));
			_actions.erase(it);
			break;
		}
	}
}

void SequenceAction::removeAllActions()
{
	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		SAFE_RELEASE((*it));
	}

	_actions.clear();
}

void SequenceAction::update(float duration)
{
	if (_actions.empty())
	{
		this->stop();
		return;
	}

	Action* front = _actions.front();
	if (front)
	{
		front->update(duration);
		if (front->isFinish())
		{
			_actions.erase(_actions.begin());
		}
	}

}
//////////////////////////////////////////////////////////////////////////

SpawnAction::SpawnAction()
{

}

SpawnAction::~SpawnAction()
{

}

void SpawnAction::addAction(Action* action)
{
	if (action)
	{
		_actions.push_back(action);
	}
}

void SpawnAction::removeAction(Action* action)
{
	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		if ((*it) == action)
		{
			SAFE_RELEASE((*it));
			_actions.erase(it);
			break;
		}
	}
}

void SpawnAction::removeAllActions()
{
	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		SAFE_RELEASE((*it));
	}

	_actions.clear();
}

void SpawnAction::update(float duration)
{
	if (_actions.empty())
	{
		this->stop();
		return;
	}

	std::vector<Action*> removeActions;

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();)
	{
		(*it)->update(duration);
		if ((*it)->isFinish())
		{
			SAFE_RELEASE((*it));
			removeActions.push_back((*it));
			it = _actions.erase(it);
		}
		else
		{
			it++;
		}
	}
}
//////////////////////////////////////////////////////////////////////////

CallFunc::CallFunc()
	:_func(nullptr)
{

}

CallFunc::~CallFunc()
{

}

void CallFunc::setFunc(std::function<void()> func)
{
	_func = func;
}

void CallFunc::update(float duration)
{
	if (!_func)
	{
		this->stop();
	}
	if (_func)
	{
		_func();
		_func = nullptr;
	}
	
}
//////////////////////////////////////////////////////////////////////////


CallFuncN::CallFuncN()
	:_func(nullptr)
{

}

CallFuncN::~CallFuncN()
{

}

void CallFuncN::setFunc(std::function<void(sys::Object*)> func)
{
	_func = func;
}

void CallFuncN::update(float duration)
{
	if (!_func)
	{
		this->stop();
	}
	if (_func)
	{
		_func(_target);
		_func = nullptr;
	}
}
