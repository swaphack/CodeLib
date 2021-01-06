#include "DeviceProxy.h"
#include "Common/Input/KeyboardManager.h"
#include "Common/Input/TouchManager.h"
#include "Common/Input/MouseManager.h"
#include "mathlib.h"
#include "Common/Tool/Tool.h"

using namespace render;

DeviceProxy::DeviceProxy()
{
}

DeviceProxy::~DeviceProxy()
{

}

void DeviceProxy::onMouseButtonHandler(sys::MouseKey key, sys::ButtonStatus type, float x, float y)
{
	const math::Volume& size = Tool::getGLViewSize();
	float xx = x;
	float yy = size.getHeight() - y;

	_lastMouseKey = key;
	_lastMouseButtonStatus = type;

	math::Vector2 touchPoint(xx, yy);

	processMouseTouchEvent(key, type, touchPoint);
	
	processMouseButtonEvent(key, type, touchPoint);
}

void DeviceProxy::onMouseMoveHandler(float x, float y)
{
	const math::Volume& size = Tool::getGLViewSize();

	float xx = x;
	float yy = size.getHeight() - y;

	math::Vector2 touchPoint(xx, yy);
	
	if (_lastMouseButtonStatus == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_MOUSEMANAGER->onDispatchButtonEvent(_lastMouseKey, _lastMouseButtonStatus, touchPoint);
	}

	if (_lastMouseKey == sys::MouseKey::LEFTBUTTON
		&& _lastMouseButtonStatus == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_TOUCHMANAGER->onTouchMoved(touchPoint);
	}
}

void render::DeviceProxy::onMouseScrollHandler(sys::ScrollEvent evt, float param)
{
	G_MOUSEMANAGER->onDispatchScrolleEvent(evt, param);
}

void render::DeviceProxy::processMouseTouchEvent(sys::MouseKey key, sys::ButtonStatus type, const math::Vector2& touchPoint)
{
	if (key != sys::MouseKey::LEFTBUTTON)
	{
		return;
	}

	if (type == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_TOUCHMANAGER->onTouchBegan(touchPoint);
	}
	else if (type == sys::ButtonStatus::BUTTON_UP)
	{
		G_TOUCHMANAGER->onTouchEnded(touchPoint);
	}
}

void render::DeviceProxy::processMouseButtonEvent(sys::MouseKey key, sys::ButtonStatus type, const math::Vector2& touchPoint)
{
	G_MOUSEMANAGER->onDispatchButtonEvent(key, type, touchPoint);
}

void DeviceProxy::onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type)
{

	G_KEYBOARDMANAGER->onDispatchButtonEvent(key, type);
}
