#pragma once

#include "Message.h"

namespace idea
{
	// 事件
	class Event : public sys::Object
	{
	public:
		Event();
		virtual ~Event();
	public:
		// 获取信息
		Result* getMessage();
		// 设置信息
		void setMessage(Result* result);
		// 获取事件类型
		int getType();
		// 设置事件类型
		void setType(int value);
	private:
		// 信息
		Message* _message;
		// 事件类型
		int _type;
	};
}