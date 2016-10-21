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

		ClientSession() :sessionID(""), clientID(0)
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
		void addHttpClient(const char* sessionID, const ClientSession& client);
		// ��ȡhttp�ͻ�����Ϣ
		ClientSession* getHttpClient(const char* sessionID);
		// �Ƴ��ͻ�����Ϣ
		void removeHttpClient(const char* sessionID);
		// �Ƴ����пͻ�����Ϣ
		void removeAllHtppClients();
	private:
		std::map<std::string, ClientSession> _httpClients;
	};
}