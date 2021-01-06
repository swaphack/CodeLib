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

	auto it = std::find(_targets.begin(), _targets.end(), target);
	if (it != _targets.end())
	{
		_targets.erase(it);
	}
}

void TouchManager::onTouchBegan(const math::Vector2& touchPoint)
{
	// 转化为opengl（0，1）会有误差,所以采用实际大小
// 	x = x / Tool::getGLViewSize().width;
// 	y = y / Tool::getGLViewSize().height;

	_temps.clear();

	for (auto item : _targets)
	{
		if (item->containTouchPoint(touchPoint))
		{
			_temps.push_back(item);
		}
		else
		{
			item->dispatchTouchEvent(TouchType::DOWN, touchPoint, false);
		}
	}

	// 判断两对象的优先级
	std::sort(_temps.begin(), _temps.end(), [](const TouchProtocol* a, const TouchProtocol* b)
	{
		return a->isInFrontOf(b);
	});

	for (auto item : _temps)
	{
		//item->onTouchBegan(touchPoint);
		item->dispatchTouchEvent(TouchType::DOWN, touchPoint, true);
		// 吞噬点击
		if (item->isTouchSwallowed())
		{
			break;
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
