#include "TouchProtocol.h"
#include "Common/Node/Node.h"
#include "TouchManager.h"

using namespace render;


TouchProtocol::TouchProtocol()
:_bTouchEnabled(false)
{
}

TouchProtocol::~TouchProtocol()
{
	this->removeAllTouchDelegates();
	this->removeAllTouchFuncs();

	this->setTouchEnabled(false);
}

void TouchProtocol::setTouchEnabled(bool status)
{
	if (_bTouchEnabled == status)
	{
		return;
	}

	_bTouchEnabled = status;
	if (status)
	{
		G_TOUCHMANAGER->addTarget(this);
	}
	else
	{
		G_TOUCHMANAGER->removeTarget(this);
	}
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

void render::TouchProtocol::setClippingEnabled(bool status)
{
	_bClippingEnabled = status;
}

bool render::TouchProtocol::isClippingEnabled()
{
	return _bClippingEnabled;
}

bool render::TouchProtocol::containTouchPoint(const math::Vector2& touchPoint)
{
	return false;
}

bool render::TouchProtocol::isInFrontOf(const TouchProtocol* target) const
{
	return false;
}

bool TouchProtocol::onTouchBegan(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}
	bool include = this->containTouchPoint(touchPoint);
	if (include)
	{
		dispatchTouchEvent(TouchType::BEGAN, touchPoint, include);
	}
	else
	{
		onTouchCanceled(touchPoint);
	}
	

	return include;
}

bool TouchProtocol::onTouchMoved(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}

	bool include = this->containTouchPoint(touchPoint);
	if (include)
	{
		dispatchTouchEvent(TouchType::MOVED, touchPoint, include);
	}
	else
	{
		onTouchCanceled(touchPoint);
	}

	return include;
}

bool TouchProtocol::onTouchEnded(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}

	bool include = this->containTouchPoint(touchPoint);
	if (include)
	{
		dispatchTouchEvent(TouchType::ENDED, touchPoint, include);
	}
	else
	{
		onTouchCanceled(touchPoint);
	}

	return include;
}

void TouchProtocol::onTouchCanceled(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return;
	}

	dispatchTouchEvent(TouchType::CANCELED, touchPoint, false);
}

void TouchProtocol::addTouchDelegate(TouchType type, sys::Object* object, TOUCH_DELEGATE_HANDLER handler)
{
	TouchDelegate del;
	del.first = object;
	del.second = handler;
	_touchDelegates[type].push_back(del);
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
	_touchFuncs[type].push_back(func);
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
		const auto& items = _touchDelegates[type];
		for (const auto& item : items)
		{
			((item.first)->*(item.second))(dynamic_cast<render::Node*>(this), touchPoint, include);
		}
	}

	auto it1 = _touchFuncs.find(type);
	if (it1 != _touchFuncs.end())
	{
		const auto& items = _touchFuncs[type];
		for (const auto& item : items)
		{
			item(touchPoint, include);
		}
	}	
}
