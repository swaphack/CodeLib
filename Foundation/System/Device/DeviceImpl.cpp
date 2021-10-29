#include "DeviceImpl.h"
#include "Keyboard.h"
#include "Mouse.h"

using namespace sys;

DeviceImpl::DeviceImpl()
{
	_keyboard = new Keyboard();
	_mouse = new Mouse();
}

DeviceImpl::~DeviceImpl()
{
	SAFE_DELETE(_keyboard);
	SAFE_DELETE(_mouse);
}

Keyboard* DeviceImpl::getKeyboard() const
{
	return _keyboard;
}

Mouse* DeviceImpl::getMouse() const
{
	return _mouse;
}

