#pragma once

#include "Author.h"
#include <string>

namespace sys
{
	// ������
	class Client;

	// ��Ȩ
	class Authorization
	{
	public:
		// Զ���Ƿ����
		bool isRemoteEnable(const std::string& url, int port);
		// ��֤Ȩ��
		bool isPermissionEnable(const Author& info);
	protected:
	protected:
	};
}