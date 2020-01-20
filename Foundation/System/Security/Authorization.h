#pragma once

#include "Author.h"

#include <string>
#include <cstdint>

namespace sys
{
	// ������
	class Client;

	// ��Ȩ
	class Authorization
	{
	public:
		// Զ���Ƿ����
		bool isRemoteEnable(const std::string& url, int32_t port);
		// ��֤Ȩ��
		bool isPermissionEnable(const Author& info);
	protected:
	protected:
	};
}