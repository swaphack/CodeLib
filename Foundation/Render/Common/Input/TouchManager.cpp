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
	// ת��Ϊopengl��0��1���������,���Բ���ʵ�ʴ�С
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
