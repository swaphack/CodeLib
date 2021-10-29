#include "TouchManager.h"
#include "TouchProtocol.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
#include "Box/BoxSpace.h"
#include "Box/BoxDrawProtocol.h"

using namespace render;

TouchManager::TouchManager()
{

}

TouchManager::~TouchManager()
{
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

	if (!_temps.empty())
	{
		auto it = std::find(_temps.begin(), _temps.end(), target);
		if (it != _temps.end())
		{
			_temps.erase(it);
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
	for (auto item : _temps)
	{
		item->onTouchCanceled(touchPoint);
	}
	_temps.clear();

	std::vector<render::BoxDrawProtocol*> boxes;
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
			_temps.push_back(item);
			if (item->isTouchSwallowed())
			{
				break;
			}
		}
	}
}

void TouchManager::onTouchMoved(const math::Vector2& touchPoint)
{
	for (auto item : _temps)
	{
		item->onTouchMoved(touchPoint);
	}
}

void TouchManager::onTouchEnded(const math::Vector2& touchPoint)
{
	for (auto item : _temps)
	{
		item->onTouchEnded(touchPoint);
	}

	//_temps.clear();
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
			onTouchBegan(item.touchPoint);
		}
		else if (item.type == TouchType::MOVED)
		{
			onTouchMoved(item.touchPoint);
		}
		else if (item.type == TouchType::ENDED)
		{
			onTouchEnded(item.touchPoint);
		}
	}
}
