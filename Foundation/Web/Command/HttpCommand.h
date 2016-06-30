#pragma once

#include <map>
#include <string>

namespace web
{
	// http命令
	class HttpCommand
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// 设置消息
		void setMessage(const char* msg, int size);
		// 获取消息
		char* getMessage();
		// 消息大小
		int size();
		// 是否有值
		virtual bool empty();
	protected:
		// 解析消息
		virtual void parseMessage();
	protected:
		std::string _msg;
	};
}