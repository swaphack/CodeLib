#pragma once

#include <map>
#include <string>

namespace sys
{
	// http命令
	class HttpCommand
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// 设置session id
		void setSessionID(const char* id);
		// 获取session id
		const char* getSessionID();
		// 设置消息
		virtual void setMessage(const char* msg, int size);
		// 生成消息
		virtual void makeMessage();
		// 获取消息
		const char* getMessage();
		// 消息大小
		int getMessageSize();
		// 是否有值
		virtual bool isMessageEmpty();
	private:
		// 消息
		std::string _msg;
		// 目标id
		std::string _sessionID;
	};
}