#pragma once

#include <string>
#include <map>

namespace web
{
	// http客户端信息
	struct HttpClient
	{
		// session ID
		std::string sessionID;
		// 客户端id
		int clientID;

		HttpClient() :sessionID(""), clientID(0)
		{}
	};

	class Session
	{
	public:
		Session();
		virtual ~Session();
	public:
		// 添加http客户端信息
		void addHttpClient(const char* sessionID, const HttpClient& client);
		// 获取http客户端信息
		HttpClient* getHttpClient(const char* sessionID);
		// 移除客户端信息
		void removeHttpClient(const char* sessionID);
		// 移除所有客户端信息
		void removeAllHtppClients();
	protected:
	private:
		std::map<std::string, HttpClient> _httpClients;
	};
}