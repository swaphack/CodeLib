#include "TouchManager.h"
#include "TouchProxy.h"
using namespace render;

TouchManager::TouchManager()
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
}

void TouchManager::removeAllTouches()
{
	_touchProtocols.clear();
}

void TouchManager::onTouchBegan(float x, float y)
{
	// 转化为opengl（0，1）会有误差,所以采用实际大小
// 	x = x / Tool::getGLViewSize().width;
// 	y = y / Tool::getGLViewSize().height;
	auto it = _touchProtocols.rbegin();
	while (it != _touchProtocols.rend())
	{
		if ((*it)->isTouchEnabled())
		{
			if ((*it)->onTouchBegan(x, y))
			{
				if ((*it)->isSwallowTouch())
				{
					break;
				}
			}
		}
		it++;
	}
}

void TouchManager::onTouchMoved(float x, float y)
{
	auto it = _touchProtocols.rbegin();
	while (it != _touchProtocols.rend())
	{
		if ((*it)->isTouchEnabled())
		{
			if ((*it)->onTouchMoved(x, y))
			{
				if ((*it)->isSwallowTouch())
				{
					break;
				}
			}
		}
		it++;
	}
}

void TouchManager::onTouchEnded(float x, float y)
{
	auto it = _touchProtocols.rbegin();
	bool ret = false;
	while (it != _touchProtocols.rend())
	{
		if ((*it)->isTouchEnabled())
		{
			if ((*it)->onTouchEnded(x, y))
			{
				if ((*it)->isSwallowTouch())
				{
					break;
				}
			}
		}
		it++;
	}
}
