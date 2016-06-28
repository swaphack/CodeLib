#pragma once

#include <map>
#include <string>

namespace web
{
	// http命令
	struct HttpCommand
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
		void parseMessage();
	private:
		std::string _msg;
		std::map<std::string, std::string> _params;
	};
}