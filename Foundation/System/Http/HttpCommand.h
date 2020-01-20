#pragma once

#include <string>
#include <cstdint>

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
		void setSessionID(const std::string& id);
		// 获取session id
		const std::string& getSessionID();
		// 设置消息
		virtual void setMessage(const std::string& msg, int32_t size);
		// 生成消息
		virtual void makeMessage();
		// 获取消息
		const std::string& getMessage();
		// 消息大小
		int32_t getMessageSize();
		// 是否有值
		virtual bool isMessageEmpty();
	private:
		// 消息
		std::string _msg;
		// 目标id
		std::string _sessionID;
	};
}