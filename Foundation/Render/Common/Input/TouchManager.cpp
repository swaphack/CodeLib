#include "TouchManager.h"
#include "TouchProtocol.h"
#include "Common/Node/Node.h"
#include "Common/Tool/Tool.h"
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

	_targets.insert(target);
}

void render::TouchManager::removeTarget(TouchProtocol* target)
{
	if (target == nullptr)
	{
		return;
	}

	if (!_targets.empty())
	{
		auto it = _targets.find(target);
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
	info.touchPoint = touchPoint - math::Vector2(0.5f * Tool::getGLViewWidth(), 0.5f * Tool::getGLViewHeight());

	_waitAddTouches.push_back(info);
}

void render::TouchManager::process()
{
	if (_waitAddTouches.empty())
	{
		return;
	}
	/*
	if (_waitAddTouches[0].type != TouchType::BEGAN)
	{// 开始不是began，移除所有直到began开始
		auto it = _waitAddTouches.begin();
		do
		{
			if ((*it).type != TouchType::BEGAN)
			{
				it = _waitAddTouches.erase(it);
			}
			else
			{
				break;
			}
		} while (!_waitAddTouches.empty());
	}

	std::vector<TouchSlotInfo> touchInfos;
	auto it = _waitAddTouches.begin();
	do
	{// 获取一个完整的点击操作
		touchInfos.push_back(*it);

		if ((*it).type == TouchType::ENDED)
		{			
			break;
		}
		it++;
	} while (!_waitAddTouches.empty());

	if (!touchInfos.empty()) return;

	int size = touchInfos.size();
	if (touchInfos[size - 1].type != TouchType::ENDED)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		_waitAddTouches.erase(_waitAddTouches.begin());
	}
	*/

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

		// 吞噬点击
		if (item->isTouchSwallowed())
		{
			break;
		}
	}
}

void TouchManager::onTouchEnded(const math::Vector2& touchPoint)
{
	for (auto item : _temps)
	{
		item->onTouchEnded(touchPoint);

		// 吞噬点击
		if (item->isTouchSwallowed())
		{
			break;
		}
	}
}
