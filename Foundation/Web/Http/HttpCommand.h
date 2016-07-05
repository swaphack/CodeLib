#pragma once

#include <map>
#include <string>

#include "../Command/Command.h"

namespace web
{
	// http命令
	class HttpCommand : public Command
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// 设置session id
		void setSessionID(const char* id);
		// 获取session id
		const char* getSessionID();
	private:
		// 目标id
		std::string _sessionID;
	};
}