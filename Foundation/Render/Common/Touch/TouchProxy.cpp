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
	this->removeAllTouchDelegates();
	this->removeAllTouchFuncs();
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

void render::TouchProxy::setSwallowTouch(bool status)
{
	_bSwallowTouch = status;
}

bool render::TouchProxy::isSwallowTouch()
{
	return _bSwallowTouch;
}

bool TouchProxy::onTouchBegan(float x, float y)
{
	if (_target == nullptr)
	{
		return false;
	}

	bool include = _target->containTouchPoint(x, y);
	_bIncludeTouch = include;
	if (!_bIncludeTouch)
	{
		return include;
	}

	dispatchTouchEvent(TouchType::DOWN, x, y, include);

	return include;
}

bool TouchProxy::onTouchMoved(float x, float y)
{
	if (_target == nullptr)
	{
		return false;
	}
	if (!_bIncludeTouch)
	{
		return false;
	}

	bool include = _target->containTouchPoint(x, y);

	dispatchTouchEvent(TouchType::ON, x, y, include);

	return include;
}

bool TouchProxy::onTouchEnded(float x, float y)
{
	if (_target == nullptr)
	{
		return false;
	}
	_bIncludeTouch = false;

	bool include = _target->containTouchPoint(x, y);

	dispatchTouchEvent(TouchType::UP, x, y, include);

	return include;
}

void TouchProxy::addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler)
{
	TouchDelegate del;
	del.first = object;
	del.second = handler;
	_touchDelegates[type] = del;
}

void TouchProxy::removeTouchDelegate(TouchType type)
{
	auto it = _touchDelegates.find(type);
	if (it == _touchDelegates.end())
	{
		return;
	}
	_touchDelegates.erase(it);
}

void TouchProxy::removeAllTouchDelegates()
{
	_touchDelegates.clear();
}

void render::TouchProxy::addTouchFunc(TouchType type, TouchFunc func)
{
	if (func == nullptr)
	{
		return;
	}
	_touchFuncs[type] = func;
}

void render::TouchProxy::removeTouchFunc(TouchType type)
{
	auto it = _touchFuncs.find(type);
	if (it == _touchFuncs.end())
	{
		return;
	}

	_touchFuncs.erase(it);
}

void render::TouchProxy::removeAllTouchFuncs()
{
	_touchFuncs.clear();
}

void TouchProxy::dispatchTouchEvent(TouchType type, float x, float y, bool include)
{
	auto it0 = _touchDelegates.find(type);
	if (it0 != _touchDelegates.end())
	{
		auto item = _touchDelegates[type];
		((item.first)->*(item.second))(_target, x, y, include);
	}

	auto it1 = _touchFuncs.find(type);
	if (it1 != _touchFuncs.end())
	{
		auto item = _touchFuncs[type];
		item(_target, x, y, include);
	}
	
}
