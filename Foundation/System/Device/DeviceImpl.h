#pragma once

namespace sys
{
	class Keyboard;
	class Mouse;

	/**
	*	�豸
	*/
	class DeviceImpl
	{
	public:
		DeviceImpl();
		virtual ~DeviceImpl();
	public:
		// ����
		virtual Keyboard* getKeyboard();
		// ���
		virtual Mouse* getMouse();
	protected:
		// ����
		Keyboard* _keyboard = nullptr;
		// ���
		Mouse* _mouse = nullptr;
	};
}