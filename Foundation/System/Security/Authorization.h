#pragma once

#include "Author.h"
#include "Base/Types.h"

namespace sys
{
	// ������
	class Client;

	// ��Ȩ
	class Authorization
	{
	public:
		// Զ���Ƿ����
		bool isRemoteEnable(const std::string& url, int32 port);
		// ��֤Ȩ��
		bool isPermissionEnable(const Author& info);
	protected:
	protected:
	};
}