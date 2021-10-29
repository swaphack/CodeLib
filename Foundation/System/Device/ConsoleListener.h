#pragma once

#include "Base/Instance.h"

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
		ReceiveLineCallback _receiveLineHandler = nullptr;
		// 是否正在运行
		bool _running = false;
	};


#define G_CONSOLELISTENER Instance<ConsoleListener>::getInstance()
}