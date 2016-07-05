#pragma once

#include <map>
#include <string>

#include "../Command/Command.h"

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
	private:
		// Ŀ��id
		std::string _sessionID;
	};
}