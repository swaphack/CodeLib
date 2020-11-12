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
	math::Volume size = Tool::getGLViewSize();
	float xx = x;
	float yy = size.getHeight() - y;

	_lastMouseKey = key;
	_lastMouseButtonStatus = type;

	processMouseTouchEvent(key, type, xx, yy);
	
	processMouseButtonEvent(key, type, xx, yy);
}

void DeviceProxy::onMouseMoveHandler(float x, float y)
{
	math::Volume size = Tool::getGLViewSize();
	float xx = x;
	float yy = size.getHeight() - y;
	
	if (_lastMouseButtonStatus == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_MOUSEMANAGER->onDispatchButtonEvent(_lastMouseKey, _lastMouseButtonStatus, xx, yy);
	}

	if (_lastMouseKey == sys::MouseKey::LEFTBUTTON
		&& _lastMouseButtonStatus == sys::ButtonStatus::BUTTON_DOWN)
	{
		math::Volume size = Tool::getGLViewSize();
		G_TOUCHMANAGER->onTouchMoved(xx, yy);
	}
}

void render::DeviceProxy::onMouseScrollHandler(sys::ScrollEvent evt, float param)
{
	G_MOUSEMANAGER->onDispatchScrolleEvent(evt, param);
}

void render::DeviceProxy::processMouseTouchEvent(sys::MouseKey key, sys::ButtonStatus type, float x, float y)
{
	if (key != sys::MouseKey::LEFTBUTTON)
	{
		return;
	}

	if (type == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_TOUCHMANAGER->onTouchBegan(x, y);
	}
	else if (type == sys::ButtonStatus::BUTTON_UP)
	{
		G_TOUCHMANAGER->onTouchEnded(x, y);
	}
}

void render::DeviceProxy::processMouseButtonEvent(sys::MouseKey key, sys::ButtonStatus type, float x, float y)
{
	G_MOUSEMANAGER->onDispatchButtonEvent(key, type, x, y);
}

void DeviceProxy::onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type)
{

	G_KEYBOARDMANAGER->onDispatchButtonEvent(key, type);
}
