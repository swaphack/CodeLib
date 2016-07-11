#pragma once

#include "Result.h"

#include <string>

namespace idea
{
	// 传递消息
	class Message : public sys::Object
	{
	public:
		Message();
		virtual ~Message();
	public:
		// 获取标题
		const char* getTitle();
		// 设置标题
		void setTitle(const char* title);
		// 获取消息体
		Result* getBody();
		// 设置消息体
		void setBody(Result* result);
		// 获取消息类型
		int getType();
		// 设置消息类型
		void setType(int value);
	public:
		std::string _title;
		// 消息体
		Result* _body;
		// 消息类型
		int _type;
	};
}