#include "TouchManager.h"
#include "TouchProtocol.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
#include "Box/BoxSpace.h"
#include "Box/BoxProtocol.h"

using namespace render;

TouchManager::TouchManager()
{

}

TouchManager::~TouchManager()
{
	for (auto item : _tempTriggers)
	{
		SAFE_RELEASE(item->getTouchNode());
	}
	_tempTriggers.clear();
}

void render::TouchManager::addTarget(TouchProtocol* target)
{
	if (target == nullptr)
	{
		return;
	}

	_targets[target->getTouchNode()] = target;
	setDirty(true);
}

void render::TouchManager::removeTarget(TouchProtocol* target)
{
	if (target == nullptr)
	{
		return;
	}

	if (!_targets.empty())
	{
		_targets.erase(target->getTouchNode());
	}

	if (!_tempTriggers.empty())
	{
		auto it = std::find(_tempTriggers.begin(), _tempTriggers.end(), target);
		if (it != _tempTriggers.end())
		{
			SAFE_RELEASE(target->getTouchNode());
			_tempTriggers.erase(it);
		}
	}
	setDirty(true);
}

void render::TouchManager::addBeganTouchPoint(const math::Vector2& touchPoint)
{
	addTouchInfo(TouchType::BEGAN, touchPoint);
}

void render::TouchManager::addMovedTouchPoint(const math::Vector2& touchPoint)
{
	addTouchInfo(TouchType::MOVED, touchPoint);
}

void render::TouchManager::addEndedTouchPoint(const math::Vector2& touchPoint)
{
	addTouchInfo(TouchType::ENDED, touchPoint);
}

void render::TouchManager::addTouchInfo(TouchType type, const math::Vector2& touchPoint)
{
	TouchSlotInfo info;
	info.type = type;
	info.touchPoint = touchPoint;

	_waitAddTouches.push_back(info);

	this->handTouch();
}

void TouchManager::onTouchBegan(const math::Vector2& touchPoint)
{
	std::vector<render::BoxProtocol*> boxes;
	if (!G_BOXSPACE->containsTouchPoint(touchPoint, boxes))
	{
		return;
	}

	std::vector<TouchProtocol*> temps;
	for (auto item : boxes)
	{
		auto it = _targets.find(item->getBoxNode());
		if (it != _targets.end())
		{
			temps.push_back(it->second);
		}
	}

	// 判断两对象的优先级
	std::sort(temps.begin(), temps.end(), [](const TouchProtocol* a, const TouchProtocol* b)
	{
		return a->isInFrontOf(b);
	});

	for (auto item : temps)
	{
		if (item->onTouchBegan(touchPoint))
		{
			SAFE_RETAIN(item->getTouchNode());
			_tempTriggers.push_back(item);
			if (item->isTouchSwallowed())
			{
				break;
			}
		}
	}
}

void TouchManager::onTouchMoved(const math::Vector2& touchPoint)
{
	for (auto item : _tempTriggers)
	{
		item->onTouchMoved(touchPoint);
	}
}

void TouchManager::onTouchEnded(const math::Vector2& touchPoint)
{
	for (auto item : _tempTriggers)
	{
		item->onTouchEnded(touchPoint);
	}

	//_tempTriggers.clear();
}

void render::TouchManager::onTouchCanceled(const math::Vector2& touchPoint)
{
	for (auto item : _tempTriggers)
	{
		item->onTouchCanceled(touchPoint);
		SAFE_RELEASE(item->getTouchNode());
	}
	_tempTriggers.clear();
}

void render::TouchManager::onCheckTriggerTouch(const math::Vector2& touchPoint)
{
	auto temps = _tempTriggers;
	for (auto item : temps)
	{
		if (!item->containsTouchPoint(touchPoint))
		{
			auto it = std::find(_tempTriggers.begin(), _tempTriggers.end(), item);
			if (it != _tempTriggers.end()) _tempTriggers.erase(it);

			item->onTouchCanceled(touchPoint);
			SAFE_RELEASE(item->getTouchNode());
		}
	}
}

void render::TouchManager::handTouch()
{

	if (_waitAddTouches.empty())
	{
		return;
	}

	std::vector<TouchSlotInfo> touchInfos = _waitAddTouches;
	_waitAddTouches.clear();

	for (const auto& item : touchInfos)
	{
		if (item.type == TouchType::BEGAN)
		{
			onTouchCanceled(item.touchPoint);
			onTouchBegan(item.touchPoint);
		}
		else if (item.type == TouchType::MOVED)
		{
			onCheckTriggerTouch(item.touchPoint);
			onTouchMoved(item.touchPoint);
		}
		else if (item.type == TouchType::ENDED)
		{
			onCheckTriggerTouch(item.touchPoint);
			onTouchEnded(item.touchPoint);
		}
	}
}
