#pragma once

#include <map>
#include <string>

namespace web
{
	// http命令
	class Command
	{
	public:
		Command();
		virtual ~Command();
	public:
		// 设置消息
		virtual void setMessage(const char* msg, int size);
		// 获取消息
		const char* getMessage();
		// 消息大小
		int size();
		// 是否有值
		virtual bool empty();
	protected:
		std::string _msg;
	};
}