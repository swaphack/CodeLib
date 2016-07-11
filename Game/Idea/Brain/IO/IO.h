#pragma once

#include "../macros.h"

#include <queue>

namespace idea
{
	// 输入
	class IO
	{
	public:
		IO();
		virtual ~IO();
	public:
		// 输入新信息
		void push(Message* msg);
		// 获取最早输入的信息
		Message* pick();
	protected:
		void clearAllMessages();
	private:
		std::queue<Message*> _msgs;
	};
}