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
		// 获取信息
		virtual Message* getMessage();
	protected:
		// 设置信息
		virtual void setMessage(Message* message);
	private:
		// 信息
		Message* _message;
	};
}