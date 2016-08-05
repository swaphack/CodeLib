#pragma once

#include <string>
#include <map>

namespace web
{
	// http�ͻ�����Ϣ
	struct HttpClient
	{
		// session ID
		std::string sessionID;
		// �ͻ���id
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
		// ���http�ͻ�����Ϣ
		void addHttpClient(const char* sessionID, const HttpClient& client);
		// ��ȡhttp�ͻ�����Ϣ
		HttpClient* getHttpClient(const char* sessionID);
		// �Ƴ��ͻ�����Ϣ
		void removeHttpClient(const char* sessionID);
		// �Ƴ����пͻ�����Ϣ
		void removeAllHtppClients();
	protected:
	private:
		std::map<std::string, HttpClient> _httpClients;
	};
}