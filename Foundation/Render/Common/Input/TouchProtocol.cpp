#include "TouchProtocol.h"
#include "Common/Node/Node.h"
#include "TouchManager.h"
using namespace render;


TouchProtocol::TouchProtocol()
:_bTouchEnabled(false)
{
}

void TouchProtocol::setTouchNode(Node* node)
{
	_touchNode = node;
}
Node* TouchProtocol::getTouchNode() const
{
	return _touchNode;
}

TouchProtocol::~TouchProtocol()
{
	this->removeAllTouchDelegates();
	this->removeAllTouchFuncs();
}

void TouchProtocol::setTouchEnabled(bool status)
{
	if (_bTouchEnabled == status)
	{
		return;
	}

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
	if (target == nullptr || target->getTouchNode() == nullptr) return false;
	if (getTouchNode() == nullptr) return false;
	return getTouchNode()->isInFrontOfNode(target->getTouchNode());
}

bool TouchProtocol::onTouchBegan(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}
	//bool include = this->containTouchPoint(touchPoint);
	//if (include)
	//{
		dispatchTouchEvent(TouchType::BEGAN, touchPoint);
	//}
	//else
	//{
	//	onTouchCanceled(touchPoint);
	//}
	//return include;

	return true;
}

bool TouchProtocol::onTouchMoved(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}

	//bool include = this->containTouchPoint(touchPoint);
	//if (include)
	//{
		dispatchTouchEvent(TouchType::MOVED, touchPoint);
	//}
	//else
	//{
	//	onTouchCanceled(touchPoint);
	//}
	//return include;
	return true;
}

bool TouchProtocol::onTouchEnded(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return false;
	}

	//bool include = this->containTouchPoint(touchPoint);
	//if (include)
	//{
		dispatchTouchEvent(TouchType::ENDED, touchPoint);
	//}
	//else
	//{
	//	onTouchCanceled(touchPoint);
	//}
	//return include;
	return true;
}

void TouchProtocol::onTouchCanceled(const math::Vector2& touchPoint)
{
	if (!isTouchEnabled())
	{
		return;
	}

	dispatchTouchEvent(TouchType::CANCELED, touchPoint);
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

void TouchProtocol::dispatchTouchEvent(TouchType type, const math::Vector2& touchPoint)
{
	auto it0 = _touchDelegates.find(type);
	if (it0 != _touchDelegates.end())
	{
		const auto& items = _touchDelegates[type];
		for (const auto& item : items)
		{
			((item.first)->*(item.second))(dynamic_cast<render::Node*>(this), touchPoint);
		}
	}

	auto it1 = _touchFuncs.find(type);
	if (it1 != _touchFuncs.end())
	{
		const auto& items = _touchFuncs[type];
		for (const auto& item : items)
		{
			item(touchPoint);
		}
	}	
}

