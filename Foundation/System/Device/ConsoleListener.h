#pragma once

#include "Base/Instance.h"
#include "IConsoleImpl.h"

#include <functional>
#include <string>

namespace sys
{
	typedef	std::function<void(const std::string& line)> ReceiveLineCallback;
	// 命令行监听
	class ConsoleListener
	{
	public:
		ConsoleListener();
		~ConsoleListener();
	public:
		//
		void setReceiveLineCallback(ReceiveLineCallback handler);
		// 执行
		void run();
		// 停止
		void stop();
	private:
		// 接受行处理
		ReceiveLineCallback _receiveLineHandler;
		// 是否正在运行
		bool _running;
	};


#define G_CONSOLELISTENER sys::Instance<sys::ConsoleListener>::getInstance()
}