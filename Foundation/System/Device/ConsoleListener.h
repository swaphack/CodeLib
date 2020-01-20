#pragma once

#include "Base/Instance.h"
#include "IConsoleImpl.h"

#include <functional>
#include <string>

namespace sys
{
	typedef	std::function<void(const std::string& line)> ReceiveLineCallback;
	// �����м���
	class ConsoleListener
	{
	public:
		ConsoleListener();
		~ConsoleListener();
	public:
		//
		void setReceiveLineCallback(ReceiveLineCallback handler);
		// ִ��
		void run();
		// ֹͣ
		void stop();
	private:
		// �����д���
		ReceiveLineCallback _receiveLineHandler;
		// �Ƿ���������
		bool _running;
	};


#define G_CONSOLELISTENER sys::Instance<sys::ConsoleListener>::getInstance()
}