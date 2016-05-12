#include "TouchManager.h"

using namespace render;

TouchManager::TouchManager()
:_lastTouchProtocol(nullptr)
{

}

TouchManager::~TouchManager()
{

}

void TouchManager::addTouch(TouchProtocol* protocol)
{
	if (protocol == nullptr)
	{
		return;
	}

	std::vector<TouchProtocol*>::iterator it = _touchProtocols.begin();
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

void TouchManager::removeTouch(TouchProtocol* protocol)
{
	if (protocol == nullptr)
	{
		return;
	}

	std::vector<TouchProtocol*>::iterator it = _touchProtocols.begin();
	while (it != _touchProtocols.end())
	{
		if ((*it) == protocol)
		{
			_touchProtocols.erase(it);
			break;
		}
		it++;
	}
}

void TouchManager::removeAllTouches()
{
	_touchProtocols.clear();
}

bool TouchManager::onTouchBegan(float x, float y)
{
	std::vector<TouchProtocol*>::reverse_iterator it = _touchProtocols.rbegin();
	while (it != _touchProtocols.rend())
	{
		if ((*it)->onTouchBegan(x, y))
		{
			_lastTouchProtocol = (*it);
			return true;
		}
		it++;
	}

	return false;
}

void TouchManager::onTouchMove(float x, float y)
{
	if (_lastTouchProtocol == nullptr)
	{
		return;
	}

	_lastTouchProtocol->onTouchMove(x, y);
}

void TouchManager::onTouchEnd(float x, float y)
{
	if (_lastTouchProtocol == nullptr)
	{
		return;
	}

	_lastTouchProtocol->onTouchEnd(x, y);
}
