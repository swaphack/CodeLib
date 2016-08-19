#pragma once

#include <map>
#include <string>

namespace sys
{
	// http����
	class HttpCommand
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// ����session id
		void setSessionID(const char* id);
		// ��ȡsession id
		const char* getSessionID();
		// ������Ϣ
		virtual void setMessage(const char* msg, int size);
		// ������Ϣ
		virtual void makeMessage();
		// ��ȡ��Ϣ
		const char* getMessage();
		// ��Ϣ��С
		int getMessageSize();
		// �Ƿ���ֵ
		virtual bool isMessageEmpty();
	private:
		// ��Ϣ
		std::string _msg;
		// Ŀ��id
		std::string _sessionID;
	};
}