#pragma once

#include <map>
#include <string>

#include "macros.h"

namespace web
{
	// http����
	class HttpCommand : public Command
	{
	public:
		HttpCommand();
		virtual ~HttpCommand();
	public:
		// ����session id
		void setSessionID(const char* id);
		// ��ȡsession id
		const char* getSessionID();
		// �Ƿ���http��ʽ
		bool isHttpFormat();
		// �����Ƿ���http��ʽ
		void setHttpFormat(bool status);
	private:
		// Ŀ��id
		std::string _sessionID;
		// �Ƿ�http��ʽ
		bool _bHttpFormat;
	};
}