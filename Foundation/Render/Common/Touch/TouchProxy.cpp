#include "TouchProxy.h"
#include "TouchManager.h"

using namespace render;


TouchProxy::TouchProxy(Node* target)
:_target(target)
, _bTouchEnabled(true)
{
	G_TOUCHMANAGER->addTouch(this);
}

TouchProxy::~TouchProxy()
{
	this->removeAllTouchEvent();
	G_TOUCHMANAGER->removeTouch(this);
}

void TouchProxy::setTarget(Node* target) 
{
	_target = target; 
}

Node* TouchProxy::getTarget() 
{
	return _target; 
}

void TouchProxy::setTouchEnabled(bool status)
{
	_bTouchEnabled = status;
}

bool TouchProxy::isTouchEnabled()
{
	return _bTouchEnabled;
}

bool TouchProxy::onTouchBegan(float x, float y)
{
	if (_target == nullptr)
	{
		return false;
	}

	if (!_target->containTouchPoint(x, y))
	{
		return false;
	}

	dispatchTouchEvent(ETT_DOWN, x, y);

	return true;
}

void TouchProxy::onTouchMoved(float x, float y)
{
	if (_target == nullptr)
	{
		return;
	}

	dispatchTouchEvent(ETT_ON, x, y);
}

void TouchProxy::onTouchEnded(float x, float y)
{
	if (_target == nullptr)
	{
		return;
	}

	dispatchTouchEvent(ETT_UP, x, y);
}

void TouchProxy::addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler)
{
	TouchDelegate del;
	del.first = object;
	del.second = handler;
	_touchEvent[type].push_back(del);
}

void TouchProxy::removeTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler)
{
	std::map<TouchType, std::vector<TouchDelegate>>::iterator it = _touchEvent.find(type);
	if (it == _touchEvent.end())
	{
		return;
	}

	std::vector<TouchDelegate>::iterator itD = it->second.begin();
	while (itD != it->second.end())
	{
		if ((*itD).first == object && (*itD).second == handler)
		{
			it->second.erase(itD);
			break;
		}
		itD++;
	}
}

void TouchProxy::removeTouchEvent(TouchType type)
{
	std::map<TouchType, std::vector<TouchDelegate>>::iterator it = _touchEvent.find(type);
	if (it == _touchEvent.end())
	{
		return;
	}

	it->second.clear();
	_touchEvent.erase(it);
}

void TouchProxy::removeAllTouchEvent()
{
	_touchEvent.clear();
}

void TouchProxy::dispatchTouchEvent(TouchType type, float x, float y)
{
	std::map<TouchType, std::vector<TouchDelegate>>::iterator it = _touchEvent.find(type);
	if (it == _touchEvent.end())
	{
		return;
	}

	std::vector<TouchDelegate>::iterator itD = it->second.begin();
	while (itD != it->second.end())
	{
		((*itD).first->*(*itD).second)(_target, x, y);
		itD++;
	}
}
