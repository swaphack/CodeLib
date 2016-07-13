#pragma once

#include <map>
#include <string>

namespace web
{
	// 命令
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
		// 是否是个完整的命令
		bool isFullCommand();
	protected:
		void setFullCommand(bool status);
	protected:
		// 消息
		std::string _msg;
		// 是否是个完整的命令
		bool _bFullCommand;
	};
}