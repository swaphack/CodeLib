#include "TouchProtocol.h"
#include "Common/Node/Node.h"

using namespace render;


TouchProtocol::TouchProtocol()
:_bTouchEnabled(false)
{
}

TouchProtocol::~TouchProtocol()
{
	this->removeAllTouchDelegates();
	this->removeAllTouchFuncs();
}

void TouchProtocol::setTouchEnabled(bool status)
{
	_bTouchEnabled = status;
}

bool TouchProtocol::isTouchEnabled()
{
	return _bTouchEnabled;
}

void render::TouchProtocol::setTouchSwallowed(bool status)
{
	_bTouchSwallowed = status;
}

bool render::TouchProtocol::isTouchSwallowed()
{
	return _bTouchSwallowed;
}

bool render::TouchProtocol::containTouchPoint(const math::Vector2& touchPoint)
{
	return false;
}

void render::TouchProtocol::doSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
}

void render::TouchProtocol::doNotSwallowTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
}

bool TouchProtocol::onTouchBegan(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		dispatchSwallowEvent(TouchType::DOWN, touchPoint, false);
		return false;
	}
	bool include = this->containTouchPoint(touchPoint);
	_bIncludeTouch = include;

	dispatchTouchEvent(TouchType::DOWN, touchPoint, include);

	return include;
}

bool TouchProtocol::onTouchMoved(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		dispatchSwallowEvent(TouchType::ON, touchPoint, false);
		return false;
	}

	if (!_bIncludeTouch)
	{
		return false;
	}

	bool include = this->containTouchPoint(touchPoint);

	dispatchTouchEvent(TouchType::ON, touchPoint, include);

	return include;
}

bool TouchProtocol::onTouchEnded(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		dispatchSwallowEvent(TouchType::UP, touchPoint, false);
		return false;
	}

	_bIncludeTouch = false;

	bool include = this->containTouchPoint(touchPoint);

	dispatchTouchEvent(TouchType::UP, touchPoint, include);

	return include;
}

void TouchProtocol::addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler)
{
	TouchDelegate del;
	del.first = object;
	del.second = handler;
	_touchDelegates[type] = del;
}

void TouchProtocol::removeTouchDelegate(TouchType type)
{
	auto it = _touchDelegates.find(type);
	if (it == _touchDelegates.end())
	{
		return;
	}
	_touchDelegates.erase(it);
}

void TouchProtocol::removeAllTouchDelegates()
{
	_touchDelegates.clear();
}

void render::TouchProtocol::addTouchFunc(TouchType type, TouchFunc func)
{
	if (func == nullptr)
	{
		return;
	}
	_touchFuncs[type] = func;
}

void render::TouchProtocol::removeTouchFunc(TouchType type)
{
	auto it = _touchFuncs.find(type);
	if (it == _touchFuncs.end())
	{
		return;
	}

	_touchFuncs.erase(it);
}

void render::TouchProtocol::removeAllTouchFuncs()
{
	_touchFuncs.clear();
}

void TouchProtocol::dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
	auto it0 = _touchDelegates.find(type);
	if (it0 != _touchDelegates.end())
	{
		auto item = _touchDelegates[type];
		((item.first)->*(item.second))(dynamic_cast<render::Node*>(this), touchPoint, include);
	}

	auto it1 = _touchFuncs.find(type);
	if (it1 != _touchFuncs.end())
	{
		auto item = _touchFuncs[type];
		item(touchPoint, include);
	}	

	dispatchSwallowEvent(type, touchPoint, include);
}

void render::TouchProtocol::dispatchSwallowEvent(TouchType type, const math::Vector2& touchPoint, bool include)
{
	if (isTouchSwallowed() && include)
	{
		doSwallowTouchEvent(type, touchPoint, true);
	}
	else
	{
		doNotSwallowTouchEvent(type, touchPoint, include);
	}
}
