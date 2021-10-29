#pragma once

namespace sys
{
	class Keyboard;
	class Mouse;

	/**
	*	设备
	*/
	class DeviceImpl
	{
	public:
		DeviceImpl();
		virtual ~DeviceImpl();
	public:
		// 键盘
		virtual Keyboard* getKeyboard() const;
		// 鼠标
		virtual Mouse* getMouse() const;
	protected:
		// 键盘
		Keyboard* _keyboard = nullptr;
		// 鼠标
		Mouse* _mouse = nullptr;
	};
}