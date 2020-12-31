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

void render::TouchManager::setRoot(Node* protocol)
{
	_root = protocol;
}

void TouchManager::onTouchBegan(const math::Vector2& touchPoint)
{
	// 转化为opengl（0，1）会有误差,所以采用实际大小
// 	x = x / Tool::getGLViewSize().width;
// 	y = y / Tool::getGLViewSize().height;

	if (_root != nullptr)
	{
		_root->onTouchBegan(touchPoint);
	}
}

void TouchManager::onTouchMoved(const math::Vector2& touchPoint)
{
	if (_root != nullptr)
	{
		_root->onTouchMoved(touchPoint);
	}
}

void TouchManager::onTouchEnded(const math::Vector2& touchPoint)
{
	if (_root != nullptr)
	{
		_root->onTouchEnded(touchPoint);
	}
}
