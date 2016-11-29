#include "TouchManager.h"

using namespace render;

TouchManager::TouchManager()
:_lastTouchProtocol(nullptr)
{

}

TouchManager::~TouchManager()
{
	this->removeAllTouches();
}

void TouchManager::addTouch(TouchProxy* protocol)
{
	if (protocol == nullptr)
	{
		return;
	}

	std::vector<TouchProxy*>::iterator it = _touchProtocols.begin();
	while (it != _touchProtocols.end())
	{
		if ((*it) == protocol)
		{
			return;
		}
		it++;
	}

	_touchProtocols.push_back(protocol);
}

void TouchManager::removeTouch(TouchProxy* protocol)
{
	if (protocol == nullptr)
	{
		return;
	}

	std::vector<TouchProxy*>::iterator it = _touchProtocols.begin();
	while (it != _touchProtocols.end())
	{
		if ((*it) == protocol)
		{
			_touchProtocols.erase(it);
			break;
		}
		it++;
	}

	if (_lastTouchProtocol == protocol)
	{
		_lastTouchProtocol = nullptr;
	}
}

void TouchManager::removeAllTouches()
{
	_touchProtocols.clear();
}

bool TouchManager::onTouchBegan(float x, float y)
{
	// 转化为opengl（0，1）会有误差,所以采用实际大小
// 	x = x / Tool::getGLViewSize().width;
// 	y = y / Tool::getGLViewSize().height;
	std::vector<TouchProxy*>::reverse_iterator it = _touchProtocols.rbegin();

	while (it != _touchProtocols.rend())
	{
		if ((*it)->isTouchEnabled() && (*it)->onTouchBegan(x, y))
		{
			_lastTouchProtocol = (*it);
			return true;
		}
		it++;
	}

	return false;
}

void TouchManager::onTouchMoved(float x, float y)
{
	if (_lastTouchProtocol == nullptr)
	{
		return;
	}

	if (_lastTouchProtocol->isTouchEnabled())
	{
		_lastTouchProtocol->onTouchMoved(x, y);
	}
}

void TouchManager::onTouchEnded(float x, float y)
{
	if (_lastTouchProtocol == nullptr)
	{
		return;
	}

	if (_lastTouchProtocol->isTouchEnabled())
	{
		_lastTouchProtocol->onTouchEnded(x, y);
	}

	_lastTouchProtocol = nullptr;
}
