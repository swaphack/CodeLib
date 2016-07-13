#pragma once

#include <map>
#include <string>

#include "macros.h"

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
		// 是否是http格式
		bool isHttpFormat();
		// 设置是否是http格式
		void setHttpFormat(bool status);
	private:
		// 目标id
		std::string _sessionID;
		// 是否http格式
		bool _bHttpFormat;
	};
}