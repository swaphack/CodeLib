#pragma once

#include "Author.h"
#include <string>

namespace sys
{
	// 发起人
	class Client;

	// 授权
	class Authorization
	{
	public:
		// 远程是否可行
		bool isRemoteEnable(const std::string& url, int port);
		// 验证权限
		bool isPermissionEnable(const Author& info);
	protected:
	protected:
	};
}