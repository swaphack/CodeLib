#pragma once

#include "Message.h"

namespace idea
{
	// 事件
	class Event
	{
	public:
		Event();
		virtual ~Event();
	public:
		// 设置信息
		void setMessage(Message* message);
		// 获取信息
		Message* getMessage();
	private:
		// 信息
		Message* _message;
	};
}