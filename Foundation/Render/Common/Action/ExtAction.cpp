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

void RepeateAction::setAction(Action* action)
{
	SAFE_RELEASE(_action);
	SAFE_RETAIN(action);
	_action = action;
}

void RepeateAction::setTarget(sys::Object* target)
{
	Action::setTarget(target);
	if (_action)
	{
		_action->setTarget(target);
	}
}

void RepeateAction::reset()
{
	if (_action)
	{
		_action->reset();
	}

	_count = 0;
}

void RepeateAction::reverse()
{
	if (_action)
	{
		_action->reverse();
	}

	_count = _totalCount - _count;
}

void RepeateAction::update(float duration)
{
	if (!_action)
	{
		return;
	}

	float d1 = duration;

	IntervalAction* pIntervalAction = dynamic_cast<IntervalAction*>(_action);
	if (pIntervalAction)
	{
		float elapsed = pIntervalAction->getElapsed();

		if (elapsed + duration > pIntervalAction->getDuration())
		{
			d1 = pIntervalAction->getDuration() - elapsed;
		}
	}

	_action->update(d1);
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
			if (pIntervalAction)
			{
				pIntervalAction->update(duration - d1);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
RepeateForeverAction::RepeateForeverAction()
	:_action(nullptr)
{

}

RepeateForeverAction::~RepeateForeverAction()
{
	SAFE_RELEASE(_action);
}

void RepeateForeverAction::setAction(Action* action)
{
	SAFE_RELEASE(_action);
	SAFE_RETAIN(action);
	_action = action;
}

void RepeateForeverAction::setTarget(sys::Object* target)
{
	Action::setTarget(target);
	if (_action)
	{
		_action->setTarget(target);
	}
}

void RepeateForeverAction::reset()
{
	if (_action)
	{
		_action->reset();
	}
}

void RepeateForeverAction::reverse()
{
	if (_action)
	{
		_action->reverse();
	}
}

void RepeateForeverAction::update(float duration)
{
	if (!_action)
	{
		return;
	}

	float d1 = duration;
	IntervalAction* pIntervalAction = dynamic_cast<IntervalAction*>(_action);
	if (pIntervalAction)
	{
		float elapsed = pIntervalAction->getElapsed();

		if (elapsed + duration > pIntervalAction->getDuration())
		{
			d1 = pIntervalAction->getDuration() - elapsed;
		}
	}	

	_action->update(d1);
	if (_action->isFinish())
	{
		_action->reset();

		if (pIntervalAction)
		{
			pIntervalAction->update(duration - d1);
		}
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

void SequenceAction::setTarget(sys::Object* target)
{
	Action::setTarget(target);

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		(*it)->setTarget(target);
	}
}

void SequenceAction::reset()
{
	Action::reset();

	_actions.insert(_actions.begin(), _removeActions.begin(), _removeActions.end());

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end(); 
		it++)
	{
		(*it)->reset();
	}

	_removeActions.clear();
}

void SequenceAction::reverse()
{
	Action::reverse();

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();)
	{
		(*it)->reverse();
	}

	for (std::list<Action*>::iterator it = _removeActions.begin();
		it != _removeActions.end();)
	{
		(*it)->reverse();
	}
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
			_removeActions.push_back(front);
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
		SAFE_RETAIN(action);
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

void SpawnAction::setTarget(sys::Object* target)
{
	Action::setTarget(target);

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		(*it)->setTarget(target);
	}
}

void SpawnAction::reset()
{
	Action::reset();

	_actions.insert(_actions.begin(), _removeActions.begin(), _removeActions.end());

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();
		it++)
	{
		(*it)->reset();
	}

	_removeActions.clear();
}

void SpawnAction::reverse()
{
	Action::reverse();

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();)
	{
		(*it)->reverse();
	}

	for (std::list<Action*>::iterator it = _removeActions.begin();
		it != _removeActions.end();)
	{
		(*it)->reverse();
	}
}

void SpawnAction::update(float duration)
{
	if (_actions.empty())
	{
		this->stop();
		return;
	}

	for (std::list<Action*>::iterator it = _actions.begin();
		it != _actions.end();)
	{
		(*it)->update(duration);
		if ((*it)->isFinish())
		{
			_removeActions.push_back(*it);
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

void CallFunc::setFunc(const std::function<void()>& func)
{
	_func = func;
}

void CallFunc::update(float duration)
{
	if (!_func)
	{
		this->stop();
		return;
	}
	if (_func)
	{
		_func();
		this->stop();
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

void CallFuncN::setFunc(const std::function<void(sys::Object*)>& func)
{
	_func = func;
}

void CallFuncN::update(float duration)
{
	if (!_func)
	{
		this->stop();
		return;
	}

	if (_func)
	{
		_func(_target);
		this->stop();
	}
}
