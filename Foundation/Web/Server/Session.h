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
		// 标识
		int tag;

		ClientSession() 
			:sessionID("")
			, clientID(0)
			, tag(0)
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
		void addSession(const std::string& sessionID, const ClientSession& client);
		// 获取http客户端信息
		ClientSession* getSession(const std::string& sessionID);
		// 获取http客户端信息
		ClientSession* getSession(int clientID);
		// 移除客户端信息
		void removeSession(const std::string& sessionID);
		// 移除客户端信息
		void removeClient(int clientID);
		// 移除所有客户端信息
		void removeAllSessions();
	private:
		std::map<std::string, ClientSession> _clientSessions;
	};
}