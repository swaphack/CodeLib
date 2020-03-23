#include "DeviceProxy.h"
#include "common/Keyboard/KeyboardManager.h"
#include "common/Touch/TouchManager.h"

using namespace render;

DeviceProxy::DeviceProxy(const TouchManager* touchManager)
{
	ASSERT(touchManager != nullptr);
	_touchManager = (TouchManager*)touchManager;

	_keyboardManager = G_KEYBOARDMANAGER;
}

DeviceProxy::~DeviceProxy()
{

}

void DeviceProxy::onMouseButtonHandler(sys::MouseKey key, sys::ButtonStatus type, float x, float y)
{
	if (key != sys::EMK_LEFTBUTTON)
	{
		return;
	}

	if (_touchManager == nullptr)
	{
		return;
	}

	math::Volume size = Tool::getGLViewSize();
	if (type == sys::EBS_BUTTON_DOWN)
	{
		_touchManager->onTouchBegan(x, size.getHeight() - y);
	}
	else if (type == sys::EBS_BUTTON_UP)
	{
		_touchManager->onTouchEnded(x, size.getHeight() - y);
	}
}

void DeviceProxy::onMouseMoveHandler(float x, float y)
{
	if (_touchManager == nullptr)
	{
		return;
	}

	math::Volume size = Tool::getGLViewSize();
	_touchManager->onTouchMoved(x, size.getHeight() - y);
}

void DeviceProxy::onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type)
{
	_keyboardManager->onDispatcher(key, type);
}