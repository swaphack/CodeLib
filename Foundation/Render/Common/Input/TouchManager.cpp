#include "TouchManager.h"
#include "TouchProtocol.h"
#include "Common/Node/Node.h"
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
	_targets.push_back(target);
}

void render::TouchManager::removeTarget(TouchProtocol* target)
{
	if (target == nullptr)
	{
		return;
	}

	if (!_targets.empty())
	{
		auto it = std::find(_targets.begin(), _targets.end(), target);
		if (it != _targets.end())
		{
			_targets.erase(it);
		}
	}

	if (!_temps.empty())
	{
		auto it = std::find(_temps.begin(), _temps.end(), target);
		if (it != _temps.end())
		{
			_temps.erase(it);
		}
	}
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
}

void render::TouchManager::process()
{
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

void TouchManager::onTouchBegan(const math::Vector2& touchPoint)
{
	_temps.clear();

	for (auto item : _targets)
	{
		if (item->containTouchPoint(touchPoint))
		{
			_temps.push_back(item);
		}
		else
		{
			item->onTouchCanceled(touchPoint);
		}
	}

	// 判断两对象的优先级
	std::sort(_temps.begin(), _temps.end(), [](const TouchProtocol* a, const TouchProtocol* b)
	{
		return a->isInFrontOf(b);
	});

	for (auto item : _temps)
	{
		if (item->onTouchBegan(touchPoint))
		{
			// 吞噬点击
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
}
