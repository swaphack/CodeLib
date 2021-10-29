#pragma once

#include <string>
#include <cstdint>

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
		void setSessionID(const std::string& id);
		// ��ȡsession id
		const std::string& getSessionID() const;
		// ������Ϣ
		virtual void setMessage(const std::string& msg, int32_t size);
		// ������Ϣ
		virtual void makeMessage();
		// ��ȡ��Ϣ
		const std::string& getMessage();
		// ��Ϣ��С
		int32_t getMessageSize() const;
		// �Ƿ���ֵ
		virtual bool isMessageEmpty() const;
	private:
		// ��Ϣ
		std::string _msg;
		// Ŀ��id
		std::string _sessionID;
	};
}