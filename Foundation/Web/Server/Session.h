#pragma once

#include <string>
#include <map>

namespace web
{
	// http�ͻ�����Ϣ
	struct ClientSession
	{
		// session ID
		std::string sessionID;
		// �ͻ���id
		int clientID;
		// ��ʶ
		int tag;

		ClientSession() 
			:sessionID("")
			, clientID(0)
			, tag(0)
		{}
	};

	// ���пͻ��˻Ự����
	class Sessions
	{
	public:
		Sessions();
		virtual ~Sessions();
	public:
		// ���http�ͻ�����Ϣ
		void addSession(const std::string& sessionID, const ClientSession& client);
		// ��ȡhttp�ͻ�����Ϣ
		ClientSession* getSession(const std::string& sessionID);
		// ��ȡhttp�ͻ�����Ϣ
		ClientSession* getSession(int clientID);
		// �Ƴ��ͻ�����Ϣ
		void removeSession(const std::string& sessionID);
		// �Ƴ��ͻ�����Ϣ
		void removeClient(int clientID);
		// �Ƴ����пͻ�����Ϣ
		void removeAllSessions();
	private:
		std::map<std::string, ClientSession> _clientSessions;
	};
}