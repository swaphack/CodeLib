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
	if (key != sys::MouseKey::LEFTBUTTON)
	{
		return;
	}

	math::Volume size = Tool::getGLViewSize();
	if (type == sys::ButtonStatus::BUTTON_DOWN)
	{
		G_TOUCHMANAGER->onTouchBegan(x, size.getHeight() - y);
	}
	else if (type == sys::ButtonStatus::BUTTON_UP)
	{
		G_TOUCHMANAGER->onTouchEnded(x, size.getHeight() - y);
	}
}

void DeviceProxy::onMouseMoveHandler(float x, float y)
{
	math::Volume size = Tool::getGLViewSize();
	G_TOUCHMANAGER->onTouchMoved(x, size.getHeight() - y);
}

void render::DeviceProxy::onMouseScrollHandler(sys::ScrollEvent evt, float param)
{
	G_MOUSEMANAGER->onDispatcher(evt, param);
}

void DeviceProxy::onKeyBoardButtonHandler(sys::BoardKey key, sys::ButtonStatus type)
{
	G_KEYBOARDMANAGER->onDispatcher(key, type);
}
