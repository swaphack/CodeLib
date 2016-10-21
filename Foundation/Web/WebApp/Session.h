#pragma once

#include <string>
#include <map>

namespace web
{
	// http客户端信息
	struct ClientSession
	{
		// session ID
		std::string sessionID;
		// 客户端id
		int clientID;

		ClientSession() :sessionID(""), clientID(0)
		{}
	};

	// 所有客户端会话保存
	class Sessions
	{
	public:
		Sessions();
		virtual ~Sessions();
	public:
		// 添加http客户端信息
		void addHttpClient(const char* sessionID, const ClientSession& client);
		// 获取http客户端信息
		ClientSession* getHttpClient(const char* sessionID);
		// 移除客户端信息
		void removeHttpClient(const char* sessionID);
		// 移除所有客户端信息
		void removeAllHtppClients();
	private:
		std::map<std::string, ClientSession> _httpClients;
	};
}